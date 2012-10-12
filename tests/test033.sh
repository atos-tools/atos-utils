#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS play options"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

$ROOT/bin/atos-play -p

$ROOT/bin/atos-play -p -i sha1-c

$ROOT/bin/atos-play -n -f size 2>&1

[ `$ROOT/bin/atos-play -p -r | grep "ATOS: sha1-c: REF" | wc -l` -ne 0 ]

[ `$ROOT/bin/atos-play -p -l d82cd2 | grep "ATOS: sha1-c: REF" | wc -l` -ne 0 ]

