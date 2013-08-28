#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS build/run reuse"

cat > getres.sh <<EOF
time=\`cat RUNLOG | grep user | awk '{ print \$2 }'\`
size=\`size ./sha1-c | tail -1 | awk '{ print \$4 }'\`
echo "ATOS: sha1: time: \$time"
echo "ATOS: sha1: size: \$size"
echo "ATOS: sha2: time: \$time"
echo "ATOS: sha2: size: \$size"
EOF

cat > run.sh <<EOF
dd if=/dev/urandom bs=4K count=1K 2>/dev/null | time -p ./sha1-c 2>&1 | tee RUNLOG
exit ${PIPESTATUS[0]}
EOF

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "sh ./run.sh" -b "sh ./build.sh" -t "sh ./getres.sh"


echo
echo "#"
echo "# reuse of fdo profile"
echo "#"
echo

$ROOT/bin/atos-opt -f -a -O2

$ROOT/bin/atos-opt -f -a -O2 --reuse 2>&1 | tee LOG
[ `cat LOG | grep "Reusing profile variant OPT-fprofile-generate-O2" | wc -l` -eq 1 ]

$ROOT/bin/atos-opt -l -f -a -O2 --reuse 2>&1 | tee LOG
[ `cat LOG | grep "Reusing profile variant OPT-fprofile-generate-O2" | wc -l` -eq 1 ]


echo
echo "#"
echo "# reuse of variant results"
echo "#"
echo

$ROOT/bin/atos-opt -r -f -a -O3 --reuse

$ROOT/bin/atos-opt -r -f -a -O3 --reuse 2>&1 | tee LOG
[ `cat LOG | grep "Reusing results of variant OPT-fprofile-use-O3-O3" | wc -l` -eq 1 ]
[ `cat atos-configurations/results.db | grep "OPT-fprofile-use-O3-O3: cookies" | wc -l` -eq 0 ]

$ROOT/bin/atos-opt -r -f -a -O3 --reuse --cookie ck1 --cookie ck2
$ROOT/bin/atos-opt -r -f -a -O3 --reuse --cookie ck3
$ROOT/bin/atos-opt -f -a -O3 --reuse --cookie ck4
[ `cat atos-configurations/results.db | grep "OPT-fprofile-use-O3-O3: cookies" | grep ck1 | wc -l` -eq 2 ]
[ `cat atos-configurations/results.db | grep "OPT-fprofile-use-O3-O3: cookies" | grep ck2 | wc -l` -eq 2 ]
[ `cat atos-configurations/results.db | grep "OPT-fprofile-use-O3-O3: cookies" | grep ck3 | wc -l` -eq 2 ]
[ `cat atos-configurations/results.db | grep "OPT-fprofile-use-O3-O3: cookies" | grep ck4 | wc -l` -eq 0 ]


echo
echo "#"
echo "# reuse of run results"
echo "#"
echo

$ROOT/bin/atos-opt -r -a -O2 --reuse
$ROOT/bin/atos-opt -r -a "-O0 -O2" --reuse 2>&1 | tee LOG
[ `cat LOG | grep "Reusing run results for variant OPT-O0-O2" | wc -l` -eq 1 ]


echo
echo "#"
echo "# reuse of fdo run results"
echo "#"
echo

$ROOT/bin/atos-opt -r -f -a "-O0 -O3" --reuse 2>&1 | tee LOG
[ `cat LOG | grep "Reusing profiling run for variant OPT-fprofile-generate-O0-O3" | wc -l` -eq 1 ]
[ `cat LOG | grep "Reusing run results for variant OPT-fprofile-use-O0-O3-O0-O3" | wc -l` -eq 1 ]
