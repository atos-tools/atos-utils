#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS gcc driver regexp"

ln -s `which gcc` gcc-4.7.real

cat > build.sh <<EOF
set -e
./gcc-4.7.real -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
./gcc-4.7.real -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
./gcc-4.7.real -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init -r "echo user 1" -b "bash ./build.sh"

