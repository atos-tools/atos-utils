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
import re, shlex, argparse
import tempfile

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
              interpreter.get_kind() == "LD" or
              interpreter.get_kind() == "CC" and
              (interpreter.ccld_interpreter().has_cc_phase("CC") or
               interpreter.ccld_interpreter().has_cc_phase("LD"))):
        # Ignore commands which are not AR or LD or
        # a CC driver running either CC or LD phase
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
        not interpreter.ccld_interpreter().has_cc_phase("CC") or
        interpreter.ccld_interpreter().last_cc_phase() != "AS"):
        # TODO: handle function map in LD phase also
        return
    outputs = interpreter.ccld_interpreter().all_cc_outputs()
    if len(outputs) != 1:  # pragma: uncovered
        # TODO: handle multiple outputs
        return
    funclist = get_object_function_list(outputs[0])
    if not funclist: funclist = ['#']
    with process.open_locked(opts.fctmap, 'a') as f:
        f.write(''.join(
                map(lambda x: '%s %s\n' % (outputs[0], x), funclist)))

def get_cc_command_additional_flags(opts, args):
    interpreter = get_interpreter()
    assert interpreter
    assert opts.optfile
    if interpreter.get_kind() != "CC":  # pragma: uncovered
        return []
    obj_opts = {}
    for line in open(opts.optfile):
        obj, flags = line.strip().split(',', 1)
        obj_opts[obj] = flags
    def_opts = obj_opts.get('*', '')
    if not interpreter.ccld_interpreter().has_cc_phase("CC"):
        return shlex.split(def_opts)
    outputs = interpreter.ccld_interpreter().all_cc_outputs()
    if len(outputs) != 1:  # pragma: uncovered
        # TODO: handle multiple input files
        return shlex.split(def_opts)
    return shlex.split(obj_opts.get(outputs[0], def_opts))

def legacy_audit_compile_command(opts, args):

    status = process.system(args, print_output=True)

    if status != 0:  # pragma: uncovered (error)
        # Record command only in case of success
        return status

    cwd = os.path.abspath(os.getcwd())
    interpreter = set_interpreter(opts, args)
    if interpreter:  # pragma: branch_uncovered
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

    logger.debug("audit: %s" % process.list2cmdline(args))

    if opts.legacy:
        return legacy_audit_compile_command(opts, args)

    def prepare_inputs(input_pairs):
        """
        This function prepare inputs and ensure that they are
        available for dependency computation from the given
        input pairs (src_kind, path).
        This includes:
        - making input paths absolute paths,
        - handling of pre-compiled headers,
        - handling of missing inputs, removed from dependencies,
        - handling of non regular file ("/dev/null" for instance),
        removed from dependencies.
        """
        actual_inputs = []
        for (src_kind, path) in input_pairs:
            actual_input = os.path.abspath(path)
            if src_kind == 'SRC_PCH':  # pragma: uncovered
                # Ensure that there is an existing fallback include
                # for the precompiled header (.gch) and
                # return the fallback include instead of the .gch.
                # An empty fallback include is created when missing.
                # This will have the effect of ignoring the
                # precompiled header when it is not compatible with
                # the options forced by the driver.
                (fallback_header, ext) = actual_input.rsplit(".", 1)
                assert(ext == "gch")
                actual_input = fallback_header
                if not os.path.exists(fallback_header):
                    process.commands.touch(fallback_header)
            if os.path.exists(actual_input) and os.path.isfile(actual_input):
                actual_inputs.append(actual_input)
        return actual_inputs

    def prepare_outputs(output_paths):
        """
        This function prepare outputs and ensure that they are
        available for dependency computation from the given
        ouputs path list.
        This includes:
        - making output paths absolute paths,
        - handling of missing outputs, ignored,
        - handling of non regular file ("/dev/null" for instance),
        ignored.
        """
        actual_outputs = []
        for path in output_paths:
            actual_output = os.path.abspath(path)
            if os.path.exists(actual_output) and os.path.isfile(actual_output):
                actual_outputs.append(actual_output)
        return actual_outputs

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
    if stgdir == None:  # pragma: uncovered
        stgdir = os.path.join(opts.configuration_path, "build.stg")
    stg = RecipeStorage(stgdir)

    # TODO: if response file is removed it does not work,
    # thus we expand it there in interpreter.get_args().
    # We should change this as it may build a too long command line.
    input_pairs = interpreter.get_input_pairs()
    actual_inputs = prepare_inputs(input_pairs)
    inps_digest = stg.store_path_ref_list(actual_inputs)
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
    actual_outputs = prepare_outputs(outputs)
    outs_digest = stg.store_path_ref_list(actual_outputs)
    rnod_digest = stg.store_recipe_node(
                    cnod_digest, inps_digest, outs_digest)
    stg.append_recipes_file(rnod_digest)
    return status

def invoque_compile_command(opts, args):

    logger.debug("invoque: %s" % process.list2cmdline(args))

    cwd = os.path.abspath(os.getcwd())
    tempfiles = []
    command_env = {}

    stg, recipe_node = None, None
    if not opts.legacy and opts.recipe_digest:
        stgdir = opts.audit_file
        if stgdir == None:  # pragma: branch_uncovered
            stgdir = os.path.join(opts.configuration_path, "build.stg")
        stg = RecipeStorage(stgdir)
        recipe_node = RecipeNode(stg, opts.recipe_digest, cwd)

    if recipe_node and stg.blacklist_contains(
        opts.recipe_digest):  # pragma: uncovered
        # If blacklisted, do not run the command at all
        logger.debug("atos-driver: skip compilation of blacklisted recipe: %s"
                     % opts.recipe_digest)
        recipe_node.get_output_files()
        return 0

    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument(
        '--atos-fctmap', dest='fctmap', action='store', default=None)
    parser.add_argument(
        '--atos-optfile', dest='optfile', action='store', default=None)

    interpreter = set_interpreter(opts, args)

    is_cc = interpreter and interpreter.get_kind() == "CC"
    is_ld = interpreter and interpreter.get_kind() == "LD"
    has_link_phase = (
        (is_cc and interpreter.ccld_interpreter().has_cc_phase("LD")) or
        (is_ld and (len(interpreter.ccld_interpreter().all_cc_outputs()) > 0)))
    generates_prog = (
        has_link_phase and interpreter.ccld_interpreter().is_ld_kind(
            "program"))
    generates_shared = (
        has_link_phase and interpreter.ccld_interpreter().is_ld_kind(
            "shared"))
    generates_reloc = (
        has_link_phase and interpreter.ccld_interpreter().is_ld_kind(
            "relocatable"))

    # TODO: handle case of CC reloc link
    has_cc_final_link = is_cc and (generates_prog or generates_shared)
    has_ld_reloc_link = is_ld and generates_reloc
    has_cc_compile = (
        is_cc and interpreter.ccld_interpreter().has_cc_phase("CC"))

    all_outputs = []
    if is_cc or is_ld:
        all_outputs = interpreter.ccld_interpreter().all_cc_outputs()
    all_outputs_pathes = atos_lib.absolute_norm_pathes(all_outputs)

    assert(not has_link_phase or len(all_outputs) == 1)
    assert(not has_cc_compile or len(all_outputs) >= 1)

    in_configured_targets = (
        (has_cc_final_link or has_ld_reloc_link) and
        atos_lib.is_configured_target(
            opts.configuration_path, all_outputs_pathes[0]))

    # TODO: for now we pass optimizations to all compiled
    # objects and executables or shared libs, even if they
    # are not in the user specified executable list.
    # It would cause issues otherwise, ref to test138.sh.
    in_optimized_objects = True
    in_optimized_targets = True

    # For the case of a relocatable link, the target
    # is optimized only if it was configured to be.
    if has_ld_reloc_link: in_optimized_targets = in_configured_targets

    is_configured_final_link = has_cc_final_link and in_optimized_targets
    is_configured_reloc_link = has_ld_reloc_link and in_optimized_targets
    is_configured_compile = has_cc_compile and in_optimized_objects

    is_configured = (
        is_configured_final_link or is_configured_reloc_link or
        is_configured_compile)

    if is_configured_final_link:
        output_sum = atos_lib.sha1sum(all_outputs_pathes[0])
        env_ALDLTOFLAGS = os.environ.get("ALDLTOFLAGS_%s" % output_sum)
        if env_ALDLTOFLAGS: args.extend(process.cmdline2list(env_ALDLTOFLAGS))

    if is_configured_final_link or is_configured_compile:
        env_ACFLAGS = os.environ.get("ACFLAGS")
        if env_ACFLAGS: args.extend(process.cmdline2list(env_ACFLAGS))

    if is_configured_final_link:
        env_ALDFLAGS = os.environ.get("ALDFLAGS")
        if env_ALDFLAGS: args.extend(process.cmdline2list(env_ALDFLAGS))

    env_PROFILE_DIR = os.environ.get("PROFILE_DIR")
    profdir_common_len = env_PROFILE_DIR and len(
        os.environ.get("COMMON_PROFILE_DIR_PREFIX", "")) or 0
    env_PROFILE_DIR_OPT = os.environ.get("PROFILE_DIR_OPT")

    if is_configured_compile:
        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            abs_output_dir = os.path.isabs(all_outputs[0])
            suffix = '' if abs_output_dir else cwd[profdir_common_len:]
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    elif is_configured_final_link:
        if env_PROFILE_DIR and env_PROFILE_DIR_OPT:
            suffix = cwd[profdir_common_len:]
            args.append("%s=%s/%s" % (
                    env_PROFILE_DIR_OPT, env_PROFILE_DIR, suffix))

    if is_configured_final_link:
        if generates_shared:
            env_ALDSOFLAGS = os.environ.get("ALDSOFLAGS")
            if env_ALDSOFLAGS:
                args.extend(process.cmdline2list(env_ALDSOFLAGS))
        if generates_prog:
            env_ALDMAINFLAGS = os.environ.get("ALDMAINFLAGS")
            if env_ALDMAINFLAGS:  # pragma: uncovered
                args.extend(process.cmdline2list(env_ALDMAINFLAGS))

    if is_configured_reloc_link:
        # Add all lto options directly to linker command and
        # set required environment variables

        env_ACFLAGS = os.environ.get("ACFLAGS")
        if (env_ACFLAGS and
            env_ACFLAGS.find('-flto') != -1):  # pragma: uncovered (lto)
            # get input files CFLAGS
            output_sum = atos_lib.sha1sum(all_outputs_pathes[0])
            env_ALDLTOFLAGS = os.environ.get("ALDLTOFLAGS_%s" % output_sum)
            if env_ALDLTOFLAGS:
                cg_args = (
                    "" + env_ALDLTOFLAGS + " " + os.environ.get("ACFLAGS"))
            else:
                cg_args = os.environ.get("ACFLAGS")

            # GCC expects the options to be quoted: '-O2'
            cg_args_quoted = ""
            cg_args_list = cg_args.split(' ')
            for cg_arg in cg_args_list:
                cg_args_quoted = cg_args_quoted + '\'' + cg_arg + '\' '

            command_env["COLLECT_GCC_OPTIONS"] = cg_args_quoted

            # Get path of gcc lto plugins
            env_ACOLLECT_GCC = os.environ.get("ACOLLECT_GCC")
            env_ACOLLECT_LTO_WRAPPER = os.environ.get("ACOLLECT_LTO_WRAPPER")
            env_ALTO_PLUGIN = os.environ.get("ALTO_PLUGIN")
            if (env_ACOLLECT_GCC and  # pragma: branch_always
                os.path.exists(env_ACOLLECT_GCC)):
                collect_gcc = env_ACOLLECT_GCC
            if (env_ACOLLECT_LTO_WRAPPER and  # pragma: branch_always
                os.path.exists(env_ACOLLECT_LTO_WRAPPER)):
                collect_lto_wrapper = env_ACOLLECT_LTO_WRAPPER
            if (env_ALTO_PLUGIN and  # pragma: branch_always
                os.path.exists(env_ALTO_PLUGIN)):
                lto_plugin = env_ALTO_PLUGIN

            tempfiles.append(tempfile.NamedTemporaryFile(suffix=".res"))

            if (collect_gcc and  # pragma: branch_always
                collect_lto_wrapper and
                lto_plugin):
                command_env["COLLECT_GCC"] = collect_gcc
                command_env["COLLECT_LTO_WRAPPER"] = collect_lto_wrapper
                args.extend(process.cmdline2list(
                    "--build-id -flto -plugin=%s -plugin-opt=%s "
                    "-plugin-opt=-fresolution=%s" %
                    (lto_plugin, collect_lto_wrapper, tempfiles[-1].name)))

    (new_opts, args) = parser.parse_known_args(args)
    opts.__dict__.update(vars(new_opts))

    # TODO: should be passed also to reloc link
    if (is_configured_compile or is_configured_final_link) and opts.optfile:
        args.extend(get_cc_command_additional_flags(opts, args))

    if recipe_node:
        recipe_node.fetch_input_files()

    args = atos_lib.replace_incompatible_options(args)
    command = atos_lib.env_command(command_env) + args

    logger.debug("executing command: %s" % process.list2cmdline(command))
    status = process.system(command, print_output=True)

    if (recipe_node and status != 0
        and opts.update_blacklist):  # pragma: uncovered (error)
        logger.warning("failed to recompile, blacklisting %s" %
                       opts.recipe_digest)
        stg.blacklist_append(opts.recipe_digest)
        recipe_node.get_output_files()
        return 0

    if (is_configured_compile or is_configured_final_link) and opts.fctmap:
        update_cc_function_map(opts, args)

    return status


if __name__ == "__main__":  # pragma: branch_always

    parser = argparse.ArgumentParser(description='atos-driver')

    parser.add_argument('--atos-debug', dest='debug',
                        action='store_true', default=False,
                        help='print debug information (default: False)')
    parser.add_argument('--atos-log-file', dest='log_file',
                        default=None,
                        help='dup log to given file')
    parser.add_argument('--atos-debug-fd', dest='debug_fd',
                        default=None,
                        help='print debug to specified fd (default: 2)')
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
    parser.add_argument('--atos-update-blacklist', dest='update_blacklist',
                        action='store_true', default=None)

    (opts, args) = parser.parse_known_args()

    process.setup(vars(opts))

    logger.setup(vars(opts))

    if opts.audit_file:
        status = audit_compile_command(opts, args)
    else:
        status = invoque_compile_command(opts, args)

    sys.exit(status)
