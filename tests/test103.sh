#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS explore flag values generator"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"

# 2 runs (REF + OPT-O3--paraminline-unit-growth=60-finline-small-functions)
$ROOT/bin/atos-opt -r -a "-O3 --param inline-unit-growth=60 -finline-small-functions"

# 14 new runs: 1_O3 + 10_paraminline+REF_paraminline + 2_inline_small
$ROOT/bin/atos-explore-flag-values \
    --variant_id=OPT-O3--paraminline-unit-growth=60-finline-small-functions --tradeoffs=5
[ `$ROOT/bin/atos lib query | wc -l` -eq 16 ]

# 9 new runs: 2_O3 + 4_paraminline + 3_inline_small
$ROOT/bin/atos-explore-flag-values \
    --variant_id=OPT-O3--paraminline-unit-growth=60-finline-small-functions \
    --nbvalues=2 --try-removing --tradeoffs=5
[ `$ROOT/bin/atos lib query | wc -l` -eq 25 ]

# 8 new runs: 1_O3 + 5_paraminline + 2_inline_small
$ROOT/bin/atos-explore-flag-values \
    --variant_id=OPT-O3--paraminline-unit-growth=60-finline-small-functions \
    --extra-arg=nbvalues=4 --tradeoffs=5
[ `$ROOT/bin/atos lib query | wc -l` -eq 33 ]

# 5 new runs: 2_O3 + 2_paraminline + 2_inline_small
$ROOT/bin/atos-explore-flag-values \
    --variant_id=OPT-O3--paraminline-unit-growth=60-finline-small-functions \
    --nbvalues=0 --try-removing --tradeoffs=5  --quiet
[ `$ROOT/bin/atos lib query | wc -l` -eq 39 ]
