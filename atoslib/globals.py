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
DEFAULT_TOOLS_CREGEXP = None
DEFAULT_DRIVER_CC_PYREGEXP = None
DEFAULT_DRIVER_AR_PYREGEXP = None

def setup(**kwargs):
    global PREFIX, BINDIR, LIBDIR, SHAREDIR, MANDIR, DOCDIR, PYTHONDIR
    global DEFAULT_CONFIGURATION_PATH, DEFAULT_TOOLS_CREGEXP, \
        DEFAULT_DRIVER_CC_PYREGEXP, DEFAULT_DRIVER_AR_PYREGEXP
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

    # Default tools regexp. This is a C regexp, not a python one.
    DEFAULT_TOOLS_CREGEXP = kwargs.get(
        'DEFAULT_TOOLS_CREGEXP',
        "-\?\(clang\|gcc\|g++\|cc\|armlink\|c++\|ar\)$")

    # Default compiler driver/linker python regexp.
    DEFAULT_DRIVER_CC_PYREGEXP = kwargs.get(
        'DEFAULT_DRIVER_CC_PYREGEXP',
        "(clang|gcc|g\+\+|cc|armlink|c\+\+)$")

    # Default archiver python regexp.
    DEFAULT_DRIVER_AR_PYREGEXP = kwargs.get(
        'DEFAULT_DRIVER_AR_PYREGEXP',
        "(ar)$")

    # Setup Path to python libs
    sys.path.insert(0, PYTHONDIR)

setup()
