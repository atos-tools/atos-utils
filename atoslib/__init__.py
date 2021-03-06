#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# ATOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
#

import sys, os, signal, atexit

def check_python_version_():
    try:
        assert sys.hexversion >= 0x02060000
    except:  # pragma: fatal
        print >>sys.stderr, \
            'error: python version >= 2.6 is required by ATOS tools'
        sys.exit(1)

def handle_signal_(sig, sigframe):
    print
    sys.stdout.flush()
    print >>sys.stderr, "Interrupted by signal %d" % sig
    sys.stderr.flush()
    # run registered exit funcs
    atexit._run_exitfuncs()  # pragma: uncovered
    # do not wait for threads termination
    os._exit(128 + sig)  # pragma: uncovered

# Fail early if python version is not supported
check_python_version_()

# Avoid KeyboardInterrupt backtrace in case of ^C
if not os.getenv("ATOS_DEBUG"): signal.signal(signal.SIGINT, handle_signal_)
