#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generators - option --reuse"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

cat > ./oprof.in <<EOF
vma              samples   %       linenr_info                    image_name symbol_name
0000000000400b93 353965337 52.2748 (no localization information)  sha1-c  SHA1ProcessMessageBlock
0000000000400a86 260243456 38.4336 (no localization information)  sha1-c  SHA1Input
00000000004006e4 62914627  9.2914  (no localization information)  sha1-c  main
0000000000400f6c 732       0.0001  (no localization information)  sha1-c  SHA1PadMessage
0000000000401110 25        0.0000  (no localization information)  sha1-c  __libc_csu_init
00000000004009c8 25        0.0000  (no localization information)  sha1-c  SHA1Reset
0000000000400a3f 20        0.0000  (no localization information)  sha1-c  SHA1Result
EOF

# there is a bug in --reuse when a same binary doesn't always
# give the same execution time (bug #220027)
cat > run.sh <<EOF
echo user \`size sha1-c | tail -1 | awk '{ print \$4 }'\`
EOF

$ROOT/bin/atos-init \
    -r "sh ./run.sh" -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"



$ROOT/bin/atos generator --generator=gen_staged --extra-arg=nbiters=3 \
    --optim-variants=base --cookie=aaaaaaaaaaaaaaaaaaaa

nb_played1=`$ROOT/bin/atos lib query | wc -l`

$ROOT/bin/atos generator --generator=gen_staged --extra-arg=nbiters=3 \
    --optim-variants=base --cookie=aaaaaaaaaaaaaaaaaaaa --reuse 2>&1 | tee LOG

nb_played2=`$ROOT/bin/atos lib query | wc -l`
[ $nb_played2 -eq `expr $nb_played1 \* 2 - 1` ]
[ `cat LOG | grep "Reusing results" | wc -l` -ne 0 ]




export ATOS_DEBUG_FILE=log.txt

$ROOT/bin/atos-explore-inline --nbiters=3

expl_cookie1=`grep "Identifier of exploration:" log.txt | sed 's/.* //g'`

nb_played1=`$ROOT/bin/atos lib query | wc -l`

export ATOS_DEBUG_FILE=log2.txt

$ROOT/bin/atos-explore-inline --nbiters=3 --reuse --cookie=$expl_cookie1 2>&1 | tee LOG

expl_cookie2=`grep "Identifier of exploration:" log2.txt | sed 's/.* //g'`

nb_played2=`$ROOT/bin/atos lib query | wc -l`

[ "$expl_cookie1" == "$expl_cookie2" ]

[ `cat LOG | grep "Reusing results" | wc -l` -ne 0 ]
