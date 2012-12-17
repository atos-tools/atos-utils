#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS shared/exe link order"

cp -a $SRCDIR/tests/resources/build_multiple_o_1/* .

# Build an verify whether we can have a build with several
# intermediate files sharing the same path name
$ROOT/bin/atos-init -c -b "make clean all" -r ./run.sh -N
mv main.exe main.exe.ref
mv main1.exe main1.exe.ref

# Verify is a sequencial build is ok
$ROOT/bin/atos-build --jobs 1
diff main.exe main.exe.ref
diff main1.exe main1.exe.ref
./run.sh

# Verify is a parallel build is ok
$ROOT/bin/atos-build --jobs 4
diff main.exe main.exe.ref
diff main1.exe main1.exe.ref
./run.sh


