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

import sys, os, stat
import globals
import arguments
import atos_lib
import logger
import process
import shutil
import copy
import glob
import re
from logger import debug, error, message, info

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
        "atos-lib": run_atos_lib,
        "atos-opt": run_atos_opt,
        "atos-play": run_atos_play,
        "atos-profile": run_atos_profile,
        "atos-raudit": run_atos_raudit,
        "atos-run": run_atos_run,
        "atos-replay": run_atos_replay,
        }

    def dryrun_tool(tool, args, **kwargs):
        """ Does not run the tool, outputs the tool command line. """
        dest_to_opt = dict(map(
                lambda x: (x.dest, x),
                arguments.parser(tool)._actions))
        arg_list, remainder = [tool], []
        for key, value in args.__dict__.items() + kwargs.items():
            if (key == 'dryrun' or key not in dest_to_opt.keys()
                or value == dest_to_opt[key].default):
                continue
            if not dest_to_opt[key].option_strings:
                remainder.extend(value)
            else:
                arg_list.append(dest_to_opt[key].option_strings[-1])
                if dest_to_opt[key].nargs != 0: arg_list.append(str(value))
        process.debug(process.list2cmdline(arg_list + remainder))
        return 0

    def run_tool(tool, args, **kwargs):
        """ Runs the tool, given the top level args and kwargs modifier. """
        tool_args = arguments.argparse.Namespace()
        for action in arguments.parser(tool)._actions:
            if action.dest is None: continue
            tool_args.__dict__[action.dest] = action.default
        tool_args.__dict__.update(vars(args))
        tool_args.__dict__.update(kwargs)
        return functions[tool](tool_args)

    global _at_toplevel
    assert(_at_toplevel != None)
    # local dryrun setting is not supported as the process module
    # depends upon the global setting
    assert(kwargs.get('dryrun') == None)

    dryrun = args.dryrun and not _at_toplevel
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

    message("Building variant %s..." % variant)
    logf.write("Building variant %s\n" % variant)

    make_options = []
    compile_options = args.options and [args.options] or []

    atos_driver = os.getenv("ATOS_DRIVER")
    if atos_driver == None:
        atos_driver = os.path.join(globals.BINDIR, "atos-driver")
    if atos_driver == '0':
        atos_driver = None

    opt_rebuild = args.force
    build_force = os.path.join(args.configuration_path, "build.force")
    if not opt_rebuild and os.path.isfile(build_force):
        opt_rebuild = int(open(build_force).read().strip())

    if args.gopts != None or args.uopts != None:
        pvariant = atos_lib.variant_id(args.gopts or args.uopts or "")
        profile_path = args.path
        if not profile_path:
            profile_path = os.path.join(
                args.configuration_path, "profiles", atos_lib.hashid(pvariant))
        process.commands.mkdir(profile_path)

    if args.gopts != None:
        with open(os.path.join(profile_path, "variant.txt"), "w") as variantf:
            variantf.write(pvariant)
        process.system(["rm", "-f"] + glob.glob('%s/*.gcda' % (profile_path)))
        compile_options += ["-fprofile-generate"]

        remote_profile_path = args.remote_path
        if not remote_profile_path:
            remote_profile_path = atos_lib.get_config_value(
                args.configuration_path, 'default_values.remote_profile_path')
        if remote_profile_path:
            profile_path = remote_profile_path
        make_options += ["PROFILE_DIR=%s" % os.path.abspath(profile_path)]

    if args.uopts != None:
        compile_options += ["-fprofile-use", "-fprofile-correction",
                            "-Wno-error=coverage-mismatch"]
        make_options += ["PROFILE_DIR=" + os.path.abspath(profile_path)]

    build_mk = os.path.join(args.configuration_path, "build.mk")
    compile_options = " ".join(compile_options)
    if not args.command and not opt_rebuild and os.path.isfile(build_mk):
        # if the configuration path contains a build.mk execute it
        command = ["make", "-f", build_mk, "-j", str(args.jobs)]
        command.append("ACFLAGS=%s" % compile_options)
        command.extend(make_options)
        if atos_driver:
            command.append("ATOS_DRIVER=%s" % atos_driver)
        if compile_options.find("-flto") != -1:
            command.append("LTO=1")
        status, output = process.system(
            atos_lib.timeout_command() + command,
            get_output=True, output_stderr=True)
    else:
        # else use proot cc_opts addon (force mode)
        build_sh = os.path.join(args.configuration_path, "build.sh")
        ccregexp = args.ccname and ("^%s$" % args.ccname) or args.ccregexp
        command = atos_lib.proot_command(
            PROOT_IGNORE_ELF_INTERPRETER=1,
            PROOT_ADDON_CC_OPTS=1,
            PROOT_ADDON_CC_OPTS_ARGS="%s" % compile_options,
            PROOT_ADDON_CC_OPTS_CCRE=ccregexp,
            PROOT_ADDON_CC_OPTS_DRIVER=atos_driver)
        if not args.command and opt_rebuild and os.path.isfile(build_sh):
            command.append(build_sh)
        else:
            command.extend(args.command)
        status, output = process.system(
            atos_lib.timeout_command() + command,
            get_output=True, output_stderr=True)

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
    if args.executables:
        targets = args.executables
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
    try:
        f = open(os.path.join(args.configuration_path, "targets"), "w")
    except:
        pass
    else:
        f.write("\n".join(args.executables
                          if args.force else graph.get_targets()) + "\n")
        f.close()

    try:
        f = open(os.path.join(args.configuration_path, "objects"), "w")
    except:
        pass
    else:
        f.write("\n".join(graph.get_objects()) + "\n")
        f.close()

    # For now only write compilers if configuration dir is there
    try:
        f = open(os.path.join(args.configuration_path, "compilers"), "w")
    except:
        pass
    else:
        f.write('\n'.join(graph.get_compilers()) + '\n')
        f.close()

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

    executables = args.exe and [args.exe] or args.executables
    if args.force and not args.results_script and not executables:
        error("when using forced mode (-f) with no custom results script (-t)"
              " the list of executables must be specified (-e option)")
        return 1

    process.commands.mkdir(args.configuration_path)

    if args.clean:
        if args.build_script:
            message("Cleaning build audit...")
            files = ' '.join(glob.glob('%s/build.*' % args.configuration_path))
            process.system("rm -f %s" % (files), print_output=True)
        if args.run_script:
            message("Cleaning run audit...")
            files = ' '.join(glob.glob('%s/run.*' % args.configuration_path))
            process.system("rm -f %s" % (files), print_output=True)
        message("Cleaning all profiles...")
        rmcommand = "rm -rf %s/profiles" % (args.configuration_path)
        process.system(rmcommand, print_output=True)
        message("Cleaning all results...")
        rmcommand = "rm -f %s/results.db" % (args.configuration_path)
        process.system(rmcommand, print_output=True)

    if args.build_script:
        status = invoque("atos-audit", args,
                         command=process.cmdline2list(args.build_script))
        if status != 0: return status
        status = invoque("atos-deps", args, executables=executables,
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
        if not args.no_run:
            # reference run
            status = invoque("atos-run", args, record=True)
            if status != 0: return status

    elif not os.path.isfile(
        os.path.join(args.configuration_path, "run.audit")):
        error("missing run audit, use -r option for specifying run script"
              " or use atos-raudit tool")
        return 1

    if args.prof_script:
        prof_sh = os.path.join(args.configuration_path, "profile.sh")
        atos_lib.generate_script(prof_sh, args.prof_script)

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

def run_atos_opt(args):
    """ ATOS opt tool implementation. """

    options = args.options or ""
    uopts = args.uopts or (args.fdo and options or None)
    if args.lto: options += " -flto"

    if args.keep:  # do nothing if existing run results
        variant = atos_lib.variant_id(options, None, args.uopts)
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

    status = invoque("atos-run", args, options=options, uopts=uopts)
    return status

def run_atos_play(args):
    """ ATOS play tool implementation. """

    if not os.path.isdir(args.configuration_path):
        error('Configuration missing: ' + args.configuration_path)
        return 1

    target_id = args.id
    if not target_id:
        executables = args.exe and [args.exe]
        if not executables:
            try:
                with open(os.path.join(
                        args.configuration_path, "targets")) as targetf:
                    executables = map(lambda x: os.path.basename(
                            x.strip()), targetf.readlines())
            except:
                error('no target executable and no identifier specified')
                return 1
        target_id = "-".join(executables)

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

def run_atos_run(args):
    """ ATOS run tool implementation. """

    def profile_path():
        lpvariant = atos_lib.variant_id(args.gopts)
        return os.path.join(
            os.path.abspath(args.configuration_path),
            "profiles", atos_lib.hashid(lpvariant))

    def get_size(executables):
        def one_size(exe):
            if not os.path.isabs(exe):
                status, exe = process.system(["which", exe], get_output=True)
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
            os.putenv("LOCAL_PROFILE_DIR", profile_path())

        run_script = os.path.join(args.configuration_path, "run.sh")
        run_script = args.command or [run_script]

        status, output = process.system(
            atos_lib.timeout_command() + ["/usr/bin/time", "-p"] + run_script,
            get_output=True, output_stderr=True)

        if args.dryrun:
            return status, ""
        if status or not output:
            return None, None

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
        return exe_time, real_output

    def output_run_results(target, variant, time, size):
        if args.silent: return
        if time is None: time = "FAILURE"
        if size is None: size = "FAILURE"
        entry = {}
        entry.update({'target': target})
        entry.update({'variant': variant})
        entry.update({'version': globals.VERSION})
        entry.update({'conf': "".join(
                    process.cmdline2list(args.options or ''))})
        if args.uopts != None:
            entry.update({'uconf': "".join(
                        process.cmdline2list(args.uopts))})
        if args.gopts != None:
            entry.update({'gconf': "".join(
                        process.cmdline2list(args.gopts))})
        entry.update({'time': str(time)})
        entry.update({'size': str(size)})
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
        executables = args.exe and [args.exe]
        if not executables:
            try:
                with open(os.path.join(
                        args.configuration_path, "targets")) as targetf:
                    executables = map(lambda x: x.strip(), targetf.readlines())
            except:
                error("no target executable specified")
                return 1
        target_id = args.id or "-".join(map(os.path.basename, executables))

    logf = atos_lib.open_atos_log_file(
        args.configuration_path, "run", variant)
    message("Running variant " + variant + "...")

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

        exe_time, output_time = get_time()

        logf.write(output_time)

        failure = check_failure(
            failure, exe_time is None, "get_time failure")
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

    process.commands.mkdir(args.results_path)

    results_db_file = os.path.join(args.results_path, "results.db")
    if not os.path.isfile(results_db_file):
        db = atos_lib.atos_db_file(results_db_file)

    config_target_file = os.path.join(args.configuration_path, 'targets')
    result_target_file = os.path.join(args.results_path, 'targets')
    if (not args.exe and os.path.exists(config_target_file)
        and not os.path.exists(result_target_file)):
        shutil.copyfile(config_target_file, result_target_file)

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
