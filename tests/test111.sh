#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS storage of modified files"

# Generate a test case that modifies a file
# in place after the command generating the
# file have been audited and the file stored
# in the ATOS objects storage.
# The important sequence of commands there is:
#   ar rc libsha.a sha.o <= libsha.a stored
#   ranlib libsha.a      <= libsha.a modified in place
cat > build.sh <<EOF
set -e
rm -f *.o *.a 
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
ar rc libsha.a sha.o
ranlib libsha.a
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha1.o -L. -lsha
EOF

$ROOT/bin/atos-init -b "sh build.sh" -r "echo user 1"

# Check that all object storage blobs have a correct
# sha1 sum, i.e. that the backed up object sha1 sum is still
# the same as it's original sha1 sum.
# The ranlib libsha.a in build.sh modifies the object
# in place, hence if the storage is a hard or soft link
# this bug will show up.
cd atos-configurations/build.stg/blobs
for i in `find . -type f`; do
    real_sha1=`sha1sum $i| cut -f1 -d' '`
    original_sha1=`echo $i | sed -e 's!^\.!!' -e 's!/!!g'`
    echo "Testing sha1 of blob build.stg/blobs/$i"
    [ "$real_sha1" == "$original_sha1" ]
done





