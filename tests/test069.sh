#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generator/deps unit tests"

python $ROOT/lib/atos/python/atoslib/deep_eq.py -v

python $ROOT/lib/atos/python/atoslib/cmd_interpreter.py

python $ROOT/lib/atos/python/atoslib/generators.py

python $ROOT/lib/atos/python/atoslib/atos_deps.py

python $ROOT/lib/atos/python/atoslib/atos_argparse.py

python $ROOT/lib/atos/python/atoslib/process.py
