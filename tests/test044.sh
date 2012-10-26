#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS file-by-file exploration"


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
    -r "$SRCDIR/examples/sha1-c/run.sh"  -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"

$ROOT/bin/atos-opt -r -a -O2

$ROOT/bin/atos-opt -r -a -O2 -f


# verify that build-force mode is supported
$ROOT/bin/atos-build -f -a "-O2"


# verify that build-make mode is supported
$ROOT/bin/atos-build -a "-O2"


# file-by-file exploration based on existing configs
$ROOT/bin/atos-explore-acf -f OPT-O2 OPT-fprofile-use-O2-O2
# only one configuration generated (cold: Os, hot: O2)
[ -d atos-configurations/acf_csv_dir ]
[ `ls atos-configurations/acf_csv_dir | wc -l` -eq 1 ]
[ `cat atos-configurations/acf_csv_dir/* | wc -l` -eq 2 ]
cat > expected.csv <<EOF
sha.o,-Os
*,-O2
EOF
[ `diff expected.csv atos-configurations/acf_csv_dir/*.csv | wc -l` -eq 0 ]


# file-by-file exploration, cold options forced
$ROOT/bin/atos-explore-acf -f -Y "-O0"
[ `ls atos-configurations/acf_csv_dir | wc -l` -eq 2 ]


# file-by-file exploration based on flag list
cat > flags_list.txt <<EOF
-O3 -funroll-loops
-O2 -ffast-math
EOF
rm -f atos-configurations/acf_csv_dir/*
$ROOT/bin/atos-explore-acf -f -F ./flags_list.txt
#  (1 ref + 2 flags * 1 file) + best tradeoffs
ls atos-configurations/acf_csv_dir
[ `ls atos-configurations/acf_csv_dir | wc -l` -ge 3 ]

# same test with 2 hot files
rm -f atos-configurations/acf_csv_dir/*
$ROOT/bin/atos-explore-acf -f -x 100 -F ./flags_list.txt
#  (1 ref + 2 flags * 2 files) + best tradeoffs
[ `ls atos-configurations/acf_csv_dir | wc -l` -ge 5 ]

# file-by-file staged exploration
$ROOT/bin/atos-explore-acf -Y "" -x 100 -f -N 1 --optim-variants "base,fdo" --optim-levels "-Os,-O2,-O3"
