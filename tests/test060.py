#!/usr/bin/env python
#
#

import common
import os, argparse, re, shutil, filecmp
from atos import logger, process, utils, atos_lib

TEST_CASE = "ATOS atos-opt invocation"

def atos_setup_args(**kwargs):
    # set environment variables
    for key, value in kwargs.items():
        if value is None: continue
        os.putenv(str(key), str(value))
    # allows to call 'invoque' function from toplevel
    logger.setup({})
    process.setup({})
    utils._at_toplevel = True
    args = argparse.Namespace()
    args.dryrun = process._dryrun
    return args

def atos_log_name(prefix, options=None, gopts=None, uopts=None, variant=None):
    logdir = os.path.join("atos-configurations", "logs")
    variant = variant or atos_lib.variant_id(options, gopts, uopts)
    return os.path.join(logdir, "%s-%s.log" % (
            prefix, str(atos_lib.hashid(variant))))

def grep_log(log, *args):
    result = []
    for line in open(log):
        line = line.rstrip()
        all_rexp_ok = True
        for rexp in args:
            if not re.search(rexp, line):
                all_rexp_ok = False
                break
        if all_rexp_ok: result.append(line)
    return result

def get_results(query=None):
    return atos_lib.atos_db.db("atos-configurations").get_results(query)

log = "debug.log"
args = atos_setup_args(ATOS_DEBUG_FILE=log)

sha1dir = os.path.join(common.SRCDIR, 'examples', 'sha1-c')

status = utils.invoque(
    "atos-init", args, run_script=os.path.join(sha1dir, "run.sh"),
    build_script="gcc -o sha1-c %s %s" % (
        os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")))
assert status == 0



#
#   -r, --record
#   -a OPTIONS, --options OPTIONS
#

status = utils.invoque("atos-opt", args, options="-O2", record=True)
assert status == 0

results = get_results({"variant" : "OPT-O2"})
assert len(results) == 1

status = utils.invoque("atos-opt", args, options="-O2", record=True)
assert status == 0

results = get_results({"variant" : "OPT-O2"})
assert len(results) == 2


#
#   -k, --keep
#

status = utils.invoque("atos-opt", args, options="-O2", record=True, keep=True)
assert status == 0

results = get_results({"variant" : "OPT-O2"})
assert len(results) == 2

#
#   -n NBRUNS, --nbruns NBRUNS
#

status = utils.invoque("atos-opt", args, options="-O3", record=True, nbruns=2)
assert status == 0

results = get_results({"variant" : "OPT-O3"})
assert len(results) == 2

status = utils.invoque("atos-opt", args, options="-O1", record=True)
assert status == 0

results = get_results({"variant" : "OPT-O1"})
assert len(results) == 1

#
#   -f, --fdo
#

status = utils.invoque("atos-opt", args, options="-O2", record=True, fdo=1)
assert status == 0

results = get_results({"variant" : "OPT-fprofile-use-O2-O2"})
assert len(results) == 1

#
#   -u UOPTS, --useprof UOPTS
#

status = utils.invoque("atos-opt", args, options="-O2", record=True, uopts="-O2")
assert status == 0

results = get_results({"variant" : "OPT-fprofile-use-O2-O2"})
assert len(results) == 2

status = utils.invoque("atos-opt", args, options="-O2", record=True, fdo=1, uopts="-O2")
assert status == 0

results = get_results({"variant" : "OPT-fprofile-use-O2-O2"})
assert len(results) == 3

#
#   -l, --lto
#

status = utils.invoque("atos-opt", args, options="-O2", record=True, lto=1)
assert len(grep_log(log, "DEBUG: command \[gcc .* -flto")) == 1

#
#   -b REMOTE_PATH, --remote_path REMOTE_PATH
#

status = utils.invoque("atos-opt", args, options="-O3", record=True, fdo=1, remote_path="/tmp/aaa")
assert len(grep_log(log, "DEBUG: command \[gcc .* -fprofile-dir", "/tmp/aaa")) == 1

#
#   --force
#

status = utils.invoque("atos-opt", args, options="-Os", force=True, record=True)
assert status == 0
assert len(grep_log(log, "DEBUG: command \[gcc .* -Os")) == 1
results = get_results({"variant" : "OPT-Os"})
assert len(results) == 1
