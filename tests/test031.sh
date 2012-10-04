#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS ACF plugin"

# Check if there is an ACF plugin for the host compiler version
acf_plugin="acf_plugin.so"
acf_plugin_path=""

config_query() {
    $ROOT/bin/atos lib config -u -t -q $*
}

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"


# Check if acf plugin is available for host compiler
if [ ! -f "`config_query '$.compilers[*].plugin_acf'`" ]; then
    skip "acf plugins not available for compiler"
fi

# Check if host compiler has plugin support 
if [ "`config_query '$.compilers[*].plugins_enabled'`" != "1" ]; then
    skip "plugins not supported by compiler"
fi

$ROOT/bin/atos-opt -r -a "-Os"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

nb_frontier=`$ROOT/bin/atos lib speedups -C atos-configurations -f | wc -l`

oprof_out_script=oprofile.sh
echo "#!/usr/bin/env bash" > $oprof_out_script
echo "echo vma     samples   %   image_name   symbol_name > oprof.out" >> $oprof_out_script
echo "echo 0400d14 813586 40.6763  sha1-c SHA1ProcessMessageBlock >> oprof.out" >> $oprof_out_script
echo "echo 0401105  393734 19.6867  sha1-c SHA1PadMessage >> oprof.out" >> $oprof_out_script
echo "echo 0400c02  357592 17.8796  sha1-c SHA1Input >> oprof.out" >> $oprof_out_script
echo "echo 0400b44  320220 16.0011  sha1-c SHA1Reset >> oprof.out" >> $oprof_out_script
echo "echo 0400bbb   84956  4.2478  sha1-c SHA1Result >> oprof.out" >> $oprof_out_script
echo "echo 0400b20     894  0.0447  sha1-c main >> oprof.out" >> $oprof_out_script

chmod +x $oprof_out_script

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 -Y "-Os noinline cold"

[ -d atos-configurations ]

# REF + Os + O2 + O3 
nb_played=`$ROOT/bin/atos lib query | wc -l`

# 2 hot functions for default treshold hot=70, cold=30
# -> only 3 new runs without list of flags to explore (base, ref, best)
[ "`expr $nb_played`" == "7" ]

echo "-O2 -finline-functions" > flags.txt
echo "-O3 -funroll-loops"     >> flags.txt

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 -Y "-Os noinline cold" -F flags.txt

nb_played=`$ROOT/bin/atos lib query | wc -l`
# 7 +  (base, ref, best) + (2 flag_list * 2 hot_functions)
[ "`expr $nb_played`" == "14" ]

# try with perf ref point
$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 OPT-O2

$ROOT/bin/atos-opt -r -a "-O2" -f

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 OPT-fprofile-use-O2-O2

$ROOT/bin/atos-opt -r -a "-O2" -f -l

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 OPT-fprofile-use-O2-O2-flto


