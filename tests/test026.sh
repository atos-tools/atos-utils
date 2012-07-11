#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS opt no-replay"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-Os" -k

$ROOT/bin/atos-opt -r -a "-Os" -k

$ROOT/bin/atos-opt -r -a "-O2" -k

$ROOT/bin/atos-opt -r -a "-O2" -k

nb_played=`$ROOT/lib/atos/atos_lib.py query | wc -l`

[ "$nb_played" == "3" ] # REF + Os + O2
