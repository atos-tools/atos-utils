#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generators - chained explorations"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "sh ./build.sh"


# chain gen_basic, gen_inline and gen_loop
$ROOT/bin/atos generator \
    --generator=gen_chained \
    --extra-arg=generator1=gen_base \
    --extra-arg=generator2=gen_explore_inline \
    --extra-arg=generator3=gen_explore_loop \
    --nbiters=5 --optim-levels=-O3 --optim-variants=base,lto --cookie=expl_first

# continue previous exploration with gen_optim
$ROOT/bin/atos generator \
    --generator=gen_chained_exploration \
    --extra-arg=generator1=gen_rnd_uniform_deps,flags_files:atos-configurations/flags.optim.cfg \
    --extra-arg=stage_cookie=expl_first \
    --nbiters=5 --cookie=expl_second

# random on all flags
$ROOT/bin/atos generator \
    --generator=gen_explore_random \
    --nbiters=5 --optim-levels=-O3 --optim-variants=base

# double gen-staged
$ROOT/bin/atos generator \
    --generator=gen_chained \
    --extra-arg=generator1=gen_base \
    --extra-arg=generator2=gen_explore_inline \
    --extra-arg=generator3=gen_explore_loop \
    --extra-arg=generator4=gen_explore_optim \
    --extra-arg=generator5=gen_explore_inline \
    --extra-arg=generator6=gen_explore_loop \
    --extra-arg=generator7=gen_explore_optim \
    --nbiters=2 --optim-levels=-O3 --optim-variants=base --tradeoffs=5
