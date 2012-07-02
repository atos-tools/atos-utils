#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS ACF plugin"

plugins_enabled()
{
     pycmd="import atos_lib;"
     pycmd="$pycmd cfg_file = \"atos-configurations/config.json\"; "
     pycmd="$pycmd cfg = atos_lib.json_config(cfg_file);"
     pycmd="$pycmd print int('plugins_enabled' in cfg._compiler_features())"
     python -c "$pycmd"
}


# Check if there is an ACF plugin for the host compiler version
acf_plugin="acf_plugin.so"
acf_plugin_path=""
libdir="$ROOT/lib/atos"

gcc_version=`gcc -dumpversion`
machine=`gcc -dumpmachine`

case "${machine}" in
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
    echo machine
      skip
      ;;
esac

if [ ! -f ${libdir}/plugins/gcc-${gcc_version}/${machine_dir}/${acf_plugin} ]; then
    # get short version limited to Major/Minor
    major=`echo $gcc_version | sed -e 's/^\([0-9]*\)\.\([0-9]*\).*/\1/g'`
    minor=`echo $gcc_version | sed -e 's/^\([0-9]*\)\.\([0-9]*\).*/\2/g'`
    vers=$major.$minor

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

$ROOT/bin/atos-init \
    -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c"

# Check if host compiler has plugin support 
export PYTHONPATH=$ROOT/lib/atos:$PYTHONPATH
plugins_ok=0
plugins_ok=`plugins_enabled`

if [ "$plugins_ok" == "0" ]; then
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

$ROOT/bin/atos-explore-acf -q -e ./sha1-c -p $oprof_out_script -x 70 -y 30 -Y "-Os noinline cold"

[ -d atos-configurations ]

# REF + Os + O2 + O3 
nb_played=`$ROOT/lib/atos/atos_lib.py query | wc -l`

# 2 hot functions for default treshold hot=70, cold=30
[ "`expr $nb_played`" == "12" ]
