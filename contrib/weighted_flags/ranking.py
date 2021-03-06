#!/usr/bin/env python

# Take several *.rank files (generated by the script oneflag.py) as
# input and do a mean of the speedups for each flag from all the
# *.rank file. Output a ranking of these flags based on these mean
# speedups.

import sys, pdb

DEBUG=0

flags_inline = ['-fearly-inlining', '-findirect-inlining', '-finline-functions', '-finline-functions-called-once', '-finline-small-functions', '-fpartial-inlining']
flags_loop   = ['-ftree-dce', '-ftree-loop-optimize', '-fivopts', '-fmove-loop-invariants', '-fpeel-loops', '-ftree-loop-distribution', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-vectorize', '-funroll-loops', '-funroll-all-loops', '-funswitch-loops', '-ftree-scev-cprop', '-fprefetch-loop-arrays', '-fexpensive-optimizations', '-frerun-cse-after-loop', '-fsplit-ivs-in-unroller', '-ftree-vect-loop-version', '-fvariable-expansion-in-unroller', '-fvect-cost-model', '-fpredictive-commoning', '-falign-loops', '-floop-block', '-floop-interchange', '-floop-strip-mine', '-fgraphite-identity', '-ftree-slp-vectorize', '-floop-flatten']
flags_optim  = ['-fauto-inc-dec', '-fdefer-pop', '-fforward-propagate', '-fomit-frame-pointer', '-foptimize-sibling-calls', '-fmerge-constants', '-fmodulo-sched', '-fmodulo-sched-allow-regmoves', '-ffunction-cse', '-fthread-jumps', '-fsplit-wide-types', '-fcse-follow-jumps', '-fcse-skip-blocks', '-fgcse', '-fgcse-lm', '-fgcse-sm', '-fgcse-las', '-fgcse-after-reload', '-fcrossjumping', '-fdce', '-fdse', '-fif-conversion', '-fif-conversion2', '-fregmove', '-fira-share-save-slots', '-fira-share-spill-slots', '-fdelayed-branch', '-fschedule-insns', '-fschedule-insns2', '-fsched-interblock', '-fsched-spec', '-fsched-spec-load', '-fsched-spec-load-dangerous', '-fsched-stalled-insns', '-fsched-stalled-insns-dep', '-fsched2-use-superblocks', '-freschedule-modulo-scheduled-loops', '-fselective-scheduling', '-fselective-scheduling2', '-fsel-sched-pipelining', '-fsel-sched-pipelining-outer-loops', '-fcaller-saves', '-fconserve-stack', '-ftree-reassoc', '-ftree-pre', '-ftree-fre', '-ftree-copy-prop', '-fipa-pure-const', '-fipa-reference', '-fipa-struct-reorg', '-fipa-pta', '-fipa-cp', '-fipa-cp-clone', '-fipa-matrix-reorg', '-ftree-sink', '-ftree-ccp', '-ftree-switch-conversion', '-ftree-builtin-call-dce', '-ftree-dominator-opts', '-ftree-dse', '-ftree-ch', '-ftree-sra', '-ftree-copyrename', '-ftree-ter', '-ftree-vrp', '-ftracer', '-fpeephole', '-fpeephole2', '-fguess-branch-probability', '-freorder-blocks', '-freorder-functions', '-falign-functions', '-falign-labels', '-falign-jumps', '-ftoplevel-reorder', '-fweb', '-fcprop-registers', '-ffloat-store', '-freciprocal-math', '-fsingle-precision-constant', '-frename-registers', '-ffunction-sections', '-fdata-sections', '-fbranch-target-load-optimize', '-fbranch-target-load-optimize2', '-fbtr-bb-exclusive', '-fipa-sra', '-fira-loop-pressure', '-fsched-pressure', '-fsched-group-heuristic', '-fsched-critical-path-heuristic', '-fsched-spec-insn-heuristic', '-fsched-rank-heuristic', '-fsched-last-insn-heuristic', '-fsched-dep-count-heuristic', '-ftree-pta', '-ftree-phiprop', '-fdevirtualize', '-fcombine-stack-adjustments', '-ftree-forwprop', '-fipa-profile', '-ftree-bit-ccp', '-ftree-loop-if-convert', '-ftree-loop-distribute-patterns', '-fcompare-elim', '-freorder-blocks-and-partition', '-fassociative-math', '-fmerge-all-constants', '-fstrict-aliasing', '-fstrict-overflow', '-ffast-math', '-fcx-limited-range', '-fmath-errno', '-funsafe-math-optimizations', '-ffinite-math-only', '-fsigned-zeros', '-ftrapping-math', '-funsafe-loop-optimizations', '-ftree-loop-if-convert-stores']

class flag_weight():
    def __init__(self, rank, weight):
        self.weight = float(weight)
        self.rank = int(rank)
        self.all_ranks=[rank]
        self.count = 1

    def add(self, wflag):
        self.weight += wflag.weight
        self.rank += wflag.rank
        self.all_ranks.append(wflag.rank)
        self.count += wflag.count
        assert (self.count == len(self.all_ranks)), 'Incorrect count value'

def read_flag_weight(filename):
    with open(filename, 'r') as file:
        for line in file:
            rank, flag, weight = line.rstrip().split()
            if float(weight) > 50 or float(weight) < -50:
                print >> sys.stderr, 'DISCARD: In file %s, speedup for flag %s is %s' % (filename, flag, weight)
                continue
            rank = rank[1:]
            wflag = flag_weight(rank, weight)

            if wflag.weight >= 2.0:
                if flag not in best_flags:
                    best_flags[flag] = wflag.weight
                elif best_flags[flag] < wflag.weight:
                    best_flags[flag] = wflag.weight
            elif wflag.weight <= -2.0:
                if flag not in worst_flags:
                    worst_flags[flag] = wflag.weight
                elif worst_flags[flag] > wflag.weight:
                    worst_flags[flag] = wflag.weight

            if not flag in flags_weight:
                flags_weight[flag] = wflag
            else:
                flags_weight[flag].add(wflag)

def print_ranking(rank_label, begin_line, flag_list):

    if len(flag_list):
        line = rank_label+' '+begin_line
        sep=' '
        for e in flag_list:
            line=line+sep+e
            sep=', '
        print line
        return 1
    return 0

def print_flag(flag, meanw):
    print '%-35s% 6.2f' % (flag, mw),
    if flag in best_flags:
        print '(% 6.2f)' % best_flags[flag],
    else:
        print '()',

    if flag in worst_flags:
        print '(% 6.2f)' % worst_flags[flag],
    else:
        print '()',

    print
    

if __name__ == "__main__":

    flags_weight = {}
    best_flags = {}
    worst_flags = {}

    rank_label = sys.argv[1]
    cfg_file = sys.argv[2]

    for rank_file in sys.argv[3:]:
        read_flag_weight(rank_file)

    best_inline = []
    best_loop = []
    best_optim = []
    worst_inline = []
    worst_loop = []
    worst_optim = []

    # Best  : ((mean >= 0.5%) && ((best >= 2%) || (mean >= 1.0%))) && (worst > -2%)
    if DEBUG:
        print "BEST"
    for rank, opt in enumerate(sorted(flags_weight.items(), key=lambda x: float(x[1].weight)/x[1].count, reverse=True )):
        flag = opt[0]
        mw = opt[1].weight/opt[1].count
        if mw < 0.5:
            break
        if flag in worst_flags:
            continue
        if not (flag in best_flags or mw >= 1.0):
                continue

        if DEBUG:
            print_flag(flag, mw)

        if flag in flags_inline:
            best_inline.append(flag)
        elif flag in flags_loop:
            best_loop.append(flag)
        elif flag in flags_optim:
            best_optim.append(flag)
        else:
            print >> sys.stderr, "WARNING: flag %s not found in any cfg file !" % flag

    # Worst  : ((mean <= -0.5%) && ((worst <= -2%) || (mean <= -1.0%))) && (best < 2%)
    if DEBUG:
        print "WORST"
    for rank, opt in enumerate(sorted(flags_weight.items(), key=lambda x: float(x[1].weight)/x[1].count, reverse=False )):
        flag = opt[0]
        mw = opt[1].weight/opt[1].count
        if mw > -0.5:
            break
        if flag in best_flags:
            continue
        if not (flag in worst_flags or mw <= -1.0):
            continue

        if DEBUG:
            print_flag(flag, mw)

        if flag in flags_inline:
            worst_inline.append(flag)
        elif flag in flags_loop:
            worst_loop.append(flag)
        elif flag in flags_optim:
            worst_optim.append(flag)
        else:
            print >> sys.stderr, "WARNING: flag %s not found in any cfg file !" % flag

    lines = 0
    if cfg_file == 'all' or cfg_file == 'inline':
        if cfg_file == 'all':
            print "flags.inline.cfg.in"
            print "~~~~~~~~~~~~~~~~~~~"
        lines += print_ranking(rank_label, "50% 80%", best_inline)
        lines += print_ranking(rank_label, "50% 20%", worst_inline)

    if cfg_file == 'all' or cfg_file == 'loop':
        if cfg_file == 'all':
            print "flags.loop.cfg.in"
            print "~~~~~~~~~~~~~~~~~~~"
        lines += print_ranking(rank_label, "50% 80%", best_loop)
        lines += print_ranking(rank_label, "50% 20%", worst_loop)

    if cfg_file == 'all' or cfg_file == 'optim':
        if cfg_file == 'all':
            print "flags.optim.cfg.in"
            print "~~~~~~~~~~~~~~~~~~~"
        lines += print_ranking(rank_label, "50% 80%", best_optim)
        lines += print_ranking(rank_label, "50% 20%", worst_optim)

    if lines or cfg_file == 'all': print

    if not DEBUG:
        exit (0)

    print "MEAN"

    for rank, opt in enumerate(sorted(flags_weight.items(), key=lambda x: float(x[1].weight)/x[1].count, reverse=True )):
        if (rank >= 15) and (rank <= (len(flags_weight.items())-15)): continue
        flag = opt[0]
        print '%-35s% 6.2f' % (flag, opt[1].weight/opt[1].count),
        if flag in best_flags:
            print '(% 6.2f)' % best_flags[flag],
        else:
            print '()',

        if flag in worst_flags:
            print '(% 6.2f)' % worst_flags[flag],
        else:
            print '()',

        print

    sort_best_flags = sorted(best_flags.items(), key=lambda x: x[1], reverse=True )
    sort_worst_flags = sorted(worst_flags.items(), key=lambda x: x[1], reverse=False )
    both_sets = set(best_flags.keys()).intersection(set(worst_flags.keys()))

    printed_flags = set()

    print "best"
    rank = 0
    for (flag, speed) in sort_best_flags:
        if (rank >= 20): break
        rank += 1
        if flag in printed_flags: continue
        printed_flags.add(flag)
        print '%-35s () (% 6.2f)' % (flag, speed),
        if flag in both_sets:
            print '(% 6.2f)' % worst_flags[flag]
        else:
            print '()'

    print "worst"
    rank = 0
    for (flag, speed) in sort_worst_flags:
        if (rank >= 20): break
        rank += 1
        if flag in printed_flags: continue
        printed_flags.add(flag)
        print '%-35s ()' % flag,
        if flag in both_sets:
            print '(% 6.2f)' % best_flags[flag],
        else:
            print '()',
        print '(% 6.2f)' % speed

    exit (0)


    for rank, opt in enumerate(sorted(flags_weight.items(), key=lambda x: float(x[1].weight)/x[1].count, reverse=True )):
#    for rank, opt in enumerate(sorted(flags_weight.items(), key=lambda x: float(x[1].rank)/x[1].count, reverse=False )):
        print '#%-3d %-35s % 6.2f #%-6.2f' % (rank, opt[0], opt[1].weight/opt[1].count, float(opt[1].rank)/opt[1].count)

    print '\nBEST FLAGS', len(best_flags)
#    print sorted(best_flags.items(), key=lambda x: x[1], reverse=True )
    for (flag, speed) in sorted(best_flags.items(), key=lambda x: x[1], reverse=True ):
        print '%s % 6.2f' % (flag, speed)

    print '\nWORST FLAGS', len(worst_flags)
#    print sorted(worst_flags.items(), key=lambda x: x[1], reverse=False )
    for (flag, speed) in sorted(worst_flags.items(), key=lambda x: x[1], reverse=False ):
        print '%s % 6.2f' % (flag, speed)

    print '\nIN BOTH SETS', len(set(best_flags.keys()).intersection(set(worst_flags.keys())))
    print set(best_flags.keys()).intersection(set(worst_flags.keys()))

