#!/usr/bin/env bash
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
#
# Usage: get usage with update_version.sh -h
#
set -e
dir=`dirname $0`

usage() {
cat <<EOF

Usage: update_version.sh file

Update the content of file with version, unless version is unchanged

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

cleanup() {
    [ ! -f "$tmpfile" ] || rm -f "$tmpfile"
}
trap "cleanup; exit 3" TERM INT
trap "cleanup" EXIT
tmpfile=`mktemp /tmp/update.XXXXXX`
file="${1?}"
(cd "$dir" && ./get_version.sh) >"$tmpfile"
[ -f "$file" ] || cp "$tmpfile" "$file"
diff "$file" "$tmpfile" >/dev/null || cp "$tmpfile" "$file"
cat < "$file"
