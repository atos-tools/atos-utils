#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps target/-l/-a"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-deps sha1-c
[ -f atos-configurations/targets ]
[ -f atos-configurations/objects ]
[ -f atos-configurations/build.mk ]
targets=`cat atos-configurations/targets`
[ "$targets" = $PWD/sha1-c ]
objects=`cat atos-configurations/objects`
[ "$objects" = "" ] # no objects as it is a link command
mv sha1-c sha1-c.ref
make -f atos-configurations/build.mk
cmp sha1-c sha1-c.ref

$ROOT/bin/atos-deps -l
make -f atos-configurations/build.mk sha1-c
cmp sha1-c sha1-c.ref

cp -a $SRCDIR/examples/sha1 .
cd sha1
make clean
$ROOT/bin/atos-audit make all
$ROOT/bin/atos-deps -a
targets=`cat atos-configurations/targets`
[ "$targets" != "" ] # check that some targets was sen
objects=`cat atos-configurations/objects`
[ "$objects" != "" ] # check that some objects was sen
mv sha sha.ref
mv shacmp shacmp.ref
mv shatest shatest.ref
make -f atos-configurations/build.mk $PWD/sha
cmp sha sha.ref
make -f atos-configurations/build.mk $PWD/shacmp
cmp shacmp shacmp.ref
make -f atos-configurations/build.mk $PWD/shatest
cmp shatest shatest.ref
