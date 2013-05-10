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

import sys, os, signal

def check_python_version_():
    try:
        assert sys.hexversion >= 0x02060000
    except:  # pragma: no cover
        print >>sys.stderr, \
            'error: python version >= 2.6 is required by ATOS tools'
        sys.exit(1)

def handle_signal_(sig, sigframe):
    print
    sys.stdout.flush()
    print >>sys.stderr, "Interrupted by signal %d" % sig
    sys.stderr.flush()
    sys.exit(128 + sig)

# Fail early if python version is not supported
check_python_version_()

# Avoid KeyboardInterrupt backtrace in case of ^C
if not os.getenv("ATOS_DEBUG"): signal.signal(signal.SIGINT, handle_signal_)
