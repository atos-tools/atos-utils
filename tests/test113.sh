#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS acf cold options"

config_query() {
    $ROOT/bin/atos lib config -u -t -q $*
}

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > ./oprof.in <<EOF
vma              samples   %       symbol_name
0000000000400b93 353965337 52.2748 .SHA1ProcessMessageBlock
0000000000400a86 260243456 38.4336 SHA1Input
00000000004006e4 62914627  9.2914  main
0000000000400f6c 732       0.0001  SHA1PadMessage
0000000000401110 25        0.0000  __libc_csu_init
00000000004009c8 25        0.0000  SHA1Reset
0000000000400a3f 20        0.0000  SHA1Result
EOF


$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh"  \
    -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"


# Check if acf plugin is available for host compiler
if [ ! -f "`config_query '$.compilers[*].plugin_acf'`" ]; then
    skip "acf plugins not available for compiler"
fi

# Check if host compiler has plugin support 
if [ "`config_query '$.compilers[*].plugins_enabled'`" != "1" ]; then
    skip "plugins not supported by compiler"
fi

$ROOT/bin/atos-explore-acf \
    --optim-levels=-O2 --optim-variants=base --tradeoffs=5 -N3 --debug 2>&1 | tee LOG1

# check that exploration on hot func starts without cold options
[ `cat LOG1 | grep "gen_function_by_function: run" \
    | grep "[{('SHA1Input', None): '-O2'}]" \
    | wc -l` -ne 0 ]

$ROOT/bin/atos-explore-acf --file-by-file \
    --optim-levels=-O2 --optim-variants=base --tradeoffs=5 -N3 --debug 2>&1 | tee LOG2

# check that no base flags is forced by atos
[ `cat atos-configurations/acf_csv_dir/fbf-*.csv | grep "\*," | wc -l` -eq 0 ]




$ROOT/bin/atos-explore-acf \
    -Y "" -Z "" \
    --optim-levels=-O2 --optim-variants=base --tradeoffs=5 -N3 --debug 2>&1 | tee LOG3

$ROOT/bin/atos-explore-acf --file-by-file \
    -Y ""  \
    --optim-levels=-O2 --optim-variants=base --tradeoffs=5 -N3 --debug 2>&1 | tee LOG4
