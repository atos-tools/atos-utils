#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS cookie db"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"

$ROOT/bin/atos-opt -r -a -O2 --cookie=expl_first

$ROOT/bin/atos-explore-staged \
    --optim-levels=-O3 --optim-variants=base,fdo \
    --cookie=expl_first --nbiters=5

[ -f atos-configurations/cookies.db ]

