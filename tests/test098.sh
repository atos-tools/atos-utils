#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="atos-driver debug options"

rm -f log*
# Check that no spurious output is emmited on stderr
$ROOT/bin/atos-driver gcc 2>log2 || true
head -1 log2 | grep "no input file" >/dev/null
[ $? = 0 ] || exit 1

rm -f log*
# Check that debug mode outputs to stderr by default
$ROOT/bin/atos-driver --atos-debug gcc 2>log2 || true
head -1 log2 | grep "DEBUG:" >/dev/null
[ $? = 0 ] || exit 1
cat log2 | grep "no input file" >/dev/null
[ $? = 0 ] || exit 1

rm -f log*
# Check that debug is redirected to fd 3 when requested
$ROOT/bin/atos-driver --atos-debug --atos-debug-fd=3 gcc 3>log3 2>log2 || true
head -1 log3 | grep "DEBUG:" >/dev/null
[ $? = 0 ] || exit 1
head -1 log2 | grep "no input file" >/dev/null
[ $? = 0 ] || exit 1

rm -f log*
# Check that debug is redirected to fd 3 and log file when requested
$ROOT/bin/atos-driver --atos-debug --atos-debug-fd=3 --atos-log-file=log4 gcc 3>log3 2>log2 || true
head -1 log4 | grep "DEBUG:" >/dev/null
[ $? = 0 ] || exit 1
head -1 log3 | grep "DEBUG:" >/dev/null
[ $? = 0 ] || exit 1
head -1 log2 | grep "no input file" >/dev/null
[ $? = 0 ] || exit 1
