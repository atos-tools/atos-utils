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
import subprocess, signal, argparse

parser = argparse.ArgumentParser(prog="atos-timeout",
                                 description="ATOS timeout utility, stops the given COMMAND after DURATION seconds.")

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

args = parser.parse_args()

if args.signal != 15 and args.signal != 9:
    print >>sys.stderr, "atos-timeout: warning: only signal 15 and 9 are supported, fallback to signal 15"
    args.signal = 15

class TimeoutException(Exception):
    pass

def timeout_handler(signum, frame):
    raise TimeoutException()

def send_signal(proc, sig):
    if sig == 9:
        proc.kill()
    else:
        proc.terminate()

try:
    proc = subprocess.Popen(args.command + args.arguments)
except OSError:
    print >>sys.stderr, "atos-timeout: error: cannot execute command: " + args.command[0]
    sys.exit(1)

signal.signal(signal.SIGALRM, timeout_handler)
signal.alarm(args.duration[0])

completed = False
terminated = False
killed = False
while not completed:
    try:
        code = proc.wait()
        completed = True
    except TimeoutException:
        if args.debug and not terminated: print >>sys.stderr, "atos-timeout: command timeout: " + args.command[0]
        if args.signal == 9 or terminated:
            if args.debug: print >>sys.stderr, "atos-timeout: sending SIGKILL"
            proc.kill()
            killed = True
        else:
            if args.debug: print >>sys.stderr, "atos-timeout: sending SIGTERM"
            signal.alarm(args.kill_after)
            proc.terminate()
            terminated = True
    except KeyboardInterrupt:
        if args.debug: print >>sys.stderr, "atos-timeout: command interrupted: " + args.command[0]
if killed:
    print >>sys.stderr, "Killed after timeout: " + args.command[0]
elif terminated:
    print >>sys.stderr, "Terminated after timeout: " + args.command[0]
sys.exit(code)
