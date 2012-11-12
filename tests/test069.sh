#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generator/deps unit tests"

python $ROOT/lib/atos/python/atoslib/generators.py

python $ROOT/lib/atos/python/atoslib/atos_deps.py
