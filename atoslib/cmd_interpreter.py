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
import deep_eq

class SimpleCmdInterpreter:
    """ Returns information on a command line for compilations tools. """
    def __init__(self, configuration_path=None):
        """ Constructor. """
        self.configuration_path_ = configuration_path

    def select_interpreter(self, command):
        """ Returns a suitable interpreter for the given command. """
        basename = os.path.basename(command['args'][0])
        if self.configuration_path_:
            ccregexp = atos_lib.get_config_value(self.configuration_path_,
                                                 'default_values.ccregexp')
            ldregexp = atos_lib.get_config_value(self.configuration_path_,
                                                 'default_values.ldregexp')
            arregexp = atos_lib.get_config_value(self.configuration_path_,
                                                 'default_values.arregexp')
        else:
            ccregexp = globals.DEFAULT_CCREGEXP
            ldregexp = globals.DEFAULT_LDREGEXP
            arregexp = globals.DEFAULT_ARREGEXP

        m = re.match("|".join(
                map(lambda x: "(%s)" % x,
                    filter(bool, [ccregexp, ldregexp]))),
                     basename)
        if m != None:
            return SimpleCCInterpreter(command)
        m = re.match(arregexp, basename)
        if m != None:
            return SimpleARInterpreter(command)
        raise Exception("unrecognized command: " + basename)

    def get_kind(self, command):
        """ Get command kind from command line args. """
        return self.select_interpreter(command).get_kind()

    def get_input_files(self, command):
        """ Get input files from command line args. """
        return self.select_interpreter(command).get_input_files()

    def get_output_files(self, command):
        """ Get output files from command line args. """
        return self.select_interpreter(command).get_output_files()

    @staticmethod
    def test():
        def test_eq(x, y):
            res = deep_eq.deep_eq(x, y)
            if not res:
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
             'expected_kind': "CCLDR",
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
             'expected_kind': "CCLD",
             'expected_inputs': ["a.o", "b.o"],
             'expected_outputs': ["main.exe"]
             },
            {'command':
                 {'args':
                      ["cc", "a.o", "b.o", "c.c", "d.ro", "e.os", "f.a"],
                  'cwd': "."},
             'expected_kind': "CCLD",
             'expected_inputs':
                 ["a.o", "b.o", "c.c", "d.ro", "e.os", "f.a"],
             'expected_outputs': ["a.out"]
             },
            ]
        passed = True
        for t in tests:
            cmd = t['command']
            print "TEST: %s" % process.list2cmdline(cmd['args'])
            kind = SimpleCmdInterpreter().get_kind(cmd)
            outputs = SimpleCmdInterpreter().get_output_files(cmd)
            inputs = SimpleCmdInterpreter().get_input_files(cmd)
            if (test_eq(kind, t['expected_kind']) and
                test_eq(outputs, t['expected_outputs']) and
                test_eq(inputs, t['expected_inputs'])):
                print "SUCCESS: %s" % process.list2cmdline(cmd['args'])
            else:
                print "FAILURE: %s" % process.list2cmdline(cmd['args'])
                passed = False
        return passed

class SimpleCCInterpreter:
    """ Returns information on a command line for a CC compiler driver.
    There are a number of limitations:
    - only well known extensions are searched for input files
    - output file is matched only in case of -o option, no stdout support
    """
    def __init__(self, command):
        """ Constructor. """
        self.command = command
        self.kind = None
        self.input_files = None
        self.output_files = None
        self.expanded_args = None

    def get_expanded_args(self):
        """ Returns the exanded args list, after response file expansion. """
        if self.expanded_args == None:
            self.expanded_args = atos_lib.expand_response_file(
                self.command['args'])
        return self.expanded_args

    def get_kind(self):
        """ Returns the command kind. """
        if self.kind != None:
            return self.kind
        args = self.get_expanded_args()
        kind = "CCLD"
        for i in range(len(args[1:])):
            m = re.search("^(-c)$", args[i + 1])
            if m != None:
                kind = "CC"
            m = re.search("^(-r)$", args[i + 1])
            if m != None:
                kind = "CCLDR"
        self.kind = kind
        return kind

    def get_input_files(self):
        """ Get input files from a CC command line args
        (C/C++ sources or object files). """
        if self.input_files != None:
            return self.input_files
        kind = self.get_kind()
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        static_link = True
        if kind == "CCLD": static_link = False
        inputs = []
        lpath = []
        i = 0
        while i + 1 < len(args):
            i = i + 1
            m = re.search("^-o(.*)$", args[i])
            if m != None:
                if m.group(1) == "":
                    i = i + 1
                continue
            m = re.search("\\.(c|cc|cxx|cpp|c\+\+|C|i|ii|o|os|ro|a)$", args[i])
            if m != None:
                inputs.append(os.path.normpath(os.path.join(cwd, args[i])))
                continue
            if kind == "CCLD" and args[i] == "-static":
                static_link = True
                continue
            if kind == "CCLD" and args[i] == "-shared":
                static_link = False
                continue
            m = re.search("^-L(.*)$", args[i])
            if (kind == "CCLD" or kind == "CCLDR") and m != None:
                path = m.group(1)
                if path == "":
                    if i + 1 < len(args):
                        path = args[i + 1]
                if path != "":
                    lpath.append(os.path.normpath(os.path.join(cwd, path)))
                continue
            m = re.search("^-l(.*)$", args[i])
            if (kind == "CCLD" or kind == "CCLDR") and m != None:
                lib = m.group(1)
                if lib == "":
                    if i + 1 < len(args):
                        lib = args[i + 1]
                    i = i + 1
                if lib != "":
                    for path in lpath:
                        # TODO: this way of finding archives is approximate, we
                        # should use an enhanced PRoot plugin for detecting
                        # actual dependencies at build audit time.
                        file_base = os.path.join(path, "lib" + lib)
                        if not static_link and os.access(
                                file_base + ".so", os.R_OK):
                            # Skip shared objects for now
                            break
                        if os.access(file_base + ".a", os.R_OK):
                            inputs.append(file_base + ".a")
                            break
                continue
        self.input_files = inputs
        return inputs

    def get_output_files(self):
        """ Get output files from CC command line args. """
        if self.output_files != None:
            return self.output_files
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        output = atos_lib.get_output_option_value(args)
        outputs = [
            os.path.normpath(os.path.join(cwd, output))] if output else []
        if len(outputs) == 0 and len(self.get_input_files()) > 0:
            if self.get_kind() == "CC":
                outputs = []
                for inp in self.get_input_files():
                    outputs.append(os.path.normpath(os.path.join(cwd, re.sub(
                                    "\\.[^.]+$", ".o",
                                    os.path.basename(inp)))))
            elif self.get_kind() == "CCLD" or self.get_kind() == "CCLDR":
                outputs = [os.path.normpath(os.path.join(cwd, "a.out"))]
            else:
                raise Exception(
                    "Can't determine output from input files in command: " +
                    str(self.command))
        self.output_files = outputs
        return outputs


class SimpleARInterpreter:
    """ Returns information on a command line for a AR archiver.
    There are a number of limitations:
    - only .o files are searched for input
    - only 'ar ...r... input_files...' form is recognized
    """
    def __init__(self, command):
        """ Constructor. """
        self.command = command
        self.input_files = None
        self.output_files = None
        self.expanded_args = None

    def get_expanded_args(self):
        """ Returns the exanded args list, after response file expansion. """
        if self.expanded_args == None:
            self.expanded_args = atos_lib.expand_response_file(
                self.command['args'])
        return self.expanded_args

    def get_kind(self):
        """ Returns the command kind. """
        return "AR"

    def get_input_files(self):
        """ Get input files from AR command line (object files only). """
        if self.input_files != None:
            return self.input_files
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        inputs = []
        for i in range(len(args[1:])):
            m = re.search("\\.(o)$", args[i + 1])
            if m != None and m.group(1) != None and i >= 2:
                    inputs.append(
                        os.path.normpath(os.path.join(cwd, args[i + 1])))
        self.input_files = inputs
        return inputs

    def get_output_files(self):
        """ Get output file from AR command line args. """
        if self.output_files != None:
            return self.output_files
        args = self.get_expanded_args()
        cwd = self.command['cwd']
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
        self.outputs = outputs
        return outputs

if __name__ == "__main__":
    passed = SimpleCmdInterpreter.test()
    if not passed: sys.exit(1)
