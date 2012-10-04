#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS replay frontier"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O0"
$ROOT/bin/atos-opt -r -a "-O1"
$ROOT/bin/atos-opt -r -a "-O2"
$ROOT/bin/atos-opt -r -a "-O3"

$ROOT/bin/atos-replay -C atos-configurations -R atos-config-replay -r "$SRCDIR/examples/sha1-c/run.sh"

nb_replayed=`$ROOT/bin/atos lib query -C atos-config-replay | grep -v REF | wc -l`
nb_frontier=`$ROOT/bin/atos lib speedups -C atos-configurations -f | grep -v REF | wc -l`

[ $nb_replayed -eq $nb_frontier ]
