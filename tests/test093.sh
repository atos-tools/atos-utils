#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS progress"

[ "$MAKELEVEL" == "" ] || skip "interactive test"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > ./oprof.in <<EOF
vma              samples   %       linenr_info                    image_name symbol_name
0000000000400b93 353965337 52.2748 (no localization information)  sha1-c  SHA1ProcessMessageBlock
0000000000400a86 260243456 38.4336 (no localization information)  sha1-c  SHA1Input
00000000004006e4 62914627  9.2914  (no localization information)  sha1-c  main
0000000000400f6c 732       0.0001  (no localization information)  sha1-c  SHA1PadMessage
0000000000401110 25        0.0000  (no localization information)  sha1-c  __libc_csu_init
00000000004009c8 25        0.0000  (no localization information)  sha1-c  SHA1Reset
0000000000400a3f 20        0.0000  (no localization information)  sha1-c  SHA1Result
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"

echo "#"
echo "#"
echo "# EXPLORE progress"
echo "#"
echo "#"

$ROOT/bin/atos-explore \
    --optim-levels=-O2,-O3 --optim-variants=base,fdo


echo "#"
echo "#"
echo "# EXPLORE-ACF progress"
echo "#"
echo "#"

$ROOT/bin/atos-explore-acf \
    --optim-variants=base,fdo --optim-levels=-O2,-O3 --file-by-file \
    --per-func-nbiters=1 --tradeoffs=10 --hot-th=95

echo "#"
echo "#"
echo "# EXPLORE-INLINE progress (only exploration)"
echo "#"
echo "#"

$ROOT/bin/atos-explore-inline \
    --optim-levels=-O2,-O3 --optim-variants=base --nbiters=3 | tee log

echo "#"
echo "#"
echo "# EXPLORE progress (quiet)"
echo "#"
echo "#"

$ROOT/bin/atos-explore \
    --optim-levels=-O2,-O3 --optim-variants=base --quiet


echo "#"
echo "#"
echo "# EXPLORE staged"
echo "#"
echo "#"

$ROOT/bin/atos-explore-staged \
    --optim-levels=-O2 --optim-variants=base,fdo --nbiters=5
