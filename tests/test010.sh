#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run -n option"

$ROOT/atos-audit gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
$ROOT/atos-raudit $ROOT/examples/sha1-c/run.sh
$ROOT/atos-deps -a
$ROOT/atos-run -r -n 3
[ `grep "REF: time: " atos-configurations/results.db | wc -l` -eq 3 ]

$ROOT/atos-explore -n 2
[ `grep "OPT-O3: time: " atos-configurations/results.db | wc -l` -eq 2 ]
[ `grep "^Running variant OPT-O3$" atos-configurations/logs/*.log | wc -l` -eq 2 ]
