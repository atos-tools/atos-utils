#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit build.audit"

# Legacy audit of simple cc command
$ROOT/bin/atos-audit --legacy gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
[ -f atos-configurations/build.audit ]
[ -f atos-configurations/build.force ]
force=`cat atos-configurations/build.force`
[ "$force" = 0 ]
grep CC_DEPS atos-configurations/build.audit >/dev/null
grep sha.c atos-configurations/build.audit >/dev/null
grep sha1-c atos-configurations/build.audit >/dev/null

# Legacy audit of make command
cp -a $ROOT/share/atos/examples/sha1 .
cd sha1
make clean
$ROOT/bin/atos-audit --legacy make sha
grep CC_DEPS atos-configurations/build.audit >/dev/null
grep sha1.cpp atos-configurations/build.audit >/dev/null
grep sha atos-configurations/build.audit >/dev/null
cd ..

# Audit of simple cc command
$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
[ -d atos-configurations/build.stg ]
[ `wc -l <atos-configurations/build.stg/recipes` == 1 ]

# Audit of make command, there are 5 recipes for the sha build
cd sha1
$ROOT/bin/atos-audit make clean sha
[ -d atos-configurations/build.stg ]
[ `wc -l <atos-configurations/build.stg/recipes` == 5 ]
cd ..
