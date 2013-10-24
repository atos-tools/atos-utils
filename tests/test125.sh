#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS weighted explorations"

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
    --nbiters=2 --generations=2 \
    --weight-class=WO2

# base: 2 (ref + O2)
# generation-1: 1 point * 5 iters
# generation-2: 2 points * 5 iters
# generation-3: 2 points * 5 iters
# generation-4: 2 points * 5 iters
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -ge 6 ]
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -le 10 ]
# 8 points expected if no failure

rm -rf atos-config

$ROOT/bin/atos-init \
    -C atos-config \
    -b "sh ./build.sh" \
    -r "$SRCDIR/examples/sha1-c/run.sh"

$ROOT/bin/atos-explore-random \
    -C atos-config \
    --optim-levels=-O2 --optim-variants=base \
    --cookie=expl_random \
    --nbiters=5 \
    --weight-class=WO2

# base: 2 (ref + O2)
# generation-1: 1 point * 5 iters
# generation-2: 2 points * 5 iters
# generation-3: 2 points * 5 iters
# generation-4: 2 points * 5 iters
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -ge 4 ]
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -le 8 ]
# 6 points expected if no failure

rm -rf atos-config

$ROOT/bin/atos-init \
    -C atos-config \
    -b "sh ./build.sh" \
    -r "$SRCDIR/examples/sha1-c/run.sh"

$ROOT/bin/atos-explore-staged \
    -C atos-config \
    --optim-levels=-O2 --optim-variants=base \
    --cookie=expl_staged \
    --nbiters=2 \
    --weight-class=WO2

# base: 2 (ref + O2)
# generation-1: 1 point * 5 iters
# generation-2: 2 points * 5 iters
# generation-3: 2 points * 5 iters
# generation-4: 2 points * 5 iters
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -ge 6 ]
[ `$ROOT/bin/atos lib query -C atos-config | wc -l` -le 15 ]
# 8 points expected if no failure
