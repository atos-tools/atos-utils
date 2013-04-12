#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS heat graph"

# this test must only be run manually
[ "$MAKELEVEL" == "" ] || skip "interactive test"


cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -C atos-config \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"

$ROOT/bin/atos-explore-staged \
    -C atos-config \
    --optim-levels=-O2 --optim-variants=base \
    --cookie=expl_staged --nbiters=15 --tradeoff=5

# classic graph with highlighted stages
$ROOT/bin/atos-graph \
    -C atos-config \
    --tradeoff=5 --cookie=expl_staged -x4 &

# heat graph
$ROOT/bin/atos-graph \
    -C atos-config \
    --heat --tradeoff=5 --cookie=expl_staged



