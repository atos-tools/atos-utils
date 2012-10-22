#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS ACF plugin with perf execution"

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

# Check that 'perf' profiling tool is available on host machine
perf_remote=0
perf_ok=`which perf 2>&1 > /dev/null || echo 1`
if [ "$perf_ok" == "1" ]; then
    # When not interactive just skip, otherwise try to use perf on remote machine
    [ "$MAKELEVEL" == "" ] || skip "perf tool not available"
    REMOTE_MACHINE=gnx2025
    # Check that 'perf' profiling tool is available on gnx2025
    perf_ok=`ssh -q $REMOTE_MACHINE "which perf" 2>&1 > /dev/null || echo 1`
    if [ "$perf_ok" == "1" ]; then
	skip "perf profiling tool not available"
    fi
    perf_remote=1
fi

$ROOT/bin/atos-opt -r -a "-Os"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

nb_frontier=`$ROOT/bin/atos lib speedups -C atos-configurations -f | wc -l`

perf_out_script=perf-profile.sh
echo "#!/usr/bin/env bash" > $perf_out_script
if [ "$perf_remote" == "1" ]; then
    cur_path=`pwd`
    cur_dir=`basename $cur_path`
    REMOTE_TEMP_TEST=`ssh -q $REMOTE_MACHINE "mktemp -d $TMPDIR/atos-test.XXXXXX"`
    echo "Remote test directory on $REMOTE_MACHINE in: $REMOTE_TEMP_TEST"
    echo "scp -rq $cur_path $REMOTE_MACHINE:$REMOTE_TEMP_TEST" >> $perf_out_script
    echo "scp -q $SRCDIR/examples/sha1-c/run.sh $REMOTE_MACHINE:$REMOTE_TEMP_TEST/$cur_dir" >> $perf_out_script
    
    echo "ssh -q $REMOTE_MACHINE \"cd $REMOTE_TEMP_TEST/$cur_dir && chmod +x ./run.sh && perf record -f ./run.sh && perf report -v --show-nr-samples > oprof.out\" " >> $perf_out_script
    echo "scp -q $REMOTE_MACHINE:$REMOTE_TEMP_TEST/$cur_dir/oprof.out $cur_path" >> $perf_out_script
else
    echo "perf record -f $SRCDIR/examples/sha1-c/run.sh && perf report -v --show-nr-samples > oprof.out" >> $perf_out_script
fi

chmod +x $perf_out_script

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 -Y "-Os noinline cold"

[ -d atos-configurations ]

# REF + Os + O2 + O3
nb_played=`$ROOT/bin/atos lib query | wc -l`

# 2 hot functions for default treshold hot=70, cold=30
# -> only 3 new runs without list of flags to explore (base, ref)
[ "`expr $nb_played`" == "6" ]

echo "-O2 -finline-functions" > flags.txt
echo "-O3 -funroll-loops"     >> flags.txt

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 -Y "-Os noinline cold" -F flags.txt

nb_played=`$ROOT/bin/atos lib query | wc -l`

# 6 +  (base, ref) + (2 flag_list * [0,1,2] hot_functions)
[ "`expr $nb_played \>= 10`" == "1" ]

# try with perf ref point
$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 OPT-O2

$ROOT/bin/atos-opt -r -a "-O2" -f

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 OPT-fprofile-use-O2-O2

$ROOT/bin/atos-opt -r -a "-O2" -f -l

date
$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 OPT-fprofile-use-O2-O2-flto

date
if [ "$perf_remote" == "1" ]; then
    ssh -q $REMOTE_MACHINE "chmod -R +xw $REMOTE_TEMP_TEST; rm -rf $REMOTE_TEMP_TEST"
fi
