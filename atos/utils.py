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

import sys, os
import re

import globals
import arguments
import atos_lib
import generators
import process
import profile
from logger import debug, warning, error, message, info

_at_toplevel = None

def invoque(tool, args, **kwargs):
    """
    Dispatcher that invoques the given tool and returns.
    This function can't be called directly from top level
    tools, use execute() in that case.
    """
    functions = {
        "atos": run_atos,
        "atos-help": run_atos_help,
        "atos-audit": run_atos_audit,
        "atos-build": run_atos_build,
        "atos-deps": run_atos_deps,
        "atos-explore": run_atos_explore,
        "atos-init": run_atos_init,
        "atos-opt": run_atos_opt,
        "atos-play": run_atos_play,
        "atos-profile": run_atos_profile,
        "atos-raudit": run_atos_raudit,
        "atos-run": run_atos_run,
        "atos-replay": run_atos_replay,
        "atos-run-profile": run_atos_run_profile,
        "atos-explore-inline": run_atos_explore_inline,
        "atos-explore-loop": run_atos_explore_loop,
        "atos-explore-optim": run_atos_explore_optim,
        "atos-explore-acf": run_atos_explore_acf,
        "atos-cookie": run_atos_cookie,
        "atos-lib": run_atos_lib,
        "atos-gen": run_atos_gen,
        }

    def tool_args(tool, args, **kwargs):
        """ Returns the args arguments modified by kwargs. """
        tool_args = arguments.argparse.Namespace()
        for action in arguments.parser(tool)._actions:
            if action.dest is None: continue
            tool_args.__dict__[action.dest] = action.default
        tool_args.__dict__.update(vars(args))
        tool_args.__dict__.update(kwargs)
        return tool_args

    def dryrun_tool(tool, args, **kwargs):
        """ Does not run the tool, outputs the tool command line. """
        dest_to_opt = dict(map(
                lambda x: (x.dest, x),
                arguments.parser(tool)._actions))
        arg_list, remainder = [tool], []
        for key, value in tool_args(tool, args, **kwargs).__dict__.items():
            if key == 'dryrun' or key not in dest_to_opt.keys():
                continue
            default = dest_to_opt[key].default
            if value == default: continue
            # default can be False while action.default is None
            if default is False and not bool(value): continue
            if not dest_to_opt[key].option_strings:
                remainder.extend(value)
                continue
            option_string = dest_to_opt[key].option_strings[-1]
            if isinstance(value, list):
                map(lambda x: arg_list.extend([option_string, x]), value)
            else:
                arg_list.append(option_string)
                if dest_to_opt[key].nargs != 0: arg_list.append(str(value))

        process.debug(process.list2cmdline(arg_list + remainder))
        return 0

    def run_tool(tool, args, **kwargs):
        """ Runs the tool, given the top level args and kwargs modifier. """
        return functions[tool](tool_args(tool, args, **kwargs))

    global _at_toplevel
    assert(_at_toplevel != None)
    # local dryrun setting is not supported as the process module
    # depends upon the global setting
    assert(kwargs.get('dryrun') == None)

    dryrun = 'dryrun' in vars(args) and args.dryrun and not _at_toplevel
    _at_toplevel = False
    if dryrun:
        status = dryrun_tool(tool, args, **kwargs)
    else:
        status = run_tool(tool, args, **kwargs)
    return status

def execute(tool, args):
    """
    Executes the invoque dispatcher and exits.
    This function cannot be called from within invoque.
    """
    global _at_toplevel
    assert(_at_toplevel == None)
    _at_toplevel = True
    sys.exit(invoque(tool, args))

def run_atos(args):
    """
    Top level atos utility implementation.
    This function is only used as a wrapper for subcommand
    invoque(), thus we reset the _at_toplevel marker.
    """
    global _at_toplevel
    assert(_at_toplevel == False)
    _at_toplevel = True
    return invoque("atos-" + args.subcmd, args)

def run_atos_help(args):
    """ ATOS help tool implementation. """
    if not args.topics:
        # Output rst form for default help page
        print "==========================================="
        print "ATOS auto tuning optimization system manual"
        print "==========================================="
        print
        print "Browse the manual with the following commands:"
        print
        print "  atos help intro    : displays ATOS short introduction."
        print "  atos help tutorial : displays ATOS tutorial."
        print
        print \
            "  atos help COMMAND  : display manual for the given atos COMMAND."
        print \
            "                      Execute ``atos -h`` for available COMMANDs."
        print
        return 0
    for topic in args.topics:
        if args.text:
            status = atos_lib.help_text(topic)
        elif args.man:
            status = atos_lib.help_man(topic)
        else:
            status = atos_lib.help_man(topic)
            if status != 0:
                status = atos_lib.help_text(topic)
        if status != 0:
            print >>sys.stderr, "atos-help: " + \
                "manual not found for topic: " + topic + "."
            print >>sys.stderr, "Execute 'atos help' for available topics."
            return 1
    return 0

def run_atos_audit(args):
    """ ATOS audit tool implementation. """

    message("Auditing build...")

    ccregexp = args.ccname and ('^%s$' % args.ccname) or args.ccregexp
    output_file = args.output_file or os.path.join(
        args.configuration_path, "build.audit")

    process.commands.mkdir(args.configuration_path)
    process.commands.touch(output_file)

    build_sh = os.path.join(args.configuration_path, "build.sh")
    atos_lib.generate_script(build_sh, args.command)
    force_sh = os.path.join(args.configuration_path, "build.force")
    with open(force_sh, 'w') as file_force:
        file_force.write(str(int(args.force)))

    command = atos_lib.proot_command(
        PROOT_IGNORE_ELF_INTERPRETER=1,
        PROOT_ADDON_CC_DEPS=1,
        PROOT_ADDON_CC_DEPS_OUTPUT=output_file,
        PROOT_ADDON_CC_DEPS_CCRE=ccregexp) + args.command
    status = process.system(command, print_output=True)
    return status

def run_atos_build(args):
    """ ATOS build tool implementation. """

    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    logf = atos_lib.open_atos_log_file(
        args.configuration_path, "build", variant)

    message("Building variant %s [%s]..." %
            (variant, atos_lib.hashid(variant)))
    logf.write("Building variant %s\n" % variant)

    driver_env = {}
    compile_options = args.options and args.options.split() or []
    link_options = []

    atos_driver = os.getenv("ATOS_DRIVER")
    if not atos_driver:
        atos_driver = os.path.join(globals.BINDIR, "atos-driver")
    assert atos_driver and os.path.isfile(atos_driver)

    opt_rebuild = args.force
    build_force = os.path.join(args.configuration_path, "build.force")
    if not opt_rebuild and os.path.isfile(build_force):
        opt_rebuild = int(open(build_force).read().strip())

    if args.gopts != None or args.uopts != None:
        pvariant = atos_lib.variant_id(args.gopts or args.uopts or "")
        profile_path = os.path.abspath(args.path) if args.path else \
            atos_lib.get_profile_path(args.configuration_path, pvariant)

    if args.gopts != None:
        process.commands.rmtree(profile_path)
        process.commands.mkdir(profile_path)
        with open(os.path.join(profile_path, "variant.txt"), "w") as variantf:
            variantf.write(pvariant)
        compile_options += ["-fprofile-generate"]
        link_options += ["-lgcov", "-lc"]

        remote_profile_path = args.remote_path
        if not remote_profile_path:
            remote_profile_path = atos_lib.get_config_value(
                args.configuration_path, 'default_values.remote_profile_path')
        if remote_profile_path:
            profile_path = remote_profile_path
        driver_env.update({"PROFILE_DIR": profile_path})

    if args.uopts != None:
        compile_options += ["-fprofile-use", "-fprofile-correction",
                            "-Wno-error=coverage-mismatch"]
        driver_env.update({"PROFILE_DIR": profile_path})

    if args.gopts != None or args.uopts != None:
        common_profdir_prefix = atos_lib.get_config_value(
            args.configuration_path, 'build_opts.common_profdir_prefix', '')
        driver_env.update({"COMMON_PROFILE_DIR_PREFIX": common_profdir_prefix})
        driver_env.update({"PROFILE_DIR_OPT": "-fprofile-dir"})

    if "-flto" in compile_options:
        lto_flags = atos_lib.get_config_value(
            args.configuration_path, 'build_opts.lto_flags', '')
        driver_env.update({"ALDLTOFLAGS": lto_flags})

    driver_env.update({"ACFLAGS": " ".join(compile_options)})
    driver_env.update({"ALDFLAGS": " ".join(link_options)})
    # useless for now
    driver_env.update({"ALDSOFLAGS": ""})
    driver_env.update({"ALDMAINFLAGS": ""})

    # add driver build variables to environment
    map(lambda (k, v): os.putenv(k, str(v)), driver_env.items())

    if not args.command and not opt_rebuild:
        build_mk = os.path.join(args.configuration_path, "build.mk")
        if not os.path.isfile(build_mk):
            error("optimized build file missing: %s" % build_mk)
            error("atos-deps was not run or configuration path mismatch")
            return 1
        # if the configuration path contains a build.mk execute it
        command = ["make", "-f", build_mk, "-j", str(args.jobs),
                   "ATOS_DRIVER=" + atos_driver]
        status, output = process.system(
            atos_lib.timeout_command() + command,
            get_output=True, output_stderr=True)
    else:
        build_sh = os.path.join(args.configuration_path, "build.sh")
        if not args.command:
            if not os.path.isfile(build_sh):
                error("build script missing: %s" % build_sh)
                error("atos-build was not run or configuration path mismatch")
                return 1
        # else use proot cc_opts addon (force mode)
        ccregexp = args.ccname and ("^%s$" % args.ccname) or args.ccregexp
        command = atos_lib.proot_command(
            PROOT_IGNORE_ELF_INTERPRETER=1,
            PROOT_ADDON_CC_OPTS=1,
            # driver must be added even if there is no CC_OPTS_ARGS set
            # TODO: fix proot cc_opts plugin and remove --atos-tmp
            PROOT_ADDON_CC_OPTS_ARGS="--atos-tmp",
            PROOT_ADDON_CC_OPTS_CCRE=ccregexp,
            PROOT_ADDON_CC_OPTS_DRIVER=atos_driver)
        command.extend(args.command or [build_sh])
        status, output = process.system(
            atos_lib.timeout_command() + command,
            get_output=True, output_stderr=True)

    # remove driver build variables from environment
    map(lambda (k, v): os.unsetenv(k), driver_env.items())

    logf.write('%s\n' % output)
    if status:
        message("FAILURE while building variant %s... " % (variant))
        logf.write("FAILURE while building variant %s\n" % (variant))
        logf.close()
        return 2

    logf.write("SUCCESS building variant %s\n" % (variant))
    logf.close()
    return 0

def run_atos_deps(args):
    """ ATOS deps tool implementation. """

    # For now we include all from atos_deps, we may separate modules later
    from atos_deps import CommandDependencyListFactory
    from atos_deps import CCDEPSParser
    from atos_deps import SimpleCmdInterpreter
    from atos_deps import DependencyGraphBuilder

    input_file = args.input_file or os.path.join(
        args.configuration_path, "build.audit")
    output_file = args.output_file or os.path.join(
        args.configuration_path, "build.mk")

    targets = None
    executables = args.exes and args.exes.split() or args.executables
    if executables:
        targets = executables
    if args.last:
        targets = "last"
    if args.all:
        targets = "all"

    if targets == None:
        raise Exception("Missing target file list.")

    message("Computing build dependencies...")
    factory = CommandDependencyListFactory(
        CCDEPSParser(open(input_file)), SimpleCmdInterpreter())
    factory.build_dependencies()
    dependencies = factory.get_dependencies()
    builder = DependencyGraphBuilder(dependencies, targets)
    builder.build_graph()
    graph = builder.get_graph()

    if not args.force:
        graph.output_makefile(output_file)

    # For now only write targets if configuration dir is there
    if not os.path.isdir(args.configuration_path):
        return 0

    with open(os.path.join(args.configuration_path, "targets"), "w") as f:
        print >>f, "\n".join(
            executables if args.force else graph.get_targets())

    with open(os.path.join(args.configuration_path, "objects"), "w") as f:
        print >>f, "\n".join(graph.get_objects())

    with open(os.path.join(args.configuration_path, "compilers"), "w") as f:
        print >>f, '\n'.join(graph.get_compilers())

    # list of options that should be passed to linker in case of LTO build
    config_file = os.path.join(args.configuration_path, 'config.json')

    atos_lib.json_config(config_file).add_value(
        "build_opts.lto_flags", ' '.join(graph.get_lto_opts()))

    atos_lib.json_config(config_file).add_value(
        "build_opts.common_profdir_prefix",
        graph.common_relative_profdir_prefix())

    return 0

def run_atos_explore(args):
    """ ATOS explore tool implementation. """

    invoque("atos-init", args)

    for opt_level in ['-O2', '-Os', '-O3']:
        for opts in ['', '-flto', '-funroll-loops', '-flto -funroll-loops']:
            options = ' '.join([opt_level, opts])
            status = invoque("atos-build", args, options=options)
            if status == 0:
                invoque("atos-run", args, record=True, options=options)

        status = invoque("atos-profile", args, options=opt_level)
        if status != 0: continue  # skip profile variants

        for opts in ['', '-flto', '-funroll-loops', '-flto -funroll-loops']:
            options = ' '.join([opt_level, opts])
            status = invoque(
                "atos-build", args, uopts=opt_level, options=options)
            if status == 0:
                status = invoque("atos-run", args, record=True,
                                 uopts=opt_level, options=options)

    message("Completed.")
    return 0

def run_atos_init(args):
    """ ATOS init tool implementation. """

    executables = args.exes and args.exes.split() or args.executables
    if args.force and not args.results_script and not executables:
        error("when using forced mode (-f) with no custom results script (-t)"
              " the list of executables must be specified (-e option)")
        return 1

    process.commands.mkdir(args.configuration_path)

    if args.clean:
        if args.build_script:
            message("Cleaning build audit...")
            process.commands.unlink('%s/build.mk' % args.configuration_path)
            process.commands.unlink('%s/build.sh' % args.configuration_path)
            process.commands.unlink('%s/build.force' % args.configuration_path)
            process.commands.unlink('%s/build.audit' % args.configuration_path)
            process.commands.unlink('%s/config.json' % args.configuration_path)
        if args.run_script:
            message("Cleaning run audit...")
            process.commands.unlink('%s/run.sh' % args.configuration_path)
            process.commands.unlink('%s/run.audit' % args.configuration_path)
        message("Cleaning all profiles...")
        process.commands.rmtree('%s/profiles' % args.configuration_path)
        process.commands.rmtree('%s/oprofiles' % args.configuration_path)
        message("Cleaning all results...")
        process.commands.unlink('%s/results.db' % args.configuration_path)

    if args.build_script:
        status = invoque("atos-audit", args,
                         command=process.cmdline2list(args.build_script))
        if status != 0: return status
        status = invoque("atos-deps", args,
                         all=(not executables))
        if status != 0: return status
        # TODO: to be replaced by invoque(atos-config)
        command_config = [
            os.path.join(globals.BINDIR, "atos-config"),
            "-C", args.configuration_path]
        status = process.system(command_config, print_output=True)
        if status != 0: return status
    elif not os.path.isfile(
        os.path.join(args.configuration_path, "build.audit")):
        error("missing build audit, use -b option for specifying build script"
              " or use atos-audit tool")
        return 1

    config_file = os.path.join(args.configuration_path, 'config.json')

    if args.remote_path:
        atos_lib.json_config(config_file).add_value(
            "default_values.remote_profile_path", args.remote_path)

    if args.nbruns and args.nbruns != 1:
        atos_lib.json_config(config_file).add_value(
            "default_values.nb_runs", str(args.nbruns))

    if args.run_script:
        status = invoque("atos-raudit", args,
                         command=process.cmdline2list(args.run_script))
        if status != 0: return status
    elif not os.path.isfile(
        os.path.join(args.configuration_path, "run.audit")):
        error("missing run audit, use -r option for specifying run script"
              " or use atos-raudit tool")
        return 1

    if args.prof_script:
        prof_sh = os.path.join(args.configuration_path, "profile.sh")
        atos_lib.generate_script(prof_sh, args.prof_script)

    # Record the reference if necessary
    if (args.clean or args.build_script or args.run_script) and \
            not args.no_run:
        status = invoque("atos-opt", args, record=True)
        if status != 0: return status

    return 0

def run_atos_lib(args):
    """ ATOS lib tool implementation. """

    if args.subcmd_lib == "create_db":
        if not os.path.exists(args.configuration_path):
            os.makedirs(args.configuration_path)
        if args.type == 'results_db':
            db_file = os.path.join(args.configuration_path, 'results.db')
            db = atos_lib.atos_db_file(db_file)
        elif args.type == 'json':
            db_file = os.path.join(args.configuration_path, 'results.json')
            db = atos_lib.atos_db_json(db_file)
        elif args.type == 'pickle':
            db_file = os.path.join(args.configuration_path, 'results.pkl')
            db = atos_lib.atos_db_pickle(db_file)
        else: assert 0
        if args.shared: process.commands.chmod(db_file, 0660)
        info('created new database in "%s"' % db_file)
        return 0

    elif args.subcmd_lib == "query":
        if args.configuration_path == '-':
            results = atos_lib.results_filter(
                atos_lib.atos_client_db.db_load(sys.stdin),
                atos_lib.strtoquery(args.query))
        else:
            client = atos_lib.atos_client_db(
                atos_lib.atos_db.db(args.configuration_path))
            results = client.query(atos_lib.strtoquery(args.query))

        atos_lib.pprint_list(results, text=args.text)
        return 0

    elif args.subcmd_lib == "speedups":
        client = atos_lib.atos_client_results(
            atos_lib.atos_db.db(args.configuration_path),
            args.targets and atos_lib.strtolist(args.targets),
            atos_lib.strtoquery(args.query), args.group_name)

        if args.ref: client.compute_speedups(args.ref)

        if args.tradeoffs:
            atos_lib.pprint_list(
                map(lambda x: client.tradeoff(x).dict(), args.tradeoffs))
        else:
            atos_lib.pprint_list(client.get_results(args.frontier))
        return 0

    elif args.subcmd_lib == "push":
        db = atos_lib.atos_db.db(args.configuration_path)
        results = atos_lib.atos_client_db.db_query(
            db, atos_lib.strtoquery(args.query),
            atos_lib.strtodict(args.replacement))

        if args.remote_configuration_path == '-':
            status, output = atos_lib.atos_client_db.db_dump(
                results, sys.stdout)
        else:
            other_db = atos_lib.atos_db.db(args.remote_configuration_path)
            status, output = atos_lib.atos_client_db.db_transfer(
                other_db, results, args.force)

        if status:
            info('exported %d results' % (output))
            return 0
        else:
            error(output)
            return 1

    elif args.subcmd_lib == "pull":
        db = atos_lib.atos_db.db(args.configuration_path)

        if args.remote_configuration_path == '-':
            results = atos_lib.atos_client_db.db_load(sys.stdin)
        else:
            other_db = atos_lib.atos_db.db(args.remote_configuration_path)
            results = atos_lib.atos_client_db.db_query(
                other_db, atos_lib.strtoquery(args.query),
                atos_lib.strtodict(args.replacement))

        status, output = atos_lib.atos_client_db.db_transfer(
            db, results, args.force)

        if status:
            info('imported %d results' % (output))
            return 0
        else:
            error(output)
            return 1

    elif args.subcmd_lib == "report":
        db = atos_lib.atos_db.db(args.configuration_path)

        # targets 'group1:targ1,targ2,targ3+group2:targ4,targ5+targ6'
        group_targets, group_names = [], []
        if args.targets:
            for group in args.targets.split('+'):
                spl = group.split(':')
                if len(spl) > 1:
                    group_targets += [spl[1].split(',')]
                    group_names += [spl[0]]
                else:
                    group_targets += [spl[0].split(',')]
                    group_names += ['+'.join(group_targets[-1])]
        else:
            results = db.get_results(atos_lib.strtoquery(args.query))
            group_targets = sorted(
                [list(set(atos_lib.results_filter(results, '$[*].target')))])
            group_names = map('+'.join, group_targets)

        # groups not supported in stdev mode
        assert (args.mode != 'stdev') or all(
            map(lambda g: len(g) == 1, group_targets))

        # results
        all_results = {}
        for num in range(len(group_targets)):
            targets, name = group_targets[num], group_names[num]
            client = atos_lib.atos_client_results(
                db, targets, atos_lib.strtoquery(args.query), name)
            if args.ref: client.compute_speedups(args.ref)
            all_results[group_names[num]] = client.results

        # variants
        variants = args.variants and args.variants.split(',') or sorted(list(
            reduce(lambda acc, s: acc.intersection(s),
                   map(lambda v: set(v.keys()), all_results.values()))))

        table = (args.mode != 'stdev') and [[''] + group_names] or []

        for variant in variants:

            table += [[variant]]
            if args.mode == 'stdev':
                table[-1] += ['AVG', 'NOISE', 'STDEV']

            for target in group_names:

                if args.mode == 'speedup':
                    table[-1] += ['%.0f %+6.1f%%' % (
                            all_results[target][variant].time,
                            all_results[target][variant].speedup * 100)]

                elif args.mode == 'sizered':
                    table[-1] += ['%.0f %+6.1f%%' % (
                            all_results[target][variant].size,
                            all_results[target][variant].sizered * 100)]

                elif args.mode == 'stdev':
                    table += [[target]]
                    results = map(
                        lambda r: r.time,
                        all_results[target][variant]._results[0]._results)
                    avg_res, min_res, max_res = (
                        atos_lib.average(results), min(results), max(results))
                    max_avg_diff = max(avg_res - min_res, max_res - avg_res)
                    table[-1] += ['%.2f' % avg_res]
                    table[-1] += ['%.2f%%' % ((max_avg_diff / avg_res) * 100)]
                    table[-1] += ['%.2f%%' % (
                            (atos_lib.standard_deviation(results) / avg_res)
                        * 100)]

                else: assert 0

            if args.mode == 'stdev': table += [None]

        atos_lib.pprint_table(table, reverse=args.reverse)
        return 0

    elif args.subcmd_lib == "add_result":
        result = atos_lib.strtodict(args.result)

        if args.configuration_path == '-':
            print atos_lib.atos_db_file.entry_str(result),

        else:
            db = (args and atos_lib.atos_db_file(args[0])
                  or atos_lib.atos_db.db(args.configuration_path))
            status, output = atos_lib.atos_client_db(db).add_result(result)
            if not status:
                error(output)
                return 1
        return 0

    elif args.subcmd_lib == "config":
        config_file = os.path.join(args.configuration_path, 'config.json')

        if args.query:
            client = atos_lib.json_config(config_file)
            results = client.query(atos_lib.strtoquery(args.query))
            if args.uniq: results = list(set(results))
            atos_lib.pprint_list(results, text=args.text)

        elif args.add_item:
            client = atos_lib.json_config(config_file)
            key, value = args.add_item.split(':')
            client.add_value(key, value)

        elif args.get_item:
            if os.path.isfile(config_file):
                client = atos_lib.json_config(config_file)
                print client.get_value(args.get_item) or ''

        elif args.add_cpl:
            client = atos_lib.json_config(config_file)
            client.add_compiler(args.add_cpl)

        elif args.cpl_flags:
            if os.path.isfile(config_file):
                client = atos_lib.json_config(config_file)
                print client.flags_for_flagfiles()

        else: pass
        return 0

def run_atos_gen(args):
    """ ATOS gen tool implementation. """
    try:
        assert args.generator
        generator = eval('generators.%s' % args.generator)
    except:
        error("unknown generator '%s'" % args.generator)
        return 1

    gen_args = arguments.argparse.Namespace()
    gen_args.__dict__.update(vars(args))

    for arg in args.args or []:
        key, value = arg.split('=')
        gen_args.__dict__[key] = value

    status = generators.run_exploration_loop(
        gen_args, generator=generator)

    return status

def run_atos_opt(args):
    """ ATOS opt tool implementation. """

    options = args.options or ""
    uopts = args.uopts or (args.fdo and options or None)
    if args.lto: options += " -flto"

    if args.reuse and args.profile:
        variant = atos_lib.variant_id(options, None, uopts)
        profile_path = atos_lib.get_oprofile_path(
            args.configuration_path, variant)
        if os.path.isdir(profile_path):
            for f in os.listdir(profile_path):
                filepath = os.path.join(profile_path, f)
                if os.path.isfile(filepath):
                    process.commands.copyfile(filepath, f)
            message("Skipping profile of variant %s..." % variant)
            return 0

    if args.reuse:  # do nothing if existing run results
        variant = atos_lib.variant_id(options, None, uopts)
        db = atos_lib.atos_db.db(args.configuration_path)
        results = atos_lib.atos_client_db(db).query({"variant": variant})
        if results:
            message("Skipping variant %s..." % variant)
            return 0

    if args.fdo:
        status = invoque("atos-profile", args, options=uopts, uopts=None)
        if status: return status

    status = invoque("atos-build", args, options=options, uopts=uopts)
    if status: return status

    if args.profile:
        status = invoque(
            "atos-run-profile", args, options=options, uopts=uopts)
        return status

    status = invoque("atos-run", args, options=options, uopts=uopts)
    return status

def run_atos_play(args):
    """ ATOS play tool implementation. """

    if not os.path.isdir(args.configuration_path):
        error('Configuration missing: ' + args.configuration_path)
        return 1

    try:
        with open(os.path.join(
                args.configuration_path, "targets")) as targetf:
            executables = map(lambda x: x.strip(), targetf.readlines())
    except:
        error('no target executable available in configuration')
        return 1
    target_id = args.id or atos_lib.target_id(executables)

    atos_db = atos_lib.atos_db.db(args.configuration_path)

    results = []
    if args.ref:
        results = atos_lib.atos_client_db(atos_db).query(
            {'variant': "REF", 'target': target_id})
    elif args.localid != None:
        results = atos_lib.atos_client_db(atos_db).query(
            {'target': target_id}) or []
        results = filter(
            lambda x: atos_lib.hashid(x['variant']).startswith(args.localid),
            results)
        if len(results) > 1:
            error('ambiguous local_id: %s' % args.localid)
            return 1
    else:
        tradeoffs = args.tradeoffs
        if not tradeoffs:
            if args.obj == "size":
                tradeoffs = [0.2]
            else:  # objective == "time"
                tradeoffs = [5.0]
        all_points = list(atos_lib.atos_client_results(
            atos_db, [target_id]).results.values())
        nbtr = max(1, args.nbpoints / len(tradeoffs))
        for tradeoff in tradeoffs:
            selected = atos_lib.atos_client_results.select_tradeoffs(
                all_points, tradeoff, nbtr) or []
            results.extend(selected)
            map(all_points.remove, selected)
        results = map(lambda x: x.dict(), results)

    if not results:
        error('no results found')
        return 1
    elif args.printvariant:
        for result in results:
            print result['variant']
        return 0
    elif args.printconfig:
        for result in results:
            print atos_lib.atos_db_file.entry_str(result),
        return 0
    elif len(results) > 1:
        error('more than one build requested')
        return 1
    else:
        result = results[0]
        message('Playing optimized build %s:%s...' % (
                target_id, result['variant']))
        status = invoque("atos-build", args,
                         options=result.get('conf', None),
                         uopts=result.get('uconf', None),
                         gopts=result.get('gconf', None))
        return status

def run_atos_profile(args):
    """ ATOS profile tool implementation. """

    message("Profiling...")
    options = args.options or ''

    status = invoque(
        "atos-build", args, gopts=options, options=options)
    if status: return status

    status = invoque(
        "atos-run", args, gopts=options, options=options, silent=True)
    return status

def run_atos_raudit(args):
    """ ATOS raudit tool implementation. """

    if not args.command:
        error('atos-raudit: missing run command')
        return 1

    message("Auditing run...")

    if not args.output_file:
        process.commands.mkdir(args.configuration_path)
        output_file = os.path.join(args.configuration_path, "run.audit")
        process.commands.touch(output_file)
        run_sh = os.path.join(args.configuration_path, "run.sh")
        atos_lib.generate_script(run_sh, args.command)
        if args.results_script != None:
            get_res_sh = os.path.join(args.configuration_path, "get_res.sh")
            atos_lib.generate_script(get_res_sh, args.results_script)

    status = process.system(args.command, print_output=True)
    return status

def run_atos_run_profile(args):
    """ ATOS run profile tool implementation. """

    variant = atos_lib.variant_id(
        args.options, args.gopts, args.uopts)

    # TODO: define default map & profile filenames in globals.py
    #  and add an option for fctmap file handling
    fctmap_file = "fctmap.out"
    profile_file = "oprof.out"
    profile_path = atos_lib.get_oprofile_path(
        args.configuration_path, variant)

    process.commands.unlink(profile_file)
    process.commands.rmtree(profile_path)

    message("Running profile variant %s..." % variant)

    prof_script = os.path.join(args.configuration_path, "profile.sh")
    prof_script = process.cmdline2list(args.prof_script) or [prof_script]

    status, output = process.system(
        atos_lib.timeout_command() + prof_script,
        get_output=True, output_stderr=True)

    if status or not os.path.isfile(profile_file):
        message("FAILURE while running profile variant %s..." % variant)
        return 2

    process.commands.mkdir(profile_path)
    process.commands.copyfile(
        profile_file, os.path.join(profile_path, profile_file))
    if os.path.isfile(fctmap_file):
        process.commands.copyfile(
            fctmap_file, os.path.join(profile_path, fctmap_file))

    debug("SUCCESS running profile variant %s\n" % variant)
    return 0

def run_atos_run(args):
    """ ATOS run tool implementation. """

    def get_size(executables):
        def one_size(exe):
            if not os.path.isfile(exe):
                if not os.path.isabs(exe):
                    status, exe = process.system(
                        ["/usr/bin/which", exe], get_output=True)
                else:
                    exe = None
            if not exe: return None
            status, output = process.system(
                ["/usr/bin/size", exe.strip()], get_output=True)
            if args.dryrun: return 0
            if status or not output: return None
            return int(output.splitlines()[1].split()[3])
        executables_size = map(one_size, executables)
        if None in executables_size:
            return None
        return sum(executables_size)

    def get_time():
        if remote_path and args.gopts:
            os.putenv("REMOTE_PROFILE_DIR", remote_path)
            os.putenv("LOCAL_PROFILE_DIR", atos_lib.get_profile_path(
                    args.configuration_path,
                    atos_lib.variant_id(args.gopts)))

        run_script = os.path.join(args.configuration_path, "run.sh")
        run_script = args.command or [run_script]

        status, output = process.system(
            atos_lib.timeout_command() + ["/usr/bin/time", "-p"] + run_script,
            get_output=True, output_stderr=True)

        if args.dryrun or status:
            return status, 0.0, output

        lines_output = output.splitlines()

        lines_user = filter(
            lambda x: x.startswith("user "), lines_output)
        # if existing 'time' lines in output,
        #   ignore the last one (produced by our time command)
        if len(lines_user) > 1: lines_user = lines_user[:-1]
        exe_time = sum(
            map(lambda x: float(x.split()[1]) * 1000, lines_user), 0.0)

        lines_filtered = filter(
            lambda x: not re.match("^(user|real|sys) ", x), lines_output)
        real_output = '\n'.join(lines_filtered) + '\n'

        os.unsetenv("REMOTE_PROFILE_DIR")
        os.unsetenv("LOCAL_PROFILE_DIR")
        return status, exe_time, real_output

    def output_run_results(target, variant, time, size):
        if args.silent: return
        if time is None: time = "FAILURE"
        if size is None: size = "FAILURE"
        entry = {}
        entry.update({'target': target})
        entry.update({'variant': variant})
        entry.update({'version': globals.VERSION})
        entry.update({'conf': " ".join(
                    process.cmdline2list(args.options or ''))})
        if args.uopts != None:
            entry.update({'uconf': " ".join(
                        process.cmdline2list(args.uopts))})
        if args.gopts != None:
            entry.update({'gconf': " ".join(
                        process.cmdline2list(args.gopts))})
        entry.update({'time': str(time)})
        entry.update({'size': str(size)})
        if args.cookies:
            entry.update({'cookies': ','.join(list(set(args.cookies)))})
        if args.output_file:
            db = atos_lib.atos_db_file(args.output_file)
            atos_lib.atos_client_db(db).add_result(entry)
        elif args.record:
            db = atos_lib.atos_db.db(args.configuration_path)
            atos_lib.atos_client_db(db).add_result(entry)
        else:
            print >>sys.stderr, atos_lib.atos_db_file.entry_str(entry),

    def check_failure(failure, fail_condition, fail_message):
        if failure: return failure
        if fail_condition:
            debug("CHKFAILURE [%s]" % fail_message)
        return fail_condition

    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)

    results_script = args.results_script
    if not results_script:
        get_res_sh = os.path.join(args.configuration_path, "get_res.sh")
        results_script = os.path.isfile(get_res_sh) and get_res_sh

    remote_path = args.remote_path
    if args.gopts and not remote_path:
        remote_path = atos_lib.get_config_value(
            args.configuration_path, 'default_values.remote_profile_path')

    nbruns = args.nbruns
    if nbruns is None:
        nbruns = args.gopts and 1 or atos_lib.get_config_value(
                args.configuration_path, "default_values.nb_runs", 1)

    if results_script:
        executables, target_id = None, None
    else:
        try:
            with open(os.path.join(
                    args.configuration_path, "targets")) as targetf:
                executables = map(lambda x: x.strip(), targetf.readlines())
        except:
            error('no target executable available in configuration')
            return 1
        target_id = args.id or atos_lib.target_id(executables)

    logf = atos_lib.open_atos_log_file(
        args.configuration_path, "run", variant)
    message("Running variant %s [%s]..." %
            (variant, atos_lib.hashid(variant)))

    failure = False

    if executables:
        exe_size = get_size(executables)
        failure = check_failure(
            failure, exe_size is None, "get_size failure")
    else:
        exe_size = None

    n = 0
    while n < nbruns:
        logf.write("Running variant %s %d/%d\n" % (variant, n + 1, nbruns))

        status, exe_time, output_time = get_time()

        logf.write(output_time)

        failure = check_failure(
            failure, status != 0, "get_time failure")
        if failure:
            output_run_results(
                results_script and "FAILURE" or target_id,
                variant, "FAILURE", "FAILURE")
            break

        if results_script:
            status, output_res = process.system(
                results_script, get_output=True,
                output_stderr=True, stdin_str=output_time)
            output_time += "\n" + output_res
            failure = check_failure(
                failure, status != 0, "get_res failure")
        output_result = {}
        for line in output_time.splitlines():
            words = line.split(': ')
            if words[0] != "ATOS": continue
            target, key, value = words[1:4]
            output_result.setdefault(target, {})[key] = value
        if output_result:
            for target, res in output_result.items():
                exe_time = res.get('time', None)
                exe_size = res.get('size', None)
                output_run_results(target, variant, exe_time, exe_size)
                failure = check_failure(
                    failure, exe_time is None, "get_res time failure")
                failure = check_failure(
                    failure, exe_size is None, "get_res size failure")
        else:  # no "ATOS: targ: time: ..." lines
            output_run_results(target_id, variant, exe_time, exe_size)

        if failure: break
        logf.write("SUCCESS running variant %s\n" % variant)
        n = n + 1

    if failure or n < nbruns:
        message("FAILURE while running variant %s..." % variant)
        logf.write("FAILURE while running variant %s\n" % variant)
        logf.close()
        return 2

    logf.close()
    return 0

def run_atos_replay(args):
    """ ATOS opt tool implementation. """

    if os.path.abspath(args.results_path) == \
            os.path.abspath(args.configuration_path):
        error("replay result path must differ from configuration path")
        return 1

    process.commands.mkdir(args.results_path)

    results_db_file = os.path.join(args.results_path, "results.db")
    if not os.path.isfile(results_db_file):
        atos_lib.atos_db_file(results_db_file)

    config_target_file = os.path.join(args.configuration_path, 'targets')
    result_target_file = os.path.join(args.results_path, 'targets')
    process.commands.copyfile(config_target_file, result_target_file)

    # reference build
    status = invoque("atos-build", args)
    if status != 0: return status

    # reference run
    status = invoque("atos-run", args,
                  configuration_path=args.results_path, record=True,
                  command=[args.run_script])
    if status != 0: return status

    # get frontier results
    results_db = atos_lib.atos_db.db(args.configuration_path)
    results_client = atos_lib.atos_client_results(results_db)
    results = results_client.get_results(only_frontier=True, objects=True)

    for result in results:
        result_conf = getattr(result, 'conf', None)
        result_uconf = getattr(result, 'uconf', None)

        status = invoque(
            "atos-build", args, options=result_conf, uopts=result_uconf)
        if status != 0: continue

        invoque("atos-run", args, configuration_path=args.results_path,
             record=True, options=result_conf, uopts=result_uconf,
             command=[args.run_script])

    return 0

def run_atos_cookie(args):
    """ ATOS cookie generator implementation. """
    print atos_lib.unique_cookie(args.cookies)
    return 0

def run_atos_explore_inline(args):
    """ ATOS explore-inline tool implementation. """

    flags_file = args.flags_file or os.path.join(
        args.configuration_path, "flags.inline.cfg")

    status = generators.run_exploration_loop(
        args, flags_file=flags_file, generator=generators.gen_rnd_uniform_deps)

    return status

def run_atos_explore_loop(args):
    """ ATOS explore-loop tool implementation. """

    flags_file = args.flags_file or os.path.join(
        args.configuration_path, "flags.loop.cfg")

    status = generators.run_exploration_loop(
        args, flags_file=flags_file, generator=generators.gen_rnd_uniform_deps)

    return status

def run_atos_explore_optim(args):
    """ ATOS explore-optim tool implementation. """

    flags_file = args.flags_file or os.path.join(
        args.configuration_path, "flags.optim.cfg")

    status = generators.run_exploration_loop(
        args, flags_file=flags_file, generator=generators.gen_rnd_uniform_deps)

    return status

def run_atos_explore_acf(args):
    """ ATOS explore-acf tool implementation. """

    imgpath = profile.get_image_pathes(
        args.exes, args.configuration_path)
    if not imgpath:
        error("executables must be specified (-e option)")
        return 1

    prof_script = args.prof_script or os.path.join(
        args.configuration_path, "profile.sh")
    if not os.path.isfile(prof_script):
        error("profiling script not specified")
        return 1

    csv_dir = os.path.join(args.configuration_path, 'acf_csv_dir')
    process.commands.mkdir(csv_dir)

    file_by_file = args.file_by_file
    if not file_by_file:

        # ACF mode - function-by-function exploration

        acf_plugin_path = atos_lib.query_config_values(
            args.configuration_path, "$.compilers[*].plugin_acf")
        acf_plugin_path = acf_plugin_path and list(set(acf_plugin_path))[0]

        host_wide_int = atos_lib.query_config_values(
            args.configuration_path, "$.compilers[*].valid_host_wide_int",
            default=None)

        plugins_enabled = atos_lib.query_config_values(
            args.configuration_path, "$.compilers[*].plugins_enabled")
        plugins_enabled = plugins_enabled and bool(int(
            list(set(plugins_enabled))[0])) or False

        if not acf_plugin_path:
            warning("compiler not supported by acf plugin")
            warning("switching to file-by-file exploration")
            file_by_file = True

        elif host_wide_int and not all(map(int, host_wide_int)):
            error("compiler not supported by acf plugin (wrong hwi_size)")
            return 1

        elif not plugins_enabled:
            warning("compiler does not support plugins")
            warning("switching to file-by-file exploration")
            file_by_file = True

        else:
            status = generators.run_exploration_loop(
                args, imgpath=imgpath, csv_dir=csv_dir,
                prof_script=prof_script, acf_plugin_path=acf_plugin_path,
                acf_hot_th=str(args.hot_th),
                acf_cold_opts=("%s %s" % (args.cold_opts, args.cold_attrs)),
                flags_file=args.flags_file,
                per_func_nbiters=args.per_func_nbiters,
                generator=generators.gen_function_by_function)

    if file_by_file:

        # FILE mode - file-by-file exploration

        status = generators.run_exploration_loop(
            args, prof_script=prof_script,
            imgpath=imgpath, csv_dir=csv_dir,
            hot_th=str(args.hot_th), cold_opts=args.cold_opts,
            flags_file=args.flags_file,
            per_file_nbiters=args.per_func_nbiters,
            generator=generators.gen_file_by_file)

    return status
