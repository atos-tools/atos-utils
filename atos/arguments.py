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

import re
import globals
import argparse

def parser(tool):
    """
    Arguments parser factory for the given tool.
    Dispatch to the corresponding per tool factory.
    """
    factories = {
        "atos": parsers.atos,
        "atos-help": parsers.atos_help,
        "atos-audit": parsers.atos_audit,
        "atos-deps": parsers.atos_deps,
        "atos-profile": parsers.atos_profile
        }
    return factories[tool]()


class parsers:
    """
    Container namespace for all top level command arguments parser factories.
    One static method per top level tool or atos subcommand.
    Some may take an optional parser argument when used both as top level tool
    or atos subcommand.
    Some may take a required parser argument when used only as atos subcommand.

    For instance, parser = parsers.atos() returns the atos argparser object.
    """

    @staticmethod
    def atos():
        """ atos tool arguments parser factory. """
        parser = argparse.ArgumentParser(prog="atos",
                                         description="ATOS auto tuning optimization system tool, " +
                                         "see available commands below or run 'atos help' for the full manual.",
                                         formatter_class=argparse.ArgumentDefaultsHelpFormatter)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        subs = parser.add_subparsers(title="atos commands",
                                     description="see short description of commands below and " +
                                     "run 'atos COMMAND -h' for each command options",
                                     dest="command",
                                     help="available atos commands")

        sub = subs.add_parser("help", help="get full ATOS tools manual")
        parsers.atos_help(sub)

        sub = subs.add_parser("audit", help="audit and generate a build template to be used by atos-build")
        parsers.atos_audit(sub)

        sub = subs.add_parser("dep", help="generate the build system from a previous build audit")
        parsers.atos_deps(sub)

        sub = subs.add_parser("prof", help="generate the profile build")
        parsers.atos_profile(sub)
        return parser

    @staticmethod
    def atos_help(parser=None):
        """ atos-help arguments parser factory. """
        if parser == None:
            parser = argparse.ArgumentParser(prog="atos-help",
                                             description="ATOS help tool",
                                             formatter_class=argparse.ArgumentDefaultsHelpFormatter)
        parser._negative_number_matcher = re.compile(r'^-.+$')
        args.version(parser)
        return parser

    @staticmethod
    def atos_audit(parser=None):
        """ atos audit arguments parser factory. """
        if parser == None:
            parser = argparse.ArgumentParser(prog="atos-audit",
                                             description="ATOS audit tool",
                                             formatter_class=argparse.ArgumentDefaultsHelpFormatter)
        args.executables(parser)
        args.configuration_path(parser)
        args.atos_audit.ccregexp(parser)
        args.atos_audit.ccname(parser)
        args.atos_audit.output(parser)
        args.force(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_deps(parser=None):
        """ atos dep arguments parser factory. """
        if parser == None:
            parser = argparse.ArgumentParser(prog="atos-deps",
                                             description="ATOS dependency and build system generation tool",
                                             formatter_class=argparse.ArgumentDefaultsHelpFormatter)
        args.executables(parser)
        args.configuration_path(parser)
        args.atos_deps.input(parser)
        args.atos_deps.output(parser)
        args.atos_deps.last(parser)
        args.atos_deps.all(parser)
        args.force(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_profile(parser=None):
        """ atos profile arguments parser factory. """
        if parser == None:
            parser = argparse.ArgumentParser(prog="atos-profile",
                                             description="ATOS profile generation tool",
                                             formatter_class=argparse.ArgumentDefaultsHelpFormatter)
        parser._negative_number_matcher = re.compile(r'^-.+$')
        args.configuration_path(parser)
        args.atos_profile.path(parser)
        args.atos_profile.remote_path(parser)
        args.atos_profile.options(parser)
        args.force(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

class args:
    """
    Container namespace for single options declarators.
    One staticmethod per single option here with the long option
    name, whatever the tool.
    Each method defines a default short and long option string that
    can be overriden in case of conflicts with a tuple of option
    strings passed to the args parameter.
    Some additional methods may group common options.

    For instance, args.version(parser) declare the --version option.
    """

    @staticmethod
    def version(parser, args=("-v", "--version")):
        parser.add_argument(*args,
                            help="output version string",
                            action="version",
                            version="atos version " + globals.VERSION)

    @staticmethod
    def quiet(parser, args=("-q", "--quiet")):
        parser.add_argument(*args,
                            help="quiet output",
                            action="store_true")

    @staticmethod
    def dryrun(parser, args=("-n", "--dryrun")):
        parser.add_argument(*args,
                            help="dry run, output commands only",
                            action="store_true")

    @staticmethod
    def configuration_path(parser, args=("-C", "--configuration")):
        parser.add_argument(*args,
                             dest="configuration_path",
                             help="atos configuration working directory",
                             default=globals.DEFAULT_CONFIGURATION_PATH)

    @staticmethod
    def force(parser, args=("-f", "--force")):
        parser.add_argument(*args,
                             action="store_true",
                             help="use atos tools in force rebuild mode, the full build command will be re-executed")

    @staticmethod
    def executables(parser):
        parser.add_argument("executables",
                            nargs=argparse.REMAINDER,
                            help="default executables list to optimize")

    class atos_audit:
        """ Namespace for non common atos-deps arguments. """

        @staticmethod
        def output(parser, args=("-o", "--output")):
            parser.add_argument(*args,
                                 dest="output_file",
                                 help="audit description file, defaults to CONFIGURATION/build.audit")

        @staticmethod
        def ccregexp(parser, args=("-r", "--ccregexp")):
            parser.add_argument(*args,
                                 dest="ccregexp",
                                 help="specify the compiler tools as a regexp for the basename",
                                 default=globals.DEFAULT_TOOLS_CREGEXP)

        @staticmethod
        def ccname(parser, args=("-c", "--ccname")):
            parser.add_argument(*args,
                                 dest="ccname",
                                 help="specify the exact compiler driver basename")

    class atos_deps:
        """ Namespace for non common atos-deps arguments. """

        @staticmethod
        def input(parser, args=("-i", "--input")):
            parser.add_argument(*args,
                                 dest="input_file",
                                 help="input build audit as generated by atos-audit, defaults to CONFIGURATION/build.audit")

        @staticmethod
        def output(parser, args=("-o", "--output")):
            parser.add_argument(*args,
                                 dest="output_file",
                                 help="output build description suitable for atos-build, defaults to CONFIGURATION/build.mk")

        @staticmethod
        def last(parser, args=("-l", "--last")):
            parser.add_argument(*args,
                                 dest="last",
                                 help="use last build target in the build audit as the default target",
                                 action="store_true")

        @staticmethod
        def all(parser, args=("-a", "--all")):
            parser.add_argument(*args,
                                 dest="all",
                                 help="use all build targets as the default targets, use it when all built executables need to be optimized",
                                 action="store_true")

    class atos_profile:
        """ Namespace for non common atos-profile arguments. """

        @staticmethod
        def path(parser, args=("-p", "--path")):
            parser.add_argument(*args,
                                 dest="path",
                                 help="path to profile files")

        @staticmethod
        def remote_path(parser, args=("-b", "--remote_path")):
            parser.add_argument(*args,
                                 dest="remote_path",
                                 help="remote path to profile files")

        @staticmethod
        def options(parser, args=("-g", "--options")):
            parser.add_argument(*args,
                                 dest="options",
                                 help="append given options to the compilation commands")

