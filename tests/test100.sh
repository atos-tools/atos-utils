#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS genetic exploration"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -C atos-config \
    -b "sh ./build.sh" \
    -r "$SRCDIR/examples/sha1-c/run.sh"

$ROOT/bin/atos-explore-genetic \
    -C atos-config \
    --optim-levels=-O2 --optim-variants=base \
    --cookie=expl_genetic \
    --nbiters=5 --generations=4 \
    --tradeoffs=5 --nbpoints=2 \
    --mutate-prob=0.3 --mutate-rate=0.3 \
    --mutate-remove-rate=0.1 --evolve-rate=0.3

# base: 2 (ref + O2)
# generation-1: 1 point * 5 iters
# generation-2: 2 points * 5 iters
# generation-3: 2 points * 5 iters
# generation-4: 2 points * 5 iters
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -eq 37 ]
