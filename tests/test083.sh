#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generators - function by function params"

config_query() {
    $ROOT/bin/atos lib config -u -t -q $*
}

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

cat > flags_list.txt <<EOF
-O3 --param large-function-growth=400 -funroll-loops
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"

# Check if acf plugin is available for host compiler
if [ ! -f "`config_query '$.compilers[*].plugin_acf'`" ]; then
    skip "acf plugins not available for compiler"
fi

# Check if host compiler has plugin support
if [ "`config_query '$.compilers[*].plugins_enabled'`" != "1" ]; then
    skip "plugins not supported by compiler"
fi

$ROOT/bin/atos-explore-acf --hot-th=50 -F ./flags_list.txt --optim-variants=base --optim-levels=-O0

[ `cat atos-configurations//acf_csv_dir/*.csv | grep param | grep large | grep 400 | wc -l` -ne 0 ]
