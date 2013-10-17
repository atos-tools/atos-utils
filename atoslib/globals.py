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
DEFAULT_BUILD_JOBS = None

def setup(**kwargs):
    global PREFIX, BINDIR, LIBDIR, SHAREDIR, MANDIR, DOCDIR, PYTHONDIR
    global DEFAULT_CONFIGURATION_PATH
    global DEFAULT_CCREGEXP, DEFAULT_LDREGEXP, DEFAULT_ARREGEXP
    global DEFAULT_SIZE_CMD, DEFAULT_TIME_CMD, DEFAULT_BUILD_JOBS

    def estimated_build_jobs():
        """ Estimates a reasonable number of build jobs. """
        try:
            # Map to the number of CPUs
            jobs = os.sysconf("SC_NPROCESSORS_ONLN")
        except ValueError:
            # Otherwise use a common value
            jobs = 4
        return jobs

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

    # Utilitary regexp fragments
    #   supported compiler drivers base names
    cc_bases = "(clang|gcc|g\+\+|cc|c\+\+)"
    #   supported ld linker base names
    ld_bases = "(ld|link)"
    #   supported archivers base names
    ar_bases = "(ar)"
    #   target names that may be direct prefix of base names
    cross_target_pfx = "(sh4|st40|arm|st200|stxp70)"
    #   otherwise generic optional prefixes, typically '.*-'
    generic_pfx = "(.*-)?"
    #   generic optional suffixes, typically '-.*'
    generic_sfx = "([-].*)?([\.].*)?"

    # Default compiler basename regexp
    # Either the bare cc basenames (ex: gcc) or
    # prefixed a cross target prefix (ex: armcc) or
    # prefixed by a generic prefix (ex: .*-gcc).
    # sufixed by a generic sufix (ex: gcc).
    DEFAULT_CCREGEXP = kwargs.get(
        'DEFAULT_CCREGEXP',
        "(%s)|(%s%s)|(%s%s%s)" % (cc_bases,
                                cross_target_pfx, cc_bases,
                                generic_pfx, cc_bases, generic_sfx))

    # Default linker basename regexp
    # This is for particular cases, we currently support invocation
    # of linker only through the compiler driver.
    # ARM RVCT is an exception where link is done with armlink.
    DEFAULT_LDREGEXP = kwargs.get(
        'DEFAULT_LDREGEXP',
        "(%s)|(%s%s)|(%s%s)" % (ld_bases,
                                cross_target_pfx, ld_bases,
                                generic_pfx, ld_bases))

    # Default archiver basename regexp
    # Same scheme as for CCREGEXP.
    DEFAULT_ARREGEXP = kwargs.get(
        'DEFAULT_ARREGEXP',
        "(%s)|(%s%s)|(%s%s)" % (ar_bases,
                                cross_target_pfx, ar_bases,
                                generic_pfx, ar_bases))

    # Default time/size commands
    DEFAULT_TIME_CMD = "time -p"
    DEFAULT_SIZE_CMD = "size"

    # Determine default build jobs
    DEFAULT_BUILD_JOBS = kwargs.get(
        'DEFAULT_BUILD_JOBS', estimated_build_jobs())

    # Setup Path to python libs
    sys.path.insert(0, PYTHONDIR)

setup()
