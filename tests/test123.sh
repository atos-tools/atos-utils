#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS parallel fdo profile"

cat > build.sh <<EOF
set -e
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > run.sh <<EOF
set -e
echo "### PWD (\$PWD) (\$PROOT_ADDON_RELOC_EXEC_DIR)"
dd if=/dev/urandom bs=4K count=1K 2>/dev/null | ./sha1-c
[ \${PIPESTATUS[0]} -eq 0 ]
echo "### SHA \`sha1sum ./sha1-c | awk '{ print \$1 }'\`"
EOF

$ROOT/bin/atos-init \
    -r "bash ./run.sh" \
    -b "bash ./build.sh" \


$ROOT/bin/atos-explore \
    --optim-levels=-O3 \
    --optim-variants=fdo \
    --build-jobs=1 --run-jobs=2

[ `find atos-configurations/profiles | grep gcda | wc -l` -eq 2 ]
[ `cat  atos-configurations/logs/* | grep "gcda not found" | wc -l` -eq 0 ]

$ROOT/bin/atos-explore \
    --optim-levels=-O2 \
    --optim-variants=fdo,fdo \
    --build-jobs=2 --run-jobs=2

[ `find atos-configurations/profiles | grep gcda | wc -l` -eq 4 ]
[ `cat  atos-configurations/logs/* | grep "gcda not found" | wc -l` -eq 0 ]

# remove profile-dir option from compiler config
# in order to activate the save/restore gcda mechanism
sed -i 's/\(\ *\)\("name": "gcc",\)/\1\2\n\1"fdo_dir_flags": "none",/' atos-configurations/config.json

$ROOT/bin/atos-explore \
    --optim-levels=-O1 \
    --optim-variants=fdo \
    --build-jobs=1 --run-jobs=2 --log-file=LOG

# check that gcda were copied from reloc to profile dir
[ `find atos-configurations/profiles | grep gcda | wc -l` -eq 6 ]

# check for absence of missing gcda
[ `cat  atos-configurations/logs/* | grep "gcda not found" | wc -l` -eq 0 ]
