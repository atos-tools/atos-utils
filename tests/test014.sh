#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS inline exploration"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \

$ROOT/bin/atos-explore-inline -S0 -M5 -Vbase,fdo
    
[ -d atos-configurations ]
[ `$ROOT/bin/atos lib query -q'variant:OPT-.*' | wc -l` -eq 10 ]

