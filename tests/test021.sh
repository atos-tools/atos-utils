#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS inline variants"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-Os"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

nb_frontier=`$ROOT/bin/atos lib speedups -C atos-configurations -f | wc -l`

$ROOT/bin/atos-explore-inline -S0 -M1 frontier OPT-O2

[ -d atos-configurations ]

# REF + Os + O2 + O3 + inl(front) + inl(O2)
nb_played=`$ROOT/bin/atos lib query | wc -l`

[ "`expr $nb_frontier + 5`" == "$nb_played" ]

