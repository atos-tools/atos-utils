#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS proot reloc_exec performances"

[ "$MAKELEVEL" == "" ] || skip "interactive test"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > loop.sh <<EOF
nbiters=\$1; shift
n=0; real1=; real2=; real3=;
while [ \$n -lt \$nbiters ]; do
  # 1: native execution
  ( /usr/bin/time -p \$* ) >LOG 2>&1
  real1="\$real1 \`cat LOG | grep real | awk '{ print \$2 }'\`"
  # 2: execution w/ proot
  ( /usr/bin/time -p $SRCDIR/bin/atos-proot \$* ) >LOG 2>&1
  real2="\$real2 \`cat LOG | grep real | awk '{ print \$2 }'\`"
  # 3: execution w/ proot + reloc_exec
  ( env PROOT_ADDON_RELOC_EXEC=1 \
     PROOT_ADDON_RELOC_EXEC_DIR=\$PWD/RELOC/RELOC-\$n \
     PROOT_ADDON_RELOC_EXEC_IGNORED="/1/,/2/,/3/,/4/,/5/" \
         /usr/bin/time -p $SRCDIR/bin/atos-proot \$* ) >LOG 2>&1
  real3="\$real3 \`cat LOG | grep real | awk '{ print \$2 }'\`"
  # 4: execution w/ proot + reloc_exec (same reloc_dir)
  ( env PROOT_ADDON_RELOC_EXEC=1 \
     PROOT_ADDON_RELOC_EXEC_DIR=\$PWD/RELOC/RELOC-0 \
     PROOT_ADDON_RELOC_EXEC_IGNORED="/1/,/2/,/3/,/4/,/5/" \
         /usr/bin/time -p $SRCDIR/bin/atos-proot \$* ) >LOG 2>&1
  real4="\$real4 \`cat LOG | grep real | awk '{ print \$2 }'\`"
  n=\`expr \$n + 1\`
done
avg1=\`python -c "print \\\`echo \$real1 | sed 's/\ /\ +\ /g'\\\` / \$n"\`
avg2=\`python -c "print \\\`echo \$real2 | sed 's/\ /\ +\ /g'\\\` / \$n"\`
avg3=\`python -c "print \\\`echo \$real3 | sed 's/\ /\ +\ /g'\\\` / \$n"\`
avg4=\`python -c "print \\\`echo \$real4 | sed 's/\ /\ +\ /g'\\\` / \$n"\`
python -c "print '  native: %.2f' % (\$avg1)"
python -c "print '   proot: %.2f -> x%.1f' % (\$avg2, \$avg2 / \$avg1)"
python -c "print '   reloc: %.2f -> x%.1f' % (\$avg3, \$avg3 / \$avg1)"
python -c "print '   srelc: %.2f -> x%.1f' % (\$avg4, \$avg4 / \$avg1)"
EOF

nbiters=${1:-50}

uname -a

echo "build of sha1-c example (realtime, $nbiters builds)"
sh loop.sh $nbiters sh -x build.sh

echo "run of sha1-c example (realtime, $nbiters runs)"
sh build.sh
sh loop.sh $nbiters sh -x $SRCDIR/examples/sha1-c/run.sh

# 1st version
#
# Linux gnx2025 2.6.32-34-generic #77-Ubuntu SMP Tue Sep 13 19:39:17 UTC 2011 x86_64 GNU/Linux
# build of sha1-c example (realtime, 50 builds)
#   native: 5.39
#    proot: 9.04 -> x1.7
#    reloc: 52.45 -> x9.7
#    srelc: 47.77 -> x8.9
# run of sha1-c example (realtime, 50 runs)
#   native: 31.49
#    proot: 37.47 -> x1.2
#    reloc: 42.25 -> x1.3
#    srelc: 40.76 -> x1.3
# SUCCESS: test120: ATOS proot reloc_exec performances

# 2nd version (w/ reloc_exec hash tables)
#
# Linux gnx2025 2.6.32-34-generic #77-Ubuntu SMP Tue Sep 13 19:39:17 UTC 2011 x86_64 GNU/Linux
# build of sha1-c example (realtime, 50 builds)
#   native: 5.12
#    proot: 9.80 -> x1.9
#    reloc: 21.69 -> x4.2
#    srelc: 17.45 -> x3.4
# run of sha1-c example (realtime, 50 runs)
#   native: 31.35
#    proot: 37.37 -> x1.2
#    reloc: 40.11 -> x1.3
#    srelc: 39.37 -> x1.3
# SUCCESS: test120: ATOS proot reloc_exec performances
