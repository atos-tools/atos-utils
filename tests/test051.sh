#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run get_results"

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


# processing of run output log

cat > getres.sh <<EOF
#!/usr/bin/env bash
time=0
while read line; do
  [[ "\$line" = "real "* ]] \
        && time=\`echo \$time + \\\`echo \$line | awk '{ print \$2 }'\\\` | bc\`
  [[ "\$line" = "user "* ]] \
        && time=\`echo \$time + \\\`echo \$line | awk '{ print \$2 }'\\\` | bc\`
  [[ "\$line" = "sys "* ]] \
        && time=\`echo \$time + \\\`echo \$line | awk '{ print \$2 }'\\\` | bc\`
done < <(cat -)
echo "ATOS: x: size: 100"
echo "ATOS: x: time: \$time"
EOF

cat > run.sh <<EOF
#!/usr/bin/env bash
echo "user 10"
echo "user 15"
echo "real 25"
echo "sys 5"
EOF

cat > build.sh <<EOF
#!/usr/bin/env bash
gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
EOF

chmod u+x build.sh run.sh getres.sh

/bin/rm -fr atos-configurations

$ROOT/bin/atos-init -r ./run.sh -b ./build.sh -t ./getres.sh

$ROOT/bin/atos-run -r

[ `cat atos-configurations/results.db | grep time | grep 55 | wc -l` -ne 0 ]

