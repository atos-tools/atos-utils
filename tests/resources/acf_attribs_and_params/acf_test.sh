#!/usr/bin/env bash
#
# use 'LTO=1 ./acf_test.sh' to enable LTO optimization

[ "$LTO_ENABLED" = "1" -o "$LTO" != "1" ] || exit 0

$ROOT/bin/atos-init -b "make config" -r "make -j 4 acf_tests LTO=$LTO CPP=$CPP" --no-run
