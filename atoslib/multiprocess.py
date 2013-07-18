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

import os, sys, atexit, glob
import threading

import globals
import atos_lib
import process

def setup(kwargs):
    """
    Configure the multiprocess module.
    """
    mp.setup(kwargs)

def enabled():
    """
    Return True if parallel mode is enabled.
    """
    return mp.enabled

def launch(*args, **kwargs):
    """
    Wrapper for atos_(opt|build|run) functions.
    """
    return mp.launch(*args, **kwargs)

def wait_for_results(cookies):
    """
    Wait for results associated to given cookies.
    """
    for cookie in cookies:
        cookie_threads = mp.opt_thread_map.get(cookie, [])
        for thr in cookie_threads: thr.join()

class mp():

    enabled = False

    reloc_enabled = False
    keep_reloc_dir = False

    # cookie_to_thread map {run_cookies: [opt_thread]}
    # used for waiting for results associated to given config cookies
    opt_thread_map = {}

    # jobid_to_optthread map {job_id: opt_thread}
    # used for waiting for the end of a specific execution
    job_thread_map = {}

    # optthread_to_runthread map {opt_thread -> [run_thread]}
    # used for waiting for run executions before ending an atos_opt thread
    run_thread_map = {}

    # configopts_to_optthread map {(opt,fdo,lto): [opt_thread]}
    # used for waiting for similar runs, for avoiding fdo_profile_path
    # overwrites and for giving reusing opportunity
    cfg_thread_map = {}
    cfg_thread_map_lock = threading.Lock()

    # pools used for limiting number of simultaneous build/run jobs
    build_pool = None
    run_pool = None
    opt_pool = None

    # pool size used for time estimation - resized in mp.setup
    build_pool_size = 1
    run_pool_size = 1

    @staticmethod
    def setup(kwargs):
        """
        Configure the multiprocess module.
        """
        configuration_path = kwargs.get(
            'configuration_path', globals.DEFAULT_CONFIGURATION_PATH)

        # get build/run pool size from envvars/cmdline/config
        mp.build_pool_size = (
            int(os.getenv("ATOS_BUILD_JOBS", "0"))
            or int(os.getenv("ATOS_PARALLEL", "0"))
            or int(kwargs.get('build_jobs', None) or 0)
            or int(atos_lib.get_config_value(
                    configuration_path, 'default_values.build_jobs', 0))
            or 1)
        mp.run_pool_size = (
            int(os.getenv("ATOS_RUN_JOBS", "0"))
            or int(os.getenv("ATOS_PARALLEL", "0"))
            or int(kwargs.get('run_jobs', None) or 0)
            or int(atos_lib.get_config_value(
                    configuration_path, 'default_values.run_jobs', 0))
            or 1)

        mp.enabled = (mp.build_pool_size > 1) or (mp.run_pool_size > 1)
        if not mp.enabled: return

        mp.reloc_enabled = bool(
            int(os.getenv("ATOS_RELOC", "1")))
        mp.keep_reloc_dir = bool(
            int(os.getenv("ATOS_KEEP_RELOC", "0")))
        opt_pool_size = (
            int(os.getenv("ATOS_OPT_JOBS", "0"))
            or (mp.build_pool_size + mp.run_pool_size + 2))

        if opt_pool_size > 0: mp.opt_pool = (
            threading.BoundedSemaphore(value=opt_pool_size))
        if mp.build_pool_size > 0: mp.build_pool = (
            SemaphoreSlot(value=mp.build_pool_size))
        if mp.run_pool_size > 0: mp.run_pool = (
            SemaphoreSlot(value=mp.run_pool_size))

    @staticmethod
    def new_job_id(): return atos_lib.new_cookie()

    @staticmethod
    def reloc_exec_dir(args, job_id):
        """
        Return the directory name for a relocated build.
        (atos-config/reloc/threadid-variantid).
        """
        def hash_variant(args):
            # return the same directory for profile-gen and profile-use builds
            options = args.options or ''
            uopts = args.uopts or vars(args).get('gopts', None)
            # atos_opt arguments
            arg_fdo = vars(args).get('fdo', False)
            arg_lto = vars(args).get('lto', False)
            if arg_fdo and uopts is None: uopts = options
            if arg_lto and "-flto" not in options: options += " -flto"
            variant_id = atos_lib.variant_id(options, None, uopts)
            return atos_lib.hashid(variant_id)
        if not mp.reloc_enabled: return None  # pragma: uncovered
        reloc_id = "%s-%s" % (job_id, hash_variant(args))
        new_cwd = os.path.abspath(os.path.join(
            args.configuration_path, "reloc", reloc_id))
        return new_cwd

    @staticmethod
    def start_atos_opt(func, args):
        """
        Launch an atos_opt execution in a dedicated thread and return.
        Update the cookie_to_thread map, which will be used before using
        this atos_opt run results.
        Wait until thread termination if profiling (oprof/perf) config.
        """
        def atos_opt_wrapper(func, args):
            # wait until similar configs run end
            wait_for_similar_jobs(args)
            # call the run_atos_opt function
            status = func(args)
            # wait for all pending runs before exit
            map(lambda thr: thr.join(), mp.run_thread_map.get(args.job_id, []))
            # call given callback if any (progress update, for ex.)
            map(lambda x: x(), args.__dict__.get('opt_callbacks', None) or [])
            # remove the reloc_exec directory
            if args.reloc_dir and not mp.keep_reloc_dir:
                process.commands.rmtree(args.reloc_dir)
            # release the opt slot
            mp.opt_pool and mp.opt_pool.release()
            return status

        def wait_for_similar_jobs(args):
            # consider fdo and fdo+lto as the same config
            config = (args.options, args.fdo, args.lto and not args.fdo)
            # register current opt-thread in cfg-thread map
            mp.cfg_thread_map_lock.acquire()
            mp.cfg_thread_map.setdefault(config, []).append(
                mp.job_thread_map[args.job_id])
            cfg_threads = mp.cfg_thread_map[config][:-1]
            mp.cfg_thread_map_lock.release()
            # wait for fdo_thread termination
            map(lambda thr: thr.join(), cfg_threads)

        # unique id for this atos-opt job
        job_id = mp.new_job_id()
        # wait for a free slot in the opt pool
        mp.opt_pool and mp.opt_pool.acquire()
        # relocated execution directory
        args = atos_lib.namespace(
            args, reloc_dir=mp.reloc_exec_dir(args, job_id), job_id=job_id)
        # create a thread for the atos-opt execution
        opt_thread = IntThread(
            target=atos_opt_wrapper, args=(func, args))
        # register it in the thread map {run_cookies: [opt_thread]}
        for cookie in args.cookies or [None]: mp.opt_thread_map.setdefault(
            cookie, []).append(opt_thread)
        # register it in the jobs map {job_id: opt_thread}
        mp.job_thread_map.update({job_id: opt_thread})
        # thread's activity can now be started
        opt_thread.start()
        # wait for the results in case of profiling (oprofile/perf) run
        # (as there will be no get_results/wait_for_results call after
        #  this profiling run)
        if args.profile: opt_thread.join()
        return 0

    @staticmethod
    def start_atos_one_run(func, args):
        """
        Launch an atos_one_run execution in a dedicated thread and return.
        Update the optthread_to_runthread map, which will be used for joining
        atos_opt thread.
        Wait until thread termination if profiling run (fdo), or if not called
        from atos_opt/atos-run.
        """
        def atos_one_run_wrapper(func, args):
            # wait for a free slot in the run pool
            slot = mp.run_pool and mp.run_pool.acquire()
            # handle reloc_exec run dir
            args = atos_lib.namespace(args, reloc_dir=reloc_run_dir(args))
            # call the run_atos_one_run function
            status = func(atos_lib.namespace(args, run_slot=slot))
            # remove the run directory - unless profile-gen run
            if args.reloc_dir and not mp.keep_reloc_dir and args.gopts is None:
                process.commands.rmtree(args.reloc_dir)
            # release the run slot
            mp.run_pool and mp.run_pool.release(slot)
            return status

        def reloc_run_dir(args):
            # nothing to do if reloc is disabled
            if not args.reloc_dir: return  # pragma: uncovered
            run_number = (args.nbruns > 1) and (args.run_number + 1) or 0
            # return reloc_build_dir if only one run
            if not run_number: return args.reloc_dir
            # handle multiple run case
            run_cwd = args.reloc_dir + '-' + str(run_number)
            # copy build_reloc_dir if existing
            if os.path.exists(args.reloc_dir):  # pragma: branch_always
                process.commands.rmtree(run_cwd)
                # avoid to open in write mode files that will be executed
                process.system(["/bin/cp", "-fr", args.reloc_dir, run_cwd])
            return run_cwd

        # create a thread for the atos-one-run execution
        run_thread = IntThread(
            target=atos_one_run_wrapper, args=(func, args))
        # register it in the run_thread map {opt_thread -> [run_thread]}
        mp.run_thread_map.setdefault(args.job_id, []).append(run_thread)
        # start the run thread activity
        run_thread.start()
        # wait for the results in case of profiling (fdo) run
        if not args.gopts is None: run_thread.join()
        return 0

    @staticmethod
    def start_atos_run(func, args):
        """
        Launch an atos_run execution.
        Blocks until end of runs.
        """
        # compute job_id/reloc_dir in the case of direct atos-run call
        job_id = args.__dict__.get(
            'job_id', mp.new_job_id())
        reloc_dir = args.__dict__.get(
            'reloc_dir', mp.reloc_exec_dir(args, job_id))
        # call the run_atos_run function
        status = func(atos_lib.namespace(
                args, reloc_dir=reloc_dir, job_id=job_id))
        # wait for all pending runs before exit
        map(lambda thr: thr.join(), mp.run_thread_map.get(job_id, []))
        return status

    @staticmethod
    def start_atos_build(func, args):
        """
        Launch an atos_build execution.
        Handle build-jobs limit by using build_pool semaphore.
        """
        # wait for a free slot in the build pool
        slot = mp.build_pool and mp.build_pool.acquire()
        # call the run_atos_build function
        status = func(atos_lib.namespace(args, build_slot=slot))
        # release the build slot
        mp.build_pool and mp.build_pool.release(slot)
        return status

    @staticmethod
    def launch(tool_func, tool_args):
        """
        Wrapper for atos_(opt|build|run) functions.
        Parallelize executions when possible and handle relocation.
        """
        func_name = tool_func.__name__

        if func_name == 'run_atos_opt':
            return mp.start_atos_opt(
                func=tool_func, args=tool_args)

        if func_name == 'run_atos_run':
            return mp.start_atos_run(
                func=tool_func, args=tool_args)

        if func_name == "run_atos_one_run":
            return mp.start_atos_one_run(
                func=tool_func, args=tool_args)

        if func_name == "run_atos_build":
            return mp.start_atos_build(
                func=tool_func, args=tool_args)

        return tool_func(tool_args)

class SemaphoreSlot(threading._Semaphore):
    """
    Semaphore managing a slots pool.
    """
    def __init__(self, value=1):
        threading._Semaphore.__init__(self, value)
        self._slots_nb = value
        self._slots_lock = threading.Lock()
        self._slots = [True] * value

    def acquire(self):
        threading._Semaphore.acquire(self, blocking=1)
        self._slots_lock.acquire()
        assert any(self._slots), "unexpected slot unavailability"
        slot = self._slots.index(True)
        self._slots[slot] = False
        self._slots_lock.release()
        return slot

    def release(self, slot):
        assert 0 <= slot < self._slots_nb, "unexpected slot number"
        assert not self._slots[slot], "unexpected slot release"
        self._slots[slot] = True
        threading._Semaphore.release(self)

class IntThread(threading.Thread):
    """
    Thread with interruptible join.
    """
    def join(self, timeout=None):
        # joining with a timeout, even with big value, can
        # be interrupted, with a Ctrl-C for example
        timeout = (
            sys.maxint if timeout is None else timeout)
        return threading.Thread.join(self, timeout)
