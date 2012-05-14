#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS profile -C option"

$ROOT/atos-audit -C atos-configurations-1 gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
$ROOT/atos-raudit -C atos-configurations-1 $ROOT/examples/sha1-c/run.sh 2> /dev/null
$ROOT/atos-deps -a -C atos-configurations-1
$ROOT/atos-profile -C atos-configurations-1
[ `find ./atos-configurations-1 -name *.gcda | wc -l` -eq 2 ]

$ROOT/atos-audit gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
$ROOT/atos-raudit $ROOT/examples/sha1-c/run.sh 2> /dev/null
$ROOT/atos-deps -a
$ROOT/atos-profile
[ `find ./atos-configurations -name *.gcda | wc -l` -eq 2 ]

$ROOT/atos-profile -C atos-configurations -p profile-2
[ `find ./profile-2 -name *.gcda | wc -l` -eq 2 ]
