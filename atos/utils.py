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
import atos

def invoque(tool, args):
    """ Dispatcher that invoques the given tool and returns. """
    functions = {
        "atos": run_atos,
        "atos-help": run_atos_help,
        "atos-deps": run_atos_deps
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
    print
    print "ATOS auto tuning optimization system manual"
    print
    print "To be done:"
    print "- should output a one page description and"
    print "- should output the per command man page when invoqued with 'atos help COMMAND'"
    print
    return 0

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
