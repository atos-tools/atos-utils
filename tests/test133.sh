#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh
# Workaround for proot failure in case the test is run in a subdirectory of $HOME
unset HOME

TEST_CASE="ATOS remote build force"

cat > build.sh <<EOF
set -ex
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > remote_exec.sh <<EOF
set -ex
tmpbase=$PWD/TMPDIR/
mkdir -p \$tmpbase
tmpdir=\`mktemp -d --tmpdir=\$tmpbase tmp.atos.XXXXXXXXXX\`
# extract archive in temporary dir
cd \$tmpdir
tar xzvf \$ATOS_CARE_SRC
# execute command
./exec.sh
# get archive back
cp atos.tar.gz \$ATOS_CARE_DST
EOF

$ROOT/bin/atos-init \
    --build-script="sh ./build.sh" \
    --run-script="$SRCDIR/examples/sha1-c/run.sh" \
    --remote-exec-script="sh ./remote_exec.sh" \
    --build-jobs=2 --run-jobs=2 \
    --force --executables=sha1-c --reuse --nbruns=2

$ROOT/bin/atos-explore \
    --optim-levels=-O1,-O2 --optim-variants=base,fdo

[ `$ROOT/bin/atos lib query | wc -l` -eq 10 ]

[ `$ROOT/bin/atos lib query -q '$[*].size' | wc -l` -ge 6 ]

