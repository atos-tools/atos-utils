#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS proot reloc exec"

# clean and prepare test environment
rm -fr SRCDIR RELOC
mkdir -p SRCDIR RELOC

echo -n "# test simple reloc... "
  mkdir -p SRCDIR/SHA1C/SOURCES
  cp $SRCDIR/examples/sha1-c/*.[ch] SRCDIR/SHA1C/SOURCES/
  env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot \
      gcc SRCDIR/SHA1C/SOURCES/sha1.c SRCDIR/SHA1C/SOURCES/sha.c -o sha1-c
  [ -f RELOC/SHA1-c/$PWD/sha1-c ]
  [ ! -f ./sha1-c ]
  echo "OK"

echo -n "# test exec getdent... "
  mkdir -p SRCDIR/SHA1C/DATA/A/B/C/D
  dd if=/dev/urandom bs=4K count=1K 2>/dev/null > SRCDIR/SHA1C/DATA/A/B/C/D/rd1
  dd if=/dev/urandom bs=4K count=1K 2>/dev/null > SRCDIR/SHA1C/DATA/A/B/C/D/rd2
  echo "./sha1-c ./SRCDIR/SHA1C/DATA/A/B/C/D/rd1 ./SRCDIR/SHA1C/DATA/A/B/C/D/rd2" > SRCDIR/run.sh
  env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot sh SRCDIR/run.sh 2>&1 > SRCDIR/LOG
  [ `cat SRCDIR/LOG | grep rd1 | wc -l` -eq 1 ]
  [ `cat SRCDIR/LOG | grep rd2 | wc -l` -eq 1 ]
  [ -f RELOC/SHA1-c/$PWD/SRCDIR/SHA1C/DATA/A/B/C/D/rd1 ]
  [ -f RELOC/SHA1-c/$PWD/SRCDIR/SHA1C/DATA/A/B/C/D/rd2 ]
  echo "OK"

echo -n "# test parent dir 1... "
  mkdir -p SRCDIR/X/Y/Z
  env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot touch SRCDIR/X/Y/Z/aaa
  [ -f RELOC/SHA1-c/$PWD/SRCDIR/X/Y/Z/aaa ]
  echo "OK"

echo -n "# test parent dir 2... "
  mkdir -p SRCDIR/X/Y/W
  echo "echo hello >> SRCDIR/X/Y/W/hhh" > SRCDIR/run2.sh
  env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot sh SRCDIR/run2.sh
  [ -f RELOC/SHA1-c/$PWD/SRCDIR/X/Y/W/hhh ]
  echo "OK"

echo -n "# test parent dir 3... "
  mkdir -p SRCDIR/X/Z/U
  echo "python -c \"open('SRCDIR/X/Z/U/a', 'a').write('z')\"" > SRCDIR/run3.sh
  env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot sh SRCDIR/run3.sh
  [ -f RELOC/SHA1-c/$PWD/SRCDIR/X/Z/U/a ]
  echo "OK"

echo -n "# test non-existing 1... "
  mkdir -p SRCDIR/NE/
  echo "[ -d SRCDIR/NE/AAABBB ] && echo KO || echo OK" > SRCDIR/run4.sh
  env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot sh SRCDIR/run4.sh > SRCDIR/LOG2
  [ ! -d RELOC/SHA1-c/$PWD/SRCDIR/NE/AAABBB ]
  echo "OK"

# FAILURE - PROOT BUG
echo -n "# test append 1... "
  echo "import os" > test1.py
  echo "src_dir = os.path.join(os.getcwd()," >> test1.py
  echo "    'SRCDIR', 'Results', 'test')" >> test1.py
  echo "os.system('mkdir -p ' + src_dir)" >> test1.py
  echo "src_log = os.path.join(src_dir, 'logfile.txt')" >> test1.py
  echo "open(src_log, 'a').write('aaa')" >> test1.py
  ! env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot python test1.py

# FAILURE - PROOT BUG
echo -n "# test append 2... "
  echo "import os" > test2.py
  echo "src_dir = os.path.join(os.getcwd()," >> test2.py
  echo "    'SRCDIR', 'Results', 'test')" >> test2.py
  echo "os.makedirs(src_dir)" >> test2.py
  ! env \
      PROOT_ADDON_RELOC_EXEC_DIR=$PWD/RELOC/SHA1-c \
      PROOT_ADDON_RELOC_EXEC=1 \
      PROOT_ADDON_RELOC_EXEC_PREFIXES=$PWD \
      $ROOT/bin/atos-proot python test2.py

echo "OK"
