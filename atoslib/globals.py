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

VERSION = "@VERSION@"
PREFIX = None
BINDIR = None
LIBDIR = None
SHAREDIR = None
MANDIR = None
DOCDIR = None
PYTHONDIR = None
DEFAULT_CONFIGURATION_PATH = None
DEFAULT_CCREGEXP = None
DEFAULT_LDREGEXP = None
DEFAULT_ARREGEXP = None
DEFAULT_TIME_CMD = None
DEFAULT_SIZE_CMD = None

def setup(**kwargs):
    global PREFIX, BINDIR, LIBDIR, SHAREDIR, MANDIR, DOCDIR, PYTHONDIR
    global DEFAULT_CONFIGURATION_PATH
    global DEFAULT_CCREGEXP, DEFAULT_LDREGEXP, DEFAULT_ARREGEXP
    global DEFAULT_SIZE_CMD, DEFAULT_TIME_CMD

    PREFIX = kwargs.get('PREFIX', os.path.abspath(
            os.path.join(os.path.dirname(sys.argv[0]), '..')))
    BINDIR = kwargs.get('BINDIR', os.path.join(PREFIX, 'bin'))
    LIBDIR = kwargs.get('LIBDIR', os.path.join(PREFIX, 'lib', 'atos'))
    SHAREDIR = kwargs.get('SHAREDIR', os.path.join(PREFIX, 'share', 'atos'))
    MANDIR = kwargs.get('MANDIR', os.path.join(SHAREDIR, 'man'))
    DOCDIR = kwargs.get('DOCDIR', os.path.join(SHAREDIR, 'doc'))
    PYTHONDIR = kwargs.get('PYTHONDIR', os.path.join(LIBDIR, 'python'))

    # Default atos configuration directory.
    DEFAULT_CONFIGURATION_PATH =  \
        kwargs.get('DEFAULT_CONFIGURATION_PATH', "./atos-configurations")

    # Default compiler basename regexp
    DEFAULT_CCREGEXP = kwargs.get(
        'DEFAULT_CCREGEXP',
        ".*(clang|gcc|g\+\+|cc|c\+\+|stxp70cc|stxp70c\+\+)")

    # Default linker basename regexp
    DEFAULT_LDREGEXP = kwargs.get(
        'DEFAULT_LDREGEXP',
        "(armlink)")

    # Default archiver basename regexp
    DEFAULT_ARREGEXP = kwargs.get(
        'DEFAULT_ARREGEXP',
        "(.*ar)")

    # Default time/size commands
    DEFAULT_TIME_CMD = "time -p"
    DEFAULT_SIZE_CMD = "size"

    # Setup Path to python libs
    sys.path.insert(0, PYTHONDIR)

setup()
