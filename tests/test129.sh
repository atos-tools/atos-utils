#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS remote build"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > remote_build.sh <<EOF
set -ex
tmpbase=$PWD/TMPDIR/
mkdir -p \$tmpbase
tmpdir=\`mktemp -d --tmpdir=\$tmpbase -t tmp.atos.XXXXXXXXXX\`
# extract archive in temporary dir
cd \$tmpdir
tar xzf \$ATOS_CARE_SRC
# execute build.sh
./exec.sh
# get build archive back
cp atos.tar.gz \$ATOS_CARE_DST
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" \
    --remote-build-script "sh ./remote_build.sh"

$ROOT/bin/atos-explore \
    --build-jobs=2 --run-jobs=2 \
    --optim-levels=-O2 \


