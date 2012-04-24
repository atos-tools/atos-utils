#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit -C option"

rm -rf atos-configurations
rm -rf atos-configurations-$TEST
rm -rf atos-configurations/$TEST

$ROOT/atos-audit gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
[ -f atos-configurations/build.sh ]

$ROOT/atos-audit -C atos-configurations-$TEST gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
[ -f atos-configurations-$TEST/build.sh ]

$ROOT/atos-audit -C atos-configurations/$TEST gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
[ -f atos-configurations/$TEST/build.sh ]
