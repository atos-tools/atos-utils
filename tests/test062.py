#!/usr/bin/env python
#
#

import common

import os
from atoslib import utils, atos_lib

TEST_CASE = "ATOS atos cookies"


args = common.atos_setup_args(ATOS_DEBUG_FILE="debug.log")

sha1dir = os.path.join(common.SRCDIR, 'examples', 'sha1-c')

status = utils.invoque(
    "atos-init", args, run_script=os.path.join(sha1dir, "run.sh"),
    build_script="gcc -o sha1-c %s %s" % (
        os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")))
assert status == 0

# atos-opt

status = utils.invoque(
    "atos-opt", args, options="-O2", record=True, cookies=["AA", "BB"])
assert status == 0

results = atos_lib.results_filter_cookie(common.atos_results(), "AA")
assert len(results) == 1

results = atos_lib.results_filter_cookie(common.atos_results(), "A")
assert len(results) == 0

results = atos_lib.results_filter_cookie(common.atos_results(), "BB")
assert len(results) == 1

cookie = atos_lib.new_cookie()
print cookie
status = utils.invoque(
    "atos-opt", args, options="-O3", record=True, cookies=[cookie])
assert status == 0

results = atos_lib.results_filter_cookie(common.atos_results(), cookie)
assert len(results) == 1

# atos-run

status = utils.invoque(
    "atos-opt", args, options="-O2", record=True, cookies=[cookie])
assert status == 0

results = atos_lib.results_filter_cookie(
    common.atos_results({"variant" : "OPT-O2"}), cookie)
assert len(results) == 1

results = atos_lib.results_filter_cookie(
    common.atos_results(), cookie)
assert len(results) == 2


# atos-explore-*

cookies = [atos_lib.new_cookie(), atos_lib.new_cookie(), atos_lib.new_cookie()]
expl_cookie = atos_lib.unique_cookie(cookies)

status = utils.invoque(
    "atos-explore-inline", args, nbiters=10, optim_variants='base', cookies=cookies)
assert status == 0
results_expl = atos_lib.results_filter_cookie(
    common.atos_results(), expl_cookie)
results_ck1 = atos_lib.results_filter_cookie(
    common.atos_results(), cookies[0])
assert len(results_expl) and len(results_expl) == len(results_ck1)

