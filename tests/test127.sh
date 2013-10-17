#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS gcc driver regexp"

ln -s `which gcc` gcc-4.7.real
ln -s gcc-4.7.real gcc

cat > build.sh <<EOF
set -e
\$CC -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
\$CC -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
\$CC -o sha1-c sha.o sha1.o
EOF

env CC=./gcc-4.7.real $ROOT/bin/atos-init -r "echo user 1" -b "bash ./build.sh"

env CC=./gcc $ROOT/bin/atos-init -r "echo user 1" -b "bash ./build.sh"

