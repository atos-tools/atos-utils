#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS play tradeoffs"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O0"

$ROOT/bin/atos-opt -r -a "-O1"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

$ROOT/bin/atos-opt -r -a "-Os"

[ `$ROOT/bin/atos-play -P -s 5 -s 0.2 -N 5 | uniq | wc -l` -eq 4 ]
