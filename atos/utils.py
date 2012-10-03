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
import atos
import arguments
import atos_lib
import fnmatch
import logger
import process
import shutil
import copy
import glob
from logger import debug, error, message

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

    if args.ccname:
        args.ccregexp = '^' + args.ccname + '$'
    if args.output_file == None:
        args.output_file = os.path.join(args.configuration_path, "build.audit")

    process.commands.mkdir(args.configuration_path)
    process.commands.touch(args.output_file)
    build_sh = os.path.join(args.configuration_path, "build.sh")
    with open(build_sh, 'w') as file_build:
        file_build.write("#!/bin/sh\n")
        file_build.write("cd %s && $ARUN %s\n" % (
                os.getcwd(),
                process.list2cmdline(args.command)))
    process.commands.chmod(build_sh, 0755)
    force_sh = os.path.join(args.configuration_path, "build.force")
    with open(force_sh, 'w') as file_force:
        file_force.write(str(int(args.force)))
    command = atos_lib.proot_command(
        PROOT_IGNORE_ELF_INTERPRETER=1,
        PROOT_ADDON_CC_DEPS=1,
        PROOT_ADDON_CC_DEPS_OUTPUT=args.output_file,
        PROOT_ADDON_CC_DEPS_CCRE=args.ccregexp) + args.command
    status = process.system(command, print_output=True)
    return status

def run_atos_build(args):
    """ ATOS build tool implementation. """

    APFLAGS = ""
    profdir_option = ""
    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    options = args.options or ""
    opt_rebuild = args.force
    pvariant = ""
    profile_path = ""
    remote_profile_path = ""
    atos_driver = os.getenv("ATOS_DRIVER")
    if atos_driver == None:
        atos_driver = os.path.join(globals.BINDIR, "atos-driver")
    if atos_driver == '0': atos_driver = None
    timeout = os.getenv("TIMEOUT")
    if timeout == None:
        timeout = os.path.join(globals.BINDIR, "atos-timeout") + " 3600"

    if args.ccname:
        args.ccregexp = '^' + args.ccname + '$'

    # TODO: could be more readable with something like args.is_set(gopts)
    # (None and '' have different meanings here)
    if args.gopts != None:
        pvariant = atos_lib.variant_id(args.gopts)
        if not args.path:
            profile_path = os.path.join(
                args.configuration_path, "profiles", atos_lib.hashid(pvariant))
        else:
            profile_path = args.path
        process.commands.mkdir(profile_path)
        variantfile = os.path.join(profile_path, "variant.txt")
        variantf = open(variantfile, 'w')
        variantf.write(pvariant)
        variantf.close()
        for file in os.listdir(profile_path):
            if fnmatch.fnmatch(file, '*.gcda'):
                rmcommand = "rm -f " + file
                process.system(rmcommand)

        APFLAGS = "-fprofile-generate"
        if not args.remote_path:
            config_file = os.path.join(args.configuration_path, 'config.json')
            if os.path.isfile(config_file):
                client = atos_lib.json_config(config_file)
                remote_profile_path = client.get_value(
                    "default_values.remote_profile_path")
            else:
                remote_profile_path = None
        else:
            remote_profile_path = args.remote_path
        if remote_profile_path:
            profdir_option = "PROFILE_DIR=" + str(
                os.path.abspath(remote_profile_path))
        else:
            profdir_option = "PROFILE_DIR=" + os.path.abspath(profile_path)

    if args.uopts != None:
        pvariant = atos_lib.variant_id(args.uopts)
        if not profile_path:
            profile_path = os.path.join(
                args.configuration_path, "profiles", atos_lib.hashid(pvariant))
        process.commands.mkdir(profile_path)
        APFLAGS = ("-fprofile-use -fprofile-correction" +
                   " -Wno-error=coverage-mismatch")
        profdir_option = "PROFILE_DIR=" + os.path.abspath(profile_path)

    failure = 0
    logs = os.path.join(args.configuration_path, "logs")
    process.commands.mkdir(logs)

    hash_var = atos_lib.hashid(variant)
    logfile = os.path.join(logs, "build-" + hash_var + ".log")
    logf = open(logfile, 'w')

    message("Building variant " + variant + "...")
    logf.write("Building variant %s\n" % variant)

    build_force = os.path.join(args.configuration_path, "build.force")
    if not opt_rebuild and os.path.isfile(build_force):
        opt_rebuild = int(open(build_force).read().strip())

    build_mk = os.path.join(args.configuration_path, "build.mk")
    build_sh = os.path.join(args.configuration_path, "build.sh")
    pwd = os.getcwd()
    if not args.command and opt_rebuild != 1 and os.path.isfile(build_mk):
        # If the configuration path contains a build.mk execute it
        if options.find("-flto") != -1:
            lto_option = "LTO=1"
        else:
            lto_option = ""
        command = (timeout + " make -f " + build_mk + " ATOS_DRIVER=" +
                   atos_driver + " ACFLAGS=\"" + APFLAGS + " " + options +
                   "\" " + lto_option + " " + profdir_option)
        command = command + " -j" + str(args.jobs)
        status, output = process.system(
            command, get_output=True, output_stderr=True)
        logf.write('%s\n' % output)

    else:
        command = timeout.split() + atos_lib.proot_command(
            PROOT_IGNORE_ELF_INTERPRETER=1,
            PROOT_ADDON_CC_OPTS=1,
            PROOT_ADDON_CC_OPTS_ARGS="%s %s" % (APFLAGS, options),
            PROOT_ADDON_CC_OPTS_CCRE=args.ccregexp,
            PROOT_ADDON_CC_OPTS_DRIVER=atos_driver)
        if not args.command and opt_rebuild == 1 and os.path.isfile(build_sh):
            command.append(build_sh)
        else:
            command.extend(args.command)
        status, output = process.system(
            command, print_output=True, get_output=True, output_stderr=True)
        logf.write('%s\n' % output)

    if status:
        message("FAILURE while building variant " + variant + "...")
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

    if args.input_file == None:
        args.input_file = os.path.join(args.configuration_path, "build.audit")
    if args.output_file == None:
        args.output_file = os.path.join(args.configuration_path, "build.mk")

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
        CCDEPSParser(open(args.input_file)), SimpleCmdInterpreter())
    factory.build_dependencies()
    dependencies = factory.get_dependencies()
    builder = DependencyGraphBuilder(dependencies, targets)
    builder.build_graph()
    graph = builder.get_graph()

    if not args.force:
        graph.output_makefile(args.output_file)

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
        invoque("atos-audit", args, command=process.cmdline2list(
                args.build_script))
        invoque("atos-deps", args,
                executables=executables, all=(not executables))
        # TODO: to be replaced by invoque(atos-config)
        command_config = [
            os.path.join(globals.BINDIR, "atos-config"),
            "-C", args.configuration_path]
        process.system(command_config, print_output=True)

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
        invoque("atos-raudit", args, command=process.cmdline2list(
                args.run_script))
        if not args.no_run:
            invoque("atos-run", args, record=True)  # reference run

    elif not os.path.isfile(
        os.path.join(args.configuration_path, "run.audit")):
        error("missing run audit, use -r option for specifying run script"
              " or use atos-raudit tool")
        return 1

    if args.prof_script:
        prof_sh = os.path.join(args.configuration_path, "profile.sh")
        with open(prof_sh, 'w') as proff:
            proff.write("#!/bin/sh\n")
            proff.write("cd $PWD && %s\n" % args.prof_script)
        process.commands.chmod(prof_sh, 0755)
    return 0

def run_atos_opt(args):
    """ ATOS opt tool implementation. """

    if args.options == None:
        options = ""
    else:
        options = args.options
    if args.fdo:
        if args.uopts == None:
            uopts = options
        else:
            uopts = args.uopts
    if args.lto:
        options += " -flto"

    if args.keep:
        variant = atos_lib.variant_id(
            args.options, None, args.uopts)
        db = atos_lib.atos_db.db(args.configuration_path)
        client = atos_lib.atos_client_db(db)
        results = client.query(atos_lib.strtoquery("variant:" + variant))
        if results:
            message("Skipping variant " + variant + "...")
            return 0

    if args.fdo:
        status = invoque("atos-profile", args,
                      options=uopts)
        if status == 0:
            status = invoque("atos-build", args,
                          options=options, uopts=uopts)
            if status == 0:
                status = invoque("atos-run", args,
                          options=options, uopts=uopts)
    else:
        status = invoque("atos-build", args,
                      options=options)
        if status == 0:
            status = invoque("atos-run", args,
                          options=options)
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
    status = invoque("atos-build", args,
                  gopts=options, options=options)
    if status == 0:
        status = invoque("atos-run", args,
                      gopts=options, options=options,
                      silent=True)
    return status

def run_atos_raudit(args):
    """ ATOS raudit tool implementation. """

    if args.command == None:
        error('atos-raudit: missing run command')
        return 1

    message("Auditing run...")

    if args.output_file == None:
        process.commands.mkdir(args.configuration_path)
        args.output_file = os.path.join(args.configuration_path, "run.audit")
        process.commands.touch(args.output_file)
        run_sh = os.path.join(args.configuration_path, "run.sh")
        f = open(run_sh, 'w')
        f.write("#!/bin/sh\n")
        f.write("cd ")
        f.write(os.getcwd())
        f.write(" && $ARUN ")
        f.write(process.list2cmdline(args.command))
        f.write("\n")
        f.close()
        process.commands.chmod(run_sh, 0755)
        if args.results_script != None:
            get_res_sh = os.path.join(args.configuration_path, "get_res.sh")
            f = open(get_res_sh, 'w')
            f.write("#!/bin/sh\n")
            f.write("cd ")
            f.write(os.getcwd())
            f.write(" &&  " + args.results_script)
            f.write("\n")
            f.close()
            process.commands.chmod(get_res_sh, 0755)

    status = process.system(args.command)
    return status

def run_atos_run(args):
    """ ATOS run tool implementation. """

    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    timeout = os.getenv("TIMEOUT")
    if timeout == None:
        timeout = os.path.join(globals.BINDIR, "atos-timeout") + " 3600"

    if args.results_script == None \
       and os.path.isfile(os.path.join(args.configuration_path,
                                       "get_res.sh")):
        args.results_script = os.path.join(args.configuration_path,
                                           "get_res.sh")
    else:
        args.results_script = ""

    if args.gopts and not args.remote_path:
        config_file = os.path.join(args.configuration_path, 'config.json')
        if os.path.isfile(config_file):
            client = atos_lib.json_config(config_file)
            args.remote_path = client.get_value(
                "default_values.remote_profile_path")

    if args.results_script == "":
        if args.exe == None or args.exe == "":
            args.exe = []
            try:
                targetf = open(os.path.join(args.configuration_path,
                                            "targets"),
                               "r")
            except:
                error("no target executable specified")
                return 1
            else:
                for line in targetf:
                    args.exe.append(line.strip())
                targetf.close()
        else:
            args.exe = [args.exe]

    else:
        args.exe = ()

    if not args.id:
        args.id = "-".join(map(os.path.basename, args.exe))

    def get_size(executables):
        exe_size = 0
        for exe in executables:
            if not os.path.isabs(exe):
                status, exe = process.system("which " + exe,
                                             get_output=True)
            if exe == "":
                return -1
            exe.strip('\n')
            command = "/usr/bin/size " + exe
            status, output = process.system(
                command, get_output=True)
            size = int(
                output.splitlines()[1].split()[3]) if not args.dryrun else 0
            exe_size = exe_size + size
        return exe_size

    def profile_path():
        lpvariant = atos_lib.variant_id(args.gopts)
        return os.path.join(
            os.path.abspath(args.configuration_path),
            "profiles",
            atos_lib.hashid(lpvariant))

    def get_time(run_script):
        exe_time = 0
        real_output = ""
        if args.remote_path and args.gopts:
            os.putenv("REMOTE_PROFILE_DIR", args.remote_path)
            os.putenv("LOCAL_PROFILE_DIR", profile_path())
        command = timeout + " /usr/bin/time -p " + run_script
        status, output = process.system(command, get_output=True,
                                        output_stderr=True)
        if args.dryrun:
            return 0, ""
        if status != 0 or not output:
            return -1, None

        count = 0
        last_time = 0
        for line in output.splitlines():
            if line.startswith("user"):
                last_time = float(line.split()[1]) * 1000
                exe_time = exe_time + last_time
                count = count + 1
            if not line.startswith(("user", "real", "sys")):
                real_output = real_output + line + "\n"
        if count > 1:
            exe_time = exe_time - last_time

        os.unsetenv("REMOTE_PROFILE_DIR")
        os.unsetenv("LOCAL_PROFILE_DIR")
        return exe_time, real_output

    def output_run_results():
        entry = "target:" + args.id
        entry = entry + ",variant:" + variant
        entry = entry + ",version:" + globals.VERSION
        entry = entry + ",conf:"
        if args.options != None:
            entry = entry + \
                    "".join(process.cmdline2list(args.options))
        if args.uopts != None:
            entry = entry + ",uconf:" + \
                    "".join(process.cmdline2list(args.uopts))
        if args.gopts != None:
            entry = entry + ",gconf:" + \
                    "".join(process.cmdline2list(args.gopts))
        entry = entry + ",size:" + str(exe_size)
        entry = entry + ",time:" + str(exe_time)
        if args.output_file != None:
            db = atos_lib.atos_db_file(args.output_file)
            status, output = atos_lib.atos_client_db(db).\
                             add_result(atos_lib.strtodict(entry))
        elif not args.record:
            output = atos_lib.atos_db_file.entry_str(
                atos_lib.strtodict(entry))
            status = 0

            if output != None:
                print >> sys.stderr, output.strip()
        else:
            db = atos_lib.atos_db.db(args.configuration_path)
            status, output = atos_lib.atos_client_db(db).\
                             add_result(atos_lib.strtodict(entry))

    message("Running variant " + variant + "...")
    failure = False
    logs = os.path.join(args.configuration_path, "logs")
    process.commands.mkdir(logs)
    hash_var = atos_lib.hashid(variant)
    logfile = os.path.join(logs, "run-" + hash_var + ".log")
    logf = open(logfile, 'w')

    exe_time = ""
    exe_size = ""

    if args.exe != "":
        exe_size = get_size(args.exe)
        if exe_size == -1:
            failure = True

    if args.gopts == None and args.nbruns == None:
        config_file = os.path.join(args.configuration_path, 'config.json')
        if os.path.isfile(config_file):
            client = atos_lib.json_config(config_file)
            args.nbruns = client.get_value("default_values.nb_runs") or ''

    if args.nbruns == "" or args.nbruns == None:
        args.nbruns = 1
    else:
        args.nbruns = int(args.nbruns)

    n = 1
    while n <= args.nbruns:
        logf.write("Running variant " + variant +
                   " " + str(n) + "/" + str(args.nbruns) + "\n")
        tmp_logfile = logfile + "." + str(n)
        process.system("rm -f " + tmp_logfile)
        run_sh = os.path.join(args.configuration_path,
                              "run.sh")
        if os.path.isfile(run_sh):
            exe_time, output_time = get_time(run_sh)
        else:
            exe_time, output_time = get_time(
                process.list2cmdline(args.command))

        if exe_time == -1:
            failure = True

        if failure:
            exe_size = "FAILURE"
            exe_time = "FAILURE"

        if not args.silent:
            if failure:
                if args.results_script == "":
                    args.id = "FAILURE"
                output_run_results()
            else:
                output_res = ""
                if args.results_script != "":
                    status, output_res = process.system(
                        args.results_script, get_output=True,
                        output_stderr=True, stdin_str=output_time)
                    if status != 0:
                        failure = True
                output = output_time + output_res
                for line in output.splitlines():
                    identifiers = []
                    if line.startswith("ATOS:"):
                        identifier = line.split(': ')[1]
                        if not identifier in identifiers:
                            identifiers.append(identifier)
                            if "time:" in line:
                                exe_time = line.split(': ')[3]
                            elif "size:" in line:
                                exe_size = line.split(': ')[3]

                if exe_time == 0 or exe_size == 0:
                    exe_time = "FAILURE"
                    exe_size = "FAILURE"
                output_run_results()
        if failure:
            message("FAILURE while running variant " + variant + "...")
            logf.write("FAILURE while running variant " + variant)
            logf.write("\n")
            logf.close()
            return 2
        else:
            logf.write("SUCCESS running variant " + variant)
            logf.write("\n")
        n = n + 1

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
