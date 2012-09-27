#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS dryrun mode"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

(
    cp -fr atos-configurations atos-configurations-init

    $ROOT/bin/atos-build --dryrun -a "-O2"

    $ROOT/bin/atos-run --dryrun -r -a "-O2"

    $ROOT/bin/atos-opt --dryrun -r -a "-O2"

    diff -rq atos-configurations-init atos-configurations


    $ROOT/bin/atos-explore --dryrun

    diff -rq atos-configurations-init atos-configurations

    $ROOT/bin/atos-audit --dryrun gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c

) 2>&1
