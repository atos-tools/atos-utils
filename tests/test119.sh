#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS parallel build/runs"

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


# ############################

$ROOT/bin/atos-explore \
    --optim-levels=-Os,-O0,-O1,-O2,-O3 \
    --optim-variants=base \
    --build-jobs=2 --run-jobs=2 \
    --log-file=LOG1

# check for absence of failure
[ `cat LOG1 | grep FAILURE | wc -l` -eq 0 ]

# check for different sizes for each config
[ `cat atos-configurations/results.db | grep size | awk '{ print $5 }' | sort -u | wc -l` -eq 5 ]

# check for different sha1sum for each config
[ `cat LOG1 | grep SHA | sort -u | wc -l` -eq 5 ]

# check that no reloc dir is kept
[ `find atos-configurations/reloc | wc -l` -eq 1 ]


# ############################

$ROOT/bin/atos-explore \
    --optim-levels=-Os,-O0,-O1,-O2,-O3 \
    --optim-variants=base \
    --build-jobs=2 --run-jobs=4 --nbruns=3 \
    --log-file=LOG2

# check for absence of failure
[ `cat LOG2 | grep FAILURE | wc -l` -eq 0 ]

# check for different sizes for each config
[ `cat atos-configurations/results.db | grep size | awk '{ print $5 }' | sort -u | wc -l` -eq 5 ]

# check for different sha1sum for each config
[ `cat LOG2 | grep SHA | sort -u | wc -l` -eq 5 ]

# check that no reloc dir is kept
[ `find atos-configurations/reloc | wc -l` -eq 1 ]


# ############################

export ATOS_KEEP_RELOC=1

$ROOT/bin/atos-explore \
    --optim-levels=-Os,-O0,-O1,-O2,-O3 \
    --optim-variants=fdo \
    --build-jobs=2 --run-jobs=3 --nbruns=2 \
    --log-file=LOG3

# check for absence of failure
[ `cat LOG3 | grep FAILURE | wc -l` -eq 0 ]

# check for absence of missing gcda
[ `cat LOG3 | grep "gcda not found" | wc -l` -eq 0 ]


# ############################

$ROOT/bin/atos-explore-staged \
    --optim-levels=-Os,-O2,-O3 \
    --optim-variants=base,fdo \
    --tradeoffs=5 \
    --nbiters=5 \
    --build-jobs=2 --run-jobs=3 --nbruns=2


# ############################

$ROOT/bin/atos-init \
    -r "bash ./run.sh" \
    -b "bash ./build.sh" \
    --build-jobs=2 --run-jobs=2 \
    -C atos-config-2

$ROOT/bin/atos-build \
    -C atos-config-2 \
    --options=-O2

$ROOT/bin/atos-run \
    -C atos-config-2 \
    --options=-O2 \
    --nbruns=3

$ROOT/bin/atos-explore \
    -C atos-config-2 \
    --optim-levels=-O2,-O2,-O2 \
    --optim-variants=fdo,fdo,fdo \
    --log-file=LOG4

# check for absence of failure
[ `cat LOG4 | grep FAILURE | wc -l` -eq 0 ]

# check for absence of missing gcda
[ `cat LOG4 | grep "gcda not found" | wc -l` -eq 0 ]
