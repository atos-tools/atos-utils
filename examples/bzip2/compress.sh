#!/usr/bin/env bash
set -e
[ "$1" != "" ] || set -- ./bzip2
dd if=/dev/urandom bs=4K count=100 2>/dev/null | "$@" -c >output.bz2
exit ${PIPESTATUS[0]}

