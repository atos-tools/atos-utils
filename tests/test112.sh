#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS storage of soft links"

# Generate a test case that takes a previously
# created link to an object (link-sha.o).
# If the ATOS object storage does not
# correctly handle link to input files
# the rebuild may fail.
# Actually the dereferenced linked file must be fully
# copied to the storage, not the link itself.
cat > build.sh <<EOF
set -e
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha1.o link-sha.o
EOF

# Create an object and a link out of atos-init
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
ln -fs sha.o link-sha.o

$ROOT/bin/atos-init -b "sh build.sh" -r "echo user 1"

# Remove all objects.
# If the link was not correctly handled, the build will fail
# with a link-sha.o: no such file or directory error.
rm -f *.o
$ROOT/bin/atos-build
