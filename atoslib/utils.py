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
import re
import traceback
import json
import tempfile
import tarfile
import functools

import globals
import arguments
import atos_lib
import generators
import process
import profile
import logger
import regexp
import progress
import multiprocess

from logger import debug, warning, error, message, info
from atoslib.recipes import RecipeStorage, RecipeManager

_at_toplevel = None

def invoque(tool, args, **kwargs):
    """
    Dispatcher that invoques the given tool and returns.
    This function can't be called directly from top level
    tools, use execute() in that case.
    """
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
        "atos-run-profile": run_atos_run_profile,
        "atos-explore-inline": run_atos_explore_inline,
        "atos-explore-loop": run_atos_explore_loop,
        "atos-explore-optim": run_atos_explore_optim,
        "atos-explore-random": run_atos_explore_random,
        "atos-explore-acf": run_atos_explore_acf,
        "atos-explore-staged": run_atos_explore_staged,
        "atos-explore-genetic": run_atos_explore_genetic,
        "atos-explore-flag-values": run_atos_explore_flag_values,
        "atos-explore-flags-pruning": run_atos_explore_flags_pruning,
        "atos-config": run_atos_config,
        "atos-cookie": run_atos_cookie,
        "atos-graph": run_atos_graph,
        "atos-lib": run_atos_lib,
        "atos-generator": run_atos_generator,
        "atos-web": run_atos_web,
        }

    global _at_toplevel
    assert(_at_toplevel != None)
    # local dryrun setting is not supported as the process module
    # depends upon the global setting
    assert(kwargs.get('dryrun') == None)
    dryrun = 'dryrun' in vars(args) and args.dryrun and not _at_toplevel
    _at_toplevel = False

    if dryrun:
        process.debug(process.list2cmdline(
                atos_tool_cmdline(tool, args, **kwargs)))
        return 0

    return run_tool_func(
        functions[tool], atos_tool_args(tool, args, **kwargs))

def atos_tool_args(tool, args, **kwargs):
    """ Returns the args arguments modified by kwargs. """
    tool_args = arguments.argparse.Namespace()
    for action in arguments.parser(tool)._actions:
        if action.dest is None: continue  # pragma: uncovered (impossible?)
        tool_args.__dict__[action.dest] = action.default
    tool_args.__dict__.update(vars(args))
    tool_args.__dict__.update(kwargs)
    return tool_args

def atos_tool_cmdline(tool, args, **kwargs):
    dest_to_opt = dict(map(
            lambda x: (x.dest, x),
            arguments.parser(tool)._actions))
    atos_bin = os.path.join(
        os.path.abspath(os.path.dirname(sys.argv[0])), "atos")
    arg_list, remainder = [atos_bin, tool[len("atos-"):]], []
    for key, value in atos_tool_args(tool, args, **kwargs).__dict__.items():
        if key == 'dryrun' or key not in dest_to_opt.keys():
            continue
        default = dest_to_opt[key].default
        if value == default: continue
        # default can be False while action.default is None
        if default is False and not bool(value): continue
        if not dest_to_opt[key].option_strings:
            remainder.extend(value)
            continue
        option_string = dest_to_opt[key].option_strings[-1]
        if isinstance(value, list):
            map(lambda x: arg_list.extend([option_string, x]), value)
        else:
            arg_list.append(option_string)
            if dest_to_opt[key].nargs != 0: arg_list.append(str(value))
    return arg_list + remainder

def run_tool_func(func_tool, func_tool_args):
    """ Runs the tool, given the processed arguments. """
    if multiprocess.enabled():
        return multiprocess.launch(func_tool, func_tool_args)
    else:
        return func_tool(func_tool_args)

def execute(tool, args):
    """
    Executes the invoque dispatcher and exits.
    This function cannot be called from within invoque.
    """
    global _at_toplevel
    assert(_at_toplevel == None)
    _at_toplevel = True
    try:
        status = invoque(tool, args)
    except KeyboardInterrupt:
        raise
    except SystemExit:
        raise
    except:
        # do not print full stacktrace in case of exception
        debug(traceback.format_exc())
        exc_str = "\n".join(
            traceback.format_exception_only(*sys.exc_info()[:2]))[:-1]
        logger.internal_error(exc_str)
    else:
        sys.exit(status)

def run_atos(args):
    """
    Top level atos utility implementation.
    This function is only used as a wrapper for subcommand
    invoque(), thus we reset the _at_toplevel marker.
    """
    global _at_toplevel
    assert(_at_toplevel == False)
    _at_toplevel = True
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
        print "The must read sections:"
        print "  atos help intro    : displays ATOS short introduction."
        print "  atos help tutorial : displays ATOS tutorial."
        print
        print "Read the release notes with:"
        print "  atos help release-notes : display release notes."
        print
        print "Some explorations results and examples of usage:"
        print "  atos help example-sha1 : exploration on sha1 example."
        print "  atos help example-coremark : exploration on coremark example."
        print
        print "Benchmarking results:"
        print "  atos help benchmarks : Benchmarks results summary."
        print
        print "Detailed usage for each of the ATOS commands:"
        print "  atos COMMAND -h  : display usage for the given COMMAND."
        print
        print "Execute ``atos -h`` for the list of available COMMANDs."
        print
        return 0
    for topic in args.topics:
        if args.text:
            status = atos_lib.help_text(topic)
        elif args.man:
            status = atos_lib.help_man(topic)
        else:
            status = atos_lib.help_man(topic)
            if status != 0:  # pragma: uncovered
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

    ccregexp = (args.ccname and re.escape(args.ccname)
                or args.ccregexp)
    if not regexp.re_utils.re_check(ccregexp):  # pragma: uncovered (error)
        error("malformed compiler regexp: %s" % ccregexp)
        return 1
    ldregexp = (args.ldname and re.escape(args.ldname)
                or args.ldregexp)
    if not regexp.re_utils.re_check(ldregexp):  # pragma: uncovered (error)
        error("malformed linker regexp: %s" % ldregexp)
        return 1
    arregexp = (args.arname and re.escape(args.arname)
                or args.arregexp)
    if not regexp.re_utils.re_check(arregexp):  # pragma: uncovered (error)
        error("malformed archiver regexp: %s" % arregexp)
        return 1
    binregexp = ("(%s)" % "|".join(
            map(lambda x: "(%s)" % x,
                filter(bool, [ccregexp, ldregexp, arregexp]))))
    cbinregexp = regexp.re_utils.re_to_cregexp(binregexp)
    assert(cbinregexp)

    if args.legacy:
        output_file = args.output_file or os.path.join(
            args.configuration_path, "build.audit")
        process.commands.mkdir(args.configuration_path)
        process.commands.unlink(output_file)
        process.commands.touch(output_file)
    else:
        output_file = args.output_file or os.path.join(
            args.configuration_path, "build.stg")
        stg = RecipeStorage(output_file)
        stg.clear_all()
        stg.init_recipes_file()

    atos_lib.json_config(args.configuration_path).add_value(
        "default_values.ccregexp", ccregexp)
    atos_lib.json_config(args.configuration_path).add_value(
        "default_values.ldregexp", ldregexp)
    atos_lib.json_config(args.configuration_path).add_value(
        "default_values.arregexp", arregexp)
    atos_lib.json_config(args.configuration_path).add_value(
        "default_values.legacy_audit", str(int(bool(args.legacy))))

    build_sh = os.path.join(args.configuration_path, "build.sh")
    atos_lib.generate_script(build_sh, args.command)

    force_sh = os.path.join(args.configuration_path, "build.force")
    with open(force_sh, 'w') as file_force:
        file_force.write(str(int(args.force)))

    atos_driver = atos_lib.driver_path()
    audit_flags = ["--atos-audit=" + os.path.abspath(output_file),
                   "--atos-cfg=" + os.path.abspath(
            args.configuration_path)]
    if args.legacy: audit_flags += ["--atos-legacy"]
    if args.debug: audit_flags += ["--atos-debug"]
    debug_fd = os.dup(2)
    audit_flags += ["--atos-debug-fd", "%d" % debug_fd]
    if args.log_file:
        audit_flags += ["--atos-log-file", args.log_file]

    command = atos_lib.proot_command(
        PROOT_ADDON_CC_OPTS=1,
        PROOT_ADDON_CC_OPTS_ARGS=" ".join(audit_flags),
        PROOT_ADDON_CC_OPTS_CCRE=("^%s$" % cbinregexp),
        PROOT_ADDON_CC_OPTS_DRIVER=atos_driver) + args.command

    status = process.system(
        command, print_output=True, keep_fds=debug_fd)

    if status != 0:  # pragma: uncovered (error)
        error("build command failed (exit status %d)."
              " Check the build command and retry (%s)." %
              (status, process.list2cmdline(args.command)))

    os.close(debug_fd)
    return status

def run_atos_build_archive(args):
    """ preparation of build care archive. """
    message("Preparing build archive...")

    care_archive_dir = os.path.join(
        args.configuration_path, "archives")
    care_output = os.path.join(
        care_archive_dir, "build.care.tar")
    process.commands.mkdir(care_archive_dir)

    atos_commands = []
    available_optim_variants = atos_lib.get_available_optim_variants(
        args.configuration_path)

    #  - atos-config --print-cfg (for plugins)
    atos_commands.append(process.list2cmdline(
            atos_tool_cmdline("atos-config", args, print_cfg=True)))

    #  - atos-build -O2 + available variants (fdo, lto)
    build_opts, genpr_opts = ["-O2"], None
    if "lto" in available_optim_variants:  # pragma: uncovered
        build_opts.extend(atos_lib.config_compiler_flags(
                "lto_flags", default="-flto",
                config_path=args.configuration_path))
    if "fdo" in available_optim_variants:  # pragma: branch_always
        genpr_opts = ["-O2"]
    build_opts = process.list2cmdline(build_opts)
    genpr_opts = process.list2cmdline(genpr_opts)
    atos_commands.append(process.list2cmdline(atos_tool_cmdline(
                "atos-build", args, local=True,
                options=build_opts, gopts=genpr_opts)))
    atos_commands = ["/bin/sh", "-c", " && ".join(atos_commands)]

    # execute care command
    status, output = process.system(
        atos_lib.proot_command(
            ATOS_CARE=1, ATOS_PARALLEL=1, ATOS_NO_BUILD_HASH=1) + [
            "--output=%s" % care_output] + atos_commands,
        get_output=True, output_stderr=True)
    if status:  # pragma: uncovered (error)
        message("FAILURE while creating build archive")

    return status

def run_atos_build(args):
    """ dispatcher for atos-build (local/remote). """
    remote_build = int(atos_lib.get_config_value(
            args.configuration_path, "default_values.remote_build", "0"))
    if remote_build and not args.local:
        status = run_atos_build_remote(args)
    else:
        status = run_atos_build_local(args)
    return status

def run_atos_build_remote(args):
    """ remote build implementation. """
    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    variant_id = atos_lib.hashid(
        atos_lib.variant_id(args.options, args.gopts, args.uopts))

    message("Building variant %s [%s]..." % (variant, variant_id))

    logs_dir = os.path.join(
        args.configuration_path, "logs")
    care_archive_dir = os.path.join(
        args.configuration_path, "archives")

    # copy care archive (build.care.tar -> build.care.id.tar)
    care_archive_init = os.path.join(
        care_archive_dir, "build.care.tar")
    care_archive_copy = os.path.join(
        care_archive_dir, "build.care.%s.tar" % variant_id)
    care_archive_dest = os.path.join(
        care_archive_dir, "build.care.%s.mod.tar.gz" % variant_id)
    process.commands.copyfile(care_archive_init, care_archive_copy)

    # add profile directory if needed
    care_file = tarfile.open(care_archive_copy, mode="a")
    if args.uopts:
        profile_path = atos_lib.get_profile_path(
            args.configuration_path, atos_lib.variant_id(gopts=args.uopts))
        for root, dirnames, filenames in os.walk(profile_path):
            filenames = map(
                functools.partial(os.path.join, root), filenames)
            archnames = map(
                functools.partial(str.format, "build.care/rootfs{0}"),
                filenames)
            map(lambda (f, a): care_file.add(f, a), zip(filenames, archnames))

    # add exec.sh script (local build & re-archive)
    rearchive_prefix = os.getcwd()  # same limit as relocation (TODO: doc)
    rebuild_cmdline = process.list2cmdline(
        atos_tool_cmdline("atos-build", args, local=True))
    with tempfile.NamedTemporaryFile() as tmpfile:
        # TODO: configurable commands (bin/sh, tar)
        print >>tmpfile, "#!/bin/sh"
        print >>tmpfile, "set -ex"
        print >>tmpfile, "cd `dirname $0`"
        print >>tmpfile, "errors=0"
        print >>tmpfile, "# execute atos-build-local command"
        print >>tmpfile, "/bin/sh -e -x build.care/re-execute.sh \\"
        print >>tmpfile, "  " + rebuild_cmdline + " || errors=1"
        print >>tmpfile, "# rebuild archive"
        print >>tmpfile, "tar czvf atos.tar.gz -C %s . || true" % (
            "build.care/rootfs" + rearchive_prefix)
        print >>tmpfile, "exit $errors"

        tmpfile.flush()
        process.commands.chmod(tmpfile.name, 0755)
        care_file.add(tmpfile.name, arcname="exec.sh")
    care_file.close()

    # compress modified archive (gzip module seems slower)
    process.system(["gzip", "--force", "--fast", care_archive_copy])
    care_archive_copy = care_archive_copy + ".gz"

    # call remote-build command
    # TODO: remote time estimation
    remote_build_sh = os.path.abspath(
        os.path.join(args.configuration_path, "build.remote.sh"))
    build_progress = progress.timer_progress(
        progress_type="build", variant_id=variant,
        config_path=args.configuration_path)
    status, output = process.system(
        atos_lib.env_command(
            ATOS_CARE_SRC=os.path.abspath(care_archive_copy),
            ATOS_CARE_DST=os.path.abspath(care_archive_dest),
            BUILD_SLOT=args.__dict__.get('build_slot', ''))
        + [remote_build_sh],
        get_output=True, output_stderr=True)
    build_progress.end(status=status)
    if status or not os.path.exists(
        care_archive_dest):  # pragma: uncovered (error)
        message("FAILURE while building variant %s" % variant)
        return 1

    # extract needed files from resulting archive
    reloc_dir_prefix = args.__dict__.get("reloc_dir", "")
    if reloc_dir_prefix: process.commands.mkdir(
        args.reloc_dir + rearchive_prefix)
    care_file = tarfile.open(care_archive_dest, "r:*")
    # - built files in reloc_dir
    members_cwd = filter(
        lambda x: args.configuration_path not in x.name,
        care_file.getmembers())
    care_file.extractall(
        path=(reloc_dir_prefix + rearchive_prefix), members=members_cwd)
    #  - log files in atos-config path
    members_log = filter(
        lambda x: logs_dir in x.name, care_file.getmembers())
    care_file.extractall(
        path=rearchive_prefix, members=members_log)

    care_file.close()
    # remove archives
    if not int(os.getenv("ATOS_KEEP_RELOC", "0")):  # pragma: uncovered
        process.commands.unlink(care_archive_copy)
        process.commands.unlink(care_archive_dest)

    return 0

def run_atos_build_local(args):
    """ ATOS build tool implementation. """

    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    logf = atos_lib.open_atos_log_file(
        args.configuration_path, "build", variant)

    message("Building variant %s [%s]..." %
            (variant, atos_lib.hashid(variant)))
    logf.write("Building variant %s\n" % variant)

    legacy = args.legacy
    if not legacy:
        legacy = int(atos_lib.get_config_value(
                args.configuration_path, 'default_values.legacy_audit', "0"))

    build_force_file = os.path.join(
        args.configuration_path, "build.force")
    build_force = os.path.isfile(
        build_force_file) and int(open(build_force_file).read().strip())
    opt_rebuild = args.force or build_force

    driver_env = {}

    compile_options = os.getenv("ATOS_ACFLAGS", "").split()
    compile_options.extend(
        args.options != None and args.options.split() or [])

    link_options = []
    shared_link_options, main_link_options = [], []
    atos_driver = atos_lib.driver_path()
    atos_driver_options = ["--atos-cfg=%s" %
                           os.path.abspath(args.configuration_path)]
    if legacy: atos_driver_options += ["--atos-legacy"]
    if not args.command and not opt_rebuild:
        atos_driver_options += ["--atos-recipe=$@"]
        if args.blacklist:
            atos_driver_options += ["--atos-update-blacklist"]
    if args.debug: atos_driver_options += ["--atos-debug"]
    debug_fd = os.dup(2)
    atos_driver_options += ["--atos-debug-fd", "%d" % debug_fd]
    if args.log_file:
        atos_driver_options += ["--atos-log-file", args.log_file]

    if args.gopts != None or args.uopts != None:
        prof_opts = args.gopts if args.gopts != None else args.uopts
        prof_variant_id = atos_lib.variant_id(gopts=prof_opts)
        if args.uopts != None:
            message("Using profile variant %s [%s]..." %
                    (prof_variant_id, atos_lib.hashid(prof_variant_id)))
            logf.write("Using profile variant %s [%s]\n" % (
                    prof_variant_id, atos_lib.hashid(prof_variant_id)))
        profile_path = os.path.abspath(
            args.path) if args.path else atos_lib.get_profile_path(
            args.configuration_path, prof_variant_id)

    if args.gopts != None:
        process.commands.rmtree(profile_path)
        process.commands.mkdir(profile_path)
        compiler_fdo_gen_flags = atos_lib.config_compiler_flags(
            "fdo_gen_flags", default="-fprofile-generate",
            config_path=args.configuration_path)
        compile_options += compiler_fdo_gen_flags
        shared_link_options += ["-lgcov", "-lc"]
        profile_path = atos_lib.get_remote_profile_path(
            args, variant) or profile_path
        driver_env.update({"PROFILE_DIR": profile_path})
        driver_env.update({"PROFILE_GEN": "1"})

    if args.uopts != None:
        fdo_use_flags_default = [
            "-fprofile-use", "-fprofile-correction",
            "-Wno-error=coverage-mismatch"]
        compiler_fdo_use_flags = atos_lib.config_compiler_flags(
            "fdo_use_flags", default=" ".join(fdo_use_flags_default),
            config_path=args.configuration_path)
        compile_options += compiler_fdo_use_flags
        driver_env.update({"PROFILE_DIR": profile_path})
        driver_env.update({"PROFILE_USE": "1"})
        atos_lib.restore_gcda_files_if_necessary(
            args, prof_path=profile_path)

    if args.gopts != None or args.uopts != None:
        common_profdir_prefix = atos_lib.get_config_value(
            args.configuration_path, 'build_opts.common_profdir_prefix', '')
        driver_env.update({"COMMON_PROFILE_DIR_PREFIX": common_profdir_prefix})
        compiler_fdo_dir_flag = atos_lib.config_compiler_flags(
            "fdo_dir_flags", default="-fprofile-dir",
            config_path=args.configuration_path)
        if compiler_fdo_dir_flag:  # pragma: uncovered (stxp70)
            driver_env.update({
                    "PROFILE_DIR_OPT": " ".join(compiler_fdo_dir_flag)})

    compiler_lto_flag = atos_lib.config_compiler_flags(
            "lto_flags", default="-flto", config_path=args.configuration_path)
    compiler_lto_flag = " ".join(compiler_lto_flag)
    if compiler_lto_flag in compile_options:
        for (target_sum, lto_flags) in atos_lib.get_config_value(
            args.configuration_path, 'build_opts.lto_flags', {}).items():
            driver_env.update({"ALDLTOFLAGS_" + target_sum: lto_flags})

    driver_env.update({"ACFLAGS": " ".join(compile_options)})
    driver_env.update({"ALDFLAGS": " ".join(link_options)})
    driver_env.update({"ALDSOFLAGS": " ".join(shared_link_options)})
    driver_env.update({"ALDMAINFLAGS": " ".join(main_link_options)})

    if not args.command and not opt_rebuild:
        # if the configuration path contains a build.mk execute it
        build_mk = os.path.join(args.configuration_path, "build.mk")
        if not os.path.isfile(build_mk):  # pragma: uncovered (error)
            error("optimized build file missing: %s" % build_mk)
            error("atos-deps was not run or configuration path mismatch")
            return 1
        if args.blacklist:
            stg = RecipeStorage(
                os.path.join(args.configuration_path, "build.stg"))
            stg.blacklist_init()
        command = atos_lib.proot_reloc_command(args) + [
            "make", "-f", build_mk, "-j", str(args.jobs),
            "QUIET=",
            "ATOS_DRIVER=" +
            " ".join([atos_driver] + atos_driver_options)]
    else:
        # else use proot cc_opts addon (force mode)
        build_sh = os.path.abspath(
            os.path.join(args.configuration_path, "build.sh"))
        if not args.command:
            if not os.path.isfile(build_sh):  # pragma: uncovered (error)
                error("build script missing: %s" % build_sh)
                error("atos-build was not run or configuration path mismatch")
                return 1
        ccregexp = (atos_lib.get_config_value(args.configuration_path,
                                              'default_values.ccregexp') or
                    globals.DEFAULT_CCREGEXP)
        ldregexp = (atos_lib.get_config_value(args.configuration_path,
                                              'default_values.ldregexp') or
                    globals.DEFAULT_LDREGEXP)
        arregexp = (atos_lib.get_config_value(args.configuration_path,
                                              'default_values.arregexp') or
                    globals.DEFAULT_ARREGEXP)
        binregexp = ("(%s)" % "|".join(
                map(lambda x: "(%s)" % x,
                    filter(bool, [ccregexp, ldregexp, arregexp]))))
        cbinregexp = regexp.re_utils.re_to_cregexp(binregexp)
        assert(cbinregexp)
        command = atos_lib.proot_command(
            PROOT_ADDON_CC_OPTS=1,
            # Warning, proot cc_opts plugin splits option arguments
            # at spaces, do not use list2cmdline there.
            # Also, args must not be empty otherwise the plugin
            # will not invoque the driver.
            # TODO: fix proot cc_opts plugin.
            PROOT_ADDON_CC_OPTS_ARGS=" ".join(atos_driver_options),
            PROOT_ADDON_CC_OPTS_CCRE=("^%s$" % cbinregexp),
            PROOT_ADDON_CC_OPTS_DRIVER=atos_driver,
            # envvars for relocated execution addon
            **atos_lib.proot_reloc_args(args))
        command.extend(args.command or [build_sh])

    driver_env.update(
        {"BUILD_SLOT": args.__dict__.get('build_slot', '')})
    build_progress = progress.timer_progress(
        progress_type="build", variant_id=variant,
        config_path=args.configuration_path)
    status, output = process.system(
        atos_lib.timeout_command() + atos_lib.env_command(driver_env)
        + command, get_output=True, output_stderr=True, keep_fds=debug_fd)
    build_progress.end(status=status)
    os.close(debug_fd)

    logf.write('%s\n' % output)
    if status:  # pragma: uncovered (error)
        message("FAILURE while building variant %s" % (variant))
        logf.write("FAILURE while building variant %s\n" % (variant))
        logf.close()
        return 2

    logf.write("SUCCESS building variant %s\n" % (variant))
    logf.close()
    return 0

def run_atos_deps(args):
    """ ATOS deps tool implementation. """

    legacy = args.legacy
    if not legacy:
        legacy = int(atos_lib.get_config_value(
                args.configuration_path, 'default_values.legacy_audit', "0"))

    opt_rebuild = args.force
    build_force = os.path.join(args.configuration_path, "build.force")
    if not opt_rebuild and os.path.isfile(build_force):
        with open(build_force) as f:
            opt_rebuild = int(f.read().strip())

    if legacy:
        # For now we include all from atos_deps,
        # we may separate modules later.
        from atos_deps import CommandDependencyListFactory
        from atos_deps import CCDEPSParser
        from atos_deps import DependencyGraphBuilder
        from cmd_interpreter import CmdInterpreterFactory

    if legacy:
        input_file = args.input_file or os.path.join(
            args.configuration_path, "build.audit")
    else:
        input_stg = args.input_file or os.path.join(
            args.configuration_path, "build.stg")

    output_file = args.output_file or os.path.join(
        args.configuration_path, "build.mk")

    targets_file_used = False
    targets = None
    executables = args.exes and args.exes.split() or args.executables
    if executables:
        targets = executables
    if args.last:
        targets = "last"
    if args.all:
        targets = "all"

    targets_file = os.path.join(args.configuration_path, "targets")
    if targets == None and not opt_rebuild:  # pragma: uncovered
        if os.path.exists(targets_file):
            with open(targets_file) as f:
                targets = filter(
                    lambda x: x != "" and not x.startswith("#"),
                    map(lambda x: x.strip(), f.readlines()))
            targets_file_used = True

    if targets == None or len(targets) == 0:  # pragma: uncovered (error)
        error("targets list not specified or "
              "targets file empty (%s)" % targets_file)
        return 1

    message("Computing build dependencies...")
    if legacy:
        deps_builder = CommandDependencyListFactory(
            CCDEPSParser(open(input_file)),
            CmdInterpreterFactory(args.configuration_path))
        deps_builder.build_dependencies()
        dependencies = deps_builder.get_dependencies()
        graph_builder = DependencyGraphBuilder(dependencies, targets)
        graph_builder.build_graph()
        graph = graph_builder.get_graph()

        if not opt_rebuild:  # pragma: branch_uncovered
            graph.output_makefile(output_file)
    else:
        stg = RecipeStorage(input_stg)
        if not os.path.isfile(stg.recipes_path()):  # pragma: uncovered (error)
            error("can't build dependencies, run atos-audit first: "
                  "audit file missing: %s" % stg.recipes_path())
            return 1
        graph = RecipeManager(stg).recipe_graph(targets=targets)
        with open(output_file, "w") as f:
            graph.write_makefile(f, prefix="$(ATOS_DRIVER)")

    # For now only write targets if configuration dir is there
    if not os.path.isdir(args.configuration_path):  # pragma: uncovered
        return 0

    if not targets_file_used:  # pragma: branch_uncovered
        with open(targets_file, "w") as f:
            targets = executables if opt_rebuild else graph.get_targets()
            print >>f, "# Targets list that will be rebuilt by ATOS"
            print >>f, "# Prefix with '#' or remove useless targets"
            if targets:  # pragma: branch_always
                print >>f, "\n".join(targets)
            else:  # pragma: uncovered (error)
                print >>f, "# ERROR: empty target list, audit failed.\n"

    with open(os.path.join(args.configuration_path, "objects"), "w") as f:
        objects = graph.get_objects()
        if objects: print >>f, "\n".join(objects),

    with open(os.path.join(args.configuration_path, "compilers"), "w") as f:
        compilers = graph.get_compilers()
        if compilers: print >>f, "\n".join(compilers),

    config_file = os.path.join(args.configuration_path, 'config.json')
    json_config = atos_lib.json_config(config_file)

    # list of options that should be passed to linker in case of LTO build
    for (k, v) in graph.get_lto_opts().items():
        json_config.add_value("build_opts.lto_flags.%s" % (
                atos_lib.sha1sum(k)), ' '.join(v))

    json_config.add_value(
        "build_opts.common_profdir_prefix",
        graph.common_relative_profdir_prefix())

    return 0

def run_atos_explore(args):
    """ ATOS explore tool implementation. """

    status = invoque("atos-init", args)
    if status != 0: return status  # pragma: uncovered (error)

    status = generators.run_exploration_loop(
        args, generator=generators.gen_explore)
    return status

def run_atos_init(args):
    """ ATOS init tool implementation. """

    executables = args.exes and args.exes.split() or args.executables
    if args.force and not args.results_script and not executables:
        error("when using forced mode (-f) with no custom results script (-t)"
              " the list of executables must be specified (-e option)")
        return 1

    # Check that given scripts are executables
    if args.build_script:
        build_command = process.cmdline2list(args.build_script)
        if not process.commands.which(build_command[0]):  # pragma: uncovered
            error("in build command, '%s' executable not found and not in PATH"
                  % build_command[0])
            return 1
    if args.results_script:
        results_command = process.cmdline2list(args.results_script)
        if not process.commands.which(results_command[0]):  # pragma: uncovered
            error("in results command, '%s' executable not found "
                  "and not in PATH" % results_command[0])
            return 1
    if args.size_cmd:
        size_command = process.cmdline2list(args.size_cmd)
        if not process.commands.which(size_command[0]):  # pragma: uncovered
            error("in size command, '%s' executable not found "
                  "and not in PATH" % size_command[0])
            return 1
    if args.time_cmd:
        time_command = process.cmdline2list(args.time_cmd)
        if not process.commands.which(time_command[0]):  # pragma: uncovered
            error("in time command, '%s' executable not found "
                  "and not in PATH" % time_command[0])
            return 1
    if args.remote_exec_script:
        rexec_command = process.cmdline2list(args.remote_exec_script)
        if not process.commands.which(rexec_command[0]):  # pragma: uncovered
            error("in remote exec command, "
                  "'%s' executable not found and not in PATH"
                  % rexec_command[0])
            return 1
    if args.remote_build_script:
        if args.remote_exec_script:  # pragma: uncovered
            error("flags --remote-exec-script and --remote-build-script"
                  " cannot be used together")
            return 1
        rbuild_command = process.cmdline2list(args.remote_build_script)
        if not process.commands.which(rbuild_command[0]):  # pragma: uncovered
            error("in remote build command, "
                  "'%s' executable not found and not in PATH"
                  % rbuild_command[0])
            return 1
    if args.remote_run_script:
        if args.remote_exec_script:  # pragma: uncovered
            error("flags --remote-exec-script and --remote-build-script"
                  " cannot be used together")
            return 1
        rrun_command = process.cmdline2list(args.remote_run_script)
        if not process.commands.which(rrun_command[0]):  # pragma: uncovered
            error("in remote run command, "
                  "'%s' executable not found and not in PATH"
                  % rrun_command[0])
            return 1

    process.commands.mkdir(args.configuration_path)

    if args.clean or args.build_script:
        if args.clean: message("Cleaning build audit...")
        process.commands.unlink('%s/build.mk' % args.configuration_path)
        process.commands.unlink('%s/targets' % args.configuration_path)
        process.commands.unlink('%s/objects' % args.configuration_path)
        process.commands.unlink('%s/compilers' % args.configuration_path)
        process.commands.unlink('%s/build.sh' % args.configuration_path)
        process.commands.unlink('%s/build.force' % args.configuration_path)
        process.commands.unlink('%s/build.audit' % args.configuration_path)
        process.commands.unlink('%s/build.time' % args.configuration_path)
        process.commands.rmtree('%s/build.stg' % args.configuration_path)
        process.commands.rmtree('%s/plugins' % args.configuration_path)
        process.commands.unlink('%s/config.json' % args.configuration_path)
        process.commands.rmtree('%s/reloc' % args.configuration_path)
        process.commands.rmtree('%s/archives' % args.configuration_path)
    if args.clean or args.run_script:
        if args.clean: message("Cleaning run audit...")
        process.commands.unlink('%s/run.sh' % args.configuration_path)
        process.commands.unlink('%s/run.audit' % args.configuration_path)
        process.commands.unlink('%s/run.time' % args.configuration_path)
    if args.clean:
        message("Cleaning all profiles...")
        process.commands.rmtree('%s/profiles' % args.configuration_path)
        process.commands.rmtree('%s/oprofiles' % args.configuration_path)
        message("Cleaning all results...")
        process.commands.unlink('%s/results.db' % args.configuration_path)

    if args.build_script:
        status = invoque("atos-audit", args,
                         command=build_command)
        if status != 0: return status  # pragma: uncovered (error)
        status = invoque("atos-deps", args,
                         all=(not executables))
        if status != 0: return status  # pragma: uncovered (error)
        status = invoque("atos-config", args)
        if status != 0: return status  # pragma: uncovered (error)

    elif (
        not (os.path.isfile(
                os.path.join(args.configuration_path, "build.audit")) or
             os.path.isdir(
                os.path.join(args.configuration_path, "build.stg")))
        or not os.path.isfile(
            os.path.join(args.configuration_path, "config.json"))
        ):  # pragma: uncovered (error)
        error("missing build audit, use -b option for specifying build script"
              " or use atos-audit tool")
        return 1

    config_file = os.path.join(args.configuration_path, 'config.json')

    if args.remote_path:
        atos_lib.json_config(config_file).add_value(
            "default_values.remote_profile_path", args.remote_path)

    nbruns = int(atos_lib.json_config(config_file).get_value(
            "default_values.nb_runs", 1))
    if args.nbruns != None: nbruns = args.nbruns
    if nbruns < 0:
        error("number of runs must be >= 0 in --nbruns argument")
        return 1
    atos_lib.json_config(config_file).add_value(
        "default_values.nb_runs", str(nbruns))

    if args.build_jobs is not None:
        atos_lib.json_config(config_file).add_value(
            "default_values.build_jobs", str(args.build_jobs))

    if args.run_jobs is not None:
        atos_lib.json_config(config_file).add_value(
            "default_values.run_jobs", str(args.run_jobs))

    if args.remote_build_script or args.remote_exec_script:
        atos_lib.json_config(config_file).add_value(
            "default_values.remote_build", str(1))
        remote_build_sh = os.path.join(
            args.configuration_path, "build.remote.sh")
        atos_lib.generate_script(
            remote_build_sh,
            (args.remote_build_script or args.remote_exec_script) + " $*")

    if args.remote_run_script or args.remote_exec_script:
        atos_lib.json_config(config_file).add_value(
            "default_values.remote_run", str(1))
        remote_run_sh = os.path.join(
            args.configuration_path, "run.remote.sh")
        atos_lib.generate_script(
            remote_run_sh,
            (args.remote_run_script or args.remote_exec_script) + " $*")

    # should be enabled by default in the future if working correctly
    if args.build_script or args.run_script:
        atos_lib.json_config(config_file).add_value(
            "default_values.reuse", str(int(bool(args.reuse))))

    time_cmd = atos_lib.json_config(config_file).get_value(
        "default_values.time_cmd", globals.DEFAULT_TIME_CMD)
    if args.time_cmd != None: time_cmd = args.time_cmd
    atos_lib.json_config(config_file).add_value(
        "default_values.time_cmd", time_cmd)

    size_cmd = atos_lib.json_config(config_file).get_value(
        "default_values.size_cmd", globals.DEFAULT_SIZE_CMD)
    if args.size_cmd != None: size_cmd = args.size_cmd
    atos_lib.json_config(config_file).add_value(
        "default_values.size_cmd", size_cmd)

    if args.run_script:
        run_command = process.cmdline2list(args.run_script)
        if process.commands.which(run_command[0]) == None:
            error("in run command, '%s' executable not found and not in PATH"
                  % run_command[0])
            return 1
        status = invoque("atos-raudit", args,
                         command=run_command)
        if status != 0: return status  # pragma: uncovered (error)
    elif not os.path.isfile(os.path.join(args.configuration_path, "run.audit")
                            ):  # pragma: uncovered (error)
        error("missing run audit, use -r option for specifying run script"
              " or use atos-raudit tool")
        return 1

    if args.prof_script:
        prof_command = process.cmdline2list(args.prof_script)
        if process.commands.which(prof_command[0]) == None:
            error("in profile command, '%s' executable not found "
                  "and not in PATH" % prof_command[0])
            return 1
        prof_sh = os.path.join(args.configuration_path, "profile.sh")
        atos_lib.generate_script(prof_sh, args.prof_script)

    # Record the reference if necessary
    if (args.clean or args.build_script or args.run_script) and \
            not args.no_run:
        status = invoque("atos-build", args, blacklist=True, local=True)
        if status != 0:  # pragma: uncovered (error)
            error("unable to compile the reference build. "
                  "Refer to the log file; %s/logs/build-%s.log." %
                  (args.configuration_path, atos_lib.hashid("REF")))
            return status
        status = invoque("atos-run", args, record=True, local=True)
        if status != 0:  # pragma: uncovered (error)
            error("run of reference build failed. "
                  "Refer to the log file: %s/logs/run-%s.log." %
                  (args.configuration_path, atos_lib.hashid("REF")))
            return status

    # Prepare care archive for remote build
    if args.remote_build_script or args.remote_exec_script:
        status = run_tool_func(run_atos_build_archive, args)
        if status != 0: return status  # pragma: uncovered (error)

    # Prepare care archive for remote run
    if args.remote_run_script or args.remote_exec_script:
        status = run_tool_func(run_atos_run_archive, args)
        if status != 0: return status  # pragma: uncovered (error)

    return 0

def run_atos_lib(args):
    """ ATOS lib tool implementation. """

    if args.subcmd_lib == "create_db":
        if not os.path.exists(args.configuration_path):  # pragma: uncovered
            os.makedirs(args.configuration_path)
        if args.type == 'results_db':
            db_file = os.path.join(args.configuration_path, 'results.db')
            db = atos_lib.atos_db_file(db_file)
        elif args.type == 'json':
            db_file = os.path.join(args.configuration_path, 'results.json')
            db = atos_lib.atos_db_json(db_file)
        elif args.type == 'pickle':  # pragma: branch_always
            db_file = os.path.join(args.configuration_path, 'results.pkl')
            db = atos_lib.atos_db_pickle(db_file)
        else: assert 0  # pragma: unreachable
        if args.shared: process.commands.chmod(db_file, 0660)
        info('created new database in "%s"' % db_file)
        return 0

    elif args.subcmd_lib == "query":
        if args.configuration_path == '-':
            results = atos_lib.results_filter(
                atos_lib.atos_client_db.db_load(sys.stdin),
                atos_lib.strtoquery(args.query))
        else:
            client = atos_lib.atos_client_db(
                atos_lib.atos_db.db(args.configuration_path))
            results = client.query(atos_lib.strtoquery(args.query))

        atos_lib.pprint_list(results, text=args.text)
        return 0

    elif args.subcmd_lib == "speedups":
        client = atos_lib.atos_client_results(
            atos_lib.atos_db.db(args.configuration_path),
            args.targets and atos_lib.strtolist(args.targets),
            atos_lib.strtoquery(args.query), args.group_name)

        client.compute_speedups(args.refid)

        if args.tradeoffs:  # pragma: uncovered
            results = map(lambda x: client.tradeoff(x).dict(), args.tradeoffs)
        else:
            results = client.get_results(args.frontier)

        if args.table:  # pragma: uncovered (error)
            atos_lib.pprint_speedups(results, reverse=args.reverse)
        else:
            atos_lib.pprint_list(results)
        return 0

    elif args.subcmd_lib == "push":
        db = atos_lib.atos_db.db(args.configuration_path)
        results = atos_lib.atos_client_db.db_query(
            db, atos_lib.strtoquery(args.query),
            atos_lib.strtodict(args.replacement))

        if args.remote_configuration_path == '-':
            status, output = atos_lib.atos_client_db.db_dump(
                results, sys.stdout)
        else:
            other_db = atos_lib.atos_db.db(args.remote_configuration_path)
            status, output = atos_lib.atos_client_db.db_transfer(
                other_db, results, args.force)

        if status:
            info('exported %d results' % (output))
            return 0
        else:  # pragma: uncovered (error)
            error(output)
            return 1

    elif args.subcmd_lib == "pull":
        db = atos_lib.atos_db.db(args.configuration_path)

        if args.remote_configuration_path == '-':
            results = atos_lib.atos_client_db.db_load(sys.stdin)
        else:
            other_db = atos_lib.atos_db.db(args.remote_configuration_path)
            results = atos_lib.atos_client_db.db_query(
                other_db, atos_lib.strtoquery(args.query),
                atos_lib.strtodict(args.replacement))

        status, output = atos_lib.atos_client_db.db_transfer(
            db, results, args.force)

        if status:
            info('imported %d results' % (output))
            return 0
        else:  # pragma: uncovered (error)
            error(output)
            return 1

    elif args.subcmd_lib == "report":
        db = atos_lib.atos_db.db(args.configuration_path)

        # targets 'group1:targ1,targ2,targ3+group2:targ4,targ5+targ6'
        group_targets, group_names = [], []
        if args.targets:
            for group in args.targets.split('+'):
                spl = group.split(':')
                if len(spl) > 1:
                    group_targets += [spl[1].split(',')]
                    group_names += [spl[0]]
                else:  # pragma: uncovered
                    group_targets += [spl[0].split(',')]
                    group_names += ['+'.join(group_targets[-1])]
        else:
            results = db.get_results(atos_lib.strtoquery(args.query))
            group_targets = sorted(
                [list(set(atos_lib.results_filter(results, '$[*].target')))])
            group_names = map('+'.join, group_targets)

        # groups not supported in stdev mode
        assert (args.mode != 'stdev') or all(
            map(lambda g: len(g) == 1, group_targets))

        # results
        all_results = {}
        for num in range(len(group_targets)):
            targets, name = group_targets[num], group_names[num]
            client = atos_lib.atos_client_results(
                db, targets, atos_lib.strtoquery(args.query), name)
            if args.refid: client.compute_speedups(args.refid)
            all_results[group_names[num]] = client.results

        # variants
        variants = args.variants and args.variants.split(',') or sorted(list(
            reduce(lambda acc, s: acc.intersection(s),
                   map(lambda v: set(v.keys()), all_results.values()))))

        table = (args.mode != 'stdev') and [[''] + group_names] or []

        for variant in variants:

            table += [[variant]]
            if args.mode == 'stdev':
                table[-1] += ['AVG', 'NOISE', 'STDEV']

            for target in group_names:

                if args.mode == 'speedup':
                    table[-1] += ['%.0f %+6.1f%%' % (
                            all_results[target][variant].time,
                            all_results[target][variant].speedup * 100)]

                elif args.mode == 'sizered':  # pragma: uncovered
                    table[-1] += ['%.0f %+6.1f%%' % (
                            all_results[target][variant].size,
                            all_results[target][variant].sizered * 100)]

                elif args.mode == 'stdev':
                    table += [[target]]
                    results = map(
                        lambda r: r.time,
                        all_results[target][variant]._results[0]._results)
                    avg_res, min_res, max_res = (
                        atos_lib.average(results), min(results), max(results))
                    max_avg_diff = max(avg_res - min_res, max_res - avg_res)
                    table[-1] += ['%.2f' % avg_res]
                    table[-1] += ['%.2f%%' % ((max_avg_diff / avg_res) * 100)]
                    table[-1] += ['%.2f%%' % (
                            (atos_lib.standard_deviation(results) / avg_res)
                        * 100)]

                else: assert 0  # pragma: unreachable

            if args.mode == 'stdev': table += [None]

        atos_lib.pprint_table(table, reverse=args.reverse)
        return 0

    elif args.subcmd_lib == "add_result":  # pragma: uncovered
        result = atos_lib.strtodict(args.result)

        if args.configuration_path == '-':
            print atos_lib.atos_db_file.entry_str(result),

        else:
            db = atos_lib.atos_db.db(args.configuration_path)
            status, output = atos_lib.atos_client_db(db).add_result(result)
            if not status:  # pragma: uncovered (error)
                error(output)
                return 1
        return 0

    elif args.subcmd_lib == "config":  # pragma: uncovered (TODO: remove ?)
        config_file = os.path.join(args.configuration_path, 'config.json')

        if args.query:
            client = atos_lib.json_config(config_file)
            results = client.query(atos_lib.strtoquery(args.query))
            if args.uniq and results:
                results = atos_lib.list_unique(results)
            atos_lib.pprint_list(results, text=args.text)

        elif args.add_item:
            client = atos_lib.json_config(config_file)
            key, value = args.add_item.split(':')
            client.add_value(key, value)

        elif args.get_item:
            if os.path.isfile(config_file):
                client = atos_lib.json_config(config_file)
                print client.get_value(args.get_item) or ''

        elif args.add_cpl:
            client = atos_lib.json_config(config_file)
            client.add_compiler(args.add_cpl)

        elif args.cpl_flags:
            if os.path.isfile(config_file):
                client = atos_lib.json_config(config_file)
                print ' '.join(client.flags_for_flagfiles())

        else: pass
        return 0

def run_atos_generator(args):
    """ ATOS generator tool implementation. """
    try:
        assert args.generator
        generator = eval('generators.%s' % args.generator)
    except:
        error("unknown generator '%s'" % args.generator)
        return 1

    gen_args = arguments.argparse.Namespace()
    gen_args.__dict__.update(vars(args))
    status = generators.run_exploration_loop(
        gen_args, generator=generator)

    return status

def run_atos_opt(args):
    """ ATOS opt tool implementation. """

    reuse = args.reuse or bool(
        int(atos_lib.get_config_value(
                args.configuration_path, "default_values.reuse", 0)))

    options = args.options or ""
    uopts = args.uopts
    if uopts == None and args.fdo:
        uopts = options

    if args.lto:
        compiler_lto_flag = atos_lib.config_compiler_flags(
            "lto_flags", default="-flto", config_path=args.configuration_path)
        compiler_lto_flag = " ".join(compiler_lto_flag)
        options += " " + compiler_lto_flag

        if args.uopts == None and args.fdo:
            # add lto flags to profile_gen options if necessary
            fdo_gen_lto = int(atos_lib.config_compiler_flags(
                    "fdo_gen_lto", default="0",
                    config_path=args.configuration_path)[0])
            if fdo_gen_lto:  # pragma: uncovered
                uopts += " " + compiler_lto_flag

    if reuse:
        variant_id = atos_lib.variant_id(options, None, uopts)
        if args.profile:  # pragma: uncovered
            # reuse oprofile dir if already existing for this variant
            profile_path = atos_lib.get_oprofile_path(
                args.configuration_path, variant_id)
            if os.path.isdir(profile_path):
                for f in os.listdir(profile_path):
                    filepath = os.path.join(profile_path, f)
                    process.commands.copyfile(filepath, f)
                message("Reusing profile of variant %s..." % variant_id)
                return 0
        else:
            # reuse existing results for this variant
            db = atos_lib.atos_db.db(args.configuration_path)
            results = atos_lib.merge_results(
                atos_lib.results_filter(
                    db.get_results(), {"variant": variant_id}),
                merge_targets=False)
            if results:
                atos_lib.reuse_run_result(
                    db, variant_id, options, uopts, args, results)
                message("Reusing results of variant %s..." % variant_id)
                return 0

    if args.fdo:
        status = invoque("atos-profile", args, options=uopts, uopts=None)
        if status: return status  # pragma: uncovered (error)

    status = invoque("atos-build", args, options=options, uopts=uopts)
    if status: return status  # pragma: uncovered (error)

    if args.profile:
        status = invoque(
            "atos-run-profile", args, options=options, uopts=uopts)
        return status

    status = invoque(
        "atos-run", args, options=options, uopts=uopts)
    return status

def run_atos_play(args):
    """ ATOS play tool implementation. """

    if not os.path.isdir(args.configuration_path):
        error('configuration path missing: ' + args.configuration_path)
        return 1

    all_results = atos_lib.get_results(args.configuration_path, args)
    if not all_results:
        error('no result found or reference variant not found')
        return 1
    results = []
    if args.ref:
        results = atos_lib.results_filter(map(lambda x: x.dict(), all_results),
                                          {'variant': 'REF'})
        if len(results) == 0:
            error('REF variant not found in results')
            return 1
    elif args.localid != None or args.variant != None:
        variant_id = args.variant
        filter_func = lambda x: x['variant'].startswith(args.variant)
        if variant_id == None:
            variant_id = args.localid
            filter_func = lambda x: atos_lib.hashid(
                x['variant']).startswith(args.localid)
        results = filter(filter_func, map(lambda x: x.dict(),
                                          all_results))
        if len(results) == 0:
            error('variant not found in results, id: %s' % variant_id)
            return 1
        if len(results) > 1:
            error('multiple variant found, ambiguous id: %s' % variant_id)
            return 1
    else:
        tradeoffs = args.tradeoffs
        if not tradeoffs:
            if args.obj == "size":
                tradeoffs = [0.2]
            else:  # objective == "time"
                tradeoffs = [5.0]
        nbtr = max(1, args.nbpoints / len(tradeoffs))
        for tradeoff in tradeoffs:
            selected = atos_lib.atos_client_results.select_tradeoffs(
                all_results, tradeoff, nbtr) or []
            results.extend(selected)
        results = atos_lib.list_unique(results)
        results = map(lambda x: x.dict(), results)
        assert(len(results) > 0)

    if args.printvariant:
        for result in results:
            print result['variant']
        return 0
    elif args.printconfig:
        for result in results:
            print atos_lib.atos_db_file.entry_str(result),
        return 0
    elif args.printtable:
        atos_lib.pprint_speedups(results, reverse=args.reverse)
        return 0
    elif len(results) > 1:
        error('more than one build requested')
        return 1
    else:
        result = results[0]
        message('Playing optimized build %s...' % (result['variant']))
        options_list = []
        options = result.get('conf', None)
        if options: options_list.append(options)
        if args.options: options_list.append(args.options)
        status = invoque("atos-build", args,
                         options=" ".join(options_list),
                         uopts=result.get('uconf', None),
                         gopts=result.get('gconf', None))
        return status

def run_atos_profile(args):
    """ ATOS profile tool implementation. """

    options = args.options or ''
    variant_id = atos_lib.variant_id(gopts=options)
    reuse = args.reuse or bool(
        int(atos_lib.get_config_value(
                args.configuration_path, "default_values.reuse", 0)))
    profile_path = os.path.abspath(args.path) if args.path else \
        atos_lib.get_profile_path(args.configuration_path, variant_id)
    variant_file = os.path.join(profile_path, "variant.txt")

    if reuse and os.path.exists(variant_file):
        # variant.txt is created after profiling run
        message("Reusing profile variant %s..." % variant_id)
        return 0

    status = invoque(
        "atos-build", args, gopts=options, options=options)
    if status: return status  # pragma: uncovered (error)

    hashsum = atos_lib.target_hash(args)

    if reuse:
        variants = atos_lib.atos_buildhash_db.hashsum_db(
            args.configuration_path).get_variants(hashsum)
        if variants:
            message("Reusing profiling run for variant %s..." % variant_id)
            new_profile_path = atos_lib.get_profile_path(
                args.configuration_path, variants[0])
            # TODO: reuse new_profile_path directly instead of copying it
            process.commands.rmtree(profile_path)
            process.commands.copytree(new_profile_path, profile_path)
            atos_lib.atos_buildhash_db.hashsum_db(
                args.configuration_path).add_hashsum(hashsum, variant_id)
            return 0

    status = invoque(
        "atos-run", args, gopts=options, options=options,
        variant=variant_id, silent=True)
    if status: return status  # pragma: uncovered (error)

    atos_lib.atos_buildhash_db.hashsum_db(
        args.configuration_path).add_hashsum(hashsum, variant_id)
    atos_lib.save_gcda_files_if_necessary(options, args)
    with open(variant_file, "w") as variantf: variantf.write(options)

    return 0

def run_atos_raudit(args):
    """ ATOS raudit tool implementation. """

    if not args.command:  # pragma: uncovered (error)
        error("missing run command.")
        return 1

    message("Auditing run...")

    if not args.output_file:  # pragma: branch_uncovered
        process.commands.mkdir(args.configuration_path)
        output_file = os.path.join(args.configuration_path, "run.audit")
        process.commands.touch(output_file)
        run_sh = os.path.join(args.configuration_path, "run.sh")
        atos_lib.generate_script(run_sh, args.command)
        if args.results_script != None:
            get_res_sh = os.path.join(args.configuration_path, "get_res.sh")
            atos_lib.generate_script(get_res_sh, args.results_script)

    status = process.system(args.command, print_output=True)

    if status != 0:  # pragma: uncovered (error)
        error("run command failed (exit status %d). "
              " Check the run command and retry (%s)." %
              (status, process.list2cmdline(args.command)))

    return status

def run_atos_run_profile(args):
    """ ATOS run profile tool implementation. """

    variant = atos_lib.variant_id(
        args.options, args.gopts, args.uopts)

    # TODO: define default map & profile filenames in globals.py
    #  and add an option for fctmap file handling
    fctmap_file = "fctmap.out"
    profile_file = "oprof.out"
    profile_path = atos_lib.get_oprofile_path(
        args.configuration_path, variant)

    process.commands.unlink(profile_file)
    process.commands.rmtree(profile_path)

    message("Running profile variant %s..." % variant)

    if 'prof_script' in vars(
        args) and args.prof_script:  # pragma: branch_uncovered
        prof_script = process.cmdline2list(args.prof_script)
    else:  # pragma: uncovered
        prof_script = [os.path.abspath(
                os.path.join(args.configuration_path, "profile.sh"))]

    status, output = process.system(
        atos_lib.timeout_command() + atos_lib.proot_reloc_command(args)
        + prof_script,
        get_output=True, output_stderr=True)

    if status or not os.path.isfile(profile_file):  # pragma: uncovered (error)
        message("FAILURE while running profile variant %s" % variant)
        return 2

    process.commands.mkdir(profile_path)
    process.commands.copyfile(
        profile_file, os.path.join(profile_path, profile_file))
    if os.path.isfile(fctmap_file):
        process.commands.copyfile(
            fctmap_file, os.path.join(profile_path, fctmap_file))

    debug("SUCCESS running profile variant %s\n" % variant)
    return 0

def run_atos_run_archive(args):
    """ preparation of run care archive. """
    message("Preparing run archive...")

    care_archive_dir = os.path.join(
        args.configuration_path, "archives")
    care_output = os.path.join(
        care_archive_dir, "run.care.tar")
    process.commands.mkdir(care_archive_dir)

    atos_commands = [process.list2cmdline(
            atos_tool_cmdline("atos-run", args, local=True))]
    atos_commands = ["/bin/sh", "-c", " && ".join(atos_commands)]

    # execute care command
    status, output = process.system(
        atos_lib.proot_command(
            ATOS_CARE=1, ATOS_PARALLEL=1, ATOS_NO_BUILD_HASH=1) + [
            "--concealed-path=%s" % os.path.join(
                args.configuration_path, "profiles"),
            "--concealed-path=%s" % os.path.join(
                args.configuration_path, "logs"),
            "--output=%s" % care_output] + atos_commands,
        get_output=True, output_stderr=True)
    if status:  # pragma: uncovered (error)
        message("FAILURE while creating run archive")

    return status

def run_atos_run(args):
    """ ATOS run tool implementation. """

    variant_id = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    reuse = args.reuse or bool(
        int(atos_lib.get_config_value(
                args.configuration_path, "default_values.reuse", 0)))
    hashsum = atos_lib.target_hash(args, variant=variant_id)

    if reuse:
        # use results of another same-hash variant if exising
        db = atos_lib.atos_db.db(args.configuration_path)
        results = atos_lib.merge_results(
            atos_lib.results_filter(db.get_results(), {'hash': hashsum}))
        if results:
            results = atos_lib.merge_results(
                atos_lib.results_filter(
                    db.get_results(), {"variant": results[0].variant}),
                merge_targets=False)
            atos_lib.reuse_run_result(
                db, variant_id, args.options, args.uopts, args, results)
            message("Reusing run results for variant %s..." % variant_id)
            return 0

    nbruns = 1 if args.gopts else args.nbruns

    if nbruns is None: nbruns = int(
        atos_lib.get_config_value(
            args.configuration_path, "default_values.nb_runs", 1))

    for n in range(nbruns):
        run_args = atos_lib.namespace(
            args, run_number=n, nbruns=nbruns, hashsum=hashsum)
        status = run_tool_func(run_atos_one_run, run_args)
        if status: return status

    return 0

def run_atos_one_run(args):
    """ dispatcher for atos-one-run (local/remote). """
    remote_run = int(atos_lib.get_config_value(
            args.configuration_path, "default_values.remote_run", "0"))
    if remote_run and not args.local:
        status = run_atos_one_run_remote(args)
    else:
        status = run_atos_one_run_local(args)
    return status

def run_atos_one_run_remote(args):
    """ remote run implementation. """
    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)
    variant_id = atos_lib.hashid(variant)

    message("Running variant %s [%s]..." % (variant, variant_id))

    run_number = args.__dict__.get('run_number', 0)
    logs_dir = os.path.join(
        args.configuration_path, "logs")
    targets_file = os.path.join(
        args.configuration_path, "targets")
    care_archive_dir = os.path.join(
        args.configuration_path, "archives")

    # copy care archive (run.care.tar -> run.care.id.tar)
    care_archive_init = os.path.join(
        care_archive_dir, "run.care.tar")
    care_archive_copy = os.path.join(
        care_archive_dir, "run.care.%s.%d.tar" % (variant_id, run_number))
    care_archive_dest = os.path.join(
        care_archive_dir, "run.care.%s.%d.mod.tar.gz" % (
            variant_id, run_number))
    process.commands.copyfile(care_archive_init, care_archive_copy)

    # add targets
    care_file = tarfile.open(care_archive_copy, mode="a")
    reloc_dir_prefix = args.__dict__.get("reloc_dir", "")
    targets = filter(
        lambda x: x != "" and not x.startswith("#"),
        map(lambda x: x.strip(), open(targets_file).readlines()))
    targets = map(os.path.abspath, targets)
    map(lambda f: care_file.add(
            reloc_dir_prefix + f, arcname="run.care/rootfs" + f), targets)

    # add exec.sh script (local build & re-archive)
    rearchive_prefix = os.getcwd()  # same limit as relocation (TODO: doc)
    rerun_cmdline = process.list2cmdline(
        atos_tool_cmdline(
            "atos-run", args, local=True, record=False, nbruns=1,
            output_file=os.path.join(rearchive_prefix, "atos_results.out")))
    with tempfile.NamedTemporaryFile() as tmpfile:
        # TODO: configurable commands (bin/sh, tar)
        print >>tmpfile, "#!/bin/sh"
        print >>tmpfile, "set -ex"
        print >>tmpfile, "cd `dirname $0`"
        print >>tmpfile, "errors=0"
        print >>tmpfile, "# execute atos-run-local command"
        print >>tmpfile, "/bin/sh -e -x run.care/re-execute.sh \\"
        print >>tmpfile, "  " + rerun_cmdline + " || errors=1"
        print >>tmpfile, "# rebuild archive"
        print >>tmpfile, "tar czvf atos.tar.gz -C %s . || true" % (
            "run.care/rootfs" + rearchive_prefix)
        print >>tmpfile, "exit $errors"
        tmpfile.flush()
        process.commands.chmod(tmpfile.name, 0755)
        care_file.add(tmpfile.name, arcname="exec.sh")
    care_file.close()

    # compress modified archive (gzip module seems slower)
    process.system(["gzip", "--force", "--fast", care_archive_copy])
    care_archive_copy = care_archive_copy + ".gz"

    # call remote-run command
    # TODO: remote time estimation
    remote_run_sh = os.path.abspath(
        os.path.join(args.configuration_path, "run.remote.sh"))
    run_progress = progress.timer_progress(
        progress_type="run", variant_id=variant,
        config_path=args.configuration_path)
    status, output = process.system(
        atos_lib.env_command(
            ATOS_CARE_SRC=os.path.abspath(care_archive_copy),
            ATOS_CARE_DST=os.path.abspath(care_archive_dest),
            RUN_SLOT=args.__dict__.get('run_slot', ''))
        + [remote_run_sh],
        get_output=True, output_stderr=True)
    run_progress.end(status=status)
    if status or not os.path.exists(
        care_archive_dest):  # pragma: uncovered (error)
        message("FAILURE while running variant %s" % variant)
        return 1

    # extract needed files from resulting archive
    care_file = tarfile.open(care_archive_dest, "r:*")
    if reloc_dir_prefix: process.commands.mkdir(
        args.reloc_dir + rearchive_prefix)

    #  - profile files
    profile_path = args.gopts and atos_lib.get_profile_path(
        args.configuration_path, atos_lib.variant_id(gopts=args.gopts))
    members_prf = args.gopts and filter(
        lambda x: os.path.basename(profile_path) in x.name,
        care_file.getmembers()) or []  # None means ALL !
    care_file.extractall(
        path=rearchive_prefix, members=members_prf)

    #  - log files in atos-config path
    members_log = filter(
        lambda x: logs_dir in x.name, care_file.getmembers())
    care_file.extractall(
        path=rearchive_prefix, members=members_log)

    #  - results
    members_err = filter(
        lambda x: "atos_results.out" in x.name, care_file.getmembers())
    results_lines = members_err and care_file.extractfile(
        members_err[0]).readlines() or []
    results = atos_lib.atos_db_file._read_results_lines(results_lines)
    atos_lib.atos_db.db(args.configuration_path).add_results(results)
    care_file.close()

    # remove archives
    if not int(os.getenv("ATOS_KEEP_RELOC", "0")):  # pragma: uncovered
        process.commands.unlink(care_archive_copy)
        process.commands.unlink(care_archive_dest)

    return 0

def run_atos_one_run_local(args):
    """ ATOS run tool implementation. """

    def get_size(executables):
        def one_size(exe):  # pragma: uncovered
            if not os.path.isfile(exe):
                if not os.path.isabs(exe):
                    exe = process.commands.which(exe)
                else:
                    exe = None
            if not exe: return None
            status, output = process.system(
                atos_lib.proot_reloc_command(args) +
                process.cmdline2list(size_command) + [exe], get_output=True)
            if args.dryrun: return 0
            if status or not output: return None  # pragma: uncovered
            return int(output.splitlines()[-1].split()[3])
        executables_size = map(one_size, executables)
        if None in executables_size:  # pragma: uncovered
            return None
        return sum(executables_size)

    def get_time():
        run_env = {}
        if remote_profile_path != None and args.gopts != None:
            run_env.update(
                {"REMOTE_PROFILE_DIR": remote_profile_path})
            run_env.update(
                {"LOCAL_PROFILE_DIR": atos_lib.get_profile_path(
                        args.configuration_path,
                        atos_lib.variant_id(gopts=args.gopts))})

        run_env.update(
            {"RUN_SLOT": args.__dict__.get('run_slot', '')})
        run_script = os.path.abspath(
            os.path.join(args.configuration_path, "run.sh"))
        run_script = args.command or [run_script]

        run_progress = progress.timer_progress(
            progress_type="run", variant_id=variant,
            config_path=args.configuration_path)
        status, output = process.system(
            atos_lib.timeout_command() + atos_lib.proot_reloc_command(args)
            + atos_lib.env_command(run_env)
            + process.cmdline2list(time_command) + run_script,
            get_output=True, output_stderr=True)
        run_progress.end(status=status)

        if args.dryrun or status:
            return status, 0.0, output

        lines_output = output.splitlines()

        lines_user = filter(
            lambda x: x.startswith("user "), lines_output)
        # if existing 'time' lines in output,
        #   ignore the last one (produced by our time command)
        if len(lines_user) > 1: lines_user = lines_user[:-1]
        exe_time = sum(
            map(lambda x: float(x.split()[1]) * 1000, lines_user), 0.0)

        # remove last output of time command added by atos
        lines_filtered = list(lines_output)
        for i in ["^user ", "^real ", "^sys "]:
            def reindex(l, r):
                for i in xrange(  # pragma: branch_uncovered
                    len(l) - 1, -1, -1):
                    if re.match(r, l[i]): return i
            last_index = reindex(lines_filtered, i)
            if last_index: lines_filtered.pop(last_index)
        real_output = '\n'.join(lines_filtered) + '\n'

        return status, exe_time, real_output

    def output_run_results(target, variant, time, size):
        if args.silent: return
        if not time: time = "FAILURE"
        if not size: size = "FAILURE"
        entry = {}
        entry.update({'target': target})
        entry.update({'variant': variant})
        entry.update({'version': globals.VERSION})
        entry.update({'conf': " ".join(
                    process.cmdline2list(args.options or ''))})
        if args.uopts != None:
            entry.update({'uconf': " ".join(
                        process.cmdline2list(args.uopts))})
        if args.gopts != None:
            entry.update({'gconf': " ".join(
                        process.cmdline2list(args.gopts))})
        entry.update({'time': str(time)})
        entry.update({'size': str(size)})
        if args.cookies:
            entry.update({'cookies': ','.join(
                        atos_lib.list_unique(args.cookies))})
        hashsum = vars(args).get('hashsum', None) or atos_lib.target_hash(
            args, variant=variant)
        if hashsum: entry.update({'hash': str(hashsum)})
        if args.output_file:
            db = atos_lib.atos_db_file(args.output_file)
            atos_lib.atos_client_db(db).add_result(entry)
        elif args.record:
            db = atos_lib.atos_db.db(args.configuration_path)
            atos_lib.atos_client_db(db).add_result(entry)
        else:
            print >>sys.stderr, atos_lib.atos_db_file.entry_str(entry),

    def check_failure(failure, fail_condition, fail_message):
        if failure: return failure  # pragma: uncovered (error)
        if args.dryrun: return failure
        if fail_condition:
            debug("CHKFAILURE [%s]" % fail_message)
        return fail_condition

    def check_cmd(cmd, msg=""):
        cmd_list = process.cmdline2list(cmd)
        if not process.commands.which(
            cmd_list[0]):  # pragma: uncovered (error)
            error("%s: command not found: %s" % (msg, cmd_list[0]))
            return False
        return True

    def status_message(logf=None, failure=False):
        if failure:
            message("FAILURE while running variant %s" % variant)
            logf.write("FAILURE while running variant %s\n" % variant)
        else:
            logf.write("SUCCESS running variant %s\n" % variant)
        logf.close()

    if not os.path.isdir(args.configuration_path):  # pragma: uncovered (error)
        error("configuration path not found: %s: run atos-init first" %
              args.configuration_path)
        return 1

    variant = args.variant or atos_lib.variant_id(
        args.options, args.gopts, args.uopts)

    results_script = args.results_script
    if not results_script:
        get_res_sh = os.path.abspath(
            os.path.join(args.configuration_path, "get_res.sh"))
        results_script = os.path.isfile(get_res_sh) and get_res_sh

    remote_profile_path = atos_lib.get_remote_profile_path(args, variant)

    time_command = args.time_cmd
    if not args.time_cmd:
        time_command = atos_lib.time_command(args.configuration_path)
    if not check_cmd(
        time_command, "in time command"): return 1  # pragma: uncovered (error)

    size_command = args.size_cmd
    if not args.size_cmd:
        size_command = atos_lib.size_command(args.configuration_path)
    if not check_cmd(
        size_command, "in size command"): return 1  # pragma: uncovered (error)

    if results_script:
        executables, target_id = None, None
    else:
        try:
            with open(os.path.join(
                    args.configuration_path, "targets")) as targetf:
                executables = filter(  # pragma: branch_uncovered
                    lambda x: x != "" and not x.startswith("#"),
                    map(lambda x: x.strip(), targetf.readlines()))
        except:
            error('no target executable available in configuration')
            return 1
        target_id = args.id or atos_lib.target_id(executables)

    log_name_prefix = "run"
    if args.nbruns > 1:  # one log file per run
        log_name_prefix += "-%d" % args.__dict__.get('run_number', 0)

    logf = atos_lib.open_atos_log_file(
        args.configuration_path, log_name_prefix, variant)
    message("Running variant %s [%s]..." %
            (variant, atos_lib.hashid(variant)))

    failure = False

    if executables:
        exe_size = get_size(executables)
        failure = check_failure(
            failure, exe_size is None, "get_size failure")
    else:
        exe_size = None

    logf.write("Running variant %s\n" % (variant))

    status, exe_time, output_time = get_time()

    logf.write(output_time)

    failure = check_failure(
        failure, status != 0, "get_time failure")
    if failure:  # pragma: uncovered (error)
        output_run_results(
            results_script and "FAILURE" or target_id,
            variant, "FAILURE", "FAILURE")
        status_message(logf=logf, failure=True)
        return 2

    if results_script:
        status, output_res = process.system(
            atos_lib.proot_reloc_command(args) +
            process.cmdline2list(results_script),
            get_output=True,
            output_stderr=True, stdin_str=output_time)
        output_time += "\n" + output_res
        failure = check_failure(
            failure, status != 0, "get_res failure")
    output_result = {}

    for line in output_time.splitlines():
        words = line.split(': ')
        if words[0] != "ATOS": continue
        target, key, value = words[1:4]
        output_result.setdefault(target, {})[key] = value

    if output_result:
        for target, res in output_result.items():
            exe_time = res.get('time', None)
            exe_size = res.get('size', None)
            output_run_results(target, variant, exe_time, exe_size)
            failure = check_failure(
                failure, not exe_time, "get_res time failure")
            failure = check_failure(
                failure, not exe_size, "get_res size failure")
    else:  # no "ATOS: targ: time: ..." lines
        output_run_results(target_id, variant, exe_time, exe_size)
        failure = check_failure(
            failure, not exe_time, "res time failure")
        failure = check_failure(
            failure, not exe_size, "res size failure")

    status_message(logf=logf, failure=failure)
    return failure and 2 or 0

def run_atos_replay(args):
    """ ATOS opt tool implementation. """

    if os.path.abspath(
        args.results_path) == os.path.abspath(
        args.configuration_path):  # pragma: uncovered (error)
        error("replay result path must differ from configuration path")
        return 1

    if not args.run_script:  # pragma: uncovered (error)
        error("run_script argument is mandatory for atos-replay")
        return 1

    process.commands.mkdir(args.results_path)

    results_db_file = os.path.join(args.results_path, "results.db")
    if not os.path.isfile(results_db_file):  # pragma: uncovered
        atos_lib.atos_db_file(results_db_file)

    config_target_file = os.path.join(args.configuration_path, 'targets')
    result_target_file = os.path.join(args.results_path, 'targets')
    process.commands.copyfile(config_target_file, result_target_file)

    if os.path.isfile(  # pragma: uncovered
        os.path.join(args.configuration_path, 'build.time')):
        process.commands.copyfile(
            os.path.join(args.configuration_path, 'build.time'),
            os.path.join(args.results_path, 'build.time'))

    time_cmd = globals.DEFAULT_TIME_CMD
    if args.time_cmd: time_cmd = args.time_cmd
    size_cmd = globals.DEFAULT_SIZE_CMD
    if args.size_cmd: size_cmd = args.size_cmd

    # get frontier results
    results_db = atos_lib.atos_db.db(args.configuration_path)
    results_client = atos_lib.atos_client_results(results_db)
    if args.variants:
        results = []
        for variant in args.variants:
            res_variant = atos_lib.atos_client_db(results_db).query(
                {'variant': variant})
            if not res_variant:  # pragma: uncovered (error)
                warning("variant not found: '%s'" % variant)
                continue
            results.append(atos_lib.atos_client_results.result(res_variant[0]))
    else:
        results_client = atos_lib.atos_client_results(results_db)
        results = results_client.get_results(only_frontier=True, objects=True)

    replay_progress = progress.exploration_progress(
        descr="replay",
        maxval=len(results) + (0 if args.no_ref else 1),
        config_path=args.results_path)

    if not args.no_ref:
        # reference build
        status = invoque("atos-build", args)
        if status != 0: return status  # pragma: uncovered (error)

        # reference run
        status = invoque("atos-run", args,
                         configuration_path=args.results_path, record=True,
                         command=process.cmdline2list(args.run_script),
                         size_cmd=size_cmd, time_cmd=time_cmd)
        if status != 0: return status  # pragma: uncovered (error)
        replay_progress.update()

    for result in results:
        result_conf = getattr(result, 'conf', None)
        result_uconf = getattr(result, 'uconf', None)
        status = invoque(
            "atos-build", args, options=result_conf, uopts=result_uconf)
        if status == 0:  # pragma: branch_always (error)
            invoque("atos-run", args, configuration_path=args.results_path,
                    record=True, options=result_conf, uopts=result_uconf,
                    command=process.cmdline2list(args.run_script),
                    size_cmd=size_cmd, time_cmd=time_cmd)
        replay_progress.update()

    replay_progress.end()

    return 0

def run_atos_config(args):
    """ ATOS config implementation. """

    compiler_list = args.compilers

    if not compiler_list:
        compilers = os.path.join(args.configuration_path, "compilers")

        if not os.path.isfile(compilers):
            error("compiler file missing: %s" % compilers)
            return 1

        with open(compilers) as inf:
            compiler_list = filter(
                str, map(lambda x: x.strip(), inf.readlines()))
        if not compiler_list:  # pragma: uncovered (error)
            error("no compiler found in configuration, "
                  "audit did not work correctly")
            return 1

    config_file = os.path.join(args.configuration_path, 'config.json')

    for compiler in compiler_list:
        if not os.path.isfile(compiler):
            error("compiler executable not found: %s" % compiler)
            return 1
        compiler_entry = atos_lib.json_config.compiler_config(
            args.configuration_path, compiler)
        if args.print_cfg:
            print json.dumps(compiler_entry, sort_keys=True, indent=4)
        else:
            json_config = atos_lib.json_config(config_file)
            json_config.add_compiler_entry(compiler_entry)

    if not args.print_cfg and not args.compilers:
        json_config = atos_lib.json_config(config_file)
        json_config.prepare_flag_files(
            args.configuration_path, compiler_list, args.flags)
        # print compiler config
        logger.message("Compilers found:")
        compilers = json_config.config.get('compilers', [])
        for compiler in compilers:
            logger.message(
                "  " + atos_lib.json_config.compiler_entry_str(compiler))
        # forbid multiple compilers
        compiler_ids = set(
            filter(bool, map(lambda c: c.get('id', False), compilers)))
        if (len(compiler_ids) > 1
            and not os.getenv("ATOS_ALLOW_MULTIPLE_COMPILERS", "")
            ):  # pragma: uncovered (error)
            error("multiple compilers are not allowed. "
                  "Compiler name can be specified with --ccname option.")
            return 1

    return 0

def run_atos_cookie(args):
    """ ATOS cookie generator implementation. """
    print atos_lib.unique_cookie(args.cookies)
    return 0

def run_atos_explore_inline(args):
    """ ATOS explore-inline tool implementation. """

    status = generators.run_exploration_loop(
        args, generator=generators.gen_explore_inline)
    return status

def run_atos_explore_loop(args):
    """ ATOS explore-loop tool implementation. """

    status = generators.run_exploration_loop(
        args, generator=generators.gen_explore_loop)
    return status

def run_atos_explore_optim(args):
    """ ATOS explore-optim tool implementation. """

    status = generators.run_exploration_loop(
        args, generator=generators.gen_explore_optim)
    return status

def run_atos_explore_random(args):
    """ ATOS explore-random tool implementation. """

    status = generators.run_exploration_loop(
        args, generator=generators.gen_explore_random)
    return status

def run_atos_explore_staged(args):
    """ ATOS explore-acf tool implementation. """

    status = invoque("atos-init", args)
    if status != 0: return status  # pragma: uncovered (error)

    status = generators.run_exploration_loop(
        args, generator=generators.gen_staged)
    return status

def run_atos_explore_genetic(args):
    """ ATOS explore-acf tool implementation. """

    status = invoque("atos-init", args)
    if status != 0: return status  # pragma: uncovered (error)

    status = generators.run_exploration_loop(
        args, generator=generators.gen_genetic)
    return status

def run_atos_explore_flag_values(args):
    """ ATOS explore-flag-values tool implementation. """

    status = invoque("atos-init", args)
    if status != 0: return status  # pragma: uncovered (error)

    status = generators.run_exploration_loop(
        args, generator=generators.gen_flag_values)
    return status

def run_atos_explore_flags_pruning(args):
    """ ATOS explore-flags-pruning tool implementation. """

    status = invoque("atos-init", args)
    if status != 0: return status  # pragma: uncovered (error)

    variant = args.variant_id
    # select best tradeoff if no variant given
    if not variant:
        res_args = vars(args or {})
        res_args.update({'refid': 'REF'})
        all_results = atos_lib.get_results(
            args.configuration_path, atos_lib.default_obj(**res_args))
        selected = atos_lib.atos_client_results.select_tradeoffs(
            all_results, args.tradeoff, 1) or []
        variant = selected and selected[0].variant or None

    if not variant:  # pragma: uncovered (error)
        error("expected identifier of variant to be pruned")
        return 1

    message("Pruning variant %s [%s]..." %
            (variant, atos_lib.hashid(variant)))

    status = generators.run_exploration_loop(
        args, variant_id=variant, generator=generators.gen_pruning)
    return status

def run_atos_explore_acf(args):
    """ ATOS explore-acf tool implementation. """

    imgpath = profile.get_image_pathes(
        args.exes, args.configuration_path)
    if not imgpath:  # pragma: uncovered (error)
        error("executables must be specified (-e option)")
        return 1

    prof_script = args.prof_script or os.path.join(
        args.configuration_path, "profile.sh")
    if not os.path.isfile(prof_script):  # pragma: uncovered (error)
        error("profiling script not specified or missing: %s" % prof_script)
        return 1

    csv_dir = os.path.join(args.configuration_path, 'acf_csv_dir')
    process.commands.mkdir(csv_dir)

    file_by_file = args.file_by_file
    if not file_by_file:

        # ACF mode - function-by-function exploration

        acf_plugin_path = atos_lib.query_config_values(
            args.configuration_path, "$.compilers[*].plugin_acf")
        acf_plugin_path = acf_plugin_path and list(set(acf_plugin_path))[0]

        host_wide_int = atos_lib.query_config_values(
            args.configuration_path, "$.compilers[*].valid_host_wide_int",
            default=None)

        plugins_enabled = atos_lib.query_config_values(
            args.configuration_path, "$.compilers[*].plugins_enabled")
        plugins_enabled = plugins_enabled and bool(int(
            list(set(plugins_enabled))[0])) or False

        if not acf_plugin_path:  # pragma: uncovered
            warning("compiler not supported by acf plugin")
            warning("switching to file-by-file exploration")
            file_by_file = True

        elif host_wide_int and not all(
            map(int, host_wide_int)):  # pragma: uncovered (error)
            error("compiler not supported by acf plugin (wrong hwi_size)")
            return 1

        elif not plugins_enabled:  # pragma: uncovered
            warning("compiler does not support plugins")
            warning("switching to file-by-file exploration")
            file_by_file = True

        else:
            status = generators.run_exploration_loop(
                args, imgpath=imgpath, csv_dir=csv_dir,
                prof_script=prof_script, acf_plugin_path=acf_plugin_path,
                acf_hot_th=str(args.hot_th),
                acf_cold_opts=("%s %s" % (args.cold_opts, args.cold_attrs)),
                flags_file=args.flags_file,
                per_func_nbiters=args.per_func_nbiters,
                generator=generators.gen_function_by_function)

    if file_by_file:

        # FILE mode - file-by-file exploration

        status = generators.run_exploration_loop(
            args, prof_script=prof_script,
            imgpath=imgpath, csv_dir=csv_dir,
            hot_th=str(args.hot_th), cold_opts=args.cold_opts,
            flags_file=args.flags_file,
            per_file_nbiters=args.per_func_nbiters,
            generator=generators.gen_file_by_file)

    return status

def run_atos_graph(args):  # pragma: uncovered
    """ ATOS graph tool implementation. """

    from atos_graph import optgraph
    from atos_graph import multgraph
    from atos_graph import correlgraph
    from atos_graph import heatgraph
    from atos_graph import draw_graph
    from atos_graph import draw_correl_graph
    from atos_graph import draw_heat_graph

    if args.correlation_graph:
        get_graph_f = lambda: correlgraph(args)
        draw_correl_graph(get_graph_f, args)

    elif args.heat_graph:
        if not (args.cookies and len(args.cookies) == 1):
            error("--heat must be used with one given cookie")
            return 1
        get_graph_f = lambda: heatgraph(args)
        draw_heat_graph(get_graph_f, args)

    elif args.configuration_pathes:
        # frontier graph
        get_graph_f = lambda: multgraph(args)
        draw_graph(get_graph_f, args)

    else:
        # classic optimization space graph
        get_graph_f = lambda: optgraph(args)
        draw_graph(get_graph_f, opts=args)

    return 0

def run_atos_web(args):  # pragma: uncovered
    """ ATOS web interface """
    import requests

    # Lower request module verbosity
    import logging
    requests_log = logging.getLogger("requests")
    requests_log.setLevel(logging.WARNING)

    def op_create(url):
        try:
            arguments = dict(token.split('=', 1)
                                for token in args.operation[1:])
        except ValueError:
            error("Arguments should be written 'key=value'")
            return

        try:
            r = requests.put("http://%s%s" % (args.server, url), arguments)
        except requests.exceptions.RequestException as ex:
            error("Error while doing the PUT request\n %s" % (ex))
            return

        try:
            if r.status_code == 200 and r.json()['status'] == 'success':
                return
            else:
                error("Error while creating: %s" % (arguments))
                if r.status_code == 200:
                    error("=> %s" % (r.json()['message']))
                elif r.status_code == 404:
                    error("=> Object not found")
        except ValueError:
            error("The answer is not a valid json object")
            return
        except TypeError:
            error("The json object is not formated as expected")
            return
        except KeyError:
            error("The json object is missing some required fields")
            return

    def op_list(url, banner, key_id='id', key_name='name'):
        try:
            r = requests.get("http://%s%s" % (args.server, url))
        except requests.exceptions.RequestException as ex:
            error("Error while doing the GET request\n %s" % (ex))
            return

        if r.status_code == 200:
            try:
                obj = r.json()
            except ValueError:
                error("The answer is not a valid json object")
                return
            message(banner)
            try:
                for l in obj:
                    message(" %s: %s" % (l[key_id], l[key_name]))
            except TypeError:
                error("The json object is not formated as expected")
                return
            except KeyError:
                error("The json object is missing some required fields")
                return
        else:
            error("Error while listing on %s" % (args.server))

    def op_details(url, key_name='name'):
        try:
            r = requests.get("http://%s%s" % (args.server, url))
        except requests.exceptions.RequestException as ex:
            error("Error while doing the GET request\n %s" % (ex))
            return

        if r.status_code == 200:
            try:
                obj = r.json()
                message("Details of '%s'" % (obj[key_name]))
                for key in obj.keys():
                    message(" %s: %s" % (key, obj[key]))
            except ValueError:
                error("The answer is not a valid json object")
                return
            except TypeError:
                error("The json object is not formated as expected")
                return
            except KeyError:
                error("The json object is missing some required fields")
                return
        else:
            error("Object not found at '%s'" % (url))

    def load_cookies_db(configuration_path):
        """
        Load the cookies.db file and return the list of cookies listed inside
        """
        try:
            fd = open(os.path.join(configuration_path, 'cookies.db'))
        except IOError:
            error("Unable to open the cookie database at '%s'" %
                    (os.path.join(configuration_path, 'cookies.db')))
            return []

        return [c for c in json.load(fd)]

    def filter_cookies(cookies_db, cookies):
        """
        Filter out the cookies that are not listed in cookies_db
        """
        # Filter everithing out if the cookies_db is empty
        if not cookies_db:
            return []

        filtered = []
        for cookie in cookies:
            if cookie in cookies_db:
                filtered.append(cookie)
        return filtered

    def print_progress(percent):
        # Only print progress in a tty
        if sys.stdout.isatty():
            # pad with space to clear previous message and
            # clamp msg to terminal width,
            with os.popen("tput cols", "r") as tput:
                # Remove 8 caracters for '[===>] xx%'
                cols = int(tput.readline()) - 8
            # Check that we have enough space in the terminal
            if cols <= 0:
                return
            # Print '[===>] xx%'
            status = '\r[' + int(cols * percent / 100) * "=" + '>]'
            status += " %d%%" % (percent)
            sys.stdout.write(status)
            sys.stdout.flush()

    # Subcommands
    if args.subcmd_web == "project":
        if len(args.operation) == 0:
            error("Missing operation: should be create, list or details")
            return

        if args.operation[0] == 'create':
            op_create('/api/1.0/projects')
        elif args.operation[0] == 'list':
            op_list('/api/1.0/projects', "Projects on %s" % (args.server))
        elif args.operation[0] == 'details':
            if len(args.operation) < 2:
                error("The operation expect a project id as parameter")
                return
            op_details("/api/1.0/projects/%s" % (args.operation[1]))
        else:
            error("atos-web-project: unknow operation '%s'"
                  % (args.operation[0]))

    elif args.subcmd_web == 'cookie':
        # Open the cookie database and return an error if that's not possible
        try:
            fd = open(os.path.join(args.configuration_path, 'cookies.db'))
        except IOError as e:
            error("Unable to open '%s': '%s'" %
                        (os.path.join(args.configuration_path, 'cookies.db'),
                         e.strerror))
            return

        # Get the cookie list for hash <=> id mapping
        r = requests.get(
                "http://%s/api/1.0/projects/%d/experiments/%d/cookies" %
                            (args.server, args.project, args.experiment))
        if r.status_code != 200:
            error('Project not found')
            return
        cookies_mapping = dict((c['hash'], c['id']) for c in r.json())

        # Load the cookie json file
        try:
            cookies_db = json.load(fd)
        except ValueError as e:
            error("Unable to load the cookies database: '%s'" % (e.message))
            return

        # Create the missing cookies
        # This way we can create the parenting relation shift right after
        message('Pushing the missing cookies')
        for cookie in cookies_db:
            if cookie not in cookies_mapping:
                message(" %s" % (cookie))
                requests.put(
                  "http://%s/api/1.0/projects/%d/experiments/%d/cookies" %
                      (args.server, args.project, args.experiment),
                          {'hash': cookie})
        message('Done')

        # Push the cookie descriptions and children
        message('Pushing the details')
        for cookie in cookies_db:
            message(" Looking at '%s'" % (cookie))
            # Push the description if available
            description = cookies_db[cookie].get('description')
            if description:
                requests.put(
                    "http://%s/api/1.0/projects/%d/experiments/%d/cookies" %
                        (args.server, args.project, args.experiment),
                    {'hash': cookie, 'description': description})

            if not 'succs' in cookies_db[cookie]:
                message('  -> No child')
                continue
            children = cookies_db[cookie]['succs']
            message('  -> Pushing children:\n   * ' + '\n   * '.join(children))

            try:
                r = requests.put(
        "http://%s/api/1.0/projects/%d/experiments/%d/cookies/%d/children" %
                        (args.server, args.project, args.experiment,
                         cookies_mapping[cookie]),
                    {'children': ','.join(children)})
                if not (r.status_code == 200 and
                        r.json()['status'] == 'success'):
                    error("Error while pushing: %s" % (cookie))
                    if r.status_code == 200:
                        error(" => %s" % (r.json()['message']))
                    else:
                        error(' => Cookie not found')
            except KeyError:
                error(' => Parent cookie not found')
        return

    elif args.subcmd_web == "experiment":
        if len(args.operation) == 0:
            error("Missing operation: should be create, list or details")
            return
        if args.operation[0] == 'create':
            op_create("/api/1.0/projects/%s/experiments"
                        % (args.project))
        elif args.operation[0] == 'list':
            op_list("/api/1.0/projects/%s/experiments" % (args.project),
                     "Experiment for project %d on %s"
                        % (args.project, args.server))
        elif args.operation[0] == 'details':
            if len(args.operation) < 2:
                error("The operation expect an experiment id as parameter")
                return
            op_details("/api/1.0/projects/%s/experiments/%s"
                            % (args.project, args.operation[1]))
        else:
            error("atos-web-experiment: unknow operation '%s'"
                  % (args.operation[0]))
            return 1

    elif args.subcmd_web == "target":
        if len(args.operation) == 0:
            error("Missing operation: should be create, list or details")
            return
        if args.operation[0] == 'create':
            op_create("/api/1.0/projects/%s/experiments/%s/targets"
                       % (args.project, args.experiment))
        elif args.operation[0] == 'list':
            op_list("/api/1.0/projects/%s/experiments/%s/targets"
                        % (args.project, args.experiment),
                     "Target for project %d on %s"
                        % (args.project, args.server))
        elif args.operation[0] == 'details':
            if len(args.operation) < 2:
                error("The operation expect a target id as parameter")
                return
            op_details("/api/1.0/projects/%s/experiments/%s/targets/%s"
                            % (args.project, args.experiment,
                               args.operation[1]))
        else:
            error("atos-web-target: unknow operation '%s'"
                  % (args.operation[0]))
            return 1

    elif args.subcmd_web == "run":
        if len(args.operation) == 0:
            error("Missing operation: should be create, list or details")
            return
        if args.operation[0] == 'create':
            # Pushing all the runs
            if len(args.operation) == 2 and args.operation[1] == "all":
                # Get the list of targets
                session = requests.Session()
                r = session.get(
                    "http://%s/api/1.0/projects/%s/experiments/%s/targets/%s"
                        % (args.server, args.project, args.experiment,
                           args.target))
                if r.status_code != 200:
                    error("Uname to find the target %d" % (args.target))
                    return 1
                target = r.json()['name']
                message("Target name: %s" % (target))

                # Get the cookies to keep
                cookies_db = load_cookies_db(args.configuration_path)

                # Load the result database
                results = atos_lib.atos_db.db(args.configuration_path) \
                                          .get_results({'target': target})

                order = 0
                num_results = len(results)
                for result in results:
                    # The order is the run number. It should be incremented
                    # even if the run failed
                    order += 1
                    print_progress((order / (float)(num_results)) * 100)
                    if result['time'] == 'FAILURE' or \
                       result['size'] == 'FAILURE':
                        message("Not pushing failed run %s"
                                % (atos_lib.hashid(result['variant'])))
                        continue

                    # Select only the cookies present in cookies_db
                    run_cookies = result.get('cookies', '').split(',')
                    filtered_cookies = filter_cookies(cookies_db, run_cookies)
                    # Push the run
                    values = {
                         'order': order,
                         'hash': atos_lib.hashid(result['variant']),
                         'version': result['version'],
                         'conf': result['conf'],
                         'uconf': result.get('uconf', ''),
                         'time': result['time'],
                         'size': result['size'],
                         'cookies': ','.join(filtered_cookies)}
                    r = session.put(
                "http://%s/api/1.0/projects/%s/experiments/%s/targets/%s/runs"
                % (args.server, args.project, args.experiment, args.target),
                values)
                    if r.status_code != 200:
                        error("Unknown error")
                    elif r.json()['status'] == 'failure':
                        error("Error: %s" % (r.json()['message']))
            else:
                op_create(
                    "/api/1.0/projects/%s/experiments/%s/targets/%s/runs"
                        % (args.project, args.experiment, args.target))
            return 0
        elif args.operation[0] == 'list':
            op_list("/api/1.0/projects/%s/experiments/%s/targets/%s/runs"
                        % (args.project, args.experiment, args.target),
                     "Run for experiment %d, target %d, on %s"
                        % (args.experiment, args.target, args.server),
                     'id', 'hash')
        elif args.operation[0] == 'details':
            if len(args.operation) < 2:
                error("The operation expect a run id as parameter")
                return
            op_details(
                "/api/1.0/projects/%s/experiments/%s/targets/%s/runs/%s"
                    % (args.project, args.experiment, args.target,
                       args.operation[1]), 'hash')
        else:
            error("atos-web-run: unknown operation '%s'"
                  % (args.operation[0]))
            return 1

    return 0
