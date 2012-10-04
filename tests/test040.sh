#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS empty flag list"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

touch f.txt

$ROOT/bin/atos-explore-inline -F ./f.txt -M 5

[ `$ROOT/bin/atos lib query | grep -v REF | wc -l` -eq 0 ]
