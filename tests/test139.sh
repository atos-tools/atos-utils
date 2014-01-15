#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS proot reloc exec"

cat > build.sh <<EOF
set -ex
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

mkdir DATA
mkdir DATA/ABCD
dd if=/dev/urandom bs=4K count=1K 2>/dev/null > DATA/random

cat > run.sh <<EOF
set -ex
./sha1-c DATA/r*
cat DATA/r* | wc -l
EOF

$ROOT/bin/atos-init \
    --build-script="sh ./build.sh" --run-script="sh ./run.sh" \
    --build-jobs=2 --run-jobs=2 --log-file=debug.txt

[ `cat debug.txt | grep FAILURE | wc -l` -eq 0 ]

$ROOT/bin/atos-explore \
    --optim-levels=-O2 --optim-variants=base --log-file=debug.txt

[ `cat debug.txt | grep FAILURE | wc -l` -eq 0 ]

$ROOT/bin/atos-explore \
    --optim-levels=-O2 --optim-variants=fdo --log-file=debug.txt

[ `find atos-configurations/profiles | grep gcda | wc -l` -ne 0 ]
