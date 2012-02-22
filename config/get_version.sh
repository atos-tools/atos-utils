#!/bin/sh
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
# Usage: get usage with get_version.sh -h
#


set -e

usage() {
cat <<EOF

Usage: get_version.sh

Returns the version of this source tree.

If a git repository, returns a git identifier,
otherwise returns the current date.

EOF
}

while getopts h opt; do
    case $opt in
	h) usage; exit 0
	    ;;
	?) usage; exit 2
	    ;;
    esac
done
shift $((OPTIND - 1))

GIT=${GIT:-git}
date=`date +%Y%m%d%H%M%S`
version=`$GIT describe --tags --dirty --abbrev=8 --always 2>/dev/null || true`
[ -z $version ] && version=$date
echo $version

