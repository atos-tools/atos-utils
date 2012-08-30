#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS lib frontier query"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/lib/atos/python/atos/atos_lib.py speedups -f \
    | $ROOT/lib/atos/python/atos/atos_lib.py query -C- -t -q'$[*].variant' \
    > frontier.variant.txt

# frontier can be the REF point
[ `cat frontier.variant.txt | wc -l` -ne 0 ]
