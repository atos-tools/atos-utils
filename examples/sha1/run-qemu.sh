#!/usr/bin/env bash
set -e
dir=`dirname $0`

[ "$1" != "" ] || set -- ./sha
exec ./run.sh $dir/atos-qemu.sh "$@"
