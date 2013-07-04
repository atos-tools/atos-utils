#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS flags pruning"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

#
# -r "$SRCDIR/examples/sha1-c/run_qemu.sh" \

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"

# 
$ROOT/bin/atos-opt \
    -r -a "-O0 -O3 -fno-inline --param inline-unit-growth=60 -finline-small-functions"

#
$ROOT/bin/atos-explore-flags-pruning \
    --variant-id=OPT-O0-O3-fno-inline--paraminline-unit-growth=60-finline-small-functions \
    --tradeoff=5 --threshold=0.01 --update-reference

# REF + OPT-O0-O3.... + PREF + O0 + O3 + fno-inline + paraminline + finline-small
[ `$ROOT/bin/atos lib query | wc -l` -eq 8 ]


$ROOT/bin/atos-explore-flags-pruning \
    --threshold=-1