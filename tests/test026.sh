#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS opt no-replay"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-Os" --reuse 2>&1 | tee LOG

$ROOT/bin/atos-opt -r -a "-Os" --reuse 2>&1 | tee -a LOG

$ROOT/bin/atos-opt -r -a "-O2" --reuse 2>&1 | tee -a LOG

$ROOT/bin/atos-opt -r -a "-O2" --reuse 2>&1 | tee -a LOG

nb_played=`$ROOT/bin/atos lib query | wc -l`

[ "$nb_played" == "5" ] # REF + Os + Os + O2 + O2

[ `cat LOG | grep "Reusing results" | wc -l` -eq 2 ]