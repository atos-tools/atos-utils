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
import atos_lib
import fnmatch
import logger
import process

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
        "atos-profile": run_atos_profile
        }
    if hasattr(args, "coverage") and args.coverage:
        import coverage
        cov = coverage.coverage(data_file=args.coverage_file)
        cov.start()
        try:
            return functions[tool](args)
        finally:
            cov.stop()
            cov.save()
    logger.setup(vars(args))
    process.setup(vars(args))
    return functions[tool](args)

def execute(tool, args):
    """ Executes the invoque dispatcher and exits. """
    sys.exit(invoque(tool, args))

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

    if args.quiet != 1:
        print "Auditing build..."

    if args.ccname:
        args.ccregexp = '^' + args.ccname + '$'
    if args.output_file == None:
        args.output_file = os.path.join(args.configuration_path, "build.audit")

    if not args.dryrun:
        if not os.path.isdir(args.configuration_path):
            os.mkdir(args.configuration_path)
        process.system("touch " + args.output_file)
        build_sh = os.path.join(args.configuration_path, "build.sh")
        f = open(build_sh, 'w')
        f.write("#!/bin/sh\n")
        f.write("cd ")
        f.write(os.getcwd())
        f.write(" && $ARUN ")
        f.write(process.list2cmdline(args.command))
        f.write("\n")
        f.close()
        os.chmod(build_sh, stat.S_IRWXU | stat.S_IRGRP |
                 stat.S_IXGRP | stat.S_IROTH | stat.S_IXOTH)
        force_sh = os.path.join(args.configuration_path, "build.force")
        f = open(force_sh, 'w')
        f.write(str(int(args.force)))
        f.close()
    else:
        print "mkdir -p " + args.configuration_path
        print "touch " + args.output_file
        print "fill " + args.configuration_path + "/build.sh"
        print "fill " + args.configuration_path + "/build.force"

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
    if timeout != None:
        timeout = os.path.join(globals.BINDIR, "atos-timeout") + " 3600"
    else:
        timeout = ""

    if args.ccname:
        args.ccregexp = '^' + args.ccname + '$'

    if args.gopts != None:
        if args.gopts:
            pvariant = ''.join(args.gopts.split())
        if not args.path:
            profile_path = os.path.join(
                args.configuration_path, "profiles", atos_lib.hashid(pvariant))
        else:
            profile_path = args.path
        if not os.path.isdir(profile_path):
            os.makedirs(profile_path)
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
            pvariant = ''.join(args.uopts.split())
        if not profile_path:
            profile_path = os.path.join(
                args.configuration_path, "profiles", atos_lib.hashid(pvariant))
        if not os.path.isdir(profile_path):
            os.makedirs(profile_path)
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
    if args.dryrun:
        print "mkdir -p " + logs
    else:
        if not os.path.isdir(logs):
            os.makedirs(logs)

    if not args.dryrun:
        hash_var = atos_lib.hashid(variant)
        logfile = os.path.join(logs, "build-" + hash_var + ".log")
        logf = open(logfile, 'w')

    if not args.quiet:
        print "Building variant " + variant + "..."
    if not args.dryrun:
        logf.write("Building variant ")
        logf.write(variant)
        logf.write('\n')

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
        if args.dryrun:
            command = command + " -n"
            process.system(command)
        else:
            command = command + " -j" + str(args.jobs)
            (status, output) = process.system(
                command, get_output=True, output_stderr=True)
            logf.write(output)
            logf.write('\n')
            if status:
                failure = 1

    elif not args.command and opt_rebuild == 1 and os.path.isfile(build_sh):
        if args.dryrun:
            print "Executing: " + build_sh
        else:
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
            logf.write(output)
            logf.write('\n')
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
        if not args.dryrun:
            print "Executing: "
            command = command + " -j" + str(args.j)
            (status, output) = process.system(
                command, get_output=True, output_stderr=True)
            logf.write(output)
            logf.write('\n')
            if status:
                failure = 1

    if failure == 1:
        if not args.quiet:
            print "FAILURE while building variant " + variant + "..."
        if not args.dryrun:
            logf.write("FAILURE while building variant ")
            logf.write(variant)
            logf.write('\n')
            logf.close()
            sys.exit(2)
        else:
            if not args.dryrun:
                logf.write("SUCCESS building variant ")
                logf.write(variant)
                logf.write('\n')
                logf.close()

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

    if not args.quiet:
        print "Computing build dependencies..."

    if not args.dryrun:
        factory = CommandDependencyListFactory(
            CCDEPSParser(open(args.input_file)), SimpleCmdInterpreter())
        factory.build_dependencies()
        dependencies = factory.get_dependencies()
        builder = DependencyGraphBuilder(dependencies, targets)
        builder.build_graph()
        graph = builder.get_graph()

        if not args.force:
            graph.output_makefile(args.output_file)

    if not args.dryrun:
        # For now only write targets if configuration dir is there
        try:
            f = open(os.path.join(args.configuration_path, "targets"), "w")
        except:
            pass
        else:
            f.write("\n".join(args.executables
                              if args.force else graph.get_targets()) + "\n")
            f.close()
    else:
        print "fill " + args.configuration_path + "/targets"

    if not args.dryrun:
        try:
            f = open(os.path.join(args.configuration_path, "objects"), "w")
        except:
            pass
        else:
            f.write("\n".join(graph.get_objects()) + "\n")
            f.close()
    else:
        print "fill " + args.configuration_path + "/objects"

    if not args.dryrun:
        # For now only write compilers if configuration dir is there
        try:
            f = open(os.path.join(args.configuration_path, "compilers"), "w")
        except:
            pass
        else:
            f.write('\n'.join(graph.get_compilers()) + '\n')
            f.close()
    else:
        print "fill " + args.configuration_path + "/compilers"

    return 0

def run_atos_explore(args):
    """ ATOS explore tool implementation. """

    if args.build_script:
        opt_build = " -b '" + args.build_script + "'"
    else:
        opt_build = ""

    if args.run_script:
        opt_run = " -r '" + args.run_script + "'"
    else:
        opt_run = ""

    if args.results_script:
        opt_results = " -t '" + args.results_script + "'"
    else:
        opt_results = ""

    if args.exe:
        executables = " -e '" + args.exe + "'"
    elif args.executables:
        executables = " -e '" + " ".join(args.executables) + "'"
    else:
        executables = ""

    if args.remote_path:
        opt_remote_profile_path = " -B '" + args.remote_path + "'"
    else:
        opt_remote_profile_path = ""

    opt_nbruns = " -n " + str(args.nbruns)
    if args.quiet:
        opt_q = " -q"
    else:
        opt_q = ""

    if args.clean:
        opt_c = " -c"
    else:
        opt_c = ""

    if args.force:
        opt_rebuild = " -f"
    else:
        opt_rebuild = ""

    command = (
        os.path.join(globals.BINDIR, "atos-init")
        + " -C " + args.configuration_path + opt_build + opt_run
        + opt_results + opt_remote_profile_path + executables
        + opt_nbruns + opt_rebuild + opt_q + opt_c)
    process.system(command, print_output=True, check_status=True)

    for gopt in ['-O2', '-Os', '-O3']:
        for opts in ['', ' -flto', ' -funroll-loops', ' -flto -funroll-loops']:
            command_build = (
                os.path.join(globals.BINDIR, "atos-build")
                + " -C " + args.configuration_path + opt_q + " -a'"
                + gopt + opts + "'")
            status = process.system(command_build, print_output=True)
            if status == 0:
                command_run = (
                    os.path.join(globals.BINDIR, "atos-run")
                    + " -C " + args.configuration_path + opt_q + " -r -a'"
                    + gopt + opts + "'")
                process.system(command_run, print_output=True)

        command_prof = (
            os.path.join(globals.BINDIR, "atos-profile")
            + " -C " + args.configuration_path + opt_q + " -g'" + gopt + "'")
        status = process.system(command_prof, print_output=True)
        if status != 0: continue
        for opts in ['', ' -flto', ' -funroll-loops', ' -flto -funroll-loops']:
            command_build = (
                os.path.join(globals.BINDIR, "atos-build")
                + " -C " + args.configuration_path + opt_q + " -u'"
                + gopt + "' -a'" + gopt + opts + "'")
            status = process.system(command_build, print_output=True)
            if status == 0:
                command_run = (
                    os.path.join(globals.BINDIR, "atos-run")
                    + " -C " + args.configuration_path + opt_q + " -r -u'"
                    + gopt + "' -a'" + gopt + opts + "'")
                process.system(command_run, print_output=True)

    if not args.quiet:
        print "Completed."
    return 0

def run_atos_init(args):
    """ ATOS init tool implementation. """

    if args.exe:
        executables = " " + args.exe
    elif args.executables:
        executables = " ".join(process.list2cmdline(args.executables))
    else:
        executables = ""

    if args.force and not args.results_script and args.executables == "":
        print "atos-init: error: when using forced mode (-f) with no custom " \
        "results script (-t) the list of executables must be specified " \
        "(-e option)"
        sys.exit(1)

    if args.results_script:
        opt_get_results_script = " -t " + args.results_script
    else:
        opt_get_results_script = ""
    if args.remote_path:
        opt_remote_profile_path = args.remote_path
    else:
        opt_remote_profile_path = ""
    opt_nbruns = " -n " + str(args.nbruns)
    if args.quiet:
        opt_q = " -q"
    else:
        opt_q = " "
    if args.clean:
        opt_c = " -c"
    else:
        opt_c = ""
    if args.force:
        opt_rebuild = " -f"
    else:
        opt_rebuild = " "

    if executables == "":
        executables = " -a"

    if not os.path.isdir(args.configuration_path):
        os.makedirs(args.configuration_path)

    if args.clean:
        if args.build_script:
            if args.dryrun:
                print "Cleaning build audit..."
            else:
                if not args.quiet:
                    print "Cleaning build audit..."
                rmcommand = "rm -f " + args.configuration_path + "/build.*"
                process.system(rmcommand, print_output=True)
        if args.run_script:
            if args.dryrun:
                print "Cleaning run audit..."
            else:
                if not args.quiet:
                    print "Cleaning run audit..."
                rmcommand = "rm -f " + args.configuration_path + "/run.*"
                process.system(rmcommand, print_output=True)
        if args.dryrun:
            print "Cleaning all profiles..."
        else:
            if not args.quiet:
                print "Cleaning all profiles..."
            rmcommand = "rm -rf " + args.configuration_path + "/profiles"
            process.system(rmcommand, print_output=True)
        if args.dryrun:
            print "Cleaning all results..."
        else:
            if not args.quiet:
                print "Cleaning all results..."
            rmcommand = "rm -rf " + args.configuration_path + "/results.db"
            process.system(rmcommand, print_output=True)

    if args.build_script:
        command_audit = (
            os.path.join(globals.BINDIR, "atos-audit")
            + " -C " + args.configuration_path + opt_q
            + opt_rebuild + " " + args.build_script)
        process.system(command_audit)
        command_deps = (
            os.path.join(globals.BINDIR, "atos-deps")
            + " -C " + args.configuration_path + opt_q
            + opt_rebuild + executables)
        process.system(command_deps)
        command_config = (
            os.path.join(globals.BINDIR, "atos-config")
            + " -C " + args.configuration_path)
        process.system(command_config)
    elif not os.path.isfile(args.configuration_path + "/build.audit"):
        print "atos-init:error: missing build audit, " \
            "use -b option for specifying build script or use atos-audit tool"
        sys.exit(1)

    command = (os.path.join(globals.PYTHONDIR, "atos", "atos_lib.py")
               + " config -C " + args.configuration_path
               + " --add \"default_values.remote_profile_path:"
               + opt_remote_profile_path + "\"")
    process.system(command)
    command = (
        os.path.join(globals.PYTHONDIR, "atos", "atos_lib.py") +
        " config -C " + args.configuration_path +
        " --add \"default_values.nb_runs:" + str(args.nbruns) + "\"")
    process.system(command)

    if args.run_script:
        command_raudit = (
            os.path.join(globals.BINDIR, "atos-raudit")
            + " -C " + args.configuration_path + opt_q +
            opt_get_results_script + args.run_script)
        process.system(command_raudit)
        # reference run
        command_run = (
            os.path.join(globals.BINDIR, "atos-run")
            + " -C " + args.configuration_path + opt_q + " -r")
        process.system(command_run)
    elif not os.path.isfile(args.configuration_path + "/run.audit"):
        print "atos-init: error: missing run audit, " \
            "use -r option for specifying run script or use atos-raudit tool"
        sys.exit(1)

    if args.prof_script:
        prof_sh = os.path.join(args.configuration_path, "profile.sh")
        proff = open(prof_sh, 'w')
        proff.write("#!/bin/sh\n")
        proff.write("cd $PWD && " + args.prof_script)
        proff.write("\n")
        proff.close()
        process.system("chmod 755 " + prof_sh)

def run_atos_opt(args):
    """ ATOS opt tool implementation. """

    if args.fdo and args.uopts == None:
        args.uopts = args.options
    if args.lto:
        args.options.join(" -flto")
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
    if args.options == None:
        args.options = ""

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
            sys.exit(0)

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

    if not args.quiet:
        print "Profiling..."

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
