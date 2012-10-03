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
