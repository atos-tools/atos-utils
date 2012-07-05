#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS loop exploration"

$ROOT/bin/atos-init \
    -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c" \

$ROOT/bin/atos-explore-loop -q -M5 -S0 -Vbase,fdo

[ -d atos-configurations ]
[ `$ROOT/lib/atos/atos_lib.py query -q'variant:OPT-.*' | wc -l` -eq 10 ]
