#!/usr/bin/env bash
set -e
dir=`dirname $0`

[ "$1" != "" ] || set -- ./bzip2
exec ./run.sh $dir/atos-qemu.sh "$@"
