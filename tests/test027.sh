#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS toolkit debug"

$ROOT/bin/atos-init \
    -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c"

(
    DEBUG=1 $ROOT/bin/atos-explore-inline -M1
) 2>&1
