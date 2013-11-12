#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS multiple compilers"

cat > build.sh <<EOF
set -e
\$CC -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
\$CC -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
\$LD -o sha1-c sha.o sha1.o
EOF

! which gcc-4.1
[ $? -ne 0 ] || skip "gcc-4.1 not found"

! which gcc-4.4
[ $? -ne 0 ] || skip "gcc-4.4 not found"

#
# gcc/g++ of same version are allowed 
#

! $ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" -b "env CC=gcc-4.4 LD=g++-4.4 sh ./build.sh"
[ $? -eq 1 ]

#
# multiple gcc/g++ versions are not allowed 
#

! $ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" -b "env CC=gcc-4.1 LD=gcc-4.4 sh ./build.sh"
[ $? -eq 0 ]

