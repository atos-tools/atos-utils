#!/usr/bin/env bash
set -e
[ "$1" != "" ] || set -- ./sha
dd if=/dev/urandom bs=4K count=1K 2>/dev/null | "$@"
exit ${PIPESTATUS[0]}


