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

_initialized = False

def invoque(tool, args):
    """ Dispatcher that invoques the given tool and returns. """
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
    global _initialized
    if not _initialized:
        logger.setup(vars(args))
        process.setup(vars(args))
        _initialized = True
    return functions[tool](args)

def execute(tool, args):
    """ Executes the invoque dispatcher and exits. """
    sys.exit(invoque(tool, args))

def call(tool, args, **kwargs):
    """ Call the given ATOS tool with args and returns.
    Handles default arguments values if needed.
    """
    if args.dryrun:
        # TODO: rebuild command line for dryrun message
        process.debug("# call: %s %s" % (tool, kwargs))
        return 0
    tool_args = arguments.argparse.Namespace()
    for action in arguments.parser(tool)._actions:
        if action.dest is None: continue
        tool_args.__dict__[action.dest] = action.default
    tool_args.__dict__.update(vars(args))
    tool_args.__dict__.update(kwargs)
    return invoque(tool, tool_args)

def run_atos(args):
    """ Top level atos utility implementation. """
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
    process.commands.chmod(build_sh, stat.S_IRWXU | stat.S_IRGRP |
                         stat.S_IXGRP | stat.S_IROTH | stat.S_IXOTH)
    force_sh = os.path.join(args.configuration_path, "build.force")
    with open(force_sh, 'w') as file_force:
        file_force.write(str(int(args.force)))

    command = ("env PROOT_IGNORE_ELF_INTERPRETER=1" +
               " PROOT_ADDON_CC_DEPS=1 PROOT_ADDON_CC_DEPS_OUTPUT='" +
               args.output_file + "' PROOT_ADDON_CC_DEPS_CCRE='"
               + args.ccregexp + "' " + atos_lib.proot_atos() +
               " -w " + os.getcwd() + " / ")
    command += process.list2cmdline(args.command)
    status = process.system(command, print_output=True)
    return status

def run_atos_build(args):
    """ ATOS build tool implementation. """

    APFLAGS = ""
    profdir_option = ""
    variant = args.variant
    opt_rebuild = args.force
    pvariant = "REF"
    profile_path = ""
    remote_profile_path = ""
    options = args.options
    if not options:
        options = ""
    atos_driver = os.getenv("ATOS_DRIVER")
    if atos_driver == None:
        atos_driver = os.path.join(globals.BINDIR, "atos-driver")
    if atos_driver != '0':
        PROOT_ADDON_CC_OPTS_DRIVER = (
            "PROOT_ADDON_CC_OPTS_DRIVER=" + atos_driver)
    timeout = os.getenv("TIMEOUT")
    if timeout == None:
        timeout = os.path.join(globals.BINDIR, "atos-timeout") + " 3600"

    if args.ccname:
        args.ccregexp = '^' + args.ccname + '$'

    if args.gopts != None:
        if args.gopts:
            pvariant = "OPT" + ''.join(args.gopts.split())
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
        pvariant = "REF"
        if args.uopts:
            pvariant = "OPT" + ''.join(args.uopts.split())
        if not profile_path:
            profile_path = os.path.join(
                args.configuration_path, "profiles", atos_lib.hashid(pvariant))
        process.commands.mkdir(profile_path)
        APFLAGS = ("-fprofile-use -fprofile-correction" +
                   " -Wno-error=coverage-mismatch")
        profdir_option = "PROFILE_DIR=" + os.path.abspath(profile_path)

    if variant == "REF":
        if options != "" or pvariant != "":
            if args.gopts != None:
                variant = ("OPT-fprofile-generate" +
                           ''.join(args.gopts.split()) +
                           ''.join(options.split()))
            elif args.uopts != None:
                variant = ("OPT-fprofile-use" +
                           ''.join(args.uopts.split()) +
                           ''.join(options.split()))
            else:
                variant = "OPT" + ''.join(options.split())

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
        (status, output) = process.system(
            command, get_output=True, output_stderr=True)
        logf.write('%s\n' % output)
        if status:
            failure = 1

    elif not args.command and opt_rebuild == 1 and os.path.isfile(build_sh):
        command = (timeout + " env PROOT_IGNORE_ELF_INTERPRETER=1" +
                   " PROOT_ADDON_CC_DEPS=1 PROOT_ADDON_CC_OPTS_ARGS='" +
                   APFLAGS + " " + options +
                   "' PROOT_ADDON_CC_DEPS_CCRE='" + args.ccregexp +
                   PROOT_ADDON_CC_OPTS_DRIVER + "' " +
                   atos_lib.proot_atos() + " -w " + os.getcwd()
                   + " / \"" + build_sh + "\"")
        (status, output) = process.system(
            command, print_output=True, get_output=True,
            output_stderr=True)
        logf.write('%s\n' % output)
        if status:
            failure = 1

    else:
        command = (timeout + " env PROOT_IGNORE_ELF_INTERPRETER=1 " +
                   "PROOT_ADDON_CC_DEPS=1 PROOT_ADDON_CC_OPTS_ARGS='" +
                   APFLAGS + " " + options +
                   "' PROOT_ADDON_CC_DEPS_CCRE='" + args.ccregexp +
                   PROOT_ADDON_CC_OPTS_DRIVER + "' " +
                   atos_lib.proot_atos() + " -w " + os.getcwd() + " / ")
        command += process.list2cmdline(args.command)
        (status, output) = process.system(
            command, print_output=True, get_output=True, output_stderr=True)
        command = command + " -j" + str(args.jobs)
        (status, output) = process.system(
            command, get_output=True, output_stderr=True)
        logf.write('%s\n' % output)
        if status:
            failure = 1

    if failure == 1:
        message("FAILURE while building variant " + variant + "...")
        logf.write("FAILURE while building variant %s\n" % (variant))
        logf.close()
        return 2
    else:
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

    call("atos-init", args)

    for opt_level in ['-O2', '-Os', '-O3']:
        for opts in ['', '-flto', '-funroll-loops', '-flto -funroll-loops']:
            options = ' '.join([opt_level, opts])
            status = call("atos-build", args, options=options)
            if status == 0:
                call("atos-run", args, record=True, options=options)

        status = call("atos-profile", args, options=opt_level)
        if status != 0: continue  # skip profile variants

        for opts in ['', '-flto', '-funroll-loops', '-flto -funroll-loops']:
            options = ' '.join([opt_level, opts])
            status = call("atos-build", args, uopts=opt_level, options=options)
            if status == 0:
                status = call("atos-run", args, record=True,
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
        call("atos-audit", args, command=process.cmdline2list(
                args.build_script))
        call("atos-deps", args, executables=executables, all=(not executables))
        # TODO: to be replaced by call(atos-config)
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
        call("atos-raudit", args, command=process.cmdline2list(
                args.run_script))
        if not args.no_run:
            call("atos-run", args, record=True)  # reference run

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
        args.options = ""
    if args.fdo and args.uopts == None:
        args.uopts = args.options
    if args.lto:
        args.options += " -flto"
    if args.quiet:
        opt_q = " -q"
    else:
        opt_q = ""
    if args.record:
        opt_r = " -r"
    else:
        opt_r = ""
    opt_nbruns = " -n" + str(args.nbruns)
    if args.remote_path:
        opt_remote_profile_path = "-b " + args.remote_path
    else:
        opt_remote_profile_path = ""

    if args.keep:
        if args.uopts:
            variant = "OPT-fprofile-use" + \
                      "".join(args.uopts.split(' ')) + \
                      "".join(args.options.split(' '))
        elif args.options != "":
            variant = "OPT" + "".join(args.options.split(' '))
        else:
            variant = "REF"
        command = os.path.join(globals.PYTHONDIR, "atos", "atos_lib.py") + \
                  " query -q \"variant:" + variant + "\""
        status, results = process.system(command, get_output=True)
        if results.strip() != "None":
            print "Skipping variant " + variant + "..."
            return 0

    if args.uopts != None:
        command = os.path.join(globals.BINDIR, "atos-profile") + \
                  " -C " + args.configuration_path + opt_q + \
                  opt_remote_profile_path + " -g '" + args.uopts + "'"
        status = process.system(command, print_output=True)
        if status == 0:
            command = os.path.join(globals.BINDIR, "atos-build") + \
                      " -C " + args.configuration_path + opt_q + \
                      " -u '" + args.uopts + "' -a '" + args.options + "'"
            status = process.system(command, print_output=True)
            if status == 0:
                command = os.path.join(globals.BINDIR, "atos-run") \
                          + " -C " + args.configuration_path + opt_q + \
                          opt_r + opt_nbruns + " -u '" + args.uopts + \
                          "' -a'" + args.options + "'"
                status = process.system(command, print_output=True)
    else:
        command = os.path.join(globals.BINDIR, "atos-build") + \
                  " -C " + args.configuration_path + opt_q + \
                  " -a '" + args.options + "'"
        status = process.system(command, print_output=True)
        if status == 0:
            command = os.path.join(globals.BINDIR, "atos-run") + \
                      " -C " + args.configuration_path + opt_q + \
                      opt_r + opt_nbruns + " -a '" + args.options + "'"
            status = process.system(command, print_output=True)
    return status

def run_atos_play(args):
    """ ATOS play tool implementation. """

    if not os.path.isdir(args.configuration_path):
        print "error: atos-play: onfiguration missing: " + \
              args.configuration_path
        sys.exit(1)

    if args.id == None:
        if args.exe == None:
            args.exe = []
            try:
                targetf = open(os.path.join(args.configuration_path,
                                            "targets"),
                               "r")
            except:
                print "error: atos-play: no target " \
                      "executable and no identifier specified"
                sys.exit(1)
            else:
                for line in targetf:
                    args.exe.append(line.strip())
                targetf.close()
        else:
            args.exe = [args.exe]

        args.id = ""
        sep = ""
        for exe in args.exe:
            args.id = sep + args.id + os.path.basename(exe)
            sep = "-"

    if args.ref:
        select_opt = " --variant=REF"
    elif args.localid != None:
        select_opt = " --hash=" + args.localid
    elif args.tradeoff != None:
        select_opt = ""
        for tradeoff in args.tradeoff:
            select_opt = select_opt + " --tradeoff=" + str(tradeoff)
    elif args.obj == "size":
        select_opt = " --tradeoff=0.2"
    else:
        select_opt = " --tradeoff=5.0"

    if args.printconfig:
        print_action = " -p"
    elif args.printvariant:
        print_action = " -P"
    else:
        print_action = ""

    command = os.path.join(globals.PYTHONDIR, "atos", "atos_lib.py") + \
              " play -C " + args.configuration_path + \
              " -i " + args.id + select_opt + " -N " + str(args.nbpoints) + \
              print_action + " \"" + process.list2cmdline(args.command) + "\""
    status = process.system(command, print_output=True)
    return status

def run_atos_profile(args):
    """ ATOS profile tool implementation. """

    if args.quiet:
        opt_q = " -q"
    else:
        opt_q = ""

    if args.path:
        opt_profile_path = " -p " + args.path
    else:
        opt_profile_path = " -p ''"

    if args.options:
        g_opt = " -g '" + args.options + "'"
        a_opt = " -a '" + args.options + "'"
    else:
        g_opt = " -g ''"
        a_opt = " -a ''"

    if args.remote_path:
        opt_remote_profile_path = " -b " + args.remote_path
    else:
        opt_remote_profile_path = ""

    message("Profiling...")

    command_build = (
        os.path.join(globals.BINDIR, "atos-build")
        + " -C " + args.configuration_path + opt_q + opt_profile_path
        + g_opt + a_opt + opt_remote_profile_path)
    command_run = (
        os.path.join(globals.BINDIR, "atos-run")
        + " -C " + args.configuration_path + opt_q + " -s"
        + g_opt + a_opt + opt_remote_profile_path)

    status = process.system(command_build, print_output=True)
    if status == 0:
        status = process.system(command_run, print_output=True)
    return status

def run_atos_raudit(args):
    """ ATOS raudit tool implementation. """

    if args.command == None:
        print "error: atos-raudit: missing run command"
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
        os.chmod(run_sh, stat.S_IRWXU | stat.S_IRGRP |
                 stat.S_IXGRP | stat.S_IROTH | stat.S_IXOTH)
        if args.results_script != None:
            get_res_sh = os.path.join(args.configuration_path, "get_res.sh")
            f = open(get_res_sh, 'w')
            f.write("#!/bin/sh\n")
            f.write("cd ")
            f.write(os.getcwd())
            f.write(" &&  " + args.results_script)
            f.write("\n")
            f.close()
            os.chmod(get_res_sh, stat.S_IRWXU | stat.S_IRGRP |
                     stat.S_IXGRP | stat.S_IROTH | stat.S_IXOTH)

    status = process.system(args.command)
    return status

def run_atos_run(args):
    """ ATOS run tool implementation. """

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

    if args.variant == "REF":
        if args.options != None:
            if args.gopts != None:
                args.variant = ("OPT-fprofile-generate" +
                                ''.join(args.gopts.split()) +
                                ''.join(args.options.split()))
            elif args.uopts != None:
                args.variant = ("OPT-fprofile-use" +
                                ''.join(args.uopts.split()) +
                                ''.join(args.options.split()))
            else:
                args.variant = "OPT" + ''.join(args.options.split())

    if args.record or args.output_file != None:
        args.fd = None

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
        lpvariant = "REF"
        if args.gopts != None:
            lpvariant = "OPT" + "".join(process.cmdline2list(args.gopts))
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
        entry = entry + ",variant:" + args.variant
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
            command = os.path.join(globals.PYTHONDIR, "atos",
                                   "atos_lib.py") +  \
                                   " add_result -r \"" + entry + "\" " + \
                                   args.output_file
            status = process.system(command)
        elif args.fd != None:
            command = os.path.join(globals.PYTHONDIR, "atos",
                                   "atos_lib.py") + \
                                   " add_result -r \"" + entry + \
                                   "\" -C-"
            status, output = process.system(command, get_output=True,
                                            print_output=False)
            if output != None:
                fo.write(output)
        else:
            command = os.path.join(globals.PYTHONDIR, "atos",
                                   "atos_lib.py") + \
                                   " add_result -r \"" + entry + "\" -C " + \
                                   args.configuration_path
            status = process.system(command)

    message("Running variant " + args.variant + "...")
    failure = False
    logs = os.path.join(args.configuration_path, "logs")
    process.commands.mkdir(logs)
    hash_var = atos_lib.hashid(args.variant)
    logfile = os.path.join(logs, "run-" + hash_var + ".log")
    logf = open(logfile, 'w')

    exe_time = ""
    exe_size = ""

    if args.exe != "":
        exe_size = get_size(args.exe)
        if exe_size == -1:
            failure = True

    if args.gopts == None and args.nbruns == None:
        command = (os.path.join(globals.PYTHONDIR, "atos", "atos_lib.py")
                   + " config -C " + args.configuration_path
                   + " --get \"default_values.nb_runs\"")
        status, args.nbruns = process.system(command, get_output=True)
        args.nbruns = args.nbruns and args.nbruns.strip()
    if args.nbruns == "" or args.nbruns == None:
        args.nbruns = 1
    else:
        args.nbruns = int(args.nbruns)

    if args.fd != None:
        fo = os.fdopen(args.fd, "w")

    n = 1
    while n <= args.nbruns:
        logf.write("Running variant " + args.variant +
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
            message("FAILURE while running variant " + args.variant + "...")
            logf.write("FAILURE while running variant " + args.variant)
            logf.write("\n")
            logf.close()
            return 2
        else:
            logf.write("SUCCESS running variant " + args.variant)
            logf.write("\n")
        n = n + 1

    logf.close()
    if args.fd != None:
        fo.close()
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
    status = call("atos-build", args)
    if status != 0: return status

    # reference run
    status = call("atos-run", args,
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

        status = call(
            "atos-build", args, options=result_conf, uopts=result_uconf)
        if status != 0: continue

        call("atos-run", args, configuration_path=args.results_path,
             record=True, options=result_conf, uopts=result_uconf,
             command=[args.run_script])

    return 0
