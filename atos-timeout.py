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
import subprocess, signal, errno, argparse

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
        self.pgroup = None
        self.old_pgroup = None
        self.proc = None

    class TimeoutException(Exception):
        """ Timeout exception used by the alarm to notify the monitor. """
        pass

    @staticmethod
    def timeout_handler(signum, frame):
        """ Handler for the alarm. """
        raise Monitor.TimeoutException()

    def send_signal(self, sig):
        """ Terminates the monitor process with the given signal.
        The signal is first sent to the monitored process in the case
        where its process group have been changed.
        Then the signal is sent to the whole process group initiated
        by the monitor.
        When possible the monitor ignores the signal such that it can
        exit with a predifined return code and message.
        The monitor resets its original pgroup also, in the case where
        it is not the group leader, it allows graceful termination even
        when signal 9 is sent.
        """
        if sig != 9:
            signal.signal(sig, signal.SIG_IGN)
        if self.pgroup != None:
            os.setpgid(0, self.old_pgroup)
        try:
            self.proc.send_signal(sig)
            if self.pgroup != None:
                os.killpg(self.pgroup, sig)
        except OSError, e:
            # Process or process group already killed
            pass

    def set_pgroup(self):
        """ Force process group or ignore if not possible.
        We also have to take control of opened tty as some
        shells such as dash do not manage correctly process
        groups created by setpgrp().
        If the timeout is called from dash (/bin/sh on Ubuntu)
        and one of the sub-process of timeout requests a tty
        read/write the full timeout process group is stopped
        while actually it should not as the process group should
        be scheduled to foreground by the shell.
        This works correctly with bash but we have to handle the
        dash case anyway.
        """

        def list_tty_filenos():
            filenos = []
            for f in os.listdir("/proc/self/fd"):
                if os.isatty(int(f)): filenos.append(int(f))
            return filenos

        # Force process group or ignore if not possible
        try:
            self.old_pgroup = os.getpgrp()
            os.setpgrp()
            self.pgroup = os.getpgrp()

            # Take control of opened ttys
            signal.signal(signal.SIGTTIN, signal.SIG_IGN)
            signal.signal(signal.SIGTTOU, signal.SIG_IGN)
            signal.signal(signal.SIGTSTP, signal.SIG_IGN)
            for f in list_tty_filenos():
                os.tcsetpgrp(f, self.pgroup)
            signal.signal(signal.SIGTTIN, signal.SIG_DFL)
            signal.signal(signal.SIGTTOU, signal.SIG_DFL)
            signal.signal(signal.SIGTSTP, signal.SIG_DFL)
        except OSError, e:
            print >>sys.stderr, "atos-timeout: warning: can't set " \
                "process group id: " + e.strerror

    def run(self):
        """ Runs the monitor and monitored process.
        This method returns the exit code to be passed
        to sys.exit.
        """

        self.set_pgroup()

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

        # Monitoring loop
        completed = False
        terminated = False
        killed = False
        while not completed:
            try:
                code = self.proc.wait()
                completed = True
            except self.TimeoutException:
                if self.args.debug and not terminated: print >>sys.stderr, \
                        "atos-timeout: command timeout: ", self.args.command[0]
                if self.args.signal == 9 or terminated:
                    if self.args.debug:
                        print >>sys.stderr, "atos-timeout: sending SIGKILL"
                    self.send_signal(9)
                    killed = True
                else:
                    if self.args.debug: print >>sys.stderr, "atos-timeout: " \
                            "sending signal " + str(self.args.signal)
                    signal.alarm(self.args.kill_after)
                    self.send_signal(self.args.signal)
                    terminated = True
            except KeyboardInterrupt:
                if self.args.debug: print >>sys.stderr, "atos-timeout: " \
                        "command interrupted: " + self.args.command[0]
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
