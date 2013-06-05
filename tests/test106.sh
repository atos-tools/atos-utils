#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS oprof.out format"


cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > ./oprof.in <<EOF
vma              samples   %       app_name symbol_name
0000000000400b93 353965337 52.2748 sha1-c  SHA1ProcessMessageBlock
0000000000400a86 260243456 38.4336 sha1-c  SHA1Input
00000000004006e4 62914627  9.2914  sha1-c  main
0000000000400f6c 732       0.0001  sha1-c  SHA1PadMessage
0000000000401110 25        0.0000  sha1-c  __libc_csu_init
00000000004009c8 25        0.0000  sha1-c  SHA1Reset
0000000000400a3f 20        0.0000  sha1-c  SHA1Result
EOF


$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh"  \
    -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"

$ROOT/bin/atos-opt -r -a -O2

$ROOT/bin/atos-explore-acf -f OPT-O2 2>&1 | tee LOG

[ `cat LOG | grep "error: oprofile output format not supported" | wc -l` -eq 0 ]
