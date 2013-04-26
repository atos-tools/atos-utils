#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS genetic crossover"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" -C atos-cfg

$ROOT/bin/atos generator \
    -C atos-cfg \
    --generator=gen_chained \
    --optim-levels=-O3 --optim-variants=base \
    --extra-arg=generator1=gen_explore \
    --extra-arg=generator2=gen_explore_inline \
    --extra-arg=generator3=gen_genetic_crossover,aggregate:1 \
    --extra-arg=generator4=gen_genetic_crossover,aggregate:1 \
    --extra-arg=nbpoints=3 --nbiters=10 --tradeoffs=5
