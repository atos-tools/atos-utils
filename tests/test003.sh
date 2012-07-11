#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit build.audit"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
[ -f atos-configurations/build.audit ]
[ -f atos-configurations/build.force ]
force=`cat atos-configurations/build.force`
[ "$force" = 0 ]
grep CC_DEPS atos-configurations/build.audit >/dev/null
grep sha.c atos-configurations/build.audit >/dev/null
grep sha1-c atos-configurations/build.audit >/dev/null

cp -a $SRCDIR/examples/sha1 .
cd sha1
make clean
$ROOT/bin/atos-audit make sha
grep CC_DEPS atos-configurations/build.audit >/dev/null
grep sha1.cpp atos-configurations/build.audit >/dev/null
grep sha atos-configurations/build.audit >/dev/null
