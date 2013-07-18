#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS parallel build check"

cat > build.sh <<EOF
set -e
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
echo "# PWD \$PWD \$PROOT_ADDON_RELOC_EXEC_DIR \$BUILD_ID" > sha1.sums
sha1sum sha.o sha1.o sha1-c >> sha1.sums
echo "# SIZE \`size sha1-c | tail -1\`" >> sha1.sums
EOF

cat > run.sh <<EOF
set -ex
echo "### PWD (\$PWD) (\$PROOT_ADDON_RELOC_EXEC_DIR) (\$RUN_ID)"
dd if=/dev/urandom bs=4K count=1K 2>/dev/null | ./sha1-c
[ \${PIPESTATUS[0]} -eq 0 ]
echo "### SHA \`sha1sum ./sha1-c | awk '{ print \$1 }'\`"
EOF

reloc_short() {
    echo $1 | sed 's/.*\/reloc\/\([[0-9a-z]*-[0-9a-z]*\).*/\1/'
}

$ROOT/bin/atos-init \
    -r "bash ./run.sh" \
    -b "bash ./build.sh" \
    --force --executables=sha1-c

$ROOT/bin/atos-explore \
    --optim-levels=-Os,-O2,-O3 \
    --optim-variants=base,fdo \
    --build-jobs=2 --run-jobs=2 --nbruns=2

# check for absence of failure
[ `cat atos-configurations/logs/* | grep FAILURE | wc -l` -eq 0 ]

# check for absence of missing gcda
[ `cat atos-configurations/logs/* | grep "gcda not found" | wc -l` -eq 0 ]

for i in `find atos-configurations -name sha1.sums`; do
    # check that sha1.sums files are properly located in build reloc_dir
    [ `reloc_short \`dirname $i\`` = `reloc_short \`cat $i | grep PWD | awk '{ print $4 }'\`` ]
    # check that build/runs sha1.sums are identical
    diff $i `echo $i | sed 's/\(.*reloc\/[0-9]*-[0-9a-z]*\)[^\/]*\(.*\)/\1\2/'`
    # check that objects/target sha1sums are correct
    ( cd `dirname $i`; sha1sum --quiet --check `basename $i` )
    # check that size matches results.db
    # check for gcda & profile dir
    # check that targhash matches hashsum db
done
