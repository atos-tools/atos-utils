#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generator/deps unit tests"

python $ROOT/lib/atos/python/atos/generators.py

python $ROOT/lib/atos/python/atos/atos_deps.py
