#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# ATOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
#

import os, sys
import hashlib
import tempfile
import shutil
import errno
from deep_eq import deep_eq
import process

class ObjWriter():
    def __init__(self):
        pass

    def make_blob_(self, blob):
        return "blob %d\n%s" % (len(blob), blob)

    def make_clst_(self, clst):
        assert(isinstance(clst, list))
        content = ""
        for obj in clst:
            content += "%s\n" % self.make_obj(obj)
        return "clst %d\n%s" % (len(content), content)

    def make_cmap_(self, cmap):
        assert(isinstance(cmap, dict))
        content = ""
        for key in sorted(cmap.keys()):
            content += "%s\n%s\n" % (key, self.make_obj(cmap[key]))
        return "cmap %d\n%s" % (len(content), content)

    def make_obj(self, obj):
        assert(isinstance(obj, (str, list, dict)))
        if isinstance(obj, str):
            return self.make_blob_(obj)
        elif isinstance(obj, list):
            return self.make_clst_(obj)
        elif isinstance(obj, dict):  # pragma: branch_always
            return self.make_cmap_(obj)

    def parse_blob_(self, content):
        (header, content) = content.split("\n", 1)
        assert(header[:5] == "blob ")
        size = int(header[5:])
        return (size + len(header) + 1, content[:size])

    def parse_clst_(self, content):
        (header, content) = content.split("\n", 1)
        assert(header[:5] == "clst ")
        content_size = int(header[5:])
        clst = []
        clst_size = 0
        while clst_size < content_size:
            (size, obj) = self.parse_obj(content)
            clst.append(obj)
            content = content[size + 1:]
            clst_size += size + 1
        return (content_size + len(header) + 1, clst)

    def parse_cmap_(self, content):
        (header, content) = content.split("\n", 1)
        assert(header[:5] == "cmap ")
        content_size = int(header[5:])
        cmap = {}
        cmap_size = 0
        while cmap_size < content_size:
            (key, content) = content.split("\n", 1)
            (size, obj) = self.parse_obj(content)
            cmap[key] = obj
            content = content[size + 1:]
            cmap_size += len(key) + 1 + size + 1
        return (cmap_size + len(header) + 1, cmap)

    def parse_obj(self, content):
        (header, _) = content.split("\n", 1)
        kind = header[:5]
        if kind == "blob ":
            (size, obj) = self.parse_blob_(content)
        elif kind == "clst ":
            (size, obj) = self.parse_clst_(content)
        elif kind == "cmap ":  # pragma: branch_always
            (size, obj) = self.parse_cmap_(content)
        else:  # pragma: unreachable
            assert(False)
        return (size, obj)

    def digest_content(self, content):
        return hashlib.sha1(content).hexdigest()

    def digest_obj(self, obj):
        return hashlib.sha1(self.make_obj(obj)).hexdigest()

    @staticmethod
    def test():
        print "TESTING ObjWriter..."
        writer = ObjWriter()
        blob = "aa"
        c = writer.make_blob_(blob)
        assert(c == "blob 2\naa")
        (s, v) = writer.parse_blob_(c)
        assert(s == 9)
        deep_eq(v, blob, _assert=True)
        assert(writer.digest_content("blob 2\naa") ==
               "e3b380d24c97baeca9843158f63c876d05492caf")
        assert(writer.digest_obj("aa") ==
               "e3b380d24c97baeca9843158f63c876d05492caf")
        clst = ["aa", "", "bb"]
        c = writer.make_clst_(clst)
        assert(c == "clst 28\n"
               "blob 2\naa\n"
               "blob 0\n\n"
               "blob 2\nbb\n")
        (s, v) = writer.parse_clst_(c)
        assert(s == 36)
        deep_eq(v, clst, _assert=True)
        cmap = {"a": "aa", "": "", "b": "bb"}
        c = writer.make_cmap_(cmap)
        assert(c == "cmap 33\n"
               "\nblob 0\n\n"
               "a\nblob 2\naa\n"
               "b\nblob 2\nbb\n")
        (s, v) = writer.parse_cmap_(c)
        assert(s == 41)
        deep_eq(v, cmap, _assert=True)
        obj = {'cmap': cmap, 'clst': clst,
               'blob': blob}
        c = writer.make_obj(obj)
        (s, v) = writer.parse_obj(c)
        deep_eq(v, obj, _assert=True)
        print "SUCCESS ObjWriter"
        return True

class ObjStorage():

    class KeyConflictError(Exception):
        pass

    def __init__(self, stg_path):
        # Hard links are required to implement atomicity
        assert(hasattr(os, "link"))
        self.writer = ObjWriter()
        self.stg_path_ = os.path.abspath(stg_path)
        assert(self.stg_path_ != "/")

    def clear_all(self):
        process.commands.rmtree(self.stg_path_)

    def get_stg_path_(self, obj_path):
        return os.path.join(self.stg_path_, obj_path)

    def get_digest_path_(self, digest):
        assert(len(digest) > 2)
        return os.path.join(digest[:2], digest[2:])

    def get_local_tmpdir_(self):
        tmpdir = self.get_stg_path_("tmp")
        process.commands.mkdir(tmpdir)
        return tmpdir

    def get_content_digest_(self, path):
        digest = hashlib.sha1()
        with open(path, "rb") as f:
            buf = f.read(4096)
            while buf:
                digest.update(buf)
                buf = f.read(4096)
        return digest.hexdigest()

    def make_dirpath_(self, obj_path):
        dirname = os.path.dirname(obj_path)
        process.commands.mkdir(dirname)

    def commit_local_file_(self, obj_path, content_path):
        self.make_dirpath_(obj_path)
        try:
            process.commands.link(content_path, obj_path)
        except OSError, e:
            # If object already exists, it's ok as obj_path
            # uniquely identify the content to be written.
            # Hence we can ignore the commit as soon as the
            # files are the same. In the highly imporbable case
            # of conflict, we raise an exception.
            if e.errno == errno.EEXIST:
                if process.commands.diff(content_path, obj_path):
                    raise ObjStorage.KeyConflictError()
                return
            raise

    def store_content_(self, obj_path, content):
        with tempfile.NamedTemporaryFile(dir=self.get_local_tmpdir_()) as f:
            f.write(content)
            f.flush()
            self.commit_local_file_(obj_path, f.name)

    def store_file_content_(self, obj_path, content_path):
        with tempfile.NamedTemporaryFile(dir=self.get_local_tmpdir_()) as f:
            process.commands.copyfile(content_path, f.name)
            self.commit_local_file_(obj_path, f.name)

    def store_obj(self, obj):
        digest = self.writer.digest_obj(obj)
        self.store_content_(self.get_obj_path(digest),
                            self.writer.make_obj(obj))
        return digest

    def store_digest_blob(self, digest, blob):
        self.store_content_(self.get_blob_path(digest),
                            blob)
        return digest

    def store_digest_file(self, digest, file_path):
        self.store_file_content_(self.get_blob_path(digest),
                                 file_path)
        return digest

    def store_file(self, file_path):
        digest = self.get_content_digest_(file_path)
        self.store_digest_file(digest, file_path)
        return digest

    def load_content_(self, obj_path):
        with open(obj_path, "rb") as f:
            return f.read()

    def load_obj(self, obj_digest):
        obj_path = self.get_obj_path(obj_digest)
        return self.writer.parse_obj(self.load_content_(obj_path))[1]

    def get_obj_path(self, obj_digest):
        return self.get_stg_path_(
            os.path.join("objects",
                         self.get_digest_path_(obj_digest)))

    def get_blob_path(self, blob_digest):
        return self.get_stg_path_(
            os.path.join("blobs",
                         self.get_digest_path_(blob_digest)))

    @staticmethod
    def test():
        print "TESTING ObjStorage..."
        tmpdir = tempfile.mkdtemp()
        try:
            stg = ObjStorage(os.path.join(tmpdir, "storage"))
            stg.store_digest_blob("a0b65939670bc2c010f4d5d6a0b3e4e4590fb92b",
                                  "Hello World!\n")
            bname = os.path.join(tmpdir, "storage", "blobs",
                                 "a0",
                                 "b65939670bc2c010f4d5d6a0b3e4e4590fb92b")
            assert(os.path.isfile(bname))
            assert(os.stat(bname)[6] == 13)
            atmpfile = tempfile.NamedTemporaryFile()
            stg.store_file(atmpfile.name)
            bname = os.path.join(tmpdir, "storage", "blobs",
                                 "da",
                                 "39a3ee5e6b4b0d3255bfef95601890afd80709")
            assert(os.path.isfile(bname))
            assert(os.stat(bname)[6] == 0)
            atmpfile.write("Hello World!\n")
            atmpfile.flush()
            stg.store_file(atmpfile.name)
            bname = os.path.join(tmpdir, "storage", "blobs",
                                 "a0",
                                 "b65939670bc2c010f4d5d6a0b3e4e4590fb92b")
            assert(os.path.isfile(bname))
            assert(os.stat(bname)[6] == 13)
            obj = ""
            stg.store_obj(obj)
            bname = os.path.join(tmpdir, "storage", "objects",
                                 "08",
                                 "6fdd7631d586d121a6192c5987834ac6cbf9f0")
            assert(os.path.isfile(bname))
            assert(os.stat(bname)[6] == 7)
            stg.clear_all()
            assert(not os.path.exists(os.path.join(tmpdir, "storage")))
            # Check key error exception by simulating a conflict
            stg.store_obj("")
            with open(os.path.join(
                    tmpdir, "storage", "objects",
                    "08",
                    "6fdd7631d586d121a6192c5987834ac6cbf9f0"), "wb") as f:
                f.write("An erroneous object\n")  # pragma: branch_uncovered
            try:
                assert(stg.store_obj("") == None)
            except ObjStorage.KeyConflictError:
                pass
        finally:
            shutil.rmtree(tmpdir)
        print "SUCCESS ObjStorage"
        return True

if __name__ == "__main__":
    passed = ObjWriter.test()
    if not passed: sys.exit(1)
    passed = ObjStorage.test()
    if not passed: sys.exit(1)
