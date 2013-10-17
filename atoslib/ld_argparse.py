#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License v2.0
# as published by the Free Software Foundation
#
# ATOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
#

import sys
import shlex
import re
import gen_argparse
import ld_arguments
from deep_eq import deep_eq
import os
import tempfile
import shutil

class LDArgumentError(Exception):
    """ User exception for invalid LD argument. """
    pass

class LDArgumentInterpreter:

    def __init__(self, namespace, desc=ld_arguments.LDArgumentsDesc):
        self.prepare_ld_phase_(namespace, desc)

    def prepare_ld_phase_(self, namespace, desc):

        self.ld_inputs_ = []
        self.ld_outputs_ = []
        self.ld_kind_ = None

        ld_inputs = []
        ld_outputs = []
        if namespace.output_kind == 'nooutput':
            return
        ld_inputs = namespace.inputs[:]
        if len(ld_inputs) == 0:
            raise LDArgumentError("no input")
        assert(len(namespace.outputs) <= 1)
        if not namespace.outputs:
            ld_outputs = ["a.out"]
        else:
            ld_outputs = namespace.outputs[:]

        self.ld_inputs_ = ld_inputs
        self.ld_outputs_ = ld_outputs
        assert(namespace.output_kind in
               ["executable", "relocatable"])
        assert(namespace.exec_kind in
               ["program", "shared"])
        self.ld_kind_ = namespace.output_kind
        if self.ld_kind_ == "executable":
            self.ld_kind_ = namespace.exec_kind

    def all_cc_inputs(self):
        """
        Returns all the inputs files for the LD command.
        """
        return self.ld_inputs_

    def all_cc_outputs(self):
        """
        Return all the output files of the LD command.
        """
        return self.ld_outputs_

    def is_ld_kind(self, kind):
        """
        Returns True if the LD output if of the given kind.
        One of "program", "relocatable", "shared".
        Returns False otherwise or if LD is not generating any
        output.
        """
        assert(kind in ["program", "relocatable", "shared"])
        return self.ld_kind_ == kind

    def has_final_link(self):
        """
        Returns true is the compiler is doing a final link phase,
        i.e. running LD and generating shared object or program file.
        """
        return (self.is_ld_kind("program") or
                self.is_ld_kind("shared"))

    def has_reloc_link(self):
        """
        Returns true is the compiler is doing a relocatable link phase,
        i.e. running LD and generating a relocatable object.
        """
        return self.is_ld_kind("relocatable")

class LDArgumentProcessor:
    def __init__(self, namespace, cwd=".", desc=ld_arguments.LDArgumentsDesc):
        self.ns_ = namespace
        self.desc_ = desc
        self.ns_.linker_flags = []
        self.ns_.unknown_flags = []
        self.ns_.inputs = []
        self.ns_.outputs = []
        self.ns_.output_kind = 'executable'
        self.ns_.exec_kind = 'program'
        self.ns_.static_libs = False
        self.ns_.cwd = cwd
        self.ns_.lpath = []

    def append_input_(self, arg):
        self.ns_.inputs.append(arg)

    def opt_o(self, args):
        self.ns_.outputs = [args[1]]

    def opt_other(self, args):
        self.ns_.unknown_flags.append(args[0])

    def opt_r(self, args):
        self.ns_.output_kind = 'relocatable'

    def opt_shared(self, args):
        self.ns_.exec_kind = 'shared'

    def opt_static(self, args):
        self.ns_.static_libs = True

    def opt_dynamic(self, args):
        self.ns_.static_libs = False

    def opt_a(self, args):
        if args[1] == "archive":
            self.ns_.static_libs = True
        elif args[1] == "shared" or args[1] == "default":
            self.ns_.static_libs = False
        else:  # unexpected, consider a no-op
            pass

    def opt_version(self, args):
        self.ns_.output_kind = 'nooutput'

    def opt_help(self, args):
        self.ns_.output_kind = 'nooutput'

    def opt_L(self, args):
        self.ns_.lpath.append(os.path.normpath(
                os.path.join(self.ns_.cwd, args[1])))

    def opt_l(self, args):
        for path in self.ns_.lpath:
            lib_base = os.path.join(path, "lib" + args[1])
            lib_path = "%s.so" % lib_base
            if not self.ns_.static_libs and os.access(lib_path, os.R_OK):
                self.append_input_(lib_path)
                break
            lib_path = "%s.a" % lib_base
            if os.access(lib_path, os.R_OK):
                self.append_input_(lib_path)
                break

    def REMAINDER(self, args):
        infile = args[1]
        self.append_input_(infile)

    def POSTPROCESS(self):
        return

class LDArgumentParser:
    def __init__(self, prog, cwd=".", desc=ld_arguments.LDArgumentsDesc):
        self.desc_ = desc
        self.cwd_ = cwd
        self.parser_ = gen_argparse.GenArgumentParser(prog)
        for desc in desc.options_desc:
            self.parser_.add_argument(**desc)

    def parse_args(self, args, namespace):
        ns, args = self.parser_.parse_args(
            args, LDArgumentProcessor(namespace, cwd=self.cwd_,
                                      desc=self.desc_))
        return ns.ns_

    @staticmethod
    def test():  # pragma: uncovered (ignore test funcs)
        class TestNameSpace():
            pass
        print "TESTING LDArgumentsParser..."
        tmpdir = tempfile.mkdtemp()
        try:
            parser = LDArgumentParser("ld")
            ns = parser.parse_args(shlex.split(
                    "--help"), TestNameSpace())
            deep_eq(ns.unknown_flags, [], _assert=True)
            deep_eq(ns.outputs, [], _assert=True)
            deep_eq(ns.inputs, [], _assert=True)
            deep_eq(ns.output_kind, 'nooutput', _assert=True)
            interp = LDArgumentInterpreter(ns)
            deep_eq(interp.all_cc_outputs(), [], _assert=True)
            deep_eq(interp.all_cc_inputs(), [], _assert=True)
            deep_eq(interp.is_ld_kind("program"), False, _assert=True)
            deep_eq(interp.has_final_link(), False, _assert=True)
            deep_eq(interp.has_reloc_link(), False, _assert=True)

            ns = parser.parse_args(shlex.split(
                    "--version"), TestNameSpace())
            deep_eq(ns.output_kind, 'nooutput', _assert=True)

            ns = parser.parse_args(shlex.split(
                    "-o a.exe in.o"), TestNameSpace())
            deep_eq(ns.unknown_flags, [], _assert=True)
            deep_eq(ns.output_kind, 'executable', _assert=True)
            deep_eq(ns.outputs, ["a.exe"], _assert=True)
            deep_eq(ns.inputs, ["in.o"], _assert=True)
            interp = LDArgumentInterpreter(ns)
            deep_eq(interp.all_cc_outputs(), ["a.exe"], _assert=True)
            deep_eq(interp.all_cc_inputs(), ["in.o"], _assert=True)
            deep_eq(interp.is_ld_kind("program"), True, _assert=True)
            deep_eq(interp.has_final_link(), True, _assert=True)
            deep_eq(interp.has_reloc_link(), False, _assert=True)

            with open("%s/libc.so" % tmpdir, 'w') as f:
                print >>f, "// A shared object"
            with open("%s/libd.a" % tmpdir, 'w') as f:
                print >>f, "// A static archive"
            ns = parser.parse_args(shlex.split(
                    ("-o out --build-id -r in.o -L%s -( -la -lb -) " +
                     "-Bdynamic -lc -Bstatic -ld " +
                     "-aarchive -le -ashared -lf -adefault -lg -a unknown") %
                    (tmpdir)),
                                   TestNameSpace())
            deep_eq(ns.unknown_flags, [], _assert=True)
            deep_eq(ns.output_kind, 'relocatable', _assert=True)
            deep_eq(ns.outputs, ["out"], _assert=True)
            deep_eq(ns.inputs, ["in.o",
                                "%s/libc.so" % tmpdir,
                                "%s/libd.a" % tmpdir],
                    _assert=True)
            interp = LDArgumentInterpreter(ns)
            deep_eq(interp.all_cc_outputs(), ["out"], _assert=True)
            deep_eq(interp.all_cc_inputs(), ["in.o",
                                             "%s/libc.so" % tmpdir,
                                             "%s/libd.a" % tmpdir],
                    _assert=True)
            deep_eq(interp.is_ld_kind("relocatable"), True, _assert=True)
            deep_eq(interp.has_final_link(), False, _assert=True)
            deep_eq(interp.has_reloc_link(), True, _assert=True)

            ns = parser.parse_args(shlex.split(
                    "-o out in.o --notanoption"), TestNameSpace())
            interp = LDArgumentInterpreter(ns)
            deep_eq(ns.unknown_flags, ["--notanoption"], _assert=True)
        finally:
            shutil.rmtree(tmpdir)
        print "SUCCESS LDArgumentsParser"
        return True

if __name__ == "__main__":
    passed = LDArgumentParser.test()
    if not passed: sys.exit(1)
