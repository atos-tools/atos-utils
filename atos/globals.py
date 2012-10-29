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

# This file is installed in PREFIX/lib/atos/python/atos/
PREFIX = os.path.abspath(
    os.path.join(os.path.dirname(__file__), '..', '..', '..', '..'))
BINDIR = os.path.join(PREFIX, 'bin')
LIBDIR = os.path.join(PREFIX, 'lib', 'atos')
SHAREDIR = os.path.join(PREFIX, 'share', 'atos')
MANDIR = os.path.join(SHAREDIR, 'man')
DOCDIR = os.path.join(SHAREDIR, 'doc')
PYTHONDIR = os.path.join(LIBDIR, 'python')
sys.path.insert(0, PYTHONDIR)

# Default atos configuration directory.
DEFAULT_CONFIGURATION_PATH = "./atos-configurations"

# Default tools regexp. This is a C regexp, not a python one.
DEFAULT_TOOLS_CREGEXP = "-\?\(clang\|gcc\|g++\|cc\|armlink\|c++\|ar\)$"

# Default compiler driver/linker python regexp.
DEFAULT_DRIVER_CC_PYREGEXP = "(clang|gcc|g\+\+|cc|armlink|c\+\+)$"

# Default archiver python regexp.
DEFAULT_DRIVER_AR_PYREGEXP = "(ar)$"
