#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS inline flags"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

[ -f atos-configurations/flags.inline.cfg ]

$ROOT/bin/atos-explore-inline -q -S0 -M5 -Vbase

[ `$ROOT/lib/atos/atos_lib.py query -q'variant:OPT-.*' | wc -l` -eq 5 ]

