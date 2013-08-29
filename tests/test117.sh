#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS flags_pruning - acf file-by-file"

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

cat > ./fbf.csv <<EOF
sha1.o,-O3 -fno-inline-small-functions -fno-inline-functions-called-once
sha.o,-Os -fno-inline-small-functions -fno-inline-functions-called-once
*,-O2
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"

$ROOT/bin/atos-opt -r -a "-O2 --atos-optfile=$PWD/fbf.csv"

$ROOT/bin/atos-explore-flags-pruning \
    --variant-id=OPT-O2--atos-optfile=$PWD/fbf.csv \
    --tradeoff=5 --threshold=0.00 --update-reference
    
# REF + OPT-O2-optfile         -> 2
# + Pruning_REF + O2 + optfile -> 3
# + SHA1 * (1 ref + 3 opts)    -> 4
# +  SHA * (1 ref + 3 opts)    -> 4
# +  '*' * (1 ref + 1 opt)     -> 2
# + opt_file final flags       -> 1
$ROOT/bin/atos lib query
$ROOT/bin/atos lib query | wc -l 1>&2
# [ `$ROOT/bin/atos lib query | wc -l` -eq 16 ]

