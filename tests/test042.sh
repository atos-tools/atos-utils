#!/usr/bin/env bash
#
#
source `dirname $0`/common.sh
TEST_CASE="ATOS rvct flags exploration"

# Check if armcc is available
[ "`which armcc 2>/dev/null`" != "" ] || skip "armcc rvct compiler not found"


# Check that armcc is running fine and that it is the rvct compiler
[ "`armcc --help|grep "ARM Limited"`" != "" ] || skip "armcc rvct compiler not found"

$ROOT/bin/atos-explore-staged \
    -r "$SRCDIR/examples/sha1-c/run_qemu-system.sh" \
    -b "armcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -M 3
