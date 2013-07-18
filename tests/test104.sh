#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS incompatible LTO options"

[ `gcc -v --help 2>&1 | grep "\-flto" | wc -l` != 0 ] || skip "non lto compiler"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o -fno-strict-aliasing
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o -fstrict-aliasing
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"


export ATOS_DEBUG=1

$ROOT/bin/atos-opt -r -a "-O2 -fno-strict-aliasing" 2>&1 | tee log1

[ `cat log1 | grep command | grep gcc | grep fstrict-aliasing | grep no-strict-aliasing | wc -l` -eq 0 ]


$ROOT/bin/atos-opt -r -l -a -O2 2>&1 | tee log2

[ `cat log2 | grep command | grep gcc | grep fstrict-aliasing | grep no-strict-aliasing | wc -l` -eq 0 ]
