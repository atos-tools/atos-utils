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
from atoslib import atos_lib
from atoslib import process
from atoslib import logger
from atoslib import globals

import re, shlex, argparse

def compile_command_kind(args):
    basename = os.path.basename(args[0])
    m = re.search(globals.DEFAULT_DRIVER_CC_PYREGEXP, basename)
    if m != None and m.group(1) != None:
        if '-c' in args:
            return 'CC'
        else:
            return 'CCLD'
    m = re.search(globals.DEFAULT_DRIVER_AR_PYREGEXP, basename)
    if m != None and m.group(1) != None:
        return 'AR'
    return None

def get_object_function_list(objfile):
    output = process.system(
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

def update_cc_function_map(mapfile, args):
    if compile_command_kind(args) != 'CC': return
    outputs = get_cc_output_files(args)
    if len(outputs) != 1: return
    funclist = get_object_function_list(outputs[0])
    if not funclist: funclist = ['#']
    with process.open_locked(mapfile, 'a') as f:
        f.write(''.join(
                map(lambda x: '%s %s\n' % (outputs[0], x), funclist)))

def get_cc_output_files(args):
    def objext(i): return os.path.splitext(i)[0] + '.o'
    assert compile_command_kind(args) == 'CC'
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
    if compile_command_kind(args) != 'CC': return shlex.split(def_opts)
    outputs = get_cc_output_files(args)
    if len(outputs) != 1: return shlex.split(def_opts)
    return shlex.split(obj_opts.get(outputs[0], def_opts))

def invoque_compile_command(args):

    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument(
        '--atos-fctmap', dest='fctmap', action='store', default=None)
    parser.add_argument(
        '--atos-optfile', dest='optfile', action='store', default=None)
    parser.add_argument(
        '--atos-audit', dest='audit_file', action='store', default=None)

    cwd = os.path.abspath(os.getcwd())
    args = list(args or [])

    kind = compile_command_kind(args)

    if kind == 'CCLD':

        env_ALDLTOFLAGS = os.environ.get("ALDLTOFLAGS")
        if env_ALDLTOFLAGS: args.extend(
            process.cmdline2list(env_ALDLTOFLAGS))

    if kind == 'CC' or kind == 'CCLD':
        env_ACFLAGS = os.environ.get("ACFLAGS")
        if env_ACFLAGS: args.extend(process.cmdline2list(env_ACFLAGS))

    if kind == 'CCLD':

        env_ALDFLAGS = os.environ.get("ALDFLAGS")
        if env_ALDFLAGS: args.extend(process.cmdline2list(env_ALDFLAGS))

    env_PROFILE_DIR = os.environ.get("PROFILE_DIR")
    profdir_common_len = env_PROFILE_DIR and len(
        os.environ.get("COMMON_PROFILE_DIR_PREFIX", "")) or 0
    env_PROFILE_DIR_OPT = os.environ.get("PROFILE_DIR_OPT")

    if kind == 'CC':

        output = atos_lib.get_output_option_value(args)
        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            suffix = not (output and os.path.isabs(output)) and cwd[
                profdir_common_len:] or ''
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    elif kind == 'CCLD':

        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            suffix = cwd[profdir_common_len:]
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

        env_ALDSOFLAGS = os.environ.get("ALDSOFLAGS")
        if env_ALDSOFLAGS and atos_lib.is_shared_lib_link(args):
            args.extend(process.cmdline2list(env_ALDSOFLAGS))

        env_ALDMAINFLAGS = os.environ.get("ALDMAINFLAGS")
        if env_ALDMAINFLAGS and not atos_lib.is_shared_lib_link(args):
            args.extend(process.cmdline2list(env_ALDMAINFLAGS))

    (opts, args) = parser.parse_known_args(args)

    if (kind == 'CC' or kind == 'CCLD') and opts.optfile:
        args.extend(get_cc_command_additional_flags(opts.optfile, args))

    if opts.audit_file:
        exp_args = atos_lib.expand_response_file(args)
        with open(opts.audit_file, "a") as outfile:
            print >>outfile, ": ".join(
                ["CC_DEPS",
                 '"%s"' % process.commands.which(args[0]),
                 ", ".join(map(lambda x: '"%s"' % x, exp_args)) + ": ",
                 '"%s"' % cwd]
                )
            outfile.flush()

    status = process.system(args, print_output=True)

    if (kind == 'CC' or kind == 'CCLD') and opts.fctmap:
        update_cc_function_map(opts.fctmap, args)

    return status


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='atos-driver')

    parser.add_argument('--atos-debug', dest='debug',
                      action='store_true', default=False,
                      help='print debug information (default: False)')
    parser.add_argument('--atos-dryrun', dest='dryrun',
                      action='store_true', default=False,
                      help='only print commands (default: False)')
    parser.add_argument('--atos-version', action='version',
                        version='atos-driver version ' + VERSION)
    # TODO: fix proot cc_opts plugin and remove --atos-tmp
    parser.add_argument('--atos-tmp', dest='tmp', action='store_true',
                        help=argparse.SUPPRESS)

    (opts, args) = parser.parse_known_args()

    process.setup(vars(opts))

    logger.setup(vars(opts))

    status = invoque_compile_command(args)

    sys.exit(status)
