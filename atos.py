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
# Usage: get usage with atos -h
#

import sys, os
sys.path.insert(0, os.path.abspath(os.path.join(
            os.path.dirname(sys.argv[0]), '..', 'lib', 'atos', 'python')))
from atoslib import arguments
from atoslib import utils
from atoslib import logger
from atoslib import process
from atoslib import multiprocess
from atoslib import progress

base = os.path.basename(sys.argv[0])
subcmd = base[5:]
if subcmd: sys.argv.insert(1, subcmd)

args = arguments.parser("atos").parse_args()
logger.setup(vars(args))
process.setup(vars(args))
multiprocess.setup(vars(args))
progress.setup(vars(args))
utils.execute("atos", args)
