#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS graph correlation"

# this test must only be run manually
[ "$MAKELEVEL" == "" ] || skip

rnd()
{
    MIN=$1; MAX=$2;
    echo `expr $RANDOM % \( $MAX - $MIN \) + $MIN`
}

graph()
{
    CFGNAME="CFG-$RANDOM"
    NBPOINTS=20

    $ROOT/lib/atos/python/atos/atos_lib.py create_db -C $CFGNAME
    $ROOT/lib/atos/python/atos/atos_lib.py add_result -C $CFGNAME \
	-r "target:X,variant:REF,time:100,size:100"

    $ROOT/lib/atos/python/atos/atos_lib.py create_db -C ${CFGNAME}-1
    $ROOT/lib/atos/python/atos/atos_lib.py add_result -C ${CFGNAME}-1 \
	-r "target:X,variant:REF,time:100,size:100"

    $ROOT/lib/atos/python/atos/atos_lib.py create_db -C ${CFGNAME}-2
    $ROOT/lib/atos/python/atos/atos_lib.py add_result -C ${CFGNAME}-2 \
	-r "target:X,variant:REF,time:100,size:100"

    N=0
    while [ $N -lt $NBPOINTS ]; do
	TIME=`rnd 90 110`
	SIZE=`rnd 90 110`
	$ROOT/lib/atos/python/atos/atos_lib.py add_result -C $CFGNAME \
	    -r "target:X,variant:VN$N,time:$TIME,size:$SIZE"

	TIME1=`expr $TIME + \`rnd -2 2\``
	SIZE1=`expr $SIZE + \`rnd -2 2\``
	$ROOT/lib/atos/python/atos/atos_lib.py add_result -C ${CFGNAME}-1 \
	    -r "target:X,variant:VN$N,time:$TIME1,size:$SIZE1"

	TIME2=`expr $TIME + \`rnd -5 5\``
	SIZE2=`expr $SIZE + \`rnd -5 5\``
	$ROOT/lib/atos/python/atos/atos_lib.py add_result -C ${CFGNAME}-2 \
	    -r "target:X,variant:VN$N,time:$TIME2,size:$SIZE2"

	N=`expr $N + 1`
    done
    echo $CFGNAME
}

echo "Running test in: $TMPTEST"

while [ 1 -eq 1 ]; do
    GRAPH=`graph`
    $ROOT/bin/atos-graph -C $GRAPH -D ${GRAPH}-1 -D ${GRAPH}-2 \
	--correl -l REF,V4,V10
done

