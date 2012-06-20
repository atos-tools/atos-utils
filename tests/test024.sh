#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS graph tradeoff"

# this test must only be run manually
[ "$MAKELEVEL" == "" ] || skip

rnd()
{
    MIN=90; MAX=110;
    echo `expr $RANDOM % \( $MAX - $MIN \) + $MIN`
}

graph()
{
    CFGNAME="CFG-$RANDOM"
    NBPOINTS=25
    $ROOT/lib/atos/atos_lib.py create_db -C $CFGNAME
    $ROOT/lib/atos/atos_lib.py add_result -C $CFGNAME \
	-r "target:X,variant:REF,time:100,size:100"
    N=0
    while [ $N -lt $NBPOINTS ]; do
	$ROOT/lib/atos/atos_lib.py add_result -C $CFGNAME \
	    -r "target:X,variant:VN$N,time:`rnd`,size:`rnd`"
	N=`expr $N + 1`
    done
    echo $CFGNAME
}

echo "Running test in: $TMPTEST"

while [ 1 -eq 1 ]; do
    $ROOT/bin/atos-graph -C `graph` \
	--tradeoff=4 --tradeoff=1 --tradeoff=0.25
done

