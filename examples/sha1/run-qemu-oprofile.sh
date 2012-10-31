#!/usr/bin/env bash
set -e
dir=`dirname $0`

[ "$1" != "" ] || set -- ./sha
exec env QEMU_PLUGIN=oprofile ./run.sh $dir/atos-qemu.sh "$@" 2>&1 | tee oprof.out

