#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit build.audit"

$ROOT/atos-audit gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
[ -f atos-configurations/build.audit ]
[ -f atos-configurations/build.force ]
force=`cat atos-configurations/build.force`
[ "$force" = 0 ]
grep CC_DEPS atos-configurations/build.audit >/dev/null
grep sha.c atos-configurations/build.audit >/dev/null
grep sha1-c atos-configurations/build.audit >/dev/null

cp -a $ROOT/examples/sha1 .
cd sha1
make clean
$ROOT/atos-audit make sha
grep CC_DEPS atos-configurations/build.audit >/dev/null
grep sha1.cpp atos-configurations/build.audit >/dev/null
grep sha atos-configurations/build.audit >/dev/null
