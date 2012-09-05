#!/bin/sh
set -e
[ "$1" != "" ] || set -- ./bzip2
exec "$@" -cd output.bz2 >/dev/null

