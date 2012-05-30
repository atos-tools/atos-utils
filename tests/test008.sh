#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS explore -C option"

$ROOT/bin/atos-explore \
    -C atos-configurations-1 -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c"
    
[ ! -d atos-configurations ]
[ `cat ./atos-configurations-1/results.db | grep "time: " | grep -v FAILURE | wc -l` -ne 0 ]
