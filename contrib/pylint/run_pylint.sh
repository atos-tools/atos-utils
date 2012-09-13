#!/usr/bin/env bash
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
# Check of python scripts using the pylint tool
#
# pylint must be available in $PATH
#

set -e

[ `which pylint` ] || (
    echo "`basename $0`: error: pylint not fount in \$PATH"
    exit 1 )

dir=`cd \`dirname $0\`; pwd`
srcdir=`cd $dir/../.. && pwd`
pysources="$srcdir/*.py $srcdir/atos/*.py"

pylint --rcfile=$dir/pylint_rc $pysources 2>&1 | (
    grep -v -e "maximum recursion depth exceeded" || true )

symilar --ignore-comments $pysources || true

