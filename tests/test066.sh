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

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh" -p "/bin/cp oprof.in oprof.out"




$ROOT/bin/atos gen --generator=gen_staged --arg=nbiters=10 \
    --optim-variants=base --cookie=aaaaaaaaaaaaaaaaaaaa

nb_played1=`$ROOT/bin/atos lib query | wc -l`

$ROOT/bin/atos gen --generator=gen_staged --arg=nbiters=10 \
    --optim-variants=base --cookie=aaaaaaaaaaaaaaaaaaaa --reuse

nb_played2=`$ROOT/bin/atos lib query | wc -l`

[ $nb_played1 -eq $nb_played2 ]




export ATOS_DEBUG_FILE=log.txt

$ROOT/bin/atos-explore-inline --nbiters=10

expl_cookie1=`grep "Identifier of exploration:" log.txt | sed 's/.* //g'`

nb_played1=`$ROOT/bin/atos lib query | wc -l`

export ATOS_DEBUG_FILE=log2.txt

$ROOT/bin/atos-explore-inline --nbiters=10 --reuse --cookie=$expl_cookie1

expl_cookie2=`grep "Identifier of exploration:" log2.txt | sed 's/.* //g'`

nb_played2=`$ROOT/bin/atos lib query | wc -l`

[ "$expl_cookie1" == "$expl_cookie2" ]

[ $nb_played1 -eq $nb_played2 ]



export ATOS_DEBUG_FILE=log3.txt

$ROOT/bin/atos-explore-acf --file-by-file --hot-th=70 --per-func-nbiters=10

expl_cookie1=`grep "Identifier of exploration:" log3.txt | sed 's/.* //g'`

nb_played1=`$ROOT/bin/atos lib query | wc -l`

export ATOS_DEBUG_FILE=log4.txt

$ROOT/bin/atos-explore-acf --file-by-file --hot-th=70 --per-func-nbiters=10 \
    --reuse --cookie=$expl_cookie1

expl_cookie2=`grep "Identifier of exploration:" log4.txt | sed 's/.* //g'`

nb_played2=`$ROOT/bin/atos lib query | wc -l`

[ "$expl_cookie1" == "$expl_cookie2" ]

[ $nb_played1 -eq `expr $nb_played2 - 1` ] # atos-fctmap run not yet kept

