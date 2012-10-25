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
    with process.open_locked(mapfile, 'a') as f:
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

def invoque_compile_command(args):

    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument(
        '--atos-fctmap', dest='fctmap', action='store', default=None)
    parser.add_argument(
        '--atos-optfile', dest='optfile', action='store', default=None)

    cwd = os.path.abspath(os.getcwd())
    args = list(args or [])
    env_ACFLAGS = os.environ.get("ACFLAGS")
    if env_ACFLAGS: args.extend(process.cmdline2list(env_ACFLAGS))

    (opts, args) = parser.parse_known_args(args)

    env_PROFILE_DIR = os.environ.get("PROFILE_DIR")
    profdir_common_len = env_PROFILE_DIR and len(
        os.environ.get("COMMON_PROFILE_DIR_PREFIX", "")) or 0
    env_PROFILE_DIR_OPT = os.environ.get("PROFILE_DIR_OPT")

    if is_cc_compile_command(args):  # CC command

        output = atos_lib.get_output_option_value(args)
        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            suffix = not (output and os.path.isabs(output)) and cwd[
                profdir_common_len:] or ''
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    else:  # CCLD command

        env_ALDFLAGS = os.environ.get("ALDFLAGS")
        if env_ALDFLAGS: args.extend(process.cmdline2list(env_ALDFLAGS))

        env_ALDLTOFLAGS = os.environ.get("ALDLTOFLAGS")
        if env_ALDLTOFLAGS: args.extend(process.cmdline2list(env_ALDLTOFLAGS))

        env_ALDSOFLAGS = os.environ.get("ALDSOFLAGS")
        if env_ALDSOFLAGS and atos_lib.is_shared_lib_link(args):
            args.extend(process.cmdline2list(env_ALDSOFLAGS))

        env_ALDMAINFLAGS = os.environ.get("ALDMAINFLAGS")
        if env_ALDMAINFLAGS and not atos_lib.is_shared_lib_link(args):
            args.extend(process.cmdline2list(env_ALDMAINFLAGS))

        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            suffix = cwd[profdir_common_len:]
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    if opts.optfile:
        args.extend(get_cc_command_additional_flags(opts.optfile, args))

    status = process.system(args, print_output=True)

    if opts.fctmap:
        update_function_map(opts.fctmap, args)

    return status


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='atos-driver')

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
    # TODO: fix proot cc_opts plugin and remove --atos-tmp
    parser.add_argument('--atos-tmp', dest='tmp', action='store_true')

    (opts, args) = parser.parse_known_args()

    process.setup(vars(opts))

    logger.setup(vars(opts))

    status = invoque_compile_command(args)

    sys.exit(status)
