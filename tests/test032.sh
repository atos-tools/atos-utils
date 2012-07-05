#!/usr/bin/env bash
#
#
KEEPTEST=1
source `dirname $0`/common.sh

TEST_CASE="ATOS optim flags exploration"

$ROOT/bin/atos-init \
    -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c" \

$ROOT/bin/atos-explore-optim -q -S0 -M5 -Vbase,fdo

[ -d atos-configurations ]
[ `$ROOT/lib/atos/atos_lib.py query -q'variant:OPT-.*' | wc -l` -eq 10 ]
