#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS graph cookies"

# this test must only be run manually
[ "$MAKELEVEL" == "" ] || skip "interactive test"

rnd()
{
    MIN=$1; MAX=$2;
    echo `expr $RANDOM % \( $MAX - $MIN \) + $MIN`
}

graph()
{
    CFGNAME="CFG-$RANDOM"
    NBPOINTS=50
    $ROOT/bin/atos lib create_db -C $CFGNAME
    $ROOT/bin/atos lib add_result -C $CFGNAME \
	-r "target:X,variant:REF,time:100,size:100,cookies:cookie-ref"
    N=0
    while [ $N -lt $NBPOINTS ]; do
	cookie="cookie-`rnd 0 2`"
	$ROOT/bin/atos lib add_result -C $CFGNAME \
	    -r "target:X,variant:VN$N,time:`rnd 90 110`,size:`rnd 90 110`,cookies:$cookie"
	N=`expr $N + 1`
    done
    echo $CFGNAME
}

echo "Running test in: $TMPTEST"

# should show about 20/30 points
while [ 1 -eq 1 ]; do
    $ROOT/bin/atos-graph -C `graph` \
	--tradeoff=4 --tradeoff=1 --tradeoff=0.25 --cookie=cookie-0 --cookie=cookie-ref
done

