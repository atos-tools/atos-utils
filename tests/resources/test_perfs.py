#!/usr/bin/env python
#
#

TEST_CASE = "ATOS compare exploration results on examples"

# Usage:
#   test-perf
#       --run | --res
#       [--prog=bzip2] [--prog=sha1] [--prog=sha1-c]
#       [--expl=staged] [--expl=random] [--expl=genetic]
#       [--nbiters=10]
#       [--testdir=/home/compwork/user/atos-perfs]
#       [--version=2.0-rc2]

import os, sys, shutil, itertools, functools, glob, operator

DIRNAME = os.path.dirname(__file__)

SRCDIR = os.getenv('SRCDIR', os.path.abspath(os.path.join(DIRNAME, '..', '..')))

ROOT = os.getenv('ROOT', SRCDIR)

PYTHONDIR = os.path.join(ROOT, 'lib', 'atos', 'python')

TEST = os.path.splitext(os.path.basename(sys.argv[0]))[0]

TESTDIR = os.path.join(SRCDIR, 'test-perf.dir')

sys.path.insert(0, PYTHONDIR)

from atoslib import atos_lib, process


explorations = {
    "staged":
        "atos-explore-staged --nbiters 33",
    "random":
        "atos generator --generator=gen_explore_random --nbiters=100",
    "genetic":
        "atos-explore-genetic --nbiters=5 --generations=10"
    }


examples = {
    "sha1-c":
        {"build": "gcc -O2 -o sha1-c sha.c sha1.c", "run": "./run_qemu.sh"},
    "sha1":
        {"build": "make clean sha", "run": "./run-qemu.sh"},
    "bzip2":
        {"build": "make clean all", "run": "./run-qemu.sh"}
    }


def debug(msg):
    print >>sys.stderr, "### " + msg


def run_example(version, prog, expl, seed):
    debug("RUN prog=%s expl=%s seed=%d" % (
            prog, expl, seed))

    if not os.path.exists(TESTDIR):
        os.makedirs(TESTDIR)
    os.chdir(TESTDIR)
    prog_dir = os.path.join(TESTDIR, version, prog)
    if not os.path.exists(prog_dir):
        shutil.copytree(
            os.path.join(SRCDIR, "examples", prog), prog_dir)
    os.chdir(prog_dir)

    atos_config = os.path.join(
        prog_dir, prog + "-" + expl + "-" + str(seed))
    if os.path.exists(atos_config):
        shutil.rmtree(atos_config)

    init_command = [
        os.path.join(ROOT, "bin", "atos-init"),
        "-C", atos_config,
        "-b", examples[prog]['build'],
        "-r", examples[prog]['run']]
    status, output = process.system(
        init_command, get_output=True, output_stderr=True)
    if status:
        debug("*** failure during init: " + output)
        return status

    common_expl_flags = [
        "--optim-levels", "-O2",
        "--optim-variants", "fdo+lto",
        "--tradeoffs", "5.0"]

    expl_command = ((
            ROOT + "/bin/" + explorations[expl]).split() + [
            "-C", atos_config, "--seed", str(seed)]
                    + common_expl_flags)
    status, output = process.system(
        expl_command, get_output=True, output_stderr=True)
    if status:
        debug("*** failure during expl: " + output)
    return status


def get_results(version, prog, expl):
    debug("RES prog=%s expl=%s" % (prog, expl))

    prog_dir = os.path.join(TESTDIR, version, prog)
    if not os.path.exists(prog_dir):
        debug("*** prog dir not found " + prog_dir)
        return None

    atos_configs = glob.glob(
        os.path.join(prog_dir, prog + "-" + expl + "-*"))
    # load results from all atos_config directories
    all_results = map(lambda x: atos_lib.get_results(
            x, atos_lib.default_obj(refid='REF')), atos_configs)
    # compute result field (perf/size tradeoff) for each result
    def set_result(optcase): optcase.result = (
        optcase.speedup * 5.0 + optcase.sizered)
    filter(functools.partial(filter, set_result), all_results)

    # compute best point at each iteration of all exploration
    all_bests = []
    for optcases in all_results:
        max_optcases = []
        max_opt = len(optcases) and optcases[0] or None
        for optcase in optcases:
            if optcase.result > max_opt.result:
                max_opt = optcase
            max_optcases += [max_opt]
        all_bests.append(max_optcases)

    # compute average of best points at each iteration
    best_avg = []
    # list of list of best at each iteration
    all_bests_it = itertools.izip_longest(*all_bests)
    for mx in all_bests_it:
        if None in mx: break # one of the explorations is over
        values = map(lambda x: x.result, list(mx))
        average = sum(values) / len(values)
        optavg = atos_lib.default_obj(result=average)
        best_avg.append(optavg)

    # print old results first
    old_results = sorted(glob.glob(
        TESTDIR + "/*/" + prog + "/results-" + expl))
    for res in old_results:
        print "\n".join(open(res).readlines()),

    # output: nb_iterations, last_result, and average
    best_avg_res = map(operator.attrgetter('result'), best_avg)
    best_avg_avg = sum(best_avg_res) / len(best_avg_res)
    print "%-10s %-10s last=%.4f avg=%.4f nbiter=%d" % (
        prog, expl, best_avg_res[-1], best_avg_avg, len(best_avg_res))
    with open(os.path.join(prog_dir, "results-" + expl), "w") as res_file:
        print >>res_file, "%-10s %-10s last=%.4f avg=%.4f nbiter=%-4d [%s]" % (
            prog, expl, best_avg_res[-1], best_avg_avg, len(best_avg_res),
            version)


if __name__ == "__main__":

    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--run', dest='run', action='store_true',
        help='run explorations')
    parser.add_argument(
        '--res', dest='res', action='store_true',
        help='get explorations results')
    parser.add_argument(
        '--graph', dest='graph', action='store_true',
        help='graph explorations results')
    parser.add_argument(
        '--prog', dest='progs', action='append',
        help='default: ' + str(examples.keys()))
    parser.add_argument(
        '--expl', dest='expls', action='append',
        help='default: ' + str(explorations.keys()))
    parser.add_argument(
        '--nbiters', dest='nbiters', type=int, default=25,
        help='default: 25')
    parser.add_argument(
        '--testdir', dest='testdir', default=None)
    parser.add_argument(
        '--version', dest='version', default=None)
    args = parser.parse_args()
    args.progs = args.progs or examples.keys()
    args.expls = args.expls or explorations.keys()
    TESTDIR = args.testdir or TESTDIR
    debug("ARGS: " + str(args))

    version = args.version
    if not version:
        output = process.system(
            [os.path.join(ROOT, "bin", "atos"), "--version"],
            get_output=True, output_stderr=True, check_status=True)
        version = output.split()[-1]
    debug("VERSION: " + version)

    if args.run:
        for (seed, prog, expl) in itertools.product(
            range(args.nbiters), args.progs, args.expls):
            run_example(version, prog, expl, seed)

    if args.res:
        for (prog, expl) in itertools.product(
            args.progs, args.expls):
            get_results(version, prog, expl)

    if args.graph:
        for prog in args.progs:
            prog_dir = os.path.join(TESTDIR, version, prog)
            command = [
                "python",
                os.path.join(SRCDIR, "contrib/graphs/cmp_expl.py"),
                "--tradeoff", "5.0"
                ] + map(
                lambda expl:
                    ",".join(glob.glob(
                            os.path.join(prog_dir, prog + "-" + expl + "-*")
                            )) + ":" + expl, args.expls)
            print " ".join(command)
