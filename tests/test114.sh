#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS init output"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
g++ -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" | tee LOG

[ `cat LOG | grep "Compilers found" | wc -l` -eq 1 ]
[ `cat LOG | grep "fdo=on" | wc -l` -eq 2 ]


