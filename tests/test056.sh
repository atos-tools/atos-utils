#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS debug mode"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"


export ATOS_DEBUG_FILE=./debug-1.log

$ROOT/bin/atos-opt -r -a "-O2" 2>&1 | tee run-1.log

[ `cat ./debug-1.log | grep DEBUG | wc -l` -ne 0 ]

[ `cat ./run-1.log | grep DEBUG | wc -l` -eq 0 ]


export ATOS_DEBUG_FILE=./debug-2.log

$ROOT/bin/atos-opt --quiet -r -a "-O2" 2>&1 | tee run-2.log

[ `cat ./debug-2.log | grep DEBUG | wc -l` -ne 0 ]

[ `cat ./run-2.log | wc -l` -eq 0 ]


$ROOT/bin/atos-init -f --quiet 2>&1 | tee error.log

[ `cat ./error.log | wc -l` -ne 0 ]
