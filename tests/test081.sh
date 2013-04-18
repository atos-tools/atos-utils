#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS shared/exe link order"

cp -a $SRCDIR/tests/resources/build_install_so_1/* .

# Build and verify whether we can have a build with several
# link commands sharing a shared object of the same name.
$ROOT/bin/atos-init -c -b "make clean all install" -r ./main.exe -e "main.exe libtest.so"
mv main.exe main.exe.ref
make clean
$ROOT/bin/atos-opt
diff main.exe main.exe.ref

# Build an verify whether we can just specify the main program name
# while the shred lib is also rebuilt
$ROOT/bin/atos-init -c -b "make clean all install" -r ./main.exe -e "main.exe"
mv main.exe main.exe.ref
make clean
$ROOT/bin/atos-opt
diff main.exe main.exe.ref


