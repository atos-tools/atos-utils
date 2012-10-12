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

import re, os
import globals
import argparse
import logger
import process

def parser(tool):
    """
    Arguments parser factory for the given tool.
    Dispatch to the corresponding per tool factory.
    """
    factories = {
        "atos": parsers.atos,
        "atos-help": parsers.atos_help,
        "atos-audit": parsers.atos_audit,
        "atos-build": parsers.atos_build,
        "atos-deps": parsers.atos_deps,
        "atos-explore": parsers.atos_explore,
        "atos-init": parsers.atos_init,
        "atos-lib": parsers.atos_lib,
        "atos-opt": parsers.atos_opt,
        "atos-play": parsers.atos_play,
        "atos-profile": parsers.atos_profile,
        "atos-raudit": parsers.atos_raudit,
        "atos-run": parsers.atos_run,
        "atos-replay": parsers.atos_replay,
        "atos-explore-inline": parsers.atos_explore_inline,
        "atos-explore-loop": parsers.atos_explore_loop,
        "atos-explore-optim": parsers.atos_explore_optim,
        }
    return factories[tool]()


class ATOSArgumentParser(argparse.ArgumentParser):
    """
    Specialization of parser class for ATOS tools.
    In particular the handling of non option arguments
    is modified to allow strings starting with '-' such as
    in atos-opt -a '-O2'.
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
        # Trick to allow strings starting with '-' for non option arguments
        self._negative_number_matcher = re.compile(r'^-.+$')

    def parse_args(self):
        """
        Calls the superclass parse_args and initialize modules with
        common arguments.
        """
        args = super(ATOSArgumentParser, self).parse_args()
        logger.setup(vars(args))
        process.setup(vars(args))
        return args

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
        parser = ATOSArgumentParser(
            prog="atos",
            description="ATOS auto tuning optimization system tool, "
            "see available commands below "
            "or run 'atos help' for the full manual.")
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        subs = parser.add_subparsers(
            title="atos commands",
            dest="subcmd",
            description="see short description of commands below and " +
            "run 'atos COMMAND -h' for each command options",
            help="available atos commands")

        sub = subs.add_parser("help", help="get full ATOS tools manual")
        parsers.atos_help(sub)

        sub = subs.add_parser("audit",
                help="audit and generate a build template "
                "to be used by atos-build")
        parsers.atos_audit(sub)

        sub = subs.add_parser("build", help="build system")
        parsers.atos_build(sub)

        sub = subs.add_parser("dep",
                help="generate the build system from a previous build audit")
        parsers.atos_deps(sub)

        sub = subs.add_parser("explore", help="do the exploration of options")
        parsers.atos_explore(sub)

        sub = subs.add_parser("init", help="initialize atos environment")
        parsers.atos_init(sub)

        sub = subs.add_parser("lib", help=argparse.SUPPRESS)
        parsers.atos_lib(sub)

        sub = subs.add_parser("opt", help="opt system")
        parsers.atos_opt(sub)

        sub = subs.add_parser("play", help="play tool")
        parsers.atos_play(sub)

        sub = subs.add_parser("profile", help="generate the profile build")
        parsers.atos_profile(sub)

        sub = subs.add_parser("raudit",
                 help="audit and generate a run template "
                 "to be used by atos-build")
        parsers.atos_raudit(sub)

        sub = subs.add_parser("run",
                 help="run system")
        parsers.atos_run(sub)

        sub = subs.add_parser("replay", help="replay system")
        parsers.atos_replay(sub)

        return parser

    @staticmethod
    def atos_help(parser=None):
        """ atos-help arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-help",
                                             description="ATOS help tool")
        parser.add_argument(
            "topics",
            nargs=argparse.REMAINDER,
            help="help topics. Execute 'atos help' for available topics.")
        args.atos_help.text(parser)
        args.atos_help.man(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_audit(parser=None):
        """ atos audit arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-audit",
                                        description="ATOS audit tool")
        args.command(parser)
        args.configuration_path(parser)
        args.ccregexp(parser)
        args.ccname(parser)
        args.output(parser, default="build.audit")
        args.force(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_build(parser=None):
        """ atos build arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-build",
                                        description="ATOS build tool")
        args.command(parser)
        args.configuration_path(parser)
        args.ccregexp(parser)
        args.ccname(parser)
        args.path(parser)
        args.options(parser)
        args.variant(parser)
        args.remote_path(parser, ("-b", "--remote_path"))
        args.atos_build.jobs(parser)
        group = parser.add_mutually_exclusive_group()
        args.useprofile(group)
        args.genprofile(group)
        args.force(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_deps(parser=None):
        """ atos dep arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-deps",
                description="ATOS dependency and build system generation tool")
        args.executables(parser)
        args.exes(parser)
        args.configuration_path(parser)
        args.atos_deps.input(parser)
        args.output(parser, default="build.mk")
        args.atos_deps.last(parser)
        args.atos_deps.all(parser)
        args.force(parser)
        args.quiet(parser)
        args.debug(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore(parser=None):
        """ atos explore arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-explore",
                                        description="ATOS explore tool")
        args.executables(parser)
        args.exes(parser)
        args.configuration_path(parser)
        args.build_script(parser)
        args.force(parser)
        args.run_script(parser)
        args.nbruns(parser, default=1)
        args.remote_path(parser)
        args.results_script(parser)
        args.clean(parser)
        args.cookie(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore_inline(parser=None):
        """ atos explore inline arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-explore-inline",
                                        description="ATOS explore inline tool")
        args.configuration_path(parser)
        args.nbruns(parser, default=1)
        args.remote_path(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore_loop(parser=None):
        """ atos explore loop arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-explore-loop",
                                        description="ATOS explore loop tool")
        args.configuration_path(parser)
        args.nbruns(parser, default=1)
        args.remote_path(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore_optim(parser=None):
        """ atos explore optim arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-explore-optim",
                                        description="ATOS explore optim tool")
        args.configuration_path(parser)
        args.nbruns(parser, default=1)
        args.remote_path(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_init(parser=None):
        """ atos init arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-init",
                                        description="ATOS init tool")
        args.executables(parser)
        args.configuration_path(parser)
        args.clean(parser)
        args.exes(parser)
        args.build_script(parser)
        args.run_script(parser)
        args.results_script(parser)
        args.atos_init.prof_script(parser)
        args.nbruns(parser, default=1)
        args.remote_path(parser)
        args.atos_init.no_run(parser)
        args.debug(parser)
        args.force(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_lib(parser=None):
        """ atos lib arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib",
                                        description="ATOS lib tool")

        subs = parser.add_subparsers(
            title="atos lib commands",
            dest="subcmd_lib",
            description="see short description of commands below and " +
            "run 'atos lib COMMAND -h' for each command options",
            help="available atos lib commands")

        sub = subs.add_parser("create_db", help="Create a new empty database")
        parsers.atos_lib_createdb(sub)

        sub = subs.add_parser("query",
                help="Query database results")
        parsers.atos_lib_query(sub)

        sub = subs.add_parser("speedups", help="Get results")
        parsers.atos_lib_speedups(sub)

        sub = subs.add_parser("push",
                              help="Export results to another database")
        parsers.atos_lib_push(sub)

        sub = subs.add_parser("pull",
                              help="Import results from another database")
        parsers.atos_lib_pull(sub)

        sub = subs.add_parser("report",
                              help="Print results")
        parsers.atos_lib_report(sub)

        sub = subs.add_parser("add_result",
                              help="Add result to database")
        parsers.atos_lib_addresult(sub)

        sub = subs.add_parser("config",
                              help=argparse.SUPPRESS)
        parsers.atos_lib_config(sub)

        return parser

    @staticmethod
    def atos_lib_createdb(parser=None):
        """ atos lib createdb arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-lib-createdb",
                description="=Create a new empty database")

        args.configuration_path(parser)
        args.atos_lib.type(parser)
        args.atos_lib.shared(parser)
        return parser

    @staticmethod
    def atos_lib_query(parser=None):
        """ atos lib query arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-lib-query",
                description="Query database results")

        args.configuration_path(parser)
        args.atos_lib.query(parser)
        args.atos_lib.text(parser)
        return parser

    @staticmethod
    def atos_lib_speedups(parser=None):
        """ atos lib speedups arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-speedups",
                                        description="ATOS lib tool")

        args.configuration_path(parser)
        args.tradeoffs(parser)
        args.atos_lib.query(parser)
        args.atos_lib.targets(parser)
        args.atos_lib.groupname(parser)
        args.atos_lib.refid(parser)
        args.atos_lib.frontier(parser)
        return parser

    @staticmethod
    def atos_lib_push(parser=None):
        """ atos lib push arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-push",
                                        description="ATOS lib tool")

        args.configuration_path(parser, ("-C", "--C1"))
        args.atos_lib.remote_configuration_path(parser)
        args.atos_lib.query(parser)
        args.atos_lib.replacement(parser)
        args.force(parser)
        return parser

    @staticmethod
    def atos_lib_pull(parser=None):
        """ atos lib pull arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-pull",
                                        description="ATOS lib tool")

        args.configuration_path(parser, ("-C", "--C1"))
        args.atos_lib.remote_configuration_path(parser)
        args.atos_lib.query(parser)
        args.atos_lib.replacement(parser)
        args.force(parser)
        return parser

    @staticmethod
    def atos_lib_report(parser=None):
        """ atos lib report arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-report",
                                        description="ATOS lib tool")

        args.configuration_path(parser)
        args.atos_lib.targets(parser)
        args.atos_lib.query(parser)
        args.atos_lib.refid(parser)
        args.atos_lib.reverse(parser)
        args.atos_lib.mode(parser)
        args.atos_lib.variants(parser)
        return parser

    @staticmethod
    def atos_lib_addresult(parser=None):
        """ atos lib add_result arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-add_result",
                                        description="ATOS lib tool")

        args.configuration_path(parser)
        args.atos_lib.result(parser)
        return parser

    @staticmethod
    def atos_lib_config(parser=None):
        """ atos lib config arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-config",
                                        description="ATOS lib tool")

        args.configuration_path(parser)
        args.atos_lib.query(parser)
        args.atos_lib.text(parser)
        args.atos_lib.uniq(parser)
        args.atos_lib.additem(parser)
        args.atos_lib.getitem(parser)
        args.atos_lib.addcpl(parser)
        args.atos_lib.cplflags(parser)
        return parser

    @staticmethod
    def atos_opt(parser=None):
        """ atos opt arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-opt",
                                        description="ATOS opt tool")
        args.configuration_path(parser)
        args.atos_opt.lto(parser)
        args.atos_opt.fdo(parser)
        args.atos_opt.keep(parser)
        args.record(parser)
        args.remote_path(parser, ("-b", "--remote_path"))
        args.useprofile(parser)
        args.nbruns(parser, default=1)
        args.options(parser)
        args.cookie(parser)
        args.debug(parser)
        args.force(parser, ("--force",))
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_play(parser=None):
        """ atos play arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-play",
                                        description="ATOS play tool")
        args.command(parser)
        args.configuration_path(parser)
        group = parser.add_mutually_exclusive_group()
        args.atos_play.objective(group)
        args.tradeoffs(group)
        args.atos_play.nbpoints(parser)
        args.atos_play.ref(parser)
        args.atos_play.localid(parser)
        args.atos_play.printconfig(parser)
        args.atos_play.printvariant(parser)
        args.id(parser)
        args.debug(parser)
        args.force(parser, ("--force",))
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_profile(parser=None):
        """ atos profile arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-profile",
                description="ATOS profile generation tool")
        args.configuration_path(parser)
        args.path(parser)
        args.remote_path(parser, ("-b", "--remote_path"))
        args.options(parser, ("-g", "--options"))
        args.debug(parser)
        args.force(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_raudit(parser=None):
        """ atos raudit arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-raudit",
                description="ATOS raudit tool")
        args.command(parser)
        args.configuration_path(parser)
        args.output(parser, default="run.audit")
        args.results_script(parser)
        args.force(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_run(parser=None):
        """ atos run arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-run",
                                        description="ATOS run tool")
        args.command(parser)
        args.configuration_path(parser)
        args.nbruns(parser)
        args.remote_path(parser, ("-b", "--remote_path"))
        args.results_script(parser)
        prof_group = parser.add_mutually_exclusive_group()
        args.useprofile(prof_group)
        args.genprofile(prof_group)
        args.record(parser)
        args.variant(parser)
        args.options(parser)
        args.cookie(parser)
        args.output(parser)
        args.id(parser)
        args.atos_run.silent(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_replay(parser=None):
        """ atos replay arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-replay",
                                        description="ATOS replay tool")
        args.configuration_path(parser)
        args.atos_replay.results_path(parser)
        args.run_script(parser)
        args.results_script(parser)
        args.nbruns(parser)
        args.cookie(parser)
        args.debug(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
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
        parser.add_argument(
            *args,
             help="output version string",
             action="version",
             version="atos version " + globals.VERSION)

    @staticmethod
    def quiet(parser, args=("-q", "--quiet")):
        parser.add_argument(
            *args,
             help="quiet output",
             action="store_true")

    @staticmethod
    def dryrun(parser, args=("-n", "--dryrun")):
        parser.add_argument(
            *args,
             help="dry run, output commands only",
             action="store_true")

    @staticmethod
    def configuration_path(parser, args=("-C", "--configuration")):
        parser.add_argument(
            *args,
             dest="configuration_path",
             help="atos configuration working directory",
             default=globals.DEFAULT_CONFIGURATION_PATH)

    @staticmethod
    def force(parser, args=("-f", "--force")):
        parser.add_argument(
            *args,
             action="store_true",
             help="use atos tools in force rebuild mode, "
             "the full build command will be re-executed")

    @staticmethod
    def build_script(parser, args=("-b", "--build-script")):
        parser.add_argument(
            *args,
             dest="build_script",
             help="build_script to be audited and optimized")

    @staticmethod
    def ccregexp(parser, args=("-r", "--ccregexp")):
        parser.add_argument(
            *args,
             dest="ccregexp",
             help="specify the compiler tools as a regexp for the basename",
             default=globals.DEFAULT_TOOLS_CREGEXP)

    @staticmethod
    def ccname(parser, args=("-c", "--ccname")):
        parser.add_argument(
            *args,
             dest="ccname",
             help="specify the exact compiler driver basename")

    @staticmethod
    def path(parser, args=("-p", "--path")):
        parser.add_argument(*args,
                             dest="path",
                             help="path to profile files")

    @staticmethod
    def remote_path(parser, args=("-B", "--remote-path")):
        parser.add_argument(
            *args,
             dest="remote_path",
             help="remote path to profile files for cross execution")

    @staticmethod
    def run_script(parser, args=("-r", "--run-script")):
        parser.add_argument(
            *args,
             dest="run_script",
             help="run_script to be audited and optimized")

    @staticmethod
    def nbruns(parser, default=None, args=("-n", "--nbruns")):
        parser.add_argument(
            *args,
             dest="nbruns",
             type=int,
             help="number of executions of <run_script>",
             default=default)

    @staticmethod
    def results_script(parser, args=("-t", "--results-script")):
        parser.add_argument(
            *args,
             dest="results_script",
             help="results_script for specific instrumentation")

    @staticmethod
    def clean(parser, args=("-c", "--clean")):
        parser.add_argument(
            *args,
             dest="clean",
             help="clean results and profiles before exploration",
             action="store_true")

    @staticmethod
    def debug(parser, args=("-d", "--debug")):
        parser.add_argument(
            *args,
             dest="debug",
             help="debug mode",
             action="store_true")

    @staticmethod
    def exes(parser, args=("-e", "--executables")):
        parser.add_argument(
            *args,
             dest="exes",
             help="executables to be instrumented, "
             "defaults to args of command or all generated executables")

    @staticmethod
    def id(parser, args=("-i", "--identifier")):
        parser.add_argument(
            *args,
            dest="id",
            help="identifier of run [default: executables basename]")

    @staticmethod
    def options(parser, args=("-a", "--options")):
        parser.add_argument(
            *args,
            dest="options",
            help="append given options to the compilation commands")

    @staticmethod
    def output(parser, default="None", args=("-o", "--output")):
        parser.add_argument(
            *args,
             dest="output_file",
             help="output description file, defaults to CONFIGURATION_PATH/"
             + default)

    @staticmethod
    def useprofile(parser, args=("-u", "--useprof")):
        parser.add_argument(*args,
                            dest="uopts",
                            help="use profile variant deduced by UOPTS")

    @staticmethod
    def genprofile(parser, args=("-g", "--genprof")):
        parser.add_argument(
            *args,
             dest="gopts",
             help="generate profile variant deduced by GOPTS")

    @staticmethod
    def record(parser, args=("-r", "--record")):
        parser.add_argument(*args,
                             dest="record",
                             action='store_true',
                             help="record results")

    @staticmethod
    def cookie(parser, args=("--cookie",)):
        parser.add_argument(*args,
                             dest="cookies",
                             action='append',
                             help=argparse.SUPPRESS)

    @staticmethod
    def tradeoffs(parser, args=("-s", "--tradeoffs")):
        parser.add_argument(*args,
                             dest="tradeoffs",
                             action='append',
                             type=float,
                             help="selected tradeoff given size/perf ratio")

    @staticmethod
    def variant(parser, args=("-w", "--variant")):
        parser.add_argument(
            *args,
             dest="variant",
             help="identifier of variant")

    @staticmethod
    def seed(parser, args=("-S", "--seed")):
        parser.add_argument(
            *args,
             dest="seed",
             help="seed for random generator",
             default=0)

    @staticmethod
    def nbiters(parser, args=("-M", "--nbiters")):
        parser.add_argument(
            *args,
             dest="nbiters",
             type=int,
             help="number of exploration loop iterations",
             default=100)

    @staticmethod
    def flags(parser, args=("-F", "--flags")):
        parser.add_argument(
            *args,
             dest="flags_file",
             help="flags list filename",
             default=None)

    @staticmethod
    def optim_levels(parser, args=("-O", "--optim-levels")):
        parser.add_argument(
            *args,
             dest="optim_levels",
             help="list of optimization levels",
             default="-Os,-O2,-O3")

    @staticmethod
    def optim_variants(parser, args=("-V", "--optim-variants")):
        parser.add_argument(
            *args,
             dest="optim_variants",
             help="list of optimization variants, defaults to all"
             " available variants",
             default=None)

    @staticmethod
    def base_variants(parser):
        parser.add_argument(
            "base_variants",
            nargs=argparse.REMAINDER,
            help="identifiers of variants"
            " on which the exploration will be based")

    @staticmethod
    def executables(parser):
        parser.add_argument(
            "executables",
            nargs=argparse.REMAINDER,
            help="default executables list to optimize")

    @staticmethod
    def command(parser):
        parser.add_argument(
            "command",
            nargs=argparse.REMAINDER,
            help="command to be executed")

    class atos_help:
        """ Namespace for non common atos help options. """

        @staticmethod
        def man(parser, args=("-m", "--man")):
            parser.add_argument(
                *args,
                 dest="man",
                 action="store_true",
                 help="display manpage for TOPICS (default if available)")

        @staticmethod
        def text(parser, args=("-t", "--text")):
            parser.add_argument(
                *args,
                 dest="text",
                 action="store_true",
                 help="display textual manual for TOPICS")

    class atos_build:
        """ Namespace for non common atos-build arguments. """

        @staticmethod
        def jobs(parser, args=("-j", "--jobs")):
            parser.add_argument(
                *args,
                 dest="jobs",
                 type=int,
                 help="use JOBS parallel thread when possible for building",
                 default=4)

    class atos_deps:
        """ Namespace for non common atos-deps arguments. """

        @staticmethod
        def input(parser, args=("-i", "--input")):
            parser.add_argument(
                *args,
                 dest="input_file",
                 help="input build audit as generated by atos-audit, "
                 "defaults to CONFIGURATION/build.audit")

        @staticmethod
        def last(parser, args=("-l", "--last")):
            parser.add_argument(
                *args,
                 dest="last",
                 help="use last build target in the build audit "
                 "as the default target",
                 action="store_true")

        @staticmethod
        def all(parser, args=("-a", "--all")):
            parser.add_argument(
                *args,
                 dest="all",
                 help="use all build targets as the default targets, "
                 "use it when all built executables need to be optimized",
                 action="store_true")

    class atos_init:
        """ Namespace for non common atos-init arguments. """

        @staticmethod
        def prof_script(parser, args=("-p", "--profile-script")):
            parser.add_argument(*args,
                                 dest="prof_script",
                                 help="script to get profile information")

        @staticmethod
        def no_run(parser, args=("-N", "--no-run")):
            parser.add_argument(
                *args,
                 dest="no_run", action='store_true', default=False,
                 help="do not run reference configuration")

    class atos_lib:
        """ Namespace for non common atos lib arguments. """

        @staticmethod
        def query(parser, args=("-q", "--query")):
            parser.add_argument(*args,
                                 dest="query",
                                 help="results query values")

        @staticmethod
        def type(parser, args=("-t", "--type")):
            parser.add_argument(
                *args,
                 dest="type",
                 choices=['results_db', 'json', 'pickle'],
                 help="database type",
                 default='results_db')

        @staticmethod
        def shared(parser, args=("--shared",)):
            parser.add_argument(
                *args,
                 dest="shared",
                 help="create a shared database "
                 "(group has write permission)",
                 action="store_true")

        @staticmethod
        def text(parser, args=("-t", "--text")):
            parser.add_argument(
                *args,
                 dest="text",
                 help="text output format (default: json)",
                 action="store_true")

        @staticmethod
        def targets(parser, args=("-t", "--targets")):
            parser.add_argument(
                *args,
                 dest="targets",
                 help="target list")

        @staticmethod
        def groupname(parser, args=("-g", "--group_name")):
            parser.add_argument(
                *args,
                 dest="group_name",
                 help="target group name")

        @staticmethod
        def refid(parser, args=("-r", "--refid")):
            parser.add_argument(
                *args,
                 dest="ref",
                 help="reference variant id",
                 default="REF")

        @staticmethod
        def frontier(parser, args=("-f", "--frontier")):
            parser.add_argument(
                *args,
                 dest="frontier",
                 help="only print frontier points",
                 action="store_true")

        @staticmethod
        def remote_configuration_path(parser, args=("-R", "--C2")):
            parser.add_argument(
                *args,
                 dest="remote_configuration_path",
                 help="remote configuration path",
                 required=True)

        @staticmethod
        def replacement(parser, args=("-r", "--repl")):
            parser.add_argument(
                *args,
                 dest="replacement",
                 help="values replacement",
                 default="")

        @staticmethod
        def reverse(parser, args=("-X", "--reverse")):
            parser.add_argument(
                *args,
                 dest="reverse",
                 help="swap line/columns",
                 action="store_true")

        @staticmethod
        def mode(parser, args=("-m", "--mode")):
            parser.add_argument(
                *args,
                 dest="mode",
                 choices=['speedup', 'sizered', 'stdev'],
                 help="report type [speedup|sizered|stdev]",
                 default="speedup")

        @staticmethod
        def variants(parser, args=("-v", "--variants")):
            parser.add_argument(
                *args,
                 dest="variants",
                 help="target list")

        @staticmethod
        def result(parser, args=("-r", "--result")):
            parser.add_argument(
                *args,
                 dest="result",
                 help="results values",
                 default="")

        @staticmethod
        def uniq(parser, args=("-u", "--uniq")):
            parser.add_argument(
                *args,
                 dest="uniq",
                 help="omit repeated results",
                 action="store_true")

        @staticmethod
        def additem(parser, args=("-a", "--add")):
            parser.add_argument(
                *args,
                 dest="add_item",
                 help="add config item (key:value)")

        @staticmethod
        def getitem(parser, args=("-g", "--get")):
            parser.add_argument(
                *args,
                 dest="get_item",
                 help="get config item")

        @staticmethod
        def addcpl(parser, args=("--add-cpl",)):
            parser.add_argument(
                *args,
                 dest="add_cpl",
                 help="add compiler description")

        @staticmethod
        def cplflags(parser, args=("--cpl-flags",)):
            parser.add_argument(
                *args,
                 dest="cpl_flags",
                 help="print flags for flags file",
                 action="store_true")

    class atos_opt:
        """ Namespace for non common atos-opt arguments. """

        @staticmethod
        def lto(parser, args=("-l", "--lto")):
            parser.add_argument(*args,
                                 dest="lto",
                                 action='store_true',
                                 help="use use link time optimizations")

        @staticmethod
        def fdo(parser, args=("-f", "--fdo")):
            parser.add_argument(*args,
                                 dest="fdo",
                                 action='store_true',
                                 help="use feedback directed optimizations")

        @staticmethod
        def keep(parser, args=("-k", "--keep")):
            parser.add_argument(*args,
                                 dest="keep",
                                 action='store_true',
                                 help="keep existing results if any")

    class atos_play:
        """ Namespace for non common atos-play arguments. """

        @staticmethod
        def objective(parser, args=("-f", "--objective")):
            parser.add_argument(*args,
                                 dest="obj",
                                 help="defined the objective function",
                                 choices=["time", "size"],
                                 default="time")

        @staticmethod
        def nbpoints(parser, args=("-N", "--nbpoints")):
            parser.add_argument(
                *args,
                 dest="nbpoints",
                 type=int,
                 help="get nb best points given objective or tradeoff",
                 default=1)

        @staticmethod
        def ref(parser, args=("-r", "--ref")):
            parser.add_argument(*args,
                                 dest="ref",
                                 action='store_true',
                                 help="get reference results")

        @staticmethod
        def localid(parser, args=("-l", "--localid")):
            parser.add_argument(*args,
                                 dest="localid",
                                 help="get result identified by local_id")

        @staticmethod
        def printconfig(parser, args=("-p", "--printconfig")):
            parser.add_argument(*args,
                                 dest="printconfig",
                                 action='store_true',
                                 help="print configuration only")

        @staticmethod
        def printvariant(parser, args=("-P", "--printvariant")):
            parser.add_argument(*args,
                                 dest="printvariant",
                                 action='store_true',
                                 help="print configuration variant id only")

    class atos_run:
        """ Namespace for non common atos-run arguments. """

        @staticmethod
        def silent(parser, args=("-s", "--silent")):
            parser.add_argument(
                *args,
                 dest="silent",
                 action='store_true',
                 help="silent mode, do not emit perf/size results")

    class atos_replay:
        """ Namespace for non common atos-replay arguments. """

        @staticmethod
        def results_path(parser, args=("-R", "--replay-dir")):
            parser.add_argument(
                *args,
                 dest="results_path",
                 help="directory for qualified results",
                 default="atos-qualif")
