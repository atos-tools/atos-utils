#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS empty graph"

# this test must only be run manually
[ "$MAKELEVEL" == "" ] || skip

# $ROOT/bin/atos-graph --version 2>/dev/null || skip

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" -n 0

$ROOT/bin/atos-graph --hide

