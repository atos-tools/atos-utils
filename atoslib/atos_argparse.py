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
import argparse

class ATOSArgumentParser(argparse.ArgumentParser):
    """
    Specialization of parser class for ATOS tools.
    We add some constraints to the arguments to better match usual
    option parsing tools such as GNU getopt.
    Ref to check_action_arg docstring.
    """
    def __init__(self,
                 prog=None,
                 usage=None,
                 description=None,
                 formatter_class=argparse.ArgumentDefaultsHelpFormatter):
        assert(prog != None)
        super(ATOSArgumentParser, self).__init__(
            prog=prog, usage=usage, description=description,
            formatter_class=formatter_class)

    def check_action_arg(self, action):
        """
        Check that we only have 0 or 1 argument options.
        I.e. we do not allow optional or multi arguments options.
        Also check that long options always start with '--'.
        This simplifies the implementation of the
        parse_args.prepare_args() function below.
        """
        if action.option_strings:
            assert(action.nargs == None or
                   action.nargs == 1 or action.nargs == 0)
            assert all(
                map(lambda option_string: (
                        len(option_string) <= 2 or option_string[:2] == "--"),
                    action.option_strings))

    def add_argument(self, *args, **kwargs):
        action = super(ATOSArgumentParser, self).add_argument(
            *args, **kwargs)
        self.check_action_arg(action)
        return action

    def parse_args(self, args=None, namespace=None):
        """
        Calls the superclass parse_args after preparing the arguments.
        """
        def prepare_args(parser, args):
            """
            Ensure that we handle correctly arguments starting with '-'.
            This is a work around for the unusual behavior of argparse.
            In the case: prog -a -O (where -O is an argument to -a),
            we transform the two arguments into: prog -a=-O.
            Otherwise argparse would treat -O as an option in itself.
            """
            def gen_option_map(actions):
                """ Generate the map option -> action. """
                option_map = {}
                for action in actions:
                    for option in action.option_strings:
                        option_map[option] = action
                return option_map

            def gen_subparser_map(actions):
                """ Generate the map subcmd -> subparser. """
                subparser_map = {}
                for action in actions:
                    if isinstance(action, argparse._SubParsersAction):
                        subparser_map = action.choices
                        break
                return subparser_map

            option_map = gen_option_map(parser._actions)
            subparser_map = gen_subparser_map(parser._actions)
            new_args = []
            i = 0
            while True:
                if i >= len(args): break
                arg = args[i]
                if arg in subparser_map:
                    return new_args + [arg] + \
                        prepare_args(subparser_map[arg], args[(i + 1):])
                if arg == '--' or arg[0] != '-': break
                if len(arg) > 2 and arg[0] == '-' and arg[1] != '-':
                    option = arg[:2]  # handle -Xval case
                else: option = arg.split("=", 1)[0]
                if not option in option_map: break
                if (option == arg and
                    option_map[option].nargs != 0 and
                    i + 1 < len(args) and args[i + 1] != "--"):
                    arg = "%s=%s" % (arg, args[i + 1])
                    i += 1
                new_args.append(arg)
                i += 1
            return new_args + args[i:]

        args = prepare_args(self, sys.argv[1:] if args == None else args)
        args = super(ATOSArgumentParser, self).parse_args(args, namespace)
        return args

    @staticmethod
    def test():
        print "TESTING ATOSArgumentParser..."
        parser = ATOSArgumentParser(prog="test")
        parser.add_argument("-o", dest="output")
        parser.add_argument("-a", dest="list", action="append")
        parser.add_argument("-t", dest="bool", action="store_true")
        parser.add_argument("rest", nargs=argparse.REMAINDER)
        args = parser.parse_args(["-t"])
        assert(args.bool == True)
        args = parser.parse_args(["-oa.out"])
        assert(args.output == "a.out")
        assert(args.bool == False)
        assert(args.list == None)
        args = parser.parse_args(["-o=a.out"])
        assert(args.output == "a.out")
        args = parser.parse_args(["-o", "a.out"])
        assert(args.output == "a.out")
        args = parser.parse_args(["-o", "a.out", "--", "-o", "-t"])
        assert(args.output == "a.out")
        assert(len(args.rest) == 3)
        assert(args.rest[0] == "--")
        assert(args.rest[1] == "-o")
        assert(args.rest[2] == "-t")
        args = parser.parse_args(["-o", "-a"])
        assert(args.output == "-a")
        args = parser.parse_args(["-o", "-a"])
        assert(args.output == "-a")
        args = parser.parse_args(["-o", "-a", "-o", "-b"])
        assert(args.output == "-b")
        args = parser.parse_args(["-o", "-t", "-t", "-a", "-a",
                                  "-a", "-b", "--", "-a", "-c"])
        assert(len(args.list) == 2)
        assert(args.list[0] == "-a")
        assert(args.list[1] == "-b")
        assert(args.output == "-t")
        assert(args.bool == True)
        assert(len(args.rest) == 3)
        assert(args.rest[0] == "--")
        assert(args.rest[1] == "-a")
        assert(args.rest[2] == "-c")
        print "SUCCESS ATOSArgumentParser"

if __name__ == "__main__":
    ATOSArgumentParser.test()
