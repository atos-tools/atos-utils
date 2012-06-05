#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps serial targets"

cp -a $ROOT/examples/sha1 .
cd sha1
$ROOT/bin/atos-audit make clean sha-shared
$ROOT/bin/atos-deps sha.so sha-shared
rm *.o *.so
# Will fail if shared lib (sha.so) is built after executable (sha-shared)
$ROOT/bin/atos-opt
