#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS profile -C option"

$ROOT/bin/atos-audit -C atos-configurations-1 gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit -C atos-configurations-1 $SRCDIR/examples/sha1-c/run.sh 2> /dev/null
$ROOT/bin/atos-deps -a -C atos-configurations-1
$ROOT/bin/atos-profile -C atos-configurations-1
[ `find ./atos-configurations-1 -name *.gcda | wc -l` -eq 2 ]

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit $SRCDIR/examples/sha1-c/run.sh 2> /dev/null
$ROOT/bin/atos-deps -a
$ROOT/bin/atos-profile
[ `find ./atos-configurations -name *.gcda | wc -l` -eq 2 ]

$ROOT/bin/atos-profile -C atos-configurations -p profile-2
[ `find ./profile-2 -name *.gcda | wc -l` -eq 2 ]
