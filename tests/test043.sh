#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS toolkit base variants"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

$ROOT/lib/atos/python/atos/atos_toolkit.py \
    --seed=0 --max=1 --variants=base --gen-base OPT-O2 OPT-O3

[ `cat atos-configurations/results.db | grep " time: " | wc -l` -eq 5 ]