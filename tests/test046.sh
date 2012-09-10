#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS timeout"

cat >uninterruptible.sh <<EOF
#!/bin/sh
trap "" TERM
sleep 10
EOF
chmod 755 uninterruptible.sh
$ROOT/bin/atos-timeout 1 sleep 5 2>&1 | grep "Terminated after timeout"
$ROOT/bin/atos-timeout -s 9 1 sleep 5 2>&1 | grep "Killed after timeout"
$ROOT/bin/atos-timeout -s 15 -k 1 1 ./uninterruptible.sh 5 2>&1 | grep "Killed after timeout"
$ROOT/bin/atos-timeout 1 $ROOT/bin/atos-timeout 2 sleep 5 2>test.out || true
grep "Terminated after timeout" test.out

# Note that the following does not work correctly, i.e. the termination message is emmited
# from the first timeout, but the pipe stays open until the sleep is terminated
$ROOT/bin/atos-timeout 1 $ROOT/bin/atos-timeout 2 sleep 5 2>&1 | grep "Terminated after timeout"
