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

def check_python_version_():
    try:
        assert sys.hexversion >= 0x02060000
    except:
        print >>sys.stderr, \
            'error: python version >= 2.6 is required by ATOS tools'
        sys.exit(1)

def enable_coverage():
    coverage_enabled = (
        bool(os.getenv("ATOS_COVERAGE_DIR")) or
        bool(os.getenv("ATOS_COVERAGE")))

    if coverage_enabled:
        import coverage, atexit

        def coverage_stop():
            cov.stop()
            cov.save()
        coverage_file = ".coverage"
        if os.getenv("ATOS_COVERAGE_DIR"):
            coverage_dir = os.getenv("ATOS_COVERAGE_DIR")
            coverage_file = os.path.join(
                coverage_dir, ".coverage.%d" % (os.getpid()))
        cov = coverage.coverage(data_file=coverage_file)
        cov.start()
        atexit.register(coverage_stop)

check_python_version_()

enable_coverage()
