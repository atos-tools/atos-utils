#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps target"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1++-c sha.o sha1.o
EOF

$ROOT/bin/atos-init -r "echo user 1" -b "sh ./build.sh"
