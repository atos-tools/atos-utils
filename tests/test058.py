#!/usr/bin/env python
#
#

import common
import os, shutil, filecmp
from atos import utils

TEST_CASE = "ATOS atos-build invocation"

log = "debug.log"

args = common.atos_setup_args(ATOS_DEBUG_FILE=log)

sha1dir = os.path.join(common.SRCDIR, 'examples', 'sha1-c')

status = utils.invoque(
    "atos-init", args, run_script=os.path.join(sha1dir, "run.sh"),
    build_script="gcc -o sha1-c %s %s" % (
        os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")))
assert status == 0

#
#   -a OPTIONS, --options OPTIONS
#

status = utils.invoque("atos-build", args, options="-O2")
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -O2\]")) == 1
shutil.copyfile("sha1-c", "sha1-c.O2")

status = utils.invoque("atos-build", args, options="-O3 -g")
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -O3 -g\]")) == 1
shutil.copyfile("sha1-c", "sha1-c.O3g")

#
#   -f, --force
#

status = utils.invoque("atos-build", args, options="-O2", force=True)
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -O2\]")) == 2
assert filecmp.cmp("sha1-c", "sha1-c.O2")

status = utils.invoque("atos-build", args, options="-O3 -g", force=True)
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -O3 -g\]")) == 2
assert filecmp.cmp("sha1-c", "sha1-c.O3g")

#
#   -g GOPTS, --genprof GOPTS
#

status = utils.invoque("atos-build", args, options="-O2", gopts="-O2")
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -fprofile-generate")) == 1
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -fprofile-dir")) == 1

status = utils.invoque("atos-run", args, options="-O2", gopts="-O2")
assert status == 0

#
#   -u UOPTS, --useprof UOPTS
#

status = utils.invoque("atos-build", args, options="-O2", uopts="-O2")
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -fprofile-use")) == 1
assert not common.grep(common.atos_log_name("build", options="-O2", uopts="-O2"), "gcda not found")


#
#   -p PATH, --path PATH
#

os.makedirs("proftmp")
status = utils.invoque("atos-build", args, options="-O3", gopts="-O3", path="proftmp")
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .*proftmp")) == 1

status = utils.invoque("atos-run", args, options="-O3", gopts="-O3")
assert status == 0

status = utils.invoque("atos-build", args, options="-O3", uopts="-O3", path="proftmp")
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .*proftmp")) == 2
assert not common.grep(common.atos_log_name("build", options="-O3", uopts="-O3"), "gcda not found")

#
#   -w VARIANT, --variant VARIANT
#

status = utils.invoque("atos-build", args, options="-O1", variant="XXXO1")
assert status == 0 and common.grep(common.atos_log_name("build", variant="XXXO1"), "SUCCESS building variant XXXO1")

#
# positional arguments: command
#

status = utils.invoque("atos-build", args, options="-O0",
                       command=["gcc", "-o", "sha1-c.O0", os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")])
assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -O0")) == 1
assert os.path.isfile("sha1-c.O0")



#
# TODO
#

if False:  # does not work for now (#180488)
    status = utils.invoque("atos-build", args, options="-O2", gopts="-O2", force=True)
    assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -fprofile-generate")) == 2
    assert status == 0 and len(common.grep(log, "DEBUG: command \[gcc .* -fprofile-dir")) == 2




