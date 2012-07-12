#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS ACF plugin"

# Check if there is an ACF plugin for the host compiler version
acf_plugin="acf_plugin.so"
acf_plugin_path=""
libdir="$ROOT/lib/atos"

config_query() {
    $libdir/atos_lib.py config -u -t -q $*
}

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

gcc_version=`config_query '$.compilers[*].version'`

gcc_machine=`config_query '$.compilers[*].target'`

case "${gcc_machine}" in
    x86_64-*)
      machine_dir=x86_64
      ;;
    i386-* | i686-*)
      machine_dir=i386
      ;;
    arm-*)
      machine_dir=arm
      ;;
    sh-*)
      machine_dir=sh4
      ;;
    *)
      echo "error: host machine ${gcc_machine} not supported by acf plugin"
      exit 1
      ;;
esac

# for gcc version, only take into account Major/Minor numbers
if [ ! -f ${libdir}/plugins/gcc-${gcc_version}/${machine_dir}/${acf_plugin} ]; then
    # get short version limited to Major/Minor
    vers=`echo $gcc_version | sed 's/\([0-9]*\.[0-9]*\).*/\1/'`
    gcc_list=`\ls -d ${libdir}/plugins/gcc-${vers}* 2>/dev/null| sort -r`
    # Take more recent gcc version matching Major/Minor
    for gcc_el in ${gcc_list}; do
	if [ -f ${gcc_el}/${machine_dir}/${acf_plugin} ]; then
	    acf_plugin_path=${gcc_el}/${machine_dir}/${acf_plugin}
	    break;
	fi
    done
else
    acf_plugin_path=${libdir}/plugins/gcc-${gcc_version}/${machine_dir}/${acf_plugin}
fi

if [ "${acf_plugin_path}" == "" ]; then
    skip
fi

# Check if host compiler has plugin support 
if [ "`config_query '$.compilers[*].plugins_enabled'`" != "1" ]; then
    skip
fi

$ROOT/bin/atos-opt -r -a "-Os"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

nb_frontier=`$ROOT/lib/atos/atos_lib.py speedups -C atos-configurations -f | wc -l`

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

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 -Y "-Os noinline cold" 2>&1

[ -d atos-configurations ]

# REF + Os + O2 + O3 
nb_played=`$ROOT/lib/atos/atos_lib.py query | wc -l`

# 2 hot functions for default treshold hot=70, cold=30
# -> only 3 new runs without list of flags to explore (base, ref, best)
[ "`expr $nb_played`" == "7" ]

echo "-O2 -finline-functions" > flags.txt
echo "-O3 -funroll-loops"     >> flags.txt

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 -Y "-Os noinline cold" -F flags.txt 2>&1

nb_played=`$ROOT/lib/atos/atos_lib.py query | wc -l`
# 7 +  (base, ref, best) + (2 flag_list * 2 hot_functions)
[ "`expr $nb_played`" == "14" ]

# try with perf ref point
$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 OPT-O2 2>&1

$ROOT/bin/atos-opt -r -a "-O2" -f

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 OPT-fprofile-use-O2-O2 2>&1

$ROOT/bin/atos-opt -r -a "-O2" -f -l

$ROOT/bin/atos-explore-acf -p ./$oprof_out_script -x 70 OPT-fprofile-use-O2-O2-flto 2>&1


