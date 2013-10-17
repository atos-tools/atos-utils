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
import cc_arguments
from deep_eq import deep_eq
import os
import tempfile
import shutil

class CCArgumentError(Exception):
    """ User exception for invalid CC argument. """
    pass

class CCArgumentInterpreter:

    def __init__(self, namespace, desc=cc_arguments.CCArgumentsDesc):
        self.prepare_cc_phases_(namespace, desc)

    def prepare_cc_phases_(self, namespace, desc):
        def replace_suffix(filename, suffix):
            prefix = re.sub("\.[^.]*$", "", filename)
            return "%s%s" % (prefix, suffix)

        def cc_phase_parent(phase):  # pragma: uncovered
            return desc.cc_phase_dependencies(phase)

        def cc_phase_has_parent(phase, parent):  # pragma: uncovered
            current = cc_phase_parent(phase)
            while current:
                if current == parent:
                    return True
            return False

        self.cc_inputs_ = []
        self.cc_outputs_ = []
        self.cc_phase_inputs_ = {}
        self.cc_phases_ = []
        self.last_cc_phase_ = None
        self.ld_kind_ = None

        phases = set()
        cc_phase_inputs = {}
        cc_inputs = []
        cmd_inputs = []
        cc_outputs = []
        first_cc_phase_ = None
        last_cc_phase = desc.output_phase.get(namespace.output_kind, None)
        if last_cc_phase == None:
            return
        for src_kind, fname in namespace.input_pairs:
            inputs_phases = desc.cc_source_phases.get(src_kind, [])
            if last_cc_phase in inputs_phases:
                if not inputs_phases[0] in cc_phase_inputs:
                    cc_phase_inputs[inputs_phases[0]] = []
                cc_phase_inputs[inputs_phases[0]].append((src_kind, fname))
                if inputs_phases[0] == 'CMD':
                    cmd_inputs.append((src_kind, fname))
                else:
                    cc_inputs.append((src_kind, fname))
                last_idx = inputs_phases.index(last_cc_phase)
                phases = phases.union(set(inputs_phases[:last_idx + 1]))
        if len(cc_inputs) == 0:
            raise CCArgumentError("no input")
        assert(len(namespace.outputs) <= 1)
        if last_cc_phase == "LD":
            if not namespace.outputs:
                cc_outputs = ["a.out"]
            else:
                cc_outputs = namespace.outputs
        elif len(cc_inputs) == 1 and len(namespace.outputs) == 1:
            cc_outputs = namespace.outputs
        else:
            # Maybe multiple outputs
            if len(namespace.outputs) == 1 and len(cc_inputs) > 1:
                raise CCArgumentError("multiple input with single output")
            if last_cc_phase == "AS" or last_cc_phase == "CC":
                suffix = ".s" if last_cc_phase == "CC" else ".o"
                cc_outputs = map(
                    lambda x: replace_suffix(os.path.basename(x[1]), suffix),
                    cc_inputs)
            elif last_cc_phase == "CPP":  # pragma: branch_always
                # Outputs to stdout
                cc_outputs = []

        self.cc_inputs_ = cmd_inputs + cc_inputs
        self.cc_outputs_ = cc_outputs
        self.cc_phase_inputs_ = cc_phase_inputs
        self.cc_phases_ = sorted(list(phases))
        self.last_cc_phase_ = last_cc_phase
        if "LD" in self.cc_phases_:
            assert(namespace.output_kind in
                   ["executable", "relocatable"])
            assert(namespace.exec_kind in
                   ["program", "shared"])
            self.ld_kind_ = namespace.output_kind
            if self.ld_kind_ == "executable":
                self.ld_kind_ = namespace.exec_kind

    def cc_phases_inputs(self, phases):
        """
        Returns the inputs for the given C/C++ phases that are
        explicit in the command line.
        I.e. if all phases are intermediate phases for some
        file, the file will not be reported.
        """
        return map(lambda y: y[1], self.cc_phases_input_pairs(phases))

    def cc_phases_input_pairs(self, phases):
        """
        Returns the input pairs (src_kind, fname)
        for the given C/C++ phases that are explicit in the command line.
        I.e. if all phases are intermediate phases for some
        file, the file will not be reported.
        """
        return sum(map(lambda x: self.cc_phase_inputs_.get(x, []),
                       phases), [])

    def cc_phase_inputs(self, phase):
        """
        Returns the inputs for the given C/C++ phase that are
        explicit in the command line.
        I.e. if the phase is an intermediate phase for some
        file, the file will not be reported.
        """
        return self.cc_phases_inputs([phase])

    def cc_phase_input_pairs(self, phase):
        """
        Returns the inputs pairs (src_kind, fname)
        for the given C/C++ phase that are explicit in the command line.
        I.e. if the phase is an intermediate phase for some
        file, the file will not be reported.
        """
        return self.cc_phases_input_pairs([phase])

    def all_cc_inputs(self):
        """
        Returns all the inputs files for the C/C++ phases implied by
        the driver command line.
        This is equivalent to cc_phase_inputs() for each
        cc_phase implied by the command.
        """
        return map(lambda x: x[1], self.all_cc_input_pairs())

    def all_cc_input_pairs(self):
        """
        Returns all the input pairs (src_knd, fname)
        for the C/C++ phases implied by the driver command line.
        This is equivalent to cc_phase_input_pairs() for each
        cc_phase implied by the command.
        """
        return self.cc_inputs_

    def all_pch_inputs(self):
        """
        Returns all the PCH inputs that need to be present.
        This is a specific case, in the case where the
        corresponding header is not present, it should be
        created such that the compiler falls back to it when
        the precompiled header is not compatible.
        """
        return map(lambda y: y[1],
                   filter(lambda x: x[0] == 'SRC_PCH',
                          self.cc_inputs_))

    def all_cc_outputs(self):
        """
        Return all the output files of the last C/C++ phase.
        """
        return self.cc_outputs_

    def has_cc_phase(self, phase):
        """
        Returns whether the command will run the given C/C++ phase.
        """
        return phase in self.cc_phases_

    def last_cc_phase(self):
        """
        Returns the last executed phase as inferred by the output
        kind.
        Returns None if no C/C++ phase is run.
        """
        return self.last_cc_phase_

    def is_ld_kind(self, kind):
        """
        Returns True if the LD output if of the given kind.
        One of "program", "relocatable", "shared".
        Returns False otherwise or if LD is not run.
        """
        assert(kind in ["program", "relocatable", "shared"])
        return self.ld_kind_ == kind

    def has_final_link(self):
        """
        Returns true is the compiler is doing a final link phase,
        i.e. running LD and generating shared object or program file.
        """
        return self.has_cc_phase("LD") and (self.is_ld_kind("program") or
                                            self.is_ld_kind("shared"))

    def has_reloc_link(self):
        """
        Returns true is the compiler is doing a relocatable link phase,
        i.e. running LD and generating a relocatable object.
        """
        return self.has_cc_phase("LD") and self.is_ld_kind("relocatable")

class CCArgumentProcessor:
    def __init__(self, namespace, cwd=".", desc=cc_arguments.CCArgumentsDesc):
        self.ns_ = namespace
        self.desc_ = desc
        self.ns_.preprocessor_flags = []
        self.ns_.assembler_flags = []
        self.ns_.linker_flags = []
        self.ns_.unknown_flags = []
        self.ns_.outputs = []
        self.ns_.input_pairs = []
        self.ns_.output_kind = 'executable'
        self.ns_.exec_kind = 'program'
        self.ns_.static_libs = False
        self.ns_.cwd = cwd
        self.ns_.lpath = []
        self.ns_.current_src_kind = None
        self.prepare_source_kind_regexp_()

    def prepare_source_kind_regexp_(self):
        regexp = "^(%s)$" % (
            "|".join(map(
                    lambda x: "(?P<%s>%s)" % (x[0],
                                              x[1]['re']),
                    self.desc_.source_kind.items())))
        self.source_kind_regexp_ = re.compile(regexp)

    def get_source_kind_(self, arg):
        match = self.source_kind_regexp_.match(arg)
        if match == None: return None
        groups = match.groupdict()
        matched_groups = filter(lambda x: x[1] != None,
                                groups.items())
        assert(len(matched_groups) == 1)
        return matched_groups[0][0]

    def append_input_(self, src_kind, arg):
        self.ns_.input_pairs.append((src_kind, arg))

    def opt_o(self, args):
        self.ns_.outputs = [args[1]]

    def opt_x(self, args):
        # If "none" or another unknown language, fall back to default
        self.ns_.current_src_kind = self.desc_.language_kind.get(args[1], None)

    def opt_preprocessor(self, args):
        self.ns_.preprocessor_flags.append(args[1])

    def opt_assembler(self, args):
        self.ns_.assembler_flags.append(args[1])

    def opt_linker(self, args):
        self.ns_.linker_flags.append(args[1])

    def opt_other(self, args):
        self.ns_.unknown_flags.append(args[0])

    def opt_E(self, args):
        self.ns_.output_kind = 'preprocessed'

    def opt_include(self, args):
        # We track explicit inclusion of headers for which
        # a precompiled header exists.
        # The actual header may not exist, and this should
        # be handled by the client.
        header = args[1]
        precompiled_header = "%s.gch" % header
        precompiled_header_path = os.path.normpath(
            os.path.join(self.ns_.cwd, precompiled_header))
        if os.path.exists(precompiled_header_path):
            self.append_input_('SRC_PCH', precompiled_header)

    def opt_M(self, args):
        # Implies -E but generates dependencies
        self.ns_.output_kind = 'dependencies'

    def opt_MM(self, args):
        # Implies -E but generates dependencies
        self.ns_.output_kind = 'dependencies'

    def opt_S(self, args):
        self.ns_.output_kind = 'assembly'

    def opt_c(self, args):
        self.ns_.output_kind = 'object'

    def opt_r(self, args):
        self.ns_.output_kind = 'relocatable'

    def opt_shared(self, args):
        self.ns_.exec_kind = 'shared'

    def opt_static(self, args):
        self.ns_.static_libs = True

    def opt_dump(self, args):
        self.ns_.output_kind = 'nooutput'

    def opt_print(self, args):
        self.ns_.output_kind = 'nooutput'

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
                self.append_input_("SRC_LNK", lib_path)
                break
            lib_path = "%s.a" % lib_base
            if os.access(lib_path, os.R_OK):
                self.append_input_("SRC_LNK", lib_path)
                break

    def REMAINDER(self, args):
        infile = args[1]
        kind = self.ns_.current_src_kind
        if kind == None: kind = self.get_source_kind_(infile)
        if kind == None: kind = 'SRC_LNK'
        self.append_input_(kind, infile)

    def POSTPROCESS(self):
        return

class CCArgumentParser:
    def __init__(self, prog, cwd=".", desc=cc_arguments.CCArgumentsDesc):
        self.desc_ = desc
        self.cwd_ = cwd
        self.parser_ = gen_argparse.GenArgumentParser(prog)
        for desc in desc.options_desc:
            self.parser_.add_argument(**desc)

    def parse_args(self, args, namespace):
        ns, args = self.parser_.parse_args(
            args, CCArgumentProcessor(namespace, cwd=self.cwd_,
                                      desc=self.desc_))
        return ns.ns_

    @staticmethod
    def test():
        class TestNameSpace():
            pass
        print "TESTING CCArgumentsParser..."
        parser = CCArgumentParser("gcc")
        ns = parser.parse_args(shlex.split(
                "-E in.c"), TestNameSpace())
        interp = CCArgumentInterpreter(ns)

        parser = CCArgumentParser("gcc")
        ns = parser.parse_args(shlex.split(
                "-o out.o -c in.c --help -I/path -pthread"),
                               TestNameSpace())
        deep_eq(ns.unknown_flags, [], _assert=True)
        deep_eq(ns.output_kind, 'nooutput', _assert=True)
        deep_eq(ns.outputs, ["out.o"], _assert=True)
        deep_eq(ns.input_pairs, [('SRC_C', "in.c")], _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.last_cc_phase(), None, _assert=True)
        deep_eq(interp.has_cc_phase('CC'), False, _assert=True)
        deep_eq(interp.cc_phase_inputs('CC'), [], _assert=True)
        deep_eq(interp.all_cc_inputs(), [], _assert=True)
        deep_eq(interp.all_cc_outputs(), [], _assert=True)
        deep_eq(interp.is_ld_kind("program"), False, _assert=True)
        deep_eq(interp.has_final_link(), False, _assert=True)
        deep_eq(interp.has_reloc_link(), False, _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out.o -c in.c -print-search-dirs"),
                               TestNameSpace())
        deep_eq(ns.output_kind, 'nooutput', _assert=True)
        deep_eq(ns.outputs, ["out.o"], _assert=True)
        deep_eq(ns.input_pairs, [('SRC_C', "in.c")], _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.all_cc_outputs(), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out.o -c in.c -dumpversion"),
                               TestNameSpace())
        deep_eq(ns.output_kind, 'nooutput', _assert=True)
        deep_eq(ns.outputs, ["out.o"], _assert=True)
        deep_eq(ns.input_pairs, [('SRC_C', "in.c")], _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.all_cc_outputs(), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out.o -c in.c --version"),
                               TestNameSpace())
        deep_eq(ns.output_kind, 'nooutput', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.all_cc_outputs(), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -E in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'preprocessed', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.last_cc_phase(), "CPP", _assert=True)
        deep_eq(interp.all_cc_outputs(), ["out"], _assert=True)
        deep_eq(interp.all_cc_inputs(), ["in.c"], _assert=True)
        deep_eq(interp.has_cc_phase("CPP"), True, _assert=True)
        deep_eq(interp.has_cc_phase("CC"), False, _assert=True)
        deep_eq(interp.has_cc_phase("LD"), False, _assert=True)
        deep_eq(interp.cc_phase_inputs("CPP"), ["in.c"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CC"), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -M in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'dependencies', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.last_cc_phase(), None, _assert=True)
        deep_eq(interp.all_cc_inputs(), [], _assert=True)
        deep_eq(interp.all_cc_outputs(), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -MM in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'dependencies', _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -c in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'object', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.last_cc_phase(), "AS", _assert=True)
        deep_eq(interp.all_cc_inputs(), ["in.c"], _assert=True)
        deep_eq(interp.all_cc_outputs(), ["out"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CPP"), ["in.c"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CC"), [], _assert=True)
        deep_eq(interp.cc_phase_inputs("AS"), [], _assert=True)
        deep_eq(interp.cc_phase_inputs("LD"), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-S in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'assembly', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.last_cc_phase(), "CC", _assert=True)
        deep_eq(interp.all_cc_inputs(), ["in.c"], _assert=True)
        deep_eq(interp.all_cc_outputs(), ["in.s"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CPP"), ["in.c"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CC"), [], _assert=True)
        deep_eq(interp.cc_phase_inputs("AS"), [], _assert=True)
        deep_eq(interp.cc_phase_inputs("LD"), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-S in1.c in2.c in3.i in4.ii in5.s in6.o in7.S"),
                               TestNameSpace())
        deep_eq(ns.output_kind, 'assembly', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.has_cc_phase("CC"), True, _assert=True)
        deep_eq(interp.has_cc_phase("CPP"), True, _assert=True)
        deep_eq(interp.last_cc_phase(), "CC", _assert=True)
        deep_eq(interp.all_cc_outputs(),
                ["in1.s", "in2.s", "in3.s", "in4.s"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CPP"),
                ["in1.c", "in2.c"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CC"),
                ["in3.i", "in4.ii"], _assert=True)
        deep_eq(interp.cc_phase_inputs("AS"), [], _assert=True)
        deep_eq(interp.cc_phase_inputs("LD"), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-c /a/in1.c ./in2.c in3.i in4.ii in5.s in6.o in7.S"),
                               TestNameSpace())
        deep_eq(ns.output_kind, 'object', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.has_cc_phase("AS"), True, _assert=True)
        deep_eq(interp.has_cc_phase("CC"), True, _assert=True)
        deep_eq(interp.has_cc_phase("CPP"), True, _assert=True)
        deep_eq(interp.last_cc_phase(), "AS", _assert=True)
        deep_eq(interp.all_cc_outputs(),
                ["in1.o", "in2.o", "in3.o", "in4.o", "in5.o", "in7.o"],
                _assert=True)
        deep_eq(interp.cc_phase_inputs("CPP"),
                ["/a/in1.c", "./in2.c", "in7.S"], _assert=True)
        deep_eq(interp.cc_phase_inputs("CC"),
                ["in3.i", "in4.ii"], _assert=True)
        deep_eq(interp.cc_phase_inputs("AS"),
                ["in5.s"], _assert=True)
        deep_eq(interp.cc_phase_inputs("LD"), [], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o all.exe in1.c in2.c in3.i in4.ii in5.s in6.o in7.S"),
                               TestNameSpace())
        deep_eq(ns.output_kind, "executable", _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.is_ld_kind("program"), True, _assert=True)
        deep_eq(interp.has_final_link(), True, _assert=True)
        deep_eq(interp.has_reloc_link(), False, _assert=True)
        deep_eq(interp.has_cc_phase("AS"), True, _assert=True)
        deep_eq(interp.has_cc_phase("CC"), True, _assert=True)
        deep_eq(interp.has_cc_phase("CPP"), True, _assert=True)
        deep_eq(interp.has_cc_phase("LD"), True, _assert=True)
        deep_eq(interp.last_cc_phase(), "LD", _assert=True)
        deep_eq(interp.all_cc_outputs(), ["all.exe"], _assert=True)
        deep_eq(interp.cc_phase_input_pairs("CPP"),
                [('SRC_C', "in1.c"), ('SRC_C', "in2.c"),
                 ('SRC_SPP', "in7.S")], _assert=True)
        deep_eq(interp.cc_phase_inputs("CPP"),
                ["in1.c", "in2.c", "in7.S"], _assert=True)
        deep_eq(interp.cc_phase_input_pairs("CC"),
                [('SRC_I', "in3.i"), ('SRC_II', "in4.ii")], _assert=True)
        deep_eq(interp.cc_phase_inputs("CC"),
                ["in3.i", "in4.ii"], _assert=True)
        deep_eq(interp.cc_phase_input_pairs("AS"),
                [('SRC_S', "in5.s")], _assert=True)
        deep_eq(interp.cc_phase_inputs("AS"),
                ["in5.s"], _assert=True)
        deep_eq(interp.cc_phase_input_pairs("LD"),
                [('SRC_LNK', "in6.o")], _assert=True)
        deep_eq(interp.cc_phase_inputs("LD"), ["in6.o"], _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -r in.o"), TestNameSpace())
        deep_eq(ns.output_kind, 'relocatable', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.is_ld_kind("relocatable"), True, _assert=True)
        deep_eq(interp.has_final_link(), False, _assert=True)
        deep_eq(interp.has_reloc_link(), True, _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'executable', _assert=True)
        deep_eq(ns.exec_kind, 'program', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.is_ld_kind("program"), True, _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -static in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'executable', _assert=True)
        deep_eq(ns.exec_kind, 'program', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.is_ld_kind("program"), True, _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out -shared -static in.c"), TestNameSpace())
        deep_eq(ns.output_kind, 'executable', _assert=True)
        deep_eq(ns.exec_kind, 'shared', _assert=True)
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.is_ld_kind("shared"), True, _assert=True)
        deep_eq(interp.has_final_link(), True, _assert=True)
        deep_eq(interp.has_reloc_link(), False, _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out.o -c -finline -Wall "
                "file1.c file2.cpp file3.cpp file4.s "
                "-Wother -mtune=i586 "
                "-Xpreprocessor pfile -Wp,-optp "
                "-Xassembler afile -Wa,-opta "
                "-Xlinker -optl -Wl,lfile "
                "-shared -not-an-option"),
                               TestNameSpace())
        deep_eq(ns.outputs, ["out.o"], _assert=True)
        deep_eq(ns.input_pairs,
                [('SRC_C', "file1.c"), ('SRC_CC', "file2.cpp"),
                 ('SRC_CC', "file3.cpp"), ('SRC_S', "file4.s")],
                _assert=True)
        deep_eq(ns.preprocessor_flags,
                ["pfile", "-optp"], _assert=True)
        deep_eq(ns.assembler_flags,
                ["afile", "-opta"], _assert=True)
        deep_eq(ns.linker_flags,
                ["-optl", "lfile"], _assert=True)
        deep_eq(ns.output_kind, 'object', _assert=True)
        deep_eq(ns.exec_kind, 'shared', _assert=True)
        deep_eq(ns.unknown_flags, ['-not-an-option'], _assert=True)
        deep_eq(ns.input_pairs,
                       [('SRC_C', "file1.c"),
                        ('SRC_CC', "file2.cpp"),
                        ('SRC_CC', "file3.cpp"),
                        ('SRC_S', "file4.s"),
                        ], _assert=True)

        tmpdir = tempfile.mkdtemp()
        f = open("%s/liba.a" % tmpdir, 'w')
        print >>f, "// An archive"
        f.close()
        f = open("%s/liba.so" % tmpdir, 'w')
        print >>f, "// A shared object"
        f.close()
        f = open("%s/libb.a" % tmpdir, 'w')
        print >>f, "// An archive"
        f.close()
        f = open("%s/libc.so" % tmpdir, 'w')
        print >>f, "// A shared object"
        f.close()
        f = open("%s/libd.so" % tmpdir, 'w')
        print >>f, "// An unreadable shared object"
        f.close()
        os.chmod("%s/libd.so" % tmpdir, 0000)
        f = open("%s/libe.a" % tmpdir, 'w')
        print >>f, "// An unreadable archive"
        f.close()
        os.chmod("%s/libe.a" % tmpdir, 0000)
        f = open("%s/include.gch" % tmpdir, 'w')
        print >>f, "// An unreadable pre-compiled header"
        f.close()

        ns = parser.parse_args(shlex.split(
                "-o out.so -shared -L. -Lundef -L%s "
                "file1.c file2.cpp file3.o "
                "-x c a_c_file b_c_file -x none "
                ".libs/lib1.so l2.a "
                "-x cpp-output i_file -x c++cpp-output ii_file "
                "-include %s/include "
                "-lundef -la -lb -lc -ld -le"
                "-shared" %
                (tmpdir, tmpdir)),
                               TestNameSpace())
        interp = CCArgumentInterpreter(ns)
        deep_eq(interp.is_ld_kind("shared"), True, _assert=True)
        deep_eq(interp.all_cc_inputs(),
                ["%s/include.gch" % tmpdir,
                 "file1.c", "file2.cpp", "file3.o", "a_c_file",
                 "b_c_file", ".libs/lib1.so", "l2.a",
                 "i_file", "ii_file"] +
                map(lambda x: os.path.join(tmpdir, x),
                    ["liba.so", "libb.a", "libc.so"]),
                _assert=True)
        deep_eq(interp.cc_phase_input_pairs("CMD"),
                [('SRC_PCH', "%s/include.gch" % tmpdir)],
                _assert=True)
        deep_eq(interp.all_pch_inputs(),
                ["%s/include.gch" % tmpdir], _assert=True)
        deep_eq(interp.cc_phase_input_pairs("CPP"),
                [('SRC_C', "file1.c"), ('SRC_CC', "file2.cpp"),
                 ('SRC_C', "a_c_file"), ('SRC_C', "b_c_file")],
                _assert=True)
        deep_eq(interp.cc_phase_input_pairs("CC"),
                [('SRC_I', "i_file"), ('SRC_II', "ii_file")],
                _assert=True)
        deep_eq(interp.cc_phase_input_pairs("LD"),
                [('SRC_LNK', "file3.o"), ('SRC_LNK', ".libs/lib1.so"),
                 ('SRC_LNK', "l2.a")] +
                map(lambda x: ('SRC_LNK', os.path.join(tmpdir, x)),
                    ["liba.so", "libb.a", "libc.so"]),
                _assert=True)

        ns = parser.parse_args(shlex.split(
                "-o out.o -c in.c "
                "-include %s/include-unk" % (tmpdir)),
                               TestNameSpace())
        interp = CCArgumentInterpreter(ns)

        shutil.rmtree(tmpdir)
        print "SUCCESS CCArgumentsParser"
        return True

if __name__ == "__main__":
    passed = CCArgumentParser.test()
    if not passed: sys.exit(1)
