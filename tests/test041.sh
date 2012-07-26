#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS nb profile run"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" -n 2 \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -f -r -a -O2

[ `cat atos-configurations/logs/run-* | grep "Running variant OPT-fprofile-generate-O2-O2" | wc -l` -eq 1 ]
