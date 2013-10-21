#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS LTO for relocatable link"

[ `ld -v --help 2>&1 | grep "\-flto" | wc -l` != 0 ] || skip "non lto linker"

cp -a $SRCDIR/tests/resources/build_incremental_link_1/* .

# Build and verify whether we can have a build with intermediate relocatable
# where LTO is performed on the final main executable only
$ROOT/bin/atos-init -c -b "make clean all" -r ./main.exe -e "main.exe test.ko"
$ROOT/bin/atos-opt --lto --fdo --options -O2 2>&1
# Verify that the relocatable object has .gnu.lto (i.e. lto was not run on it
[ `objdump -h kotmp/test.ko | fgrep .gnu.lto | wc -l` -ne 0 ]
# Verify that the executable does not have .gnu.lto (i.e. lto was run on it)
[ `objdump -h main.exe | fgrep .gnu.lto | wc -l` -eq 0 ]
