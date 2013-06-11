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

import sys, os, re

import globals
import atos_lib
import process
from deep_eq import deep_eq
import shlex
import gen_argparse
import cc_argparse

class CmdInterpreterFactory:
    """
    Returns a suitable interpreter for the given command.
    """
    def __init__(self, configuration_path=None):
        """ Constructor. """
        self.configuration_path_ = configuration_path

    def get_interpreter(self, command, kind=None):
        """
        Returns a suitable interpreter for the given command.
        If kind is specified, calls directly the corresponding
        interpreter constructor.
        Otherwise the command kind is infered from the command
        arguments.
        """
        if kind == None:
            return self.get_interpreter(command,
                                        self.get_command_kind(command))
        if kind == "CC":
            return CCInterpreter(command)
        elif kind == "AR":
            return ARInterpreter(command)
        return None

    def get_command_kind(self, command):
        """
        Infer the command kind from the command arguments.
        Note that if a configuration_path was given to the
        factory constructor, the command regexps are read from there.
        The currently recognized commands are:
        "CC": a C/C++ driver
        "AR": an archiver
        If no command is recognized, "UNK" is returned.
        """
        basename = os.path.basename(command['args'][0])
        if self.configuration_path_:
            ccregexp = (atos_lib.get_config_value(self.configuration_path_,
                                                  'default_values.ccregexp') or
                        globals.DEFAULT_CCREGEXP)
            ldregexp = (atos_lib.get_config_value(self.configuration_path_,
                                                  'default_values.ldregexp') or
                        globals.DEFAULT_LDREGEXP)
            arregexp = (atos_lib.get_config_value(self.configuration_path_,
                                                  'default_values.arregexp') or
                        globals.DEFAULT_ARREGEXP)
        else:
            ccregexp = globals.DEFAULT_CCREGEXP
            ldregexp = globals.DEFAULT_LDREGEXP
            arregexp = globals.DEFAULT_ARREGEXP

        regexps = []
        regexps.append(("CC",
                        re.compile("|".join(
                        map(lambda x: "(%s)" % x,
                            filter(bool, [ccregexp, ldregexp]))))))
        regexps.append(("AR", re.compile(arregexp)))
        for kind, regexp in regexps:
            if regexp.match(basename):
                return kind
        return "UNK"

    @staticmethod
    def test():
        def test_eq(x, y):
            res = deep_eq(x, y)
            if not res:  # pragma: uncovered (error)
                print "FAILURE: %s and %s differ" % (str(x), str(y))
            return res

        tests = [
            {'command': {'args': ["cc", "-c", "a.c", "b.c"],
                         'cwd': "."},
             'expected_kind': "CC",
             'expected_inputs': ["a.c", "b.c"],
             'expected_outputs': ["a.o", "b.o"]
             },
            {'command': {'args': ["cc", "-r", "a.o", "b.o"],
                         'cwd': "."},
             'expected_kind': "CC",
             'expected_inputs': ["a.o", "b.o"],
              'expected_outputs': ["a.out"]
             },
            {'command': {'args': ["ar", "cru", "liba.a", "a.o", "b.o"],
                         'cwd': "."},
             'expected_kind': "AR",
             'expected_inputs': ["a.o", "b.o"],
             'expected_outputs': ["liba.a"]
             },
            {'command': {'args': ["cc", "-o", "main.exe", "a.o", "b.o"],
                         'cwd': "."},
             'expected_kind': "CC",
             'expected_inputs': ["a.o", "b.o"],
             'expected_outputs': ["main.exe"]
             },
            {'command':
                 {'args':
                      ["cc", "a.o", "b.o", "c.c", "d.ro", "e.os", "f.a"],
                  'cwd': "."},
             'expected_kind': "CC",
             'expected_inputs':
                 ["a.o", "b.o", "c.c", "d.ro", "e.os", "f.a"],
             'expected_outputs': ["a.out"]
             },
            {'command':
                 {'args': ["proot"], 'cwd': "."},
             'expected_kind': "UNK",
             'expected_inputs': [],
             'expected_outputs': []
             },

            ]
        passed = True
        for t in tests:
            cmd = t['command']
            print "TEST: %s" % process.list2cmdline(cmd['args'])
            interpreter = CmdInterpreterFactory().get_interpreter(cmd)
            if not interpreter:
                if test_eq("UNK", t['expected_kind']):
                    print "SUCCESS: %s" % process.list2cmdline(cmd['args'])
                else:  # pragma: uncovered (error)
                    print "FAILURE: %s" % process.list2cmdline(cmd['args'])
                    passed = False
            else:
                kind = interpreter.get_kind()
                outputs = interpreter.get_output_files()
                inputs = interpreter.get_input_files()
                if (test_eq(kind, t['expected_kind']) and
                    test_eq(outputs, t['expected_outputs']) and
                    test_eq(inputs, t['expected_inputs'])):
                    print "SUCCESS: %s" % process.list2cmdline(cmd['args'])
                else:  # pragma: uncovered
                    print "FAILURE: %s" % process.list2cmdline(cmd['args'])
                    passed = False
        return passed

class CCInterpreter:
    """
    Returns information on a command line for a CC compiler driver.
    The information is used by the atos-driver or the dependency builder.
    """
    class NameSpace():
        """ Simple container for argument values. """
        pass

    def __init__(self, command):
        """ Constructor. """
        self.command_ = command
        self.expanded_args_ = self.get_expanded_args_()
        self.interp_ = self.parse_args_()
        self.input_pairs_ = None
        self.output_files_ = None

    def get_expanded_args_(self):
        return ([self.command_['args'][0]] +
                atos_lib.expand_response_file(
                self.command_['args'][1:], self.command_['cwd']))

    def parse_args_(self):
        cwd = self.command_['cwd']
        arg0 = self.expanded_args_[0]
        args = self.expanded_args_[1:]
        parser = cc_argparse.CCArgumentParser(arg0, cwd)
        try:
            ns = parser.parse_args(args, self.NameSpace())
            interp = cc_argparse.CCArgumentInterpreter(ns)
        except (cc_argparse.CCArgumentError,
                gen_argparse.MalformedArgument):
            # If an error occurs in arguments parsing
            # we consider the command failing and ignore it.
            return None
        return interp

    def cc_interpreter(self):
        """
        Returns the CCArgumentInterpreter object,
        or None if command is invalid.
        """
        return self.interp_

    def is_wellformed(self):
        """
        Returns true if the command is wellformed.
        Otherwise the command is expected to fail.
        """
        return self.interp_ != None

    def get_args(self):
        """
        Returns the full args list after response file expansion.
        """
        return self.expanded_args_

    def get_kind(self):
        """
        Returns the command kind, actually a CC driver.
        """
        return "CC"

    def get_input_files(self):
        """
        Get input files to be processed as dependencies
        from a CC command line args (all C/C++ driver input files).
        It is invalid to call this function if interpreter() is
        None.
        """
        assert(self.interp_ != None)
        return map(lambda x: x[1], self.get_input_pairs())

    def get_input_pairs(self):
        """
        Get input files pairs (src_kind, fname) to be processed as
        dependencies from a CC command line args (C/C++ driver input files).
        It is invalid to call this function if interpreter() is None.
        """
        assert(self.interp_ != None)
        if self.input_pairs_ == None:
            cwd = self.command_['cwd']
            self.input_pairs_ = map(
                lambda x: (x[0], os.path.normpath(os.path.join(cwd, x[1]))),
                self.interp_.all_cc_input_pairs())
        return self.input_pairs_

    def get_output_files(self):
        """
        Get output files to be processed as some dependency targets
        for a CC command (C/C++ driver output files).
        It is invalid to call this function if interpreter() is
        None.
        """
        assert(self.interp_ != None)
        if self.output_files_ == None:
            cwd = self.command_['cwd']
            self.output_files_ = map(
                lambda x: os.path.normpath(os.path.join(cwd, x)),
                self.interp_.all_cc_outputs())
        return self.output_files_

    @staticmethod
    def test():
        print "TESTING: CCInterpreter..."
        cc = CCInterpreter(
            {'args': shlex.split("cc a.o b.o c.c d.ro e.os f.a"),
             'cwd': "."})
        assert(cc.cc_interpreter() != None)
        deep_eq(cc.get_kind(), "CC", _assert=True)
        deep_eq(cc.get_output_files(), ["a.out"], _assert=True)
        deep_eq(cc.get_input_pairs(),
                [('SRC_LNK', "a.o"), ('SRC_LNK', "b.o"),
                 ('SRC_C', "c.c"), ('SRC_LNK', "d.ro"),
                 ('SRC_LNK', "e.os"), ('SRC_LNK', "f.a")], _assert=True)
        deep_eq(cc.get_input_files(),
                ["a.o", "b.o", "c.c", "d.ro", "e.os", "f.a"], _assert=True)
        print "SUCCESS: CCInterpreter"
        return True

class ARInterpreter:
    """ Returns information on a command line for a AR archiver.
    There are a number of limitations:
    - no check is done on actual input kind, all are 'SRC_AR' source kind,
    - only 'ar ...r... input_files...' form is recognized.
    """
    def __init__(self, command):
        """ Constructor. """
        self.command_ = command
        self.expanded_args_ = self.get_expanded_args_()
        self.input_pairs_ = None
        self.output_files_ = None

    def get_expanded_args_(self):
        return ([self.command_['args'][0]] +
                atos_lib.expand_response_file(
                self.command_['args'][1:], self.command_['cwd']))

    def is_wellformed(self):
        """
        Returns true if the command is wellformed.
        Otherwise the command is expected to fail.
        """
        return len(self.get_args()) > 3

    def get_args(self):
        """
        Returns the full args list after response file expansion.
        """
        return self.expanded_args_

    def get_kind(self):
        """
        Returns the command kind.
        """
        return "AR"

    def get_input_files(self):
        """ Get input files from AR command line. """
        return map(lambda x: x[1], self.get_input_pairs())

    def get_input_pairs(self):
        """ Get input pairs (src_kind, abs_fname) from AR command line. """
        if self.input_pairs_ != None:
            return self.input_pairs_
        args = self.get_args()
        cwd = self.command_['cwd']
        inputs = map(lambda x: ('SRC_AR',
                                os.path.normpath(os.path.join(cwd, x))),
                     args[3:])
        self.input_pairs_ = inputs
        return inputs

    def get_output_files(self):
        """ Get output file from AR command line args. """
        if self.output_files_ != None:
            return self.output_files_
        args = self.get_args()
        cwd = self.command_['cwd']
        outputs = []
        update = False
        for i in range(len(args[1:])):
            if i == 0:
                m = re.search("r", args[i + 1])
                if m != None:
                    update = True
            elif i == 1 and update:
                outputs = [os.path.normpath(os.path.join(cwd, args[i + 1]))]
            else:
                break
        self.output_files_ = outputs
        return outputs

    @staticmethod
    def test():
        print "TESTING: ARInterpreter..."
        cc = ARInterpreter(
            {'args': shlex.split("ar cru lib.a a.o b.o c.c"),
             'cwd': "."})
        deep_eq(cc.get_kind(), "AR", _assert=True)
        deep_eq(cc.get_output_files(), ["lib.a"], _assert=True)
        deep_eq(cc.get_output_files(), ["lib.a"], _assert=True)
        deep_eq(cc.get_input_pairs(),
                [('SRC_AR', "a.o"), ('SRC_AR', "b.o"),
                 ('SRC_AR', "c.c")], _assert=True)
        deep_eq(cc.get_input_files(),
                ["a.o", "b.o", "c.c"], _assert=True)
        cc = ARInterpreter(
            {'args': shlex.split("ar -v"),
             'cwd': "."})
        deep_eq(cc.get_output_files(), [], _assert=True)
        print "SUCCESS: ARInterpreter"

        return True

if __name__ == "__main__":
    passed = CCInterpreter.test()
    if not passed: sys.exit(1)
    passed = ARInterpreter.test()
    if not passed: sys.exit(1)
    passed = CmdInterpreterFactory.test()
    if not passed: sys.exit(1)
