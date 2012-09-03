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

def invoque(tool, args):
    """ Dispatcher that invoques the given tool and returns. """
    functions = {
        "atos": run_atos,
        "atos-help": run_atos_help,
        "atos-audit": run_atos_audit,
        "atos-deps": run_atos_deps,
        "atos-explore": run_atos_explore,
        "atos-profile": run_atos_profile
        }
    return functions[tool](args)

def execute(tool, args):
    """ Executes the invoque dispatcher and exits. """
    sys.exit(invoque(tool, args))

def run_atos(args):
    """ Top level atos utility implementation. """
    return invoque("atos-" + args.command, args)

def run_atos_help(args):
    """ ATOS help tool implementation. """
    if not args.topic:
        print ""
        print "ATOS auto tuning optimization system manual"
        print "==========================================="
        print
        print "Browse the manual with the following commands:"
        print
        print " atos help intro    : displays ATOS short introduction"
        print " atos help tutorial : displays ATOS tutorial"
        print
        print " atos help COMMAND  : display manual for the given atos COMMAND"
        print
        return 0
    if args.topic[0] == "intro":
        doc = "intro.rst"
    elif args.topic[0] == "tutorial":
        doc = "tutorial.rst"
    else:
        # For now the per command manual does not exist, it may end with
        # a call to man atos-<cmd> for instance
        doc = args.topic[0] + ".rst"
    return atos_lib.pagercall("cat " + os.path.join(globals.SHAREDIR, "doc", doc))

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
        atos_lib.subcall("touch " + args.output_file)
        build_sh = os.path.join(args.configuration_path, "build.sh")
        f = open(build_sh, 'w')
        f.write("#!/bin/sh\n")
        f.write("cd ")
        f.write(os.getcwd())
        f.write(" && $ARUN ")
        f.write(" ".join(args.executables))
        f.write("\n")
        f.close()
        os.chmod(build_sh,stat.S_IRWXU|stat.S_IRGRP|stat.S_IXGRP|stat.S_IROTH|stat.S_IXOTH)
        force_sh = os.path.join(args.configuration_path, "build.force")
        f = open(force_sh, 'w')
        f.write(str(int(args.force)))
        f.close()
    else:
        print "mkdir -p " + args.configuration_path
        print "touch " + args.output_file
        print "fill " + args.configuration_path + "/build.sh"
        print "fill " + args.configuration_path + "/build.force"

    command = ("env PROOT_IGNORE_ELF_INTERPRETER=1 PROOT_ADDON_CC_DEPS=1 PROOT_ADDON_CC_DEPS_OUTPUT=\"" +
               args.output_file + "\" PROOT_ADDON_CC_DEPS_CCRE=\"" + args.ccregexp + "\" " +
               atos_lib.proot_atos() +" -w " + os.getcwd() + " / ")
    command += " ".join(args.executables)
    status, output = atos_lib.system(command, True, False)
    return status

def run_atos_deps(args):
    """ ATOS deps tool implementation. """

    # For now we include all from atos_deps, we may separate modules later
    from atos_deps import CommandDependencyListFactory
    from atos_deps import CCDEPSParser
    from atos_deps import SimpleCmdInterpreter
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
        factory = CommandDependencyListFactory(CCDEPSParser(open(args.input_file)), SimpleCmdInterpreter())
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
            f.write("\n".join(args.executables if args.force else graph.get_targets()) + "\n")
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
        opt_build = " -b \"" + args.build_script + "\""
    else:
        opt_build = ""

    if args.run_script:
        opt_run = " -r \"" + args.run_script + "\""
    else:
        opt_run = ""

    if args.results_script:
        opt_results = " -t \"" + args.results_script + "\""
    else:
        opt_results = ""

    if args.exe:
        executables = " -e \"" + args.exe + "\""
    elif args.executables:
        executables = " -e \"" + " ".join(args.executables) + "\""
    else:
        executables = ""

    if args.remote_path:
        opt_remote_profile_path = " -B \"" + args.remote_path + "\""
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

    status = 0
    command = os.path.join(globals.BINDIR,"atos-init") + " -C " + args.configuration_path \
              + opt_build + opt_run \
              + opt_results + opt_remote_profile_path + executables + opt_nbruns \
              + opt_rebuild + opt_q + opt_c
    status,output = atos_lib.system(command, print_out=True, check_status=True)

    for gopt in ['-O2', '-Os', '-O3']:
        for opts in ['', ' -flto', ' -funroll-loops', ' -flto -funroll-loops']:
            command_build = os.path.join(globals.BINDIR,"atos-build") + " -C " + args.configuration_path + opt_q + " -a'" + gopt + opts + "'"
            status, output = atos_lib.system(command_build, print_out=True)
            if status == 0:
                command_run = os.path.join(globals.BINDIR,"atos-run") + " -C " + args.configuration_path + opt_q + " -r -a'" + gopt + opts + "'"
                status, output = atos_lib.system(command_run, print_out=True)

        command_prof = os.path.join(globals.BINDIR,"atos-profile") +  " -C " + args.configuration_path + opt_q + " -g'" + gopt + "'"
        status, output = atos_lib.system(command_prof, print_out=True)
        if status != 0: continue
        for opts in ['', ' -flto', ' -funroll-loops', ' -flto -funroll-loops']:
            command_build = os.path.join(globals.BINDIR, "atos-build") + " -C " + args.configuration_path + opt_q + " -u'" + gopt + "' -a'" + gopt + opts + "'"
            status,output = atos_lib.system(command_build, print_out=True)
            if status == 0:
                command_run = os.path.join(globals.BINDIR, "atos-run") + " -C " + args.configuration_path + opt_q + " -r -u'" + gopt + "' -a'" + gopt + opts + "'"
                status,output = atos_lib.system(command_run, print_out=True)

    if not args.quiet:
        print "Completed."
    return 0

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

    command_build = os.path.join(globals.BINDIR, "atos-build") + " -C " + args.configuration_path + opt_q + opt_profile_path + g_opt + a_opt + opt_remote_profile_path
    command_run = os.path.join(globals.BINDIR, "atos-run") + " -C " + args.configuration_path + opt_q + " -s" + g_opt + a_opt + opt_remote_profile_path

    status, output = atos_lib.system(command_build, print_out=True)
    if status == 0:
        status, output = atos_lib.system(command_run, print_out=True)
    return status
