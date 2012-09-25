#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS dryrun mode"

cat > getres.sh <<EOF
#!/usr/bin/env bash
time=0
while read line; do
 if [ \`echo \$line | grep "^AAA" | wc -l\` -ne 0 ]; then
    time="\`echo \$line | awk '{ print \$2 " + 1"}' | bc\`"
    break
 fi
done < <(cat -)
echo "ATOS: x: size: 100"
echo "ATOS: x: time: \$time"
EOF

cat > run.sh <<EOF
#!/usr/bin/env bash
echo "AAA 17"
EOF

cat > build.sh <<EOF
#!/usr/bin/env bash
gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
EOF

chmod u+x build.sh run.sh getres.sh

$ROOT/bin/atos-init -r ./run.sh -b ./build.sh -t ./getres.sh

$ROOT/bin/atos-run -r

[ `cat atos-configurations/results.db | grep time | grep 18 | wc -l` -ne 0 ]

