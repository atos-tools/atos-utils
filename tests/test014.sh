#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS inline exploration"

# test temporarily skipped
# until atos-inline can determine compiler version
skip

$ROOT/bin/atos-inline \
    -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c" \
    --max 5 --variants=base 2>&1
    
[ -d atos-configurations ]
[ `cat ./atos-configurations/results.db | grep "time: " | wc -l` -eq 6 ]

