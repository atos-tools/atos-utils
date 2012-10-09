#!/usr/bin/env python

import os, sys, signal, traceback, atexit, tempfile, shutil, __builtin__
import __main__


# This file is installed in PREFIX/tests
DIRNAME = os.path.dirname(__file__)
SRCDIR = os.getenv('SRCDIR', os.path.abspath(os.path.join(DIRNAME, '..')))
ROOT = os.getenv('ROOT', SRCDIR)
PYTHONDIR = os.path.join(ROOT, 'lib', 'atos', 'python')
TEST = os.path.splitext(os.path.basename(sys.argv[0]))[0]

sys.path.insert(0, PYTHONDIR)


def success():
    test_case = getattr(__main__, 'TEST_CASE', '?')
    print >>sys.stderr, "SUCCESS: %s: %s" % (
        TEST, test_case)
    os._exit(0)

def failure(msg='', code=1):
    test_case = getattr(__main__, 'TEST_CASE', '?')
    print >>sys.stderr, "***FAIL: %s: %s%s" % (
        TEST, test_case, msg and ': ' + msg or '')
    os._exit(code)

def interrupted(code=1):
    test_case = getattr(__main__, 'TEST_CASE', '?')
    print >>sys.stderr, "***INTERRUPTED: %s: %s" % (
        TEST, test_case)
    os._exit(code)

def skip(msg=''):
    test_case = getattr(__main__, 'TEST_CASE', '?')
    print >>sys.stderr, "---SKIP: %s: %s%s" % (
        TEST, test_case, msg and ': ' + msg or '')
    os._exit(0)


@atexit.register
def cleanup(*args):
    if not keeptest:
        os.chdir(tmpdir)
        shutil.rmtree(tstdir)
    if not args:         # normal exit
        success()
    elif len(args) == 1: # sys.exit, exit
        code = int(args[0])
        success() if code == 0 else failure(code=code)
    elif len(args) == 2: # signal catched
        interrupted(int(args[0]))
    elif len(args) == 3: # exception
        excname = traceback.format_exception_only(
            args[0], args[1])[-1].strip()
        traceback.print_exception(*args)
        failure(excname)
    else:                # unknown
        failure(msg='unknown')
    assert 0


# override exit functions and uncatched exceptions hook
sys.exit = __builtin__.exit = sys.excepthook = cleanup

# register for catcheable signals
signal.signal(signal.SIGINT, cleanup)
signal.signal(signal.SIGQUIT, cleanup)
signal.signal(signal.SIGTERM, cleanup)

# create and go to new tmp directory
tmpdir = os.getenv('TMPDIR', '/tmp')
keeptest = os.getenv('KEEPTEST', False)
if keeptest:
    tstdir = TEST + '.dir'
    shutil.rmtree(tstdir, ignore_errors=True)
    os.makedirs(tstdir)
    print "Keeping test directory in:", tstdir
else:
    tstdir = tempfile.mkdtemp(prefix='atos-test.', dir=tmpdir)
os.chdir(tstdir)


# ##########################################################
#
#

def atos_setup_args(**kwargs):
    import argparse
    import atos.logger
    import atos.process
    import atos.utils
    # set environment variables
    for key, value in kwargs.items():
        if value is None: continue
        os.putenv(str(key), str(value))
    # allows to call 'invoque' function from toplevel
    atos.logger.setup({})
    atos.process.setup({})
    atos.utils._at_toplevel = True
    args = argparse.Namespace()
    args.dryrun = atos.process._dryrun
    return args

def atos_log_name(prefix="run", configuration_path="atos-configurations",
                  options=None, gopts=None, uopts=None, variant=None):
    import atos.atos_lib
    logdir = os.path.join(configuration_path, "logs")
    variant = variant or atos.atos_lib.variant_id(options, gopts, uopts)
    return os.path.join(logdir, "%s-%s.log" % (
            prefix, str(atos.atos_lib.hashid(variant))))

def atos_results(query=None, configuration_path="atos-configurations"):
    import atos.atos_lib
    return atos.atos_lib.atos_db.db(configuration_path).get_results(query)

def grep(log, *args):
    import re
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
