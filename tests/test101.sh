#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS acf genetic exploration"

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
    -b "sh ./build.sh" \
    -p "/bin/cp oprof.in oprof.out"

# func-by-func genetic exploration
$ROOT/bin/atos-explore-acf \
    --hot-th=50 --tradeoffs=5.0 --optim-variants=base --optim-levels=-O2 \
    --genetic --per-func-nbiters=1 --log-file=log1
[ `grep gen_genetic_deps log1 | wc -l` -ne 0 ]

# file-by-file genetic exploration
$ROOT/bin/atos-explore-acf \
    --hot-th=50 --tradeoffs=5.0 --optim-variants=base --optim-levels=-O2 \
    --file-by-file \
    --genetic --per-func-nbiters=1 --log-file=log2
[ `grep gen_genetic_deps log2 | wc -l` -ne 0 ]

# file-by-file random exploration
$ROOT/bin/atos-explore-acf \
    --hot-th=50 --tradeoffs=5.0 --optim-variants=base --optim-levels=-O2 \
    --random --per-func-nbiters=1 --log-file=log3
[ `grep gen_rnd_uniform_deps log3 | wc -l` -ne 0 ]

$ROOT/bin/atos-explore-acf \
    --hot-th=50 --tradeoffs=5.0 --optim-variants=base --optim-levels=-O2 \
    --file-by-file \
    --random --per-func-nbiters=1 --log-file=log4
[ `grep gen_rnd_uniform_deps log4 | wc -l` -ne 0 ]
