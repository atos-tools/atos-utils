#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS LTO for relocatable link target"

[ `ld -v --help 2>&1 | grep "\-flto" | wc -l` != 0 ] || skip "non lto linker"

cp -a $SRCDIR/tests/resources/build_incremental_link_3/* .

# Build and verify whether we can have a build with relocatable
# link target command with LTO.
$ROOT/bin/atos-init -c -b "make clean relocatable" -r "bash -c 'rm -f main.exe && make all && ./main.exe'"
$ROOT/bin/atos-opt --lto --fdo --options -O2 2>&1
# Verify that objects have .gnu.lto (i.e. lto was activated)
[ `objdump -h test1.o | fgrep .gnu.lto | wc -l` -ne 0 ]
[ `objdump -h test2.o | fgrep .gnu.lto | wc -l` -ne 0 ]
# Verify that the relocatable object does not have .gnu.lto (i.e. lto was run on it)
[ `objdump -h kotmp/test.ko | fgrep .gnu.lto | wc -l` -eq 0 ]
