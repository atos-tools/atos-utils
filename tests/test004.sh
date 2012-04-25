#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps target/-l/-a"

$ROOT/atos-audit gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
$ROOT/atos-deps sha1-c
[ -f atos-configurations/targets ]
[ -f atos-configurations/build.mk ]
targets=`cat atos-configurations/targets`
[ "$targets" = $PWD/sha1-c ]
mv sha1-c sha1-c.ref
make -f atos-configurations/build.mk
cmp sha1-c sha1-c.ref

$ROOT/atos-deps -l
make -f atos-configurations/build.mk sha1-c
cmp sha1-c sha1-c.ref

cp -a $ROOT/examples/sha1 .
cd sha1
make clean
$ROOT/atos-audit make all
$ROOT/atos-deps -a
mv sha sha.ref
mv shacmp shacmp.ref
mv shatest shatest.ref
make -f atos-configurations/build.mk $PWD/sha
cmp sha sha.ref
make -f atos-configurations/build.mk $PWD/shacmp
cmp shacmp shacmp.ref
make -f atos-configurations/build.mk $PWD/shatest
cmp shatest shatest.ref
