#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit -f option"

rm -rf atos-configurations-$TEST

$ROOT/atos-audit -C atos-configurations-$TEST -f gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
mv sha1-c sha1-c.ref
[ -f atos-configurations-$TEST/build.sh ]
[ -f atos-configurations-$TEST/build.force ]
force=`cat atos-configurations-$TEST/build.force`
[ "$force" = 1 ]
atos-configurations-$TEST/build.sh
cmp sha1-c sha1-c.ref
