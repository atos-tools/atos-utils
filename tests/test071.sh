#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS command errors"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

(
$ROOT/bin/atos explore -b 'sh ./build.sh' \
    -r "time ./src/proot -B perl -e 'system("/usr/bin/true") for (1..10000)" || true
) 2>log

[ `cat log | grep "Traceback (most recent call last)" | wc -l` -eq 0 ]
