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

import re, os, sys
import globals
from atos_argparse import ATOSArgumentParser
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
        "atos-build": parsers.atos_build,
        "atos-deps": parsers.atos_deps,
        "atos-explore": parsers.atos_explore,
        "atos-init": parsers.atos_init,
        "atos-opt": parsers.atos_opt,
        "atos-play": parsers.atos_play,
        "atos-profile": parsers.atos_profile,
        "atos-raudit": parsers.atos_raudit,
        "atos-run": parsers.atos_run,
        "atos-replay": parsers.atos_replay,
        "atos-run-profile": parsers.atos_run_profile,
        "atos-explore-inline": parsers.atos_explore_inline,
        "atos-explore-loop": parsers.atos_explore_loop,
        "atos-explore-optim": parsers.atos_explore_optim,
        "atos-explore-acf": parsers.atos_explore_acf,
        "atos-explore-staged": parsers.atos_explore_staged,
        "atos-explore-genetic": parsers.atos_explore_genetic,
        "atos-config": parsers.atos_config,
        "atos-cookie": parsers.atos_cookie,
        "atos-lib": parsers.atos_lib,
        "atos-generator": parsers.atos_generator,
        "atos-graph": parsers.atos_graph,
        "atos-web": parsers.atos_web,
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

        sub = subs.add_parser("init", help="initialize atos environment")
        parsers.atos_init(sub)

        sub = subs.add_parser("explore", help="exploration of common variants")
        parsers.atos_explore(sub)

        sub = subs.add_parser("explore-inline",
                              help="exploration of inlining optimizations")
        parsers.atos_explore_inline(sub)

        sub = subs.add_parser("explore-loop",
                              help="exploration of loop optimizations")
        parsers.atos_explore_loop(sub)

        sub = subs.add_parser("explore-optim",
                              help="exploration of backend optimizations")
        parsers.atos_explore_optim(sub)

        sub = subs.add_parser("explore-staged", help="full staged exploration")
        parsers.atos_explore_staged(sub)

        sub = subs.add_parser(
            "explore-genetic", help="full genetic exploration")
        parsers.atos_explore_genetic(sub)

        sub = subs.add_parser("explore-acf", help="fine grain exploration")
        parsers.atos_explore_acf(sub)

        sub = subs.add_parser("play", help="play an existing variant")
        parsers.atos_play(sub)

        sub = subs.add_parser("audit",
                help="audit and generate a build template "
                "to be used by atos-build")
        parsers.atos_audit(sub)

        sub = subs.add_parser("build", help="build a variant")
        parsers.atos_build(sub)

        sub = subs.add_parser("deps",
                help="generate the build system from a previous build audit")
        parsers.atos_deps(sub)

        sub = subs.add_parser("opt", help="build and run a variant")
        parsers.atos_opt(sub)

        sub = subs.add_parser("profile", help="generate a profile build")
        parsers.atos_profile(sub)

        sub = subs.add_parser("raudit",
                 help="audit and generate a run template "
                 "to be used by atos-build")
        parsers.atos_raudit(sub)

        sub = subs.add_parser("run", help="run a variant")
        parsers.atos_run(sub)

        sub = subs.add_parser("replay", help="replay a session")
        parsers.atos_replay(sub)

        sub = subs.add_parser("config", help="find compilers configuration")
        parsers.atos_config(sub)

        sub = subs.add_parser("cookie", help="generate a cookie")
        parsers.atos_cookie(sub)

        sub = subs.add_parser("run-profile",
                              help="run a variant in profile collection mode")
        parsers.atos_run_profile(sub)

        sub = subs.add_parser("graph",
                              help="show exploration results in a graph")
        parsers.atos_graph(sub)

        sub = subs.add_parser("lib",
                              help="internal API access to ATOS library")
        parsers.atos_lib(sub)

        sub = subs.add_parser("generator",
                              help="internal API access to ATOS generators")
        parsers.atos_generator(sub)

        sub = subs.add_parser("web",
                              help="web user interface API")
        parsers.atos_web(sub)

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
        args.ldregexp(parser)
        args.ldname(parser)
        args.arregexp(parser)
        args.arname(parser)
        args.output(parser, default="build.audit")
        args.legacy(parser)
        args.force(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.ldregexp(parser)
        args.ldname(parser)
        args.arregexp(parser)
        args.arname(parser)
        args.path(parser)
        args.options(parser)
        args.variant(parser)
        args.remote_path(parser, ("-b", "--remote_path"))
        args.jobs(parser)
        group = parser.add_mutually_exclusive_group()
        args.useprofile(group)
        args.genprofile(group)
        args.legacy(parser)
        args.blacklist(parser)
        args.force(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.legacy(parser)
        args.force(parser)
        args.quiet(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.legacy(parser)
        args.force(parser)
        args.run_script(parser)
        args.nbruns(parser)
        args.remote_path(parser)
        args.results_script(parser)
        args.size_cmd(parser)
        args.time_cmd(parser)
        args.clean(parser)
        args.cookie(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.reuse(parser)
        args.jobs(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.nbruns(parser)
        args.remote_path(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.jobs(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.nbruns(parser)
        args.remote_path(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.jobs(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.nbruns(parser)
        args.remote_path(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.jobs(parser)
        args.debug(parser)
        args.log_file(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore_acf(parser=None):
        """ atos explore acf arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-explore-acf",
                                        description="ATOS explore acf tool")

        args.exes(parser)
        args.configuration_path(parser)
        args.nbruns(parser)
        args.remote_path(parser)
        args.prof_script(parser)
        args.seed(parser)
        args.per_func_nbiters(parser)
        args.flags(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.base_variants(parser)
        args.atos_explore.file_by_file(parser)
        args.atos_explore.hot_threshold(parser)
        args.atos_explore.cold_options(parser)
        args.atos_explore.cold_attributes(parser)
        args.atos_explore.genetic(parser)
        args.atos_explore.random(parser)
        args.extra_arguments(parser)
        args.tradeoffs(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.jobs(parser)
        args.debug(parser)
        args.log_file(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore_staged(parser=None):
        """ atos explore staged arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-explore-staged",
                                        description="ATOS explore staged tool")

        args.exes(parser)
        args.configuration_path(parser)
        args.build_script(parser)
        args.legacy(parser)
        args.force(parser)
        args.run_script(parser)
        args.nbruns(parser)
        args.remote_path(parser)
        args.results_script(parser)
        args.prof_script(parser)
        args.size_cmd(parser)
        args.time_cmd(parser)
        args.clean(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.per_func_nbiters(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.atos_explore.file_by_file(parser, ("--file-by-file",))
        args.atos_explore.hot_threshold(parser)
        args.tradeoffs(parser)
        args.jobs(parser)
        args.debug(parser)
        args.log_file(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_explore_genetic(parser=None):
        """ atos explore genetic arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-explore-genetic",
                description="ATOS explore genetic tool")

        args.exes(parser)
        args.configuration_path(parser)
        args.build_script(parser)
        args.legacy(parser)
        args.force(parser)
        args.prof_script(parser)
        args.run_script(parser)
        args.nbruns(parser)
        args.remote_path(parser)
        args.results_script(parser)
        args.size_cmd(parser)
        args.time_cmd(parser)
        args.clean(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.seed(parser)
        args.nbiters(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.tradeoffs(parser)
        args.atos_explore.generations(parser)
        args.atos_explore.flags(parser)
        args.atos_explore.mutate_prob(parser)
        args.atos_explore.mutate_rate(parser)
        args.atos_explore.mutate_remove(parser)
        args.atos_explore.evolve_rate(parser)
        args.atos_explore.nbpoints(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.prof_script(parser)
        args.size_cmd(parser)
        args.time_cmd(parser)
        args.ccregexp(parser)
        args.ccname(parser)
        args.ldregexp(parser)
        args.ldname(parser)
        args.arregexp(parser)
        args.arname(parser)
        args.nbruns(parser)
        args.remote_path(parser)
        args.atos_init.no_run(parser)
        args.cookie(parser)
        args.debug(parser)
        args.log_file(parser)
        args.legacy(parser)
        args.blacklist(parser)
        args.force(parser)
        args.jobs(parser)
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
                description="Create a new empty database")

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
        args.query(parser)
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
        args.cookie(parser)
        args.query(parser)
        args.targets(parser)
        args.atos_lib.groupname(parser)
        args.refid(parser)
        args.atos_lib.frontier(parser)
        args.atos_lib.table(parser)
        args.atos_lib.reverse(parser)
        return parser

    @staticmethod
    def atos_lib_push(parser=None):
        """ atos lib push arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-lib-push",
                                        description="ATOS lib tool")

        args.configuration_path(parser, ("-C", "--C1"))
        args.atos_lib.remote_configuration_path(parser)
        args.query(parser)
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
        args.query(parser)
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
        args.targets(parser)
        args.query(parser)
        args.refid(parser)
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
        args.query(parser)
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
        args.atos_opt.profile(parser)
        args.reuse(parser)
        args.record(parser)
        args.remote_path(parser, ("-b", "--remote_path"))
        args.useprofile(parser)
        args.nbruns(parser)
        args.options(parser)
        args.cookie(parser)
        args.debug(parser)
        args.log_file(parser)
        args.legacy(parser)
        args.blacklist(parser)
        args.force(parser, ("--force",))
        args.jobs(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_graph(parser=None):
        """ atos graph arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-graph",
                                        description="ATOS graph tool")
        args.atos_graph.outfile(parser)
        args.atos_graph.hide(parser)
        args.id(parser)
        args.atos_graph.follow(parser)
        args.atos_graph.correl(parser)
        args.atos_graph.heat(parser)
        args.atos_graph.highlight(parser)
        args.atos_graph.frontier(parser)
        args.atos_graph.xd(parser)
        args.atos_graph.anonymous(parser)
        args.atos_graph.labels(parser)
        args.tradeoffs(parser)
        args.targets(parser)
        args.refid(parser)
        args.atos_graph.filter(parser)
        args.query(parser)
        args.configuration_path(parser)
        args.atos_graph.configuration_pathes(parser)
        args.atos_graph.xlim(parser)
        args.atos_graph.ylim(parser)
        args.atos_graph.cookie(parser)
        args.atos_graph.dbfile(parser)
        args.dryrun(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_generator(parser=None):
        """ atos gen arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-generator",
                                        description="ATOS gen tool")
        args.configuration_path(parser)
        args.base_variants(parser)
        args.nbiters(parser)
        args.per_func_nbiters(parser)
        args.seed(parser)
        args.tradeoffs(parser)
        args.extra_arguments(parser)
        args.atos_generator.generator(parser)
        args.optim_levels(parser)
        args.optim_variants(parser)
        args.cookie(parser)
        args.reuse(parser)
        args.debug(parser)
        args.log_file(parser)
        args.quiet(parser)
        args.dryrun(parser)
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
        args.atos_play.ref(parser, ("--ref",))
        args.atos_play.localid(parser)
        args.variant(parser)
        group = parser.add_mutually_exclusive_group()
        args.atos_play.printconfig(group)
        args.atos_play.printvariant(group)
        args.atos_play.printtable(group)
        args.atos_play.reverse(parser)
        args.id(parser)
        args.options(parser)
        args.targets(parser, ("--targets",))
        args.refid(parser)
        args.atos_graph.cookie(parser)
        args.atos_graph.filter(parser, ("--filter",))
        args.query(parser, ("--query",))
        args.debug(parser)
        args.log_file(parser)
        args.legacy(parser)
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
        args.log_file(parser)
        args.legacy(parser)
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
        args.size_cmd(parser)
        args.time_cmd(parser)
        args.legacy(parser)
        args.force(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.size_cmd(parser)
        args.time_cmd(parser)
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
        args.log_file(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_run_profile(parser=None):
        """ atos run profile arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-run-profile",
                                        description="ATOS run profile tool")
        args.command(parser)
        args.configuration_path(parser)
        prof_group = parser.add_mutually_exclusive_group()
        args.useprofile(prof_group)
        args.genprofile(prof_group)
        args.options(parser)
        args.debug(parser)
        args.log_file(parser)
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
        args.size_cmd(parser)
        args.time_cmd(parser)
        args.nbruns(parser)
        args.cookie(parser)
        args.atos_replay.no_ref(parser)
        args.atos_replay.variants(parser)
        args.debug(parser)
        args.log_file(parser)
        args.quiet(parser)
        args.dryrun(parser, ("--dryrun",))
        args.version(parser)
        return parser

    @staticmethod
    def atos_cookie(parser=None):
        """ atos cookie arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-cookie",
                                        description="ATOS cookie generator")
        args.cookie(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_config(parser=None):
        """ atos config arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-config",
                                        description="ATOS config generator")
        args.configuration_path(parser)
        args.atos_config.compiler(parser)
        args.atos_config.printcfg(parser)
        args.atos_config.ppflags(parser)
        args.debug(parser)
        args.version(parser)
        return parser

    @staticmethod
    def atos_web(parser=None):
        """ atos web arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(prog="atos-web",
                                        description="ATOS web tool")

        args.atos_web.server(parser)

        subs = parser.add_subparsers(
            title="atos web commands",
            dest="subcmd_web",
            description="see short description of commands below",
            help="available atos web commands")

        sub = subs.add_parser("project", help="Manage projects")
        parsers.atos_web_project(sub)

        sub = subs.add_parser("experiment", help="Manage experiments")
        parsers.atos_web_experiment(sub)

        sub = subs.add_parser("cookie", help="Manage cookies")
        parsers.atos_web_cookie(sub)

        sub = subs.add_parser("target", help="Manage targets")
        parsers.atos_web_target(sub)

        sub = subs.add_parser("run", help="Manage runs")
        parsers.atos_web_run(sub)

        return parser

    @staticmethod
    def atos_web_project(parser=None):
        """ atos web project arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-web-project",
                description="Manage web projects")

        args.atos_web.operation(parser)
        return parser

    @staticmethod
    def atos_web_experiment(parser=None):
        """ atos web experiment arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-web-experiment",
                description="Manage web experiments")

        args.atos_web.operation(parser)
        args.atos_web.project(parser)
        return parser

    @staticmethod
    def atos_web_cookie(parser=None):
        """ atos web cookie arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-web-cookie",
                description="Manage web cookies")

        args.atos_web.project(parser)
        args.atos_web.experiment(parser)
        args.configuration_path(parser)
        return parser

    @staticmethod
    def atos_web_target(parser=None):
        """ atos web target arguments parser factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-web-target",
                description="Manage web targets")

        args.atos_web.operation(parser)
        args.atos_web.project(parser)
        args.atos_web.experiment(parser)
        return parser

    @staticmethod
    def atos_web_run(parser=None):
        """ atos web run argument parsers factory. """
        if parser == None:
            parser = ATOSArgumentParser(
                prog="atos-web-run",
                description="Manage web runs")

        args.atos_web.operation(parser)
        args.atos_web.project(parser)
        args.atos_web.experiment(parser)
        args.atos_web.target(parser)
        args.configuration_path(parser)

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
    def legacy(parser, args=("--legacy",)):
        parser.add_argument(
            *args,
             action="store_true",
             help="use legacy scheme for audit and exploration")

    @staticmethod
    def blacklist(parser, args=("--blacklist",)):
        parser.add_argument(
            *args,
             action="store_true",
             help="initialize the objects blacklist automatically")

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
    def ccregexp(parser, args=("--ccregexp",)):
        parser.add_argument(
            *args,
             dest="ccregexp",
             help="specify the compiler tools basename regexp",
             default=globals.DEFAULT_CCREGEXP)

    @staticmethod
    def ccname(parser, args=("--ccname",)):
        parser.add_argument(
            *args,
             dest="ccname",
             help="specify the compiler basename, default to CCREGEXP")

    @staticmethod
    def ldregexp(parser, args=("--ldregexp",)):
        parser.add_argument(
            *args,
             dest="ldregexp",
             help="specify the linker tools basename regexp",
             default=globals.DEFAULT_LDREGEXP)

    @staticmethod
    def ldname(parser, args=("--ldname",)):
        parser.add_argument(
            *args,
             dest="ldname",
             help="specify the linker basename, defaults to LDREGEXP")

    @staticmethod
    def arregexp(parser, args=("--arregexp",)):
        parser.add_argument(
            *args,
             dest="arregexp",
             help="specify the archivers basename regexp",
             default=globals.DEFAULT_ARREGEXP)

    @staticmethod
    def arname(parser, args=("--arname",)):
        parser.add_argument(
            *args,
             dest="arname",
             help="specify the archiver basename, defaults to ARREGEXP")

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
    def size_cmd(parser, args=("--size-cmd",)):
        parser.add_argument(
            *args,
             dest="size_cmd",
             help="if specified, overrides bintutils size command "
             "[default: %s]" % globals.DEFAULT_SIZE_CMD)

    @staticmethod
    def time_cmd(parser, args=("--time-cmd",)):
        parser.add_argument(
            *args,
             dest="time_cmd",
             help="if specified, overrides posix time command "
             "[default: %s]" % globals.DEFAULT_TIME_CMD)

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
    def log_file(parser, args=("--log-file",)):
        parser.add_argument(
            *args,
             dest="log_file",
             help="log file for debug mode, defaults to stderr")

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
                             help="use to identify results")

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
             help="number of iterations for per target exploration",
             default=100)

    @staticmethod
    def per_func_nbiters(parser, args=("-N", "--per-func-nbiters")):
        parser.add_argument(
            *args,
             dest="per_func_nbiters",
             type=int,
             help="number of exploration for per function/file exploration",
             default=None)

    @staticmethod
    def flags(parser, args=("-F", "--flags")):
        parser.add_argument(
            *args,
             dest="flags_file",
             help="flags list filename",
             default=None)

    @staticmethod
    def optim_levels(parser, args=("--optim-levels",)):
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

    @staticmethod
    def prof_script(parser, args=("-p", "--profile-script")):
        parser.add_argument(*args,
                             dest="prof_script",
                             help="script to get profile information")

    @staticmethod
    def reuse(parser, args=("--reuse",)):
        parser.add_argument(*args,
                             dest="reuse",
                             action='store_true',
                             help="reuse existing results")

    @staticmethod
    def jobs(parser, args=("-j", "--jobs")):
        parser.add_argument(
            *args,
             dest="jobs",
             type=int,
             help="use JOBS parallel thread when possible for building",
             default=globals.DEFAULT_BUILD_JOBS)

    @staticmethod
    def targets(parser, args=("-t", "--targets")):
        parser.add_argument(
            *args,
             dest="targets",
             help="target list")

    @staticmethod
    def refid(parser, args=("-r", "--refid")):
        parser.add_argument(
            *args,
             dest="refid",
             help="reference variant id",
             default="REF")

    @staticmethod
    def query(parser, args=("-q", "--query")):
        parser.add_argument(*args,
                             dest="query",
                             help="results query values")

    @staticmethod
    def extra_arguments(parser, args=("--extra-arg",)):
        parser.add_argument(
            *args,
             dest="extra_args",
             action='append',
             help="argument for generator ('key=value')")

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
        def no_run(parser, args=("-N", "--no-run")):
            parser.add_argument(
                *args,
                 dest="no_run", action='store_true', default=False,
                 help="do not run reference configuration")

    class atos_lib:
        """ Namespace for non common atos lib arguments. """

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
        def groupname(parser, args=("-g", "--group_name")):
            parser.add_argument(
                *args,
                 dest="group_name",
                 help="target group name")

        @staticmethod
        def frontier(parser, args=("-f", "--frontier")):
            parser.add_argument(
                *args,
                 dest="frontier",
                 help="only print frontier points",
                 action="store_true")

        @staticmethod
        def table(parser, args=("--table",)):
            parser.add_argument(
                *args,
                 dest="table",
                 help="output textual table form",
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
        def profile(parser, args=("--profile",)):
            parser.add_argument(*args,
                                 dest="profile",
                                 action='store_true',
                                 help="run in profiling mode")

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

        @staticmethod
        def printtable(parser, args=("-T", "--printtable")):
            parser.add_argument(*args,
                                 dest="printtable",
                                 action='store_true',
                                 help="print results table only")

        @staticmethod
        def reverse(parser, args=("-X", "--reverse")):
            parser.add_argument(
                *args,
                 dest="reverse",
                 help="swap line/columns of results table",
                 action="store_true")

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

        @staticmethod
        def no_ref(parser, args=("--no-ref",)):
            parser.add_argument(
                *args,
                 dest="no_ref", action='store_true', default=False,
                 help="do not run reference")

        @staticmethod
        def variants(parser):
            parser.add_argument(
                "variants",
                nargs=argparse.REMAINDER,
                help="identifiers of variants")

    class atos_explore:
        """ Namespace for non common atos-explore-* arguments. """

        @staticmethod
        def file_by_file(parser, args=("-f", "--file-by-file")):
            parser.add_argument(
                *args,
                 dest="file_by_file",
                 action='store_true',
                 help="force file-by-file exploration",
                 default=False)

        @staticmethod
        def hot_threshold(parser, args=("-x", "--hot-th")):
            parser.add_argument(
                *args,
                 dest="hot_th",
                 type=int,
                 help="hot functions treshold percentage",
                 default=70)

        @staticmethod
        def cold_options(parser, args=("-Y", "--cold-opts")):
            parser.add_argument(
                *args,
                 dest="cold_opts",
                 help="cold functions options",
                 default="-Os")

        @staticmethod
        def cold_attributes(parser, args=("-Z", "--cold-attrs")):
            parser.add_argument(
                *args,
                 dest="cold_attrs",
                 help="cold functions attributes",
                 default="noinline cold")

        @staticmethod
        def genetic(parser, args=("--genetic",)):
            parser.add_argument(
                *args, dest="genetic", action="store_true",
                 help="use genetic exploration")

        @staticmethod
        def random(parser, args=("--random",)):
            parser.add_argument(
                *args, dest="random", action="store_true",
                 help="use random flags exploration")

        @staticmethod
        def generations(parser, args=("--generations",)):
            parser.add_argument(
                *args,
                 dest="generations",
                 help="number of generations",
                 default="10")

        @staticmethod
        def flags(parser, args=("-F", "--flags")):
            parser.add_argument(
                *args, action='append',
                 dest="flags_files",
                 help="flags list filenames",
                 default=None)

        @staticmethod
        def mutate_prob(parser, args=("--mutate-prob",)):
            parser.add_argument(
                *args,
                 dest="mutate_prob", type=float, default=0.3,
                 help="mutation probability")

        @staticmethod
        def mutate_rate(parser, args=("--mutate-rate",)):
            parser.add_argument(
                *args,
                 dest="mutate_rate", type=float, default=0.3,
                 help="mutation rate")

        @staticmethod
        def mutate_remove(parser, args=("--mutate-remove-rate",)):
            parser.add_argument(
                *args,
                 dest="mutate_remove", type=float, default=0.1,
                 help="mutation remove rate")

        @staticmethod
        def evolve_rate(parser, args=("--evolve-rate",)):
            parser.add_argument(
                *args,
                 dest="evolve_rate", type=float, default=0.3,
                 help="evolve rate")

        @staticmethod
        def nbpoints(parser, args=("--nbpoints",)):
            parser.add_argument(
                *args,
                 dest="nbpoints",
                 type=int, default=None,
                 help="number of selected points for each tradeoff")

    class atos_generator:
        """ Namespace for non common atos-generator arguments. """

        @staticmethod
        def generator(parser, args=("--generator",)):
            parser.add_argument(
                *args,
                 dest="generator",
                 help="generator used for exploration")

    class atos_graph:
        """ Namespace for non common atos-graph arguments. """

        @staticmethod
        def outfile(parser, args=("-o", "--outfile")):
            parser.add_argument(
                *args,
                 dest="outfile", help="output file name")

        @staticmethod
        def hide(parser, args=("-d", "--hide")):
            parser.add_argument(
                *args,
                 dest="show", action="store_false",
                 help="do not show resulting graph")

        @staticmethod
        def follow(parser, args=("--follow",)):
            parser.add_argument(
                *args,
                 dest="follow", action="store_true",
                 help="continuously update graph with new results")

        @staticmethod
        def correl(parser, args=("--correl",)):
            parser.add_argument(
                *args,
                 dest="correlation_graph", action="store_true",
                 help="show correlation graph")

        @staticmethod
        def heat(parser, args=("--heat",)):
            parser.add_argument(
                *args,
                 dest="heat_graph", action="store_true",
                 help="show heat graph")

        @staticmethod
        def highlight(parser, args=("-H", "--highlight")):
            parser.add_argument(
                *args,
                 dest="highlight",
                 help="highlight points given a regexp")

        @staticmethod
        def frontier(parser, args=("-F", "--frontier")):
            parser.add_argument(
                *args,
                 dest="frontier_only", action="store_true",
                 help="display only frontier points")

        @staticmethod
        def xd(parser, args=("-x",)):
            parser.add_argument(
                *args,
                 dest="xd", type=int, default=0,
                 help="highlight different options sets -x[0123]")

        @staticmethod
        def anonymous(parser, args=("-a", "--anonymous")):
            parser.add_argument(
                *args,
                 dest="anonymous", action="store_true",
                 help="anonymous configuration, no configuration id on graph")

        @staticmethod
        def labels(parser, args=("-l", "--cfglbl")):
            parser.add_argument(
                *args,
                 dest="labels",
                 help="atos-configurations labels")

        @staticmethod
        def filter(parser, args=("-f", "--filter")):
            parser.add_argument(
                *args,
                 dest="filter",
                 help="filter in the points given by the regexp")

        @staticmethod
        def configuration_pathes(parser, args=("-D",)):
            parser.add_argument(
                *args,
                 dest="configuration_pathes", action='append',
                 help="additional configuration pathes")

        @staticmethod
        def xlim(parser, args=("--xlim",)):
            parser.add_argument(
                *args,
                 dest="xlim",
                 help="defines the x axis limits")

        @staticmethod
        def ylim(parser, args=("--ylim",)):
            parser.add_argument(
                *args,
                 dest="ylim",
                 help="defines the y axis limits")

        @staticmethod
        def cookie(parser, args=("--cookie",)):
            parser.add_argument(
                *args,
                 dest="cookies",
                 action='append',
                 help="cookies used for results filtering")

        @staticmethod
        def dbfile(parser):
            parser.add_argument(
                dest="dbfile",
                nargs=argparse.REMAINDER,
                help="results file")

    class atos_config:
        """ Namespace for non common atos-config arguments. """

        @staticmethod
        def ppflags(parser, args=("-D",)):
            parser.add_argument(
                *args,
                 dest="flags", action='append',
                 help="additional preprocessing flags")

        @staticmethod
        def compiler(parser, args=("--compiler",)):
            parser.add_argument(
                *args,
                 dest="compilers", action='append',
                 help="path to compiler, "
                 "defaults compilers listed in CONFIGURATION/compilers")

        @staticmethod
        def printcfg(parser, args=("--print-cfg",)):
            parser.add_argument(
                *args,
                 dest="print_cfg", action='store_true',
                 help="only print compiler configuration")

    class atos_web:
        """ Namespace for non common atos-web arguments. """

        @staticmethod
        def server(parser, args=("--server",)):
            parser.add_argument(
                *args,
                dest="server",
                help="Remote server (server:port)",
                required=True)

        @staticmethod
        def operation(parser):
            parser.add_argument(
                "operation",
                nargs=argparse.REMAINDER,
                help="operations to realize, should be 'create', "
                     "'list' or 'details'")

        @staticmethod
        def project(parser, args=("--project",)):
            parser.add_argument(
                *args,
                dest="project",
                type=int,
                help="Current project identifier",
                required=True)

        @staticmethod
        def experiment(parser, args=("--experiment",)):
            parser.add_argument(
                *args,
                dest="experiment",
                type=int,
                help="Current experiment identifier",
                required=True)

        @staticmethod
        def target(parser, args=("--target",)):
            parser.add_argument(
                *("--target",),
                dest="target",
                type=int,
                help="Current target identifier",
                required=True)
