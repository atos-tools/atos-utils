#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS opt no-replay"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-Os" --reuse

$ROOT/bin/atos-opt -r -a "-Os" --reuse

$ROOT/bin/atos-opt -r -a "-O2" --reuse

$ROOT/bin/atos-opt -r -a "-O2" --reuse

nb_played=`$ROOT/bin/atos lib query | wc -l`

[ "$nb_played" == "3" ] # REF + Os + O2
