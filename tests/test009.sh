#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps PROFILE_DIR"

mkdir TMPDIR; cd TMPDIR

cat > ./build.sh <<EOF
  # CCLD command
  gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c

  # CCLD command in another directory
  ( mkdir TMP2; cd TMP2
    gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
  )

  # CC command
  ( mkdir TMP3; cd TMP3
    gcc -c -o sha.o $SRCDIR/examples/sha1-c/sha.c
    gcc -c -o sha1.o $SRCDIR/examples/sha1-c/sha1.c
    gcc -o sha1-c sha.o sha1.o
  )

  # CC command with relative outputs
  ( mkdir TMP4; cd TMP4; mkdir -p TMP2/TMP3
    gcc -c -o TMP2/sha.o $SRCDIR/examples/sha1-c/sha.c
    gcc -c -o ../TMP4/TMP2/TMP3/sha1.o $SRCDIR/examples/sha1-c/sha1.c
    gcc -o sha1-c TMP2/sha.o TMP2/TMP3/sha1.o
  )

  # CC command with absolute outputs
  ( mkdir TMP5; cd TMP5; mkdir TMP2
    gcc -c -o \$PWD/TMP2/sha.o $SRCDIR/examples/sha1-c/sha.c
    gcc -c -o \$PWD/TMP2/../sha1.o $SRCDIR/examples/sha1-c/sha1.c
    gcc -o sha1-c \$PWD/TMP2/sha.o sha1.o
  )

  # CC command with output in upper level
  ( mkdir TMP6
    gcc -c -o ../sha.o $SRCDIR/examples/sha1-c/sha.c
    gcc -c -o ../sha1.o $SRCDIR/examples/sha1-c/sha1.c
    gcc -o TMP6/sha1-c ../sha.o ../sha1.o
  )
EOF

cat > ./run.sh <<EOF
  for i in ./ ./TMP2 ./TMP3 ./TMP4 ./TMP5 ./TMP6; do
    ( dd if=/dev/urandom status=noxfer iflag=fullblock bs=320 count=32 2> /dev/null) | \$i/sha1-c
  done
EOF

$ROOT/bin/atos-audit sh ./build.sh
$ROOT/bin/atos-raudit sh ./run.sh
$ROOT/bin/atos-deps -a
$ROOT/bin/atos-profile -g -O2
$ROOT/bin/atos-build -a -O2 -u -O2
[ `find atos-configurations/profiles -name *.gcda | wc -l` -eq 12 ]
[ `find atos-configurations/logs -name *.log -exec grep "gcda not found" {} ";" | wc -l` -eq 0 ]
[ `ls atos-configurations/profiles | grep gcda | wc -l` -eq 0 ]



cat > ./build.2.sh <<EOF

  # common relative target prefix longer than cwd common prefix
  ( mkdir TMP7; cd TMP7; mkdir -p TMP2/TMP3/TMP4
    gcc -c -o TMP2/TMP3/TMP4/sha.o $SRCDIR/examples/sha1-c/sha.c
    gcc -c -o TMP2/TMP3/TMP4/sha1.o $SRCDIR/examples/sha1-c/sha1.c
    gcc -o sha1-c TMP2/TMP3/TMP4/sha.o TMP2/TMP3/TMP4/sha1.o
  )

EOF

cat > ./run.2.sh <<EOF
  ( dd if=/dev/urandom status=noxfer iflag=fullblock bs=320 count=32 2> /dev/null) | ./TMP7/sha1-c
EOF

$ROOT/bin/atos-audit -C atos-configurations-2 sh ./build.2.sh
$ROOT/bin/atos-raudit -C atos-configurations-2 sh ./run.2.sh
$ROOT/bin/atos-deps -a -C atos-configurations-2
$ROOT/bin/atos-profile -C atos-configurations-2 -g -O2
$ROOT/bin/atos-build -C atos-configurations-2 -a -O2 -u -O2
[ `find atos-configurations-2/profiles -name *.gcda | wc -l` -eq 2 ]
[ `find atos-configurations-2/logs -name *.log -exec grep "gcda not found" {} ";" | wc -l` -eq 0 ]
[ `ls atos-configurations-2/profiles | grep gcda | wc -l` -eq 0 ]



cat > ./build.3.sh <<EOF
  # relative targets in parent directories of cwd
  ( mkdir TMP8; cd TMP8
    gcc -c -o ../../sha.o $SRCDIR/examples/sha1-c/sha.c
    gcc -c -o ../../sha1.o $SRCDIR/examples/sha1-c/sha1.c
    gcc -o sha1-c ../../sha.o ../../sha1.o
  )
EOF

cat > ./run.3.sh <<EOF
  ( dd if=/dev/urandom status=noxfer iflag=fullblock bs=320 count=32 2> /dev/null) | ./TMP8/sha1-c
EOF

$ROOT/bin/atos-audit -C atos-configurations-3 sh ./build.3.sh
$ROOT/bin/atos-raudit -C atos-configurations-3 sh ./run.3.sh
$ROOT/bin/atos-deps -a -C atos-configurations-3
$ROOT/bin/atos-profile -C atos-configurations-3 -g -O2
$ROOT/bin/atos-build -C atos-configurations-3 -a -O2 -u -O2
[ `find atos-configurations-3/profiles -name *.gcda | wc -l` -eq 2 ]
[ `find atos-configurations-3/logs -name *.log -exec grep "gcda not found" {} ";" | wc -l` -eq 0 ]
[ `ls atos-configurations-3/profiles | grep gcda | wc -l` -eq 0 ]

