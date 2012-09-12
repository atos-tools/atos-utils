#!/usr/bin/env python
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
# Usage: get usage with atos-driver --atos-help
#

VERSION = "@VERSION@"

import sys, os
sys.path.insert(0, os.path.abspath(os.path.join(
            os.path.dirname(__file__), '..', 'lib', 'atos', 'python')))
from atos import atos_lib
from atos import process
from atos import logger

import re, shlex, argparse

def get_object_function_list(objfile):
    status, output = process.system(
        'readelf --wide --symbols ' + objfile,
        check_status=True, get_output=True)
    funclist = []
    for line in output.split('\n'):
        reobj = re.match('\s+[0-9]+:' + 7 * '\s+(\S+)', line)
        if not reobj: continue
        # 1: 00000000     0 FUNC    GLOBAL DEFAULT  UND open@GLIBC_2.0 (2)
        value, size, type, bind, vis, ndx, name = reobj.groups()
        if type != 'FUNC' or ndx == 'UND': continue
        funclist.append(name)
    return funclist

def update_function_map(mapfile, args):
    if not is_cc_compile_command(args): return
    outputs = get_cc_output_files(args)
    if len(outputs) != 1: return
    funclist = get_object_function_list(outputs[0])
    if not funclist: funclist = ['#']
    with atos_lib.open_locked(mapfile, 'a') as f:
        f.write(''.join(
                map(lambda x: '%s %s\n' % (outputs[0], x), funclist)))

def is_cc_compile_command(args):
    return '-c' in args

def get_cc_output_files(args):
    def objext(i): return os.path.splitext(i)[0] + '.o'
    assert is_cc_compile_command(args)
    output = atos_lib.get_output_option_value(args)
    if output: return [output]
    inputs = atos_lib.get_input_source_files(args)
    return map(objext, inputs)

def get_cc_command_additional_flags(optfile, args):
    if not optfile: return []
    obj_opts = {}
    for line in open(optfile):
        obj, opts = line.strip().split(',', 1)
        obj_opts[obj] = opts
    def_opts = obj_opts.get('*', '')
    if not is_cc_compile_command(args): return shlex.split(def_opts)
    outputs = get_cc_output_files(args)
    if len(outputs) != 1: return shlex.split(def_opts)
    return shlex.split(obj_opts.get(outputs[0], def_opts))

def invoque_compile_command(args, optfile=None):
    status = process.system(
        args + get_cc_command_additional_flags(optfile, args))
    return status


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='atos-driver', add_help=False)

    parser.add_argument('--atos-help', dest='help',
                      action='store_true', default=False,
                      help='print help message')

    parser.add_argument('--atos-debug', dest='debug',
                      action='store_true', default=False,
                      help='print debug information (default: False)')
    parser.add_argument('--atos-dryrun', dest='dryrun',
                      action='store_true', default=False,
                      help='only print commands (default: False)')
    parser.add_argument('--atos-version', action='version',
                        version='atos-driver version ' + VERSION)

    parser.add_argument('--atos-fctmap', dest='fctmap',
                      action='store', default=None,
                      help='write function map in <fctmap> file')
    parser.add_argument('--atos-optfile', dest='optfile',
                      action='store', default=None,
                      help='set option file')

    (opts, args) = parser.parse_known_args()

    if opts.help:
        parser.print_help()
        parser.exit()

    process.setup(vars(opts))

    logger.setup(vars(opts))

    status = 0

    if args: status = invoque_compile_command(args, optfile=opts.optfile)

    if opts.fctmap: update_function_map(opts.fctmap, args)

    sys.exit(status)
