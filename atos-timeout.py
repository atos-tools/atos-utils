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
#
# Usage: get usage with atos-timeout -h
#

import sys, os
sys.path.insert(0, os.path.abspath(os.path.join(
            os.path.dirname(__file__), '..', 'lib', 'atos', 'python')))
from atos import globals
import subprocess, signal, errno, argparse, time

GRP_ENVVAR = "ATOS_TIMEOUT_GRP"

class ExitCodes:
    """ Exit codes used to feedback the parent process.
    This codes are aligned with the coreutils timeout implementation.
    Note that, as for coreutils, in case of termination with signal 9
    the TIMEOUT code can't be returned, the exit code will be (128+9).
    """
    TIMEDOUT = 124  # job timed out
    CANCELED = 125  # internal error
    CANNOT_INVOKE = 126  # error executing job
    ENOENT = 127  # couldn't find job to exec

class LocalArgumentParser(argparse.ArgumentParser):
    """
    Overrides ArgumentParser for exiting with the correct code on error.
    """
    def __init__(self, prog=None, description=None):
        super(LocalArgumentParser, self).__init__(
            prog=prog, description=description)

    def exit(self, status=0, message=None):
        """ Always exit with status CANCELED on error. """
        if status != 0:
            status = ExitCodes.CANCELED
        super(LocalArgumentParser, self).exit(status, message)


parser = LocalArgumentParser(
    prog="atos-timeout",
    description="ATOS timeout utility"
    ", stops the given COMMAND after DURATION seconds.")

parser.add_argument("-v", "--version",
                    help="output version string",
                    action="version",
                    version="atos-timeout version " + globals.VERSION)
parser.add_argument("-d", "--debug",
                     dest="debug",
                     help="debug mode",
                     action="store_true")
parser.add_argument("-s", "--signal",
                     type=int, default=15,
                     help="signal to be sent for terminating the COMMAND")
parser.add_argument("-k", "--kill-after",
                     type=int, default=10,
                     help="signal to be sent for terminating the COMMAND")
parser.add_argument("duration",
                    nargs=1,
                    type=int,
                    help="duration in seconds before the timeout")
parser.add_argument("command",
                    nargs=1,
                    help="command to be executed")
parser.add_argument("arguments",
                    nargs=argparse.REMAINDER,
                    help="command arguments")

class Monitor():
    """ Monitor class for interrupting a process after a given timeout. """
    def __init__(self, args):
        """ Constructor, arguments are stored into the args object. """
        self.args = args
        self.proc = None
        self.group = None

    class TimeoutException(Exception):
        """ Timeout exception used by the alarm to notify the monitor. """
        pass

    def timeout_grps(self, pid):
        """
        Get the timeout groups for the given process, it is available through
        the GRP_ENVVAR (see definition above) envvar of the process.
        Returns the list of timeout groups for the process or [].
        """
        try:
            with open("/proc/%d/environ" % pid) as f:
                env_vars = f.read()
        except IOError:
            # Can't read, not accessible
            return []
        env_list = env_vars.strip().split('\0')
        for env in env_list:
            index = env.find(GRP_ENVVAR + "=")
            if index == 0:
                return map(int, env[(len(GRP_ENVVAR) + 1):].split(':'))
        return []

    def process_list(self, sid):
        """
        Returns the list of processes in the given session id.
        """
        def filter_ps_pid(pid):
            return pid != ps_pid

        try:
            proc = subprocess.Popen(["ps", "-s", str(sid),
                                     "-o", "pid"],
                                    stdout=subprocess.PIPE)
        except OSError:
            return []
        output = proc.communicate()[0]
        if proc.returncode != 0:
            return []
        ps_pid = proc.pid
        return filter(filter_ps_pid,
                      map(int, [x.strip() for x in
                                output.strip().split("\n")[1:]]))

    def sub_processes(self):
        """
        Construct the full list of process in the monitor hierarchy.
        """
        def all_grp_processes(grp, process_list):
            """ Get all processes that match the given group. """
            def filter_grp(pid):
                return grp in self.timeout_grps(pid)
            return filter(filter_grp, process_list)

        processes = self.process_list(os.getsid(self.group))
        grp_processes = all_grp_processes(self.group, processes)
        return grp_processes

    @staticmethod
    def timeout_handler(signum, frame):
        """ Handler for the alarm. """
        raise Monitor.TimeoutException()

    @staticmethod
    def interrupt_handler(signum, frame):
        """ Handler for signals that require immediate exit. """
        print >>sys.stderr, \
            "atos-timeout: interrupted by signal %d" % signum
        sys.exit(128 + signum)

    def send_signal(self, sig):
        """
        Terminates the monitored processes with the given signal.
        All processes in the monitor hierarchy will receive the signal.
        In order to avoid race conditions when a process is created
        after the list of processes in the group is constructed, we
        iterate until no more processes in the group is found.
        Note that in the main monitor loop an alarm is setup in the
        case where the signal is not SIGKILL, thus in practice the
        loop will always be exited.
        """
        def filter_monitor(proc):
            return proc != self.group

        while True:
            to_be_killed = filter(filter_monitor, self.sub_processes())
            if not to_be_killed: break
            for proc in to_be_killed:
                try:
                    os.kill(proc, sig)
                    if self.args.debug:
                        print >>sys.stderr, "atos-timeout: killed " + \
                            str(proc)
                except OSError, e:
                    # Process already killed
                    pass
            time.sleep(1)

    def run(self):
        """
        Runs the monitor and monitored process.
        This method returns the exit code to be passed to sys.exit.
        """

        # Set the timeout group to the monitor pid
        self.group = os.getpid()
        grps = os.environ.get(GRP_ENVVAR, None)
        os.environ[GRP_ENVVAR] = (str(self.group) if not grps else
                                  ':'.join((str(self.group), grps)))

        # Launch monitored process
        try:
            self.proc = subprocess.Popen(
                self.args.command + self.args.arguments)
        except OSError, e:
            print >>sys.stderr, "atos-timeout: error: failed to run " \
                "command: " + self.args.command[0] + ": " + e.strerror
            if e.errno == errno.ENOENT:
                return ExitCodes.ENOENT
            else:
                return ExitCodes.CANNOT_INVOKE

        # Install timer through alarm
        signal.signal(signal.SIGALRM, self.timeout_handler)
        signal.alarm(self.args.duration[0])

        # Install handler for ^C
        signal.signal(signal.SIGINT, self.interrupt_handler)

        # Monitoring loop
        completed = False
        terminated = False
        killed = False
        while not completed:
            try:
                if killed:
                    self.send_signal(9)
                elif terminated:
                    signal.alarm(self.args.kill_after)
                    self.send_signal(self.args.signal)
                code = self.proc.wait()
                completed = True
            except self.TimeoutException:
                if self.args.debug and not terminated: print >>sys.stderr, \
                        "atos-timeout: command timeout: ", self.args.command[0]
                if self.args.signal == 9 or terminated:
                    if self.args.debug:
                        print >>sys.stderr, "atos-timeout: sending SIGKILL"
                    killed = True
                else:
                    if self.args.debug: print >>sys.stderr, "atos-timeout: " \
                            "sending signal " + str(self.args.signal)
                    terminated = True
        if killed:
            print >>sys.stderr, "Killed after timeout: " + \
                " ".join(self.args.command + self.args.arguments)
            return ExitCodes.TIMEDOUT
        elif terminated:
            print >>sys.stderr, "Terminated after timeout: " + \
                " ".join(self.args.command + self.args.arguments)
            return ExitCodes.TIMEDOUT
        return code

args = parser.parse_args()
sys.exit(Monitor(args).run())
