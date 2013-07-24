#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS staged_expl pruning"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"

$ROOT/bin/atos-explore-staged \
    --optim-levels=-O2 --optim-variants=base \
    --nbiters=3 --tradeoffs=15 --tradeoffs=5 --pruning 2>&1 | tee LOG

[ `cat LOG | grep "explore-flags-pruning: best variant" | wc -l` -ge 3 ]