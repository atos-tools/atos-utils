#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS replay frontier"

cat > ./run.sh <<EOF
#!/usr/bin/env bash
set -e
dd if=/dev/urandom bs=4K count=\$1 2>/dev/null | ./sha1-c
exit \${PIPESTATUS[0]}
EOF
chmod +x ./run.sh

$ROOT/bin/atos-init \
    -r "./run.sh 1K" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O0"
$ROOT/bin/atos-opt -r -a "-O1"
$ROOT/bin/atos-opt -r -a "-O2"
$ROOT/bin/atos-opt -r -a "-O3"

$ROOT/bin/atos-replay -C atos-configurations -R atos-config-replay -r "./run.sh 1K"

nb_replayed=`$ROOT/bin/atos lib query -C atos-config-replay | grep -v REF | wc -l`
nb_frontier=`$ROOT/bin/atos lib speedups -C atos-configurations -f | grep -v REF | wc -l`

[ $nb_replayed -eq $nb_frontier ]
