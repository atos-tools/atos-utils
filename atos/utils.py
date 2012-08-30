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

import sys
import atos

def invoque(tool, args):
    """ Dispatcher that invoques the given tool and returns. """
    functions = {
        "atos": run_atos,
        "atos-help": run_atos_help
        }
    return functions[tool](args)

def execute(tool, args):
    """ Executes the invoque dispatcher and exits. """
    sys.exit(invoque(tool, args))

def run_atos(args):
    """ Top level atos utility implementation. """
    return invoque("atos-" + args.command, args)

def run_atos_help(args):
    """ ATOS help tool. """
    print
    print "ATOS auto tuning optimization system manual"
    print
    print "To be done:"
    print "- should output a one page description and"
    print "- should output the per command man page when invoqued with 'atos help COMMAND'"
    print
    return 0
