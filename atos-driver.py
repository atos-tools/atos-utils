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
from atoslib import cmd_interpreter
from atoslib.recipes import RecipeStorage, RecipeNode
import re, shlex, argparse, functools

command_interpreter_ = None

def get_interpreter():
    global command_interpreter_
    return command_interpreter_

def set_interpreter(opts, args):
    global command_interpreter_
    factory = cmd_interpreter.CmdInterpreterFactory(
        opts.configuration_path)
    interpreter = factory.get_interpreter(
        {'cwd': os.path.abspath(os.getcwd()),
             'args': args})
    if not (interpreter and interpreter.is_wellformed()):
        # Ignore unknnow command kind or malformed commands
        interpreter = None
    elif not (interpreter.get_kind() == "AR" or
              interpreter.get_kind() == "CC" and
              (interpreter.cc_interpreter().has_cc_phase("CC") or
               interpreter.cc_interpreter().has_cc_phase("LD"))):
        # Ignore commands which are not AR or a CC driver
        # running either CC or LD phase
        interpreter = None
    command_interpreter_ = interpreter
    return interpreter

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

def update_cc_function_map(opts, args):
    interpreter = get_interpreter()
    assert(interpreter != None)
    if (interpreter.get_kind() != "CC" or
        not interpreter.cc_interpreter().has_cc_phase("CC") or
        interpreter.cc_interpreter().last_cc_phase() != "AS"):
        # TODO: handle function map in LD phase also
        return
    outputs = interpreter.cc_interpreter().all_cc_outputs()
    if len(outputs) != 1:
        # TODO: handle multiple outputs
        return
    funclist = get_object_function_list(outputs[0])
    if not funclist: funclist = ['#']
    with process.open_locked(opts.fctmap, 'a') as f:
        f.write(''.join(
                map(lambda x: '%s %s\n' % (outputs[0], x), funclist)))

def get_cc_command_additional_flags(opts, args):
    interpreter = get_interpreter()
    assert(interpreter != None)
    if interpreter.get_kind() != "CC": return []
    if not opts.optfile: return []
    obj_opts = {}
    for line in open(opts.optfile):
        obj, flags = line.strip().split(',', 1)
        obj_opts[obj] = flags
    def_opts = obj_opts.get('*', '')
    if not interpreter.cc_interpreter().has_cc_phase("CC"):
        return shlex.split(def_opts)
    outputs = interpreter.cc_interpreter().all_cc_outputs()
    if len(outputs) != 1:
        # TODO: handle multiple input files
        return shlex.split(def_opts)
    return shlex.split(obj_opts.get(outputs[0], def_opts))

def legacy_audit_compile_command(opts, args):

    status = process.system(args, print_output=True)

    if status != 0:
        # Record command only in case of success
        return status

    cwd = os.path.abspath(os.getcwd())
    interpreter = set_interpreter(opts, args)
    if interpreter:
        # TODO: if response file is removed it does not work,
        # thus we expand it there in interpreter.get_args().
        # We should change this as it may build a too long command line.
        exp_args = interpreter.get_args()
        outline = ": ".join(
            ["CC_DEPS",
             '"%s"' % process.commands.which(args[0]),
             ", ".join(map(lambda x: '"%s"' % x, exp_args)) + ": ",
             '"%s"' % cwd])
        with open(opts.audit_file, "a", len(outline) + 1) as outfile:
            print >>outfile, outline
            outfile.flush()

    return status

def audit_compile_command(opts, args):
    if opts.legacy:
        return legacy_audit_compile_command(opts, args)

    def filter_envs(envs):
        """
        Filter out ATOS internal keys in environment.
        In particular PROOT envs used for the audit.
        """
        return dict((k, v) for k, v in envs.items() if
                    k.find("PROOT_ADDON_CC_OPTS") != 0)

    interpreter = set_interpreter(opts, args)
    if not interpreter:
        # Do not record this command, just run it
        return process.system(args, print_output=True)

    stgdir = opts.audit_file
    if stgdir == None:
        stgdir = os.path.join(opts.configuration_path, "build.stg")
    stg = RecipeStorage(stgdir)

    # TODO: if response file is removed it does not work,
    # thus we expand it there in interpreter.get_args().
    # We should change this as it may build a too long command line.
    inputs = interpreter.get_input_files()
    inps_digest = stg.store_path_ref_list(map(os.path.abspath, inputs))
    status = process.system(args, print_output=True)
    if status != 0:
        return status
    prog = process.commands.which(args[0])
    cwd = os.getcwd()
    exp_args = interpreter.get_args()
    envs = filter_envs(dict(os.environ))
    kind = interpreter.get_kind()
    cnod_digest = stg.store_cmd_node(prog, cwd, exp_args, envs, kind)
    outputs = interpreter.get_output_files()
    outs_digest = stg.store_path_ref_list(map(os.path.abspath, outputs))
    rnod_digest = stg.store_recipe_node(
                    cnod_digest, inps_digest, outs_digest)
    stg.append_recipes_file(rnod_digest)
    return status

def invoque_compile_command(opts, args):

    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument(
        '--atos-fctmap', dest='fctmap', action='store', default=None)
    parser.add_argument(
        '--atos-optfile', dest='optfile', action='store', default=None)

    cwd = os.path.abspath(os.getcwd())

    interpreter = set_interpreter(opts, args)

    has_final_link = (interpreter and interpreter.get_kind() == "CC" and
                      interpreter.cc_interpreter().has_cc_phase("LD") and
                      (interpreter.cc_interpreter().is_ld_kind("program") or
                       interpreter.cc_interpreter().is_ld_kind("shared")))
    has_cc = (interpreter and interpreter.get_kind() == "CC" and
              interpreter.cc_interpreter().has_cc_phase("CC"))

    cc_outputs = ((has_final_link or has_cc) and
                  interpreter.cc_interpreter().all_cc_outputs())

    if has_final_link:
        cc_output_pathes = map(os.path.abspath, map(
                functools.partial(os.path.join, os.getcwd()), cc_outputs))
        cc_output_sums = map(atos_lib.sha1sum, cc_output_pathes)
        for output_sum in cc_output_sums:
            env_ALDLTOFLAGS = os.environ.get("ALDLTOFLAGS_" + output_sum)
            if env_ALDLTOFLAGS: args.extend(
                process.cmdline2list(env_ALDLTOFLAGS))

    if has_cc or has_final_link:
        env_ACFLAGS = os.environ.get("ACFLAGS")
        if env_ACFLAGS: args.extend(process.cmdline2list(env_ACFLAGS))

    if has_final_link:
        env_ALDFLAGS = os.environ.get("ALDFLAGS")
        if env_ALDFLAGS: args.extend(process.cmdline2list(env_ALDFLAGS))

    env_PROFILE_DIR = os.environ.get("PROFILE_DIR")
    profdir_common_len = env_PROFILE_DIR and len(
        os.environ.get("COMMON_PROFILE_DIR_PREFIX", "")) or 0
    env_PROFILE_DIR_OPT = os.environ.get("PROFILE_DIR_OPT")

    if has_cc:
        assert(len(cc_outputs) >= 1)
        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            abs_output_dir = os.path.isabs(cc_outputs[0])
            suffix = '' if abs_output_dir else cwd[profdir_common_len:]
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    elif has_final_link:
        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            suffix = cwd[profdir_common_len:]
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    if has_final_link:
        env_ALDSOFLAGS = os.environ.get("ALDSOFLAGS")
        if (env_ALDSOFLAGS and
            interpreter.cc_interpreter().is_ld_kind("shared")):
            args.extend(process.cmdline2list(env_ALDSOFLAGS))

        env_ALDMAINFLAGS = os.environ.get("ALDMAINFLAGS")
        if (env_ALDMAINFLAGS and
            interpreter.cc_interpreter().is_ld_kind("program")):
            args.extend(process.cmdline2list(env_ALDMAINFLAGS))

    (new_opts, args) = parser.parse_known_args(args)
    opts.__dict__.update(vars(new_opts))

    if (has_cc or has_final_link) and opts.optfile:
        args.extend(get_cc_command_additional_flags(opts, args))

    if not opts.legacy and opts.recipe_digest:
        # Read recipe node and prepare input files.
        stgdir = opts.audit_file
        if stgdir == None:
            stgdir = os.path.join(opts.configuration_path, "build.stg")
        stg = RecipeStorage(stgdir)
        recipe_node = RecipeNode(stg, opts.recipe_digest, cwd)
        recipe_node.fetch_input_files()

    status = process.system(args, print_output=True)

    if (has_cc or has_final_link) and opts.fctmap:
        update_cc_function_map(opts, args)

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
    parser.add_argument('--atos-cfg', dest='configuration_path',
                        default=globals.DEFAULT_CONFIGURATION_PATH,
                        help='configuration path')
    parser.add_argument('--atos-audit', dest='audit_file',
                        action='store', default=None)
    parser.add_argument('--atos-legacy', dest='legacy',
                        action='store_true', default=None)
    parser.add_argument('--atos-recipe', dest='recipe_digest',
                        action='store', default=None)

    (opts, args) = parser.parse_known_args()

    process.setup(vars(opts))

    logger.setup(vars(opts))

    if opts.audit_file:
        status = audit_compile_command(opts, args)
    else:
        status = invoque_compile_command(opts, args)

    sys.exit(status)
