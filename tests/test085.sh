#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS flag_values exploration"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"



$ROOT/bin/atos-opt -r -a "-O3 --param inline-unit-growth=60 -finline-small-functions"

$ROOT/bin/atos generator --generator=gen_flag_values \
    --extra-arg=variant_id=OPT-O3--paraminline-unit-growth=60-finline-small-functions



$ROOT/bin/atos-opt -r -f -l -a "-O3 --param inline-unit-growth=60 --param max-inline-insns-recursive=600 --param max-inline-insns-single=1200 --param max-inline-recursive-depth-auto=4 --param max-inline-recursive-depth=10 --param partial-inlining-entry-probability=0"

$ROOT/bin/atos generator --generator=gen_flag_values \
    --extra-arg=variant_id=OPT-fprofile-use-O3--paraminline-unit-growth=60--parammax-inline-insns-recursive=600--parammax-inline-insns-single=1200--parammax-inline-recursive-depth-auto=4--parammax-inline-recursive-depth=10--parampartial-inlining-entry-probability=0-O3--paraminline-unit-growth=60--parammax-inline-insns-recursive=600--parammax-inline-insns-single=1200--parammax-inline-recursive-depth-auto=4--parammax-inline-recursive-depth=10--parampartial-inlining-entry-probability=0-flto



$ROOT/bin/atos-opt -r -l -a "-O3 --param inline-unit-growth=40 --param large-function-growth=200 --param large-stack-frame-growth=4000 --param large-stack-frame=250 --param large-unit-insns=34000 --param max-inline-insns-recursive=800 --param max-inline-recursive-depth-auto=4 --param max-inline-recursive-depth=8 --param min-inline-recursive-probability=95 --param partial-inlining-entry-probability=70 -findirect-inlining -finline-functions -fno-inline-functions-called-once -finline-small-functions -fno-partial-inlining"

$ROOT/bin/atos generator --generator=gen_flag_values \
    --extra-arg=variant_id=OPT-O3--paraminline-unit-growth=40--paramlarge-function-growth=200--paramlarge-stack-frame-growth=4000--paramlarge-stack-frame=250--paramlarge-unit-insns=34000--parammax-inline-insns-recursive=800--parammax-inline-recursive-depth-auto=4--parammax-inline-recursive-depth=8--parammin-inline-recursive-probability=95--parampartial-inlining-entry-probability=70-findirect-inlining-finline-functions-fno-inline-functions-called-once-finline-small-functions-fno-partial-inlining-flto



$ROOT/bin/atos-opt -r -l -a "-Os --param large-function-growth=400 --param large-function-insns=1500 --param max-inline-insns-recursive=700 --param max-inline-insns-single=1600 --param max-inline-recursive-depth-auto=12 --param partial-inlining-entry-probability=90 -fno-early-inlining -fno-inline-functions -finline-functions-called-once"

$ROOT/bin/atos generator --generator=gen_flag_values \
    --extra-arg=variant_id=OPT-Os--paramlarge-function-growth=400--paramlarge-function-insns=1500--parammax-inline-insns-recursive=700--parammax-inline-insns-single=1600--parammax-inline-recursive-depth-auto=12--parampartial-inlining-entry-probability=90-fno-early-inlining-fno-inline-functions-finline-functions-called-once-flto
