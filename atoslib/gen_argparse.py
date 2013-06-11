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
import re
import shlex
from deep_eq import deep_eq
import types

class NameSpace():
    """ Default namespace for options processing. """
    pass

class MalformedArgument(Exception):
    """ User exception for invalid argument. """
    pass

class GenArgumentParser():
    """
    Generic argument parser class.
    A simple implementation of argument parsing,
    customized to be compatible with compiler
    driver options in particular.
    The standard modules optparse, argparse or
    getopt can't used as their behavior is not
    matching for instance the GCC argument parsing
    scheme.
    """
    class Action():
        """
        Simple namespace class for storing
        behavior and options description.
        """
        def __init__(self, **kwargs):
            for key, val in kwargs.items():
                exec 'self.%s = %s' % (key, 'val')

    def __init__(self, prog=None):
        """
        Initialize parser, prog na;e can be passed
        for error messages.
        """
        self.prog_ = prog
        self.argregexps_actions_ = []
        self.argregexps_compiled_ = None

    def add_argument(self, *args, **kwargs):
        """
        Declare a new optional argument, the fixed
        list of option string can be passed in args.
        Otherwise, kwargs can contain:
        - re: a regexp for the option string
        example: re="-m.*"
        for "-m32" or "-mtune"
        - str: a fixed option string (could be also
        passed in args
        example: nargs=1, str="-o"
        for "-ofile" or "-o file"
        - nargs: 0 or 1 option arguments (default: 0)
        example: nargs=1
        - next: if true, option argument is always
        the next arg in list. I.e. never joined with
        option
        example: str="-X" nargs=1, next=True
        for "-X sep" but not "-Xsep" nor "-X=sep"
        - sep: separator, if specified, it is mandatory
        and the option and argument are always joined
        example: str="-mtune", nargs=1, sep="="
        for "-mtune=i586" but not "-mtunei586", nor
        "-mtune i586"
        - optsep: optional separator
        example: str="--param", nargs=1, optsep="="
        for "--param=p" or "--param p", but not
        "--paramp"
        - dest: the option argument or True for non
        argument options will be stored in the
        namespace attribute with this name.
        If the attribute is a function or method, it
        will be called with the matched arguments list.
        """
        opt_str = kwargs.get('str')
        opt_re = kwargs.get('re')
        opt_nargs = kwargs.get('nargs', 0)
        opt_next = kwargs.get('next', False)
        opt_sep = kwargs.get('sep')
        opt_optsep = kwargs.get('optsep')
        opt_dest = kwargs.get('dest')
        fixed, regexps, argregexps = [], [], []
        fixed += args
        argregexp_id = len(self.argregexps_actions_)
        if opt_str: fixed += [opt_str]
        if opt_re: regexps += [opt_re]
        if opt_nargs == 1 and not opt_next:
            # If 'next' is False, the argument may be
            # joined with the option
            sep = opt_sep or opt_optsep
            if sep:
                # If sep, we must pass for instance
                # "arg=.*" when sep is "="
                argregexps += map(
                    lambda x: "(?P<O%d>%s)%s(?P<A%d>.+)" %
                    (argregexp_id + x[0], x[1], sep,
                     argregexp_id + x[0]),
                    enumerate(fixed + regexps))
            else:
                # If not sep is specified, the argument may be
                # joined with the option as in -oArg
                argregexps += map(
                    lambda x: "(?P<O%d>%s)(?P<A%d>.+)" %
                    (argregexp_id + x[0], x[1],
                     argregexp_id + x[0]),
                    enumerate(fixed + regexps))
            if opt_sep:
                # if sep is mandatory, we never have the option
                # alone
                fixed, regexps = [], []
        argregexp_id = len(self.argregexps_actions_) + len(argregexps)
        argregexps += map(
            lambda x: "(?P<O%d>%s)" % (argregexp_id + x[0],
                                       x[1]),
            enumerate(fixed + regexps))
        action = self.Action(str=opt_str, re=opt_re,
                             nargs=opt_nargs, next=opt_next,
                             sep=opt_sep, optsep=opt_optsep,
                             argregexps=argregexps, dest=opt_dest)
        for re in argregexps:
            self.argregexps_actions_.append((re, action))
        return action

    def parse_args(self, args=None, namespace=None):
        """
        Actually parse the given lis of arguments.
        The namespace object will be used to store
        argument values. If not specified a new
        namespace object will be created.
        All non matched arguments will be stored in
        a list attribute namespace.REMAINDER.
        The function returns a tuple with the namespace
        and the preprocessed argument list.
        """
        self.prepare_arguments_()
        if args == None: args = sys.argv[1:]
        if namespace == None: namespace = NameSpace()
        parsed_args = []
        i = 0
        while i < len(args):
            arg = args[i]
            i += 1
            if arg[0] == "-":
                (action, opt_args) = self.get_action_(arg)
                if action != None:
                    if action.nargs == 1 and len(opt_args) == 1:
                        if i >= len(args):
                            raise MalformedArgument(
                                "missing argument to option: %s" % opt_args[0])
                        opt_args += [args[i]]
                        i += 1
                    parsed_args.append(opt_args)
                    self.process_argument_(namespace, action, opt_args)
                else:
                    parsed_args.append([None, arg])
                    self.process_argument_(namespace, None, [None, arg])
            else:
                parsed_args.append([None, arg])
                self.process_argument_(namespace, None, [None, arg])
        if hasattr(namespace, 'POSTPROCESS'):
            namespace.POSTPROCESS()
        return (namespace, parsed_args)

    def process_argument_(self, namespace, action, args):
        assert namespace
        if action == None:
            assert(args[0] == None)
            if not hasattr(namespace, 'REMAINDER'):
                namespace.REMAINDER = []
            dest = 'REMAINDER'
        elif action.dest == None:
            return
        else:
            dest = action.dest
        if not hasattr(namespace, dest):
            setattr(namespace, dest, None)
        dest_type = eval("type(namespace.%s)" % dest)
        if dest_type in [types.ListType]:
            eval("namespace.%s.append(args[1])" % dest)
        elif dest_type in [types.FunctionType, types.MethodType]:
            eval("namespace.%s(args)" % dest)
        elif len(args) == 1:
            setattr(namespace, dest, True)
        elif len(args) > 1:  # pragma: branch_always
            setattr(namespace, dest, args[1])

    def prepare_arguments_(self):
        def build_regexps(regexp_actions):
            if len(regexp_actions) == 0:
                return []
            # Create a list of global regexp with a symbolic group
            # for each option regexp.
            # We split the regexps list into chunks as python
            # does not support more than 100 symbolic regexp groups.
            # For each option regexp, its index in the list
            # matches the \d in the "i\d" given as group id.
            regexps = []
            chunk_count = 25
            chunk_nb = len(regexp_actions) / chunk_count
            i = 0
            for cc in range(chunk_nb + 1):
                count = chunk_count
                if cc == chunk_nb:
                    count = len(regexp_actions) - i
                    if count == 0: break  # pragma: branch_uncovered
                regexp = "^(%s)$" % (
                    "|".join(map(
                            lambda x: x[0],
                            regexp_actions[i:i + count])))
                regexps.append(regexp)
                i += chunk_count
            return map(re.compile, regexps)

        if self.argregexps_compiled_ != None:
            return
        self.argregexps_compiled_ = build_regexps(self.argregexps_actions_)

    def get_action_(self, arg):
        for regexp in self.argregexps_compiled_:
            match = regexp.match(arg)
            if match == None: continue
            groups = match.groupdict()
            matched_groups = filter(lambda x:
                                        (x[1] != None and
                                         x[0][0] == "O"),
                                    groups.items())
            assert(len(matched_groups) == 1)
            # We extract \d from the "O\d" symbolic group id
            idx = int(matched_groups[0][0][1:])
            opt = groups.get("O%d" % idx)
            arg = groups.get("A%d" % idx)
            return (self.argregexps_actions_[idx][1],
                    [opt] if arg == None else [opt, arg])
        return (None, None)

    @staticmethod
    def test():
        """ Unitary test, returns True if passed. """
        class TestNameSpace(NameSpace):
            def opt_X(self, args):
                self.X_kind = args[0][2:]
                self.X_arg = args[1]
        print "TESTING: GenArgumentParser..."
        parser = GenArgumentParser()
        ns, args = parser.parse_args(shlex.split(
                "-E -oout.i file.c file2.cc"))
        parser = GenArgumentParser()
        parser.add_argument("-E")
        parser.add_argument("-c")
        parser.add_argument("-S")
        parser.add_argument("-W")
        parser.add_argument("-Wall")
        parser.add_argument("-o", nargs=1, dest="output")
        parser.add_argument("-mtune", nargs=1, sep="=", dest="tune")
        parser.add_argument("--help", nargs=1, optsep="=", dest="help")
        parser.add_argument(re="-X.*", nargs=1, next=True, dest="opt_X")
        parser.add_argument(re="-f(no-)?inline")
        parser.add_argument(re="-m.*")
        parser.add_argument(re="-W.*")
        parser.add_argument(re="-f.*")
        ns, args = parser.parse_args(shlex.split(
                "-E -oout.i file.c file2.cc"))
        deep_eq(args, [["-E"], ["-o", "out.i"],
                       [None, "file.c"], [None, "file2.cc"]],
                _assert=True)
        deep_eq(vars(ns),
                {'output': 'out.i',
                 'REMAINDER': ['file.c', 'file2.cc']}, _assert=True)
        ns, args = parser.parse_args(shlex.split(
                "-o out.o -c -finline -fno-inline -W -Wall "
                "file.c -Wother -mtune=i586 --help=warnings --help driver "
                "-Xpreprocessed afile -undef"), TestNameSpace())
        deep_eq(args,
                [["-o", "out.o"], ["-c"], ["-finline"], ["-fno-inline"],
                 ["-W"], ["-Wall"], [None, "file.c"], ["-Wother"],
                 ["-mtune", "i586"], ["--help", "warnings"],
                 ["--help", "driver"], ["-Xpreprocessed", "afile"],
                 [None, "-undef"]],
                _assert=True)
        deep_eq(vars(ns),
                {'help': 'driver', 'tune': 'i586',
                 'X_kind': 'preprocessed', 'X_arg': 'afile',
                 'output': 'out.o',
                 'REMAINDER': ['file.c', '-undef']},
                _assert=True)
        try:
            args = None
            _, args = parser.parse_args(shlex.split("-o"))
        except MalformedArgument, e:
            pass
        assert(args == None)
        print "SUCCESS: GenArgumentParser"
        return True

if __name__ == "__main__":
    passed = GenArgumentParser.test()
    if not passed: sys.exit(1)
