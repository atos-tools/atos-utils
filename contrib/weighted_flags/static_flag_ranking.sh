#!/bin/bash

# Usage <path>/static_flag_ranking.sh <bench1> <bench2> ...
# Each directory <bench*> must contain a file atos-init.sh that will
# call "atos init -C $1 ...." (see file oneflag.py for more details)

# This script will evaluate the effect of individual flags at
# different optimization levels and variants, using the list of
# benchmarks provided on the command line

# It will then output a set of flags ranking that can be added in the
# *.cfg files for ATOS

# example
# cd /home/compwork/ferriere/ATOS/atos-ranking
# ../ranking.explorations/static_flag_ranking.sh atos-build/atos-utils/examples/bzip2 atos-build/atos-utils/examples/sha1 atos-build/atos-utils/examples/astar

CUR_DIR=`pwd`
SCRIPT_DIR=`dirname $0`
SCRIPT_DIR=`(cd $SCRIPT_DIR; pwd)`

ATOS_CONF="_oneflag_temp"
ATOS_RANK=${ATOS_CONF}.rank
ATOS_WARN=${ATOS_CONF}.warn

for bench in $*; do
    BENCH_DIR=`(cd $bench; pwd)`
    BENCH_NAME=`basename $BENCH_DIR`
    cd $BENCH_DIR
    $SCRIPT_DIR/oneflag.py -C $ATOS_CONF
    for rk in `ls $ATOS_CONF*.rank`; do
	mv $rk $CUR_DIR/${BENCH_NAME}_$rk
    done
    cd $CUR_DIR
done

rm -f ${ATOS_RANK}

for file in inline loop optim; do
    echo "flags.$file.cfg.in" >> ${ATOS_RANK}
    echo "~~~~~~~~~~~~~~~~~~~" >> ${ATOS_RANK}
    rm -f ${ATOS_WARN}
    for opt in Os O2 O3; do
	for fopt in "$opt" "$opt-f" "$opt-l" "$opt-f-l"; do
	    Wopt=`echo $fopt | sed -e "s/-//g"`
	    $SCRIPT_DIR/ranking.py W$Wopt $file *_${ATOS_CONF}-$fopt.rank >> ${ATOS_RANK} 2>> ${ATOS_WARN}
	done
    done
done

cat  ${ATOS_WARN} ${ATOS_RANK}
rm -f ${ATOS_WARN} ${ATOS_RANK}
