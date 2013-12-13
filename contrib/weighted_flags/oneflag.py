#!/usr/bin/env python

# cd <bench_dir>
# Edit file "atos-init.sh" that calls "atos-init -C $1 ..."
# chmod +x atos-init.sh
# Usage <path>/oneflag.py -C <atos_conf_dir>

import sys, os, shutil, commands, subprocess, time

import pdb

atos_graph_bin = commands.getoutput("which atos-graph")
assert atos_graph_bin, "ATOS tools not found in $$PATH"

bin_dir = os.path.dirname(atos_graph_bin)
lib_dir = os.path.abspath(os.path.join(
      bin_dir, '..', 'lib', 'atos', 'python'))
sys.path.append(lib_dir)

from atoslib import atos_lib

######################## GCC OPTIONS FOR 4.6.2 ########################

def get_gcc_version():

    out_cmd = subprocess.Popen(['gcc', '--version'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    out_lines = out_cmd.communicate()[0].split('\n')
    return out_lines[0].split()[-1]

def init_gcc_flags(gcc_version):

    print 'Initializing GCC default flags for gcc %s' % gcc_version

    global opt_level_defaults, fno_init

    O0_defaults = ['-fasynchronous-unwind-tables', '-fbranch-count-reg', '-fcommon', '-fdce', '-fdelete-null-pointer-checks', '-fdse', '-fearly-inlining', '-fgcse-lm', '-finline-functions-called-once', '-fivopts', '-fjump-tables', '-fmath-errno', '-fmove-loop-invariants', '-fno-threadsafe-statics', '-fpeephole', '-fprefetch-loop-arrays', '-frename-registers', '-frtti', '-fsched-critical-path-heuristic', '-fsched-dep-count-heuristic', '-fsched-group-heuristic', '-fsched-interblock', '-fsched-last-insn-heuristic', '-fsched-rank-heuristic', '-fsched-spec', '-fsched-spec-insn-heuristic', '-fsched-stalled-insns-dep', '-fshort-enums', '-fsigned-zeros', '-fsplit-ivs-in-unroller', '-ftoplevel-reorder', '-ftrapping-math', '-ftree-cselim', '-ftree-forwprop', '-ftree-loop-if-convert', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-loop-optimize', '-ftree-phiprop', '-ftree-pta', '-ftree-reassoc', '-ftree-scev-cprop', '-ftree-slp-vectorize', '-ftree-vect-loop-version', '-funit-at-a-time', '-fvar-tracking', '-fvar-tracking-assignments', '-fvect-cost-model', '-fweb']

    if gcc_version == '4.7.2':
        O0_defaults.remove('-finline-functions-called-once')
        O0_defaults.append('-finline-atomics')

    O1_defaults = ['-fasynchronous-unwind-tables', '-fbranch-count-reg', '-fcombine-stack-adjustments', '-fcommon', '-fcompare-elim', '-fcprop-registers', '-fdce', '-fdefer-pop', '-fdelete-null-pointer-checks', '-fdse', '-fearly-inlining', '-fforward-propagate', '-fgcse-lm', '-fguess-branch-probability', '-fif-conversion', '-fif-conversion2', '-finline-functions-called-once', '-fipa-profile', '-fipa-pure-const', '-fipa-reference', '-fivopts', '-fjump-tables', '-fmath-errno', '-fmerge-constants', '-fmove-loop-invariants', '-fno-threadsafe-statics', '-fpeephole', '-fprefetch-loop-arrays', '-frename-registers', '-frtti', '-fsched-critical-path-heuristic', '-fsched-dep-count-heuristic', '-fsched-group-heuristic', '-fsched-interblock', '-fsched-last-insn-heuristic', '-fsched-rank-heuristic', '-fsched-spec', '-fsched-spec-insn-heuristic', '-fsched-stalled-insns-dep', '-fshort-enums', '-fsigned-zeros', '-fsplit-ivs-in-unroller', '-fsplit-wide-types', '-ftoplevel-reorder', '-ftrapping-math', '-ftree-bit-ccp', '-ftree-ccp', '-ftree-ch', '-ftree-copy-prop', '-ftree-copyrename', '-ftree-cselim', '-ftree-dce', '-ftree-dominator-opts', '-ftree-dse', '-ftree-forwprop', '-ftree-fre', '-ftree-loop-if-convert', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-loop-optimize', '-ftree-phiprop', '-ftree-pta', '-ftree-reassoc', '-ftree-scev-cprop', '-ftree-sink', '-ftree-slp-vectorize', '-ftree-sra', '-ftree-ter', '-ftree-vect-loop-version', '-funit-at-a-time', '-fvar-tracking', '-fvar-tracking-assignments', '-fvect-cost-model', '-fweb',
               '-fdelayed-branch']

    if gcc_version == '4.7.2':
        O1_defaults.append('-finline-atomics')
        O1_defaults.append('-fshrink-wrap')

    O2_defaults = ['-falign-functions', '-falign-jumps', '-falign-labels', '-falign-loops', '-fasynchronous-unwind-tables', '-fbranch-count-reg', '-fcaller-saves', '-fcombine-stack-adjustments', '-fcommon', '-fcompare-elim', '-fcprop-registers', '-fcrossjumping', '-fcse-follow-jumps', '-fdce', '-fdefer-pop', '-fdelete-null-pointer-checks', '-fdevirtualize', '-fdse', '-fearly-inlining', '-fexpensive-optimizations', '-fforward-propagate', '-fgcse', '-fgcse-lm', '-fguess-branch-probability', '-fif-conversion', '-fif-conversion2', '-finline-functions-called-once', '-finline-small-functions', '-fipa-cp', '-fipa-profile', '-fipa-pure-const', '-fipa-reference', '-fipa-sra', '-fivopts', '-fjump-tables', '-fmath-errno', '-fmerge-constants', '-fmove-loop-invariants', '-fno-threadsafe-statics', '-foptimize-register-move', '-foptimize-sibling-calls', '-fpeephole', '-fpeephole2', '-fprefetch-loop-arrays', '-fregmove', '-frename-registers', '-freorder-blocks', '-freorder-functions', '-frerun-cse-after-loop', '-frtti', '-fsched-critical-path-heuristic', '-fsched-dep-count-heuristic', '-fsched-group-heuristic', '-fsched-interblock', '-fsched-last-insn-heuristic', '-fsched-rank-heuristic', '-fsched-spec', '-fsched-spec-insn-heuristic', '-fsched-stalled-insns-dep', '-fschedule-insns2', '-fshort-enums', '-fsigned-zeros', '-fsplit-ivs-in-unroller', '-fsplit-wide-types', '-fstrict-aliasing', '-fthread-jumps', '-ftoplevel-reorder', '-ftrapping-math', '-ftree-bit-ccp', '-ftree-builtin-call-dce', '-ftree-ccp', '-ftree-ch', '-ftree-copy-prop', '-ftree-copyrename', '-ftree-cselim', '-ftree-dce', '-ftree-dominator-opts', '-ftree-dse', '-ftree-forwprop', '-ftree-fre', '-ftree-loop-if-convert', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-loop-optimize', '-ftree-phiprop', '-ftree-pre', '-ftree-pta', '-ftree-reassoc', '-ftree-scev-cprop', '-ftree-sink', '-ftree-slp-vectorize', '-ftree-sra', '-ftree-switch-conversion', '-ftree-ter', '-ftree-vect-loop-version', '-ftree-vrp', '-funit-at-a-time', '-fvar-tracking', '-fvar-tracking-assignments', '-fvect-cost-model', '-fweb',
               '-fdelayed-branch', '-findirect-inlining', '-fpartial-inlining', '-fschedule-insns', '-fstrict-overflow']

    if gcc_version == '4.7.2':
        O2_defaults.append('-finline-atomics')
        O2_defaults.append('-foptimize-strlen')
        O2_defaults.append('-fshrink-wrap')
        O2_defaults.append('-ftree-tail-merge')

    Os_defaults = ['-falign-functions', '-falign-jumps', '-falign-labels', '-falign-loops', '-fasynchronous-unwind-tables', '-fbranch-count-reg', '-fcaller-saves', '-fcombine-stack-adjustments', '-fcommon', '-fcompare-elim', '-fcprop-registers', '-fcrossjumping', '-fcse-follow-jumps', '-fdce', '-fdefer-pop', '-fdelete-null-pointer-checks', '-fdevirtualize', '-fdse', '-fearly-inlining', '-fexpensive-optimizations', '-fforward-propagate', '-fgcse', '-fgcse-lm', '-fguess-branch-probability', '-fif-conversion', '-fif-conversion2', '-finline-functions', '-finline-functions-called-once', '-finline-small-functions', '-fipa-cp', '-fipa-profile', '-fipa-pure-const', '-fipa-reference', '-fipa-sra', '-fivopts', '-fjump-tables', '-fmath-errno', '-fmerge-constants', '-fmove-loop-invariants', '-fno-threadsafe-statics', '-foptimize-register-move', '-foptimize-sibling-calls', '-fpeephole', '-fpeephole2', '-fprefetch-loop-arrays', '-fregmove', '-frename-registers', '-freorder-blocks', '-freorder-functions', '-frerun-cse-after-loop', '-frtti', '-fsched-critical-path-heuristic', '-fsched-dep-count-heuristic', '-fsched-group-heuristic', '-fsched-interblock', '-fsched-last-insn-heuristic', '-fsched-rank-heuristic', '-fsched-spec', '-fsched-spec-insn-heuristic', '-fsched-stalled-insns-dep', '-fschedule-insns2', '-fshort-enums', '-fsigned-zeros', '-fsplit-ivs-in-unroller', '-fsplit-wide-types', '-fstrict-aliasing', '-fthread-jumps', '-ftoplevel-reorder', '-ftrapping-math', '-ftree-bit-ccp', '-ftree-builtin-call-dce', '-ftree-ccp', '-ftree-ch', '-ftree-copy-prop', '-ftree-copyrename', '-ftree-cselim', '-ftree-dce', '-ftree-dominator-opts', '-ftree-dse', '-ftree-forwprop', '-ftree-fre', '-ftree-loop-if-convert', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-loop-optimize', '-ftree-phiprop', '-ftree-pre', '-ftree-pta', '-ftree-reassoc', '-ftree-scev-cprop', '-ftree-sink', '-ftree-slp-vectorize', '-ftree-sra', '-ftree-switch-conversion', '-ftree-ter', '-ftree-vect-loop-version', '-ftree-vrp', '-funit-at-a-time', '-fvar-tracking', '-fvar-tracking-assignments', '-fvect-cost-model', '-fweb',
               '-fdelayed-branch', '-findirect-inlining', '-fpartial-inlining', '-fstrict-overflow']

    if gcc_version == '4.7.2':
        Os_defaults.append('-finline-atomics')
        Os_defaults.append('-fshrink-wrap')
        Os_defaults.append('-ftree-tail-merge')

    O3_defaults = ['-falign-functions', '-falign-jumps', '-falign-labels', '-falign-loops', '-fasynchronous-unwind-tables', '-fbranch-count-reg', '-fcaller-saves', '-fcombine-stack-adjustments', '-fcommon', '-fcompare-elim', '-fcprop-registers', '-fcrossjumping', '-fcse-follow-jumps', '-fdce', '-fdefer-pop', '-fdelete-null-pointer-checks', '-fdevirtualize', '-fdse', '-fearly-inlining', '-fexpensive-optimizations', '-fforward-propagate', '-fgcse', '-fgcse-after-reload', '-fgcse-lm', '-fguess-branch-probability', '-fif-conversion', '-fif-conversion2', '-finline-functions', '-finline-functions-called-once', '-finline-small-functions', '-fipa-cp', '-fipa-cp-clone', '-fipa-profile', '-fipa-pure-const', '-fipa-reference', '-fipa-sra', '-fivopts', '-fjump-tables', '-fmath-errno', '-fmerge-constants', '-fmove-loop-invariants', '-fno-threadsafe-statics', '-foptimize-register-move', '-foptimize-sibling-calls', '-fpeephole', '-fpeephole2', '-fpredictive-commoning', '-fprefetch-loop-arrays', '-fregmove', '-frename-registers', '-freorder-blocks', '-freorder-functions', '-frerun-cse-after-loop', '-frtti', '-fsched-critical-path-heuristic', '-fsched-dep-count-heuristic', '-fsched-group-heuristic', '-fsched-interblock', '-fsched-last-insn-heuristic', '-fsched-rank-heuristic', '-fsched-spec', '-fsched-spec-insn-heuristic', '-fsched-stalled-insns-dep', '-fschedule-insns2', '-fshort-enums', '-fsigned-zeros', '-fsplit-ivs-in-unroller', '-fsplit-wide-types', '-fstrict-aliasing', '-fthread-jumps', '-ftoplevel-reorder', '-ftrapping-math', '-ftree-bit-ccp', '-ftree-builtin-call-dce', '-ftree-ccp', '-ftree-ch', '-ftree-copy-prop', '-ftree-copyrename', '-ftree-cselim', '-ftree-dce', '-ftree-dominator-opts', '-ftree-dse', '-ftree-forwprop', '-ftree-fre', '-ftree-loop-distribute-patterns', '-ftree-loop-if-convert', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-loop-optimize', '-ftree-phiprop', '-ftree-pre', '-ftree-pta', '-ftree-reassoc', '-ftree-scev-cprop', '-ftree-sink', '-ftree-slp-vectorize', '-ftree-sra', '-ftree-switch-conversion', '-ftree-ter', '-ftree-vect-loop-version', '-ftree-vectorize', '-ftree-vrp', '-funit-at-a-time', '-funswitch-loops', '-fvar-tracking', '-fvar-tracking-assignments', '-fvect-cost-model', '-fweb',
               '-fdelayed-branch', '-findirect-inlining', '-fpartial-inlining', '-fschedule-insns', '-fstrict-overflow']
    if gcc_version == '4.7.2':
        O3_defaults.append('-finline-atomics')
        O3_defaults.append('-foptimize-strlen')
        O3_defaults.append('-fshrink-wrap')
        O3_defaults.append('-ftree-tail-merge')

    Ofast_defaults = ['-falign-functions', '-falign-jumps', '-falign-labels', '-falign-loops', '-fasynchronous-unwind-tables', '-fbranch-count-reg', '-fcaller-saves', '-fcombine-stack-adjustments', '-fcommon', '-fcompare-elim', '-fcprop-registers', '-fcrossjumping', '-fcse-follow-jumps', '-fcx-limited-range', '-fdce', '-fdefer-pop', '-fdelete-null-pointer-checks', '-fdevirtualize', '-fdse', '-fearly-inlining', '-fexpensive-optimizations', '-ffinite-math-only', '-fforward-propagate', '-fgcse', '-fgcse-after-reload', '-fgcse-lm', '-fguess-branch-probability', '-fif-conversion', '-fif-conversion2', '-finline-functions', '-finline-functions-called-once', '-finline-small-functions', '-fipa-cp', '-fipa-cp-clone', '-fipa-profile', '-fipa-pure-const', '-fipa-reference', '-fipa-sra', '-fivopts', '-fjump-tables', '-fmerge-constants', '-fmove-loop-invariants', '-fno-threadsafe-statics', '-foptimize-register-move', '-foptimize-sibling-calls', '-fpeephole', '-fpeephole2', '-fpredictive-commoning', '-fprefetch-loop-arrays', '-fregmove', '-frename-registers', '-freorder-blocks', '-freorder-functions', '-frerun-cse-after-loop', '-frtti', '-fsched-critical-path-heuristic', '-fsched-dep-count-heuristic', '-fsched-group-heuristic', '-fsched-interblock', '-fsched-last-insn-heuristic', '-fsched-rank-heuristic', '-fsched-spec', '-fsched-spec-insn-heuristic', '-fsched-stalled-insns-dep', '-fschedule-insns2', '-fshort-enums', '-fsplit-ivs-in-unroller', '-fsplit-wide-types', '-fstrict-aliasing', '-fthread-jumps', '-ftoplevel-reorder', '-ftree-bit-ccp', '-ftree-builtin-call-dce', '-ftree-ccp', '-ftree-ch', '-ftree-copy-prop', '-ftree-copyrename', '-ftree-cselim', '-ftree-dce', '-ftree-dominator-opts', '-ftree-dse', '-ftree-forwprop', '-ftree-fre', '-ftree-loop-distribute-patterns', '-ftree-loop-if-convert', '-ftree-loop-im', '-ftree-loop-ivcanon', '-ftree-loop-optimize', '-ftree-phiprop', '-ftree-pre', '-ftree-pta', '-ftree-reassoc', '-ftree-scev-cprop', '-ftree-sink', '-ftree-slp-vectorize', '-ftree-sra', '-ftree-switch-conversion', '-ftree-ter', '-ftree-vect-loop-version', '-ftree-vectorize', '-ftree-vrp', '-funit-at-a-time', '-funsafe-math-optimizations', '-funswitch-loops', '-fvar-tracking', '-fvar-tracking-assignments', '-fvect-cost-model', '-fweb',
                  '-fdelayed-branch', '-ffast-math', '-findirect-inlining', '-fpartial-inlining', '-fschedule-insns', '-fstrict-overflow']

    if gcc_version == '4.7.2':
        Ofast_defaults.append('-finline-atomics')
        Ofast_defaults.append('-foptimize-strlen')
        Ofast_defaults.append('-fshrink-wrap')
        Ofast_defaults.append('-ftree-tail-merge')

    fno_init = ['-fno-align-functions', '-fno-align-jumps', '-fno-align-labels', '-fno-align-loops', '-fno-asynchronous-unwind-tables', '-fno-branch-count-reg', '-fno-branch-probabilities', '-fno-branch-target-load-optimize', '-fno-branch-target-load-optimize2', '-fno-btr-bb-exclusive', '-fno-caller-saves', '-fno-combine-stack-adjustments', '-fno-common', '-fno-compare-elim', '-fno-conserve-stack', '-fno-cprop-registers', '-fno-crossjumping', '-fno-cse-follow-jumps', '-fno-cx-fortran-rules', '-fno-cx-limited-range', '-fno-data-sections', '-fno-dce', '-fno-defer-pop', '-fno-delayed-branch', '-fno-delete-null-pointer-checks', '-fno-devirtualize', '-fno-dse', '-fno-early-inlining', '-fno-exceptions', '-fno-expensive-optimizations', '-fno-finite-math-only', '-fno-float-store', '-fno-forward-propagate', '-fno-gcse', '-fno-gcse-after-reload', '-fno-gcse-las', '-fno-gcse-lm', '-fno-gcse-sm', '-fno-graphite-identity', '-fno-guess-branch-probability', '-fno-handle-exceptions', '-fno-if-conversion', '-fno-if-conversion2', '-fno-inline-functions', '-fno-inline-functions-called-once', '-fno-inline-small-functions', '-fno-ipa-cp', '-fno-ipa-cp-clone', '-fno-ipa-matrix-reorg', '-fno-ipa-profile', '-fno-ipa-pta', '-fno-ipa-pure-const', '-fno-ipa-reference', '-fno-ipa-sra', '-fno-ivopts', '-fno-jump-tables', '-fno-loop-block', '-fno-loop-flatten', '-fno-loop-interchange', '-fno-loop-parallelize-all', '-fno-loop-strip-mine', '-fno-lto-report', '-fno-ltrans', '-fno-math-errno', '-fno-merge-all-constants', '-fno-merge-constants', '-fno-modulo-sched', '-fno-move-loop-invariants', '-fno-threadsafe-statics', '-fno-non-call-exceptions', '-fno-nothrow-opt', '-fno-omit-frame-pointer', '-fno-optimize-register-move', '-fno-optimize-sibling-calls', '-fno-pack-struct', '-fno-pack-struct', '-fno-peel-loops', '-fno-peephole', '-fno-peephole2', '-fno-predictive-commoning', '-fno-prefetch-loop-arrays', '-fno-reg-struct-return', '-fno-regmove', '-fno-rename-registers', '-fno-reorder-blocks', '-fno-reorder-blocks-and-partition', '-fno-reorder-functions', '-fno-rerun-cse-after-loop', '-fno-reschedule-modulo-scheduled-loops', '-fno-rounding-math', '-fno-rtti', '-fno-sched-critical-path-heuristic', '-fno-sched-dep-count-heuristic', '-fno-sched-group-heuristic', '-fno-sched-interblock', '-fno-sched-last-insn-heuristic', '-fno-sched-pressure', '-fno-sched-rank-heuristic', '-fno-sched-spec', '-fno-sched-spec-insn-heuristic', '-fno-sched-spec-load', '-fno-sched-spec-load-dangerous', '-fno-sched-stalled-insns', '-fno-sched-stalled-insns-dep', '-fno-sched2-use-superblocks', '-fno-schedule-insns', '-fno-schedule-insns2', '-fno-section-anchors', '-fno-sel-sched-pipelining', '-fno-sel-sched-pipelining-outer-loops', '-fno-sel-sched-reschedule-pipelined', '-fno-selective-scheduling', '-fno-selective-scheduling2', '-fno-short-double', '-fno-short-enums', '-fno-short-wchar', '-fno-signaling-nans', '-fno-signed-zeros', '-fno-single-precision-constant', '-fno-split-ivs-in-unroller', '-fno-split-wide-types', '-fno-strict-aliasing', '-fno-strict-enums', '-fno-thread-jumps', '-fno-toplevel-reorder', '-fno-trapping-math', '-fno-trapv', '-fno-tree-bit-ccp', '-fno-tree-builtin-call-dce', '-fno-tree-ccp', '-fno-tree-ch', '-fno-tree-copy-prop', '-fno-tree-copyrename', '-fno-tree-cselim', '-fno-tree-dce', '-fno-tree-dominator-opts', '-fno-tree-dse', '-fno-tree-forwprop', '-fno-tree-fre', '-fno-tree-loop-distribute-patterns', '-fno-tree-loop-distribution', '-fno-tree-loop-if-convert', '-fno-tree-loop-if-convert-stores', '-fno-tree-loop-im', '-fno-tree-loop-ivcanon', '-fno-tree-loop-optimize', '-fno-tree-lrs', '-fno-tree-phiprop', '-fno-tree-pre', '-fno-tree-pta', '-fno-tree-reassoc', '-fno-tree-scev-cprop', '-fno-tree-sink', '-fno-tree-slp-vectorize', '-fno-tree-sra', '-fno-tree-switch-conversion', '-fno-tree-ter', '-fno-tree-vect-loop-version', '-fno-tree-vectorize', '-fno-tree-vrp', '-fno-unit-at-a-time', '-fno-unroll-all-loops', '-fno-unroll-loops', '-fno-unsafe-loop-optimizations', '-fno-unsafe-math-optimizations', '-fno-unswitch-loops', '-fno-unwind-tables', '-fno-var-tracking', '-fno-var-tracking-assignments', '-fno-var-tracking-assignments-toggle', '-fno-var-tracking-uninit', '-fno-variable-expansion-in-unroller', '-fno-vect-cost-model', '-fno-vpt', '-fno-web', '-fno-whole-program', '-fno-wpa', '-fno-wrapv',
            '-fno-indirect-inlining', '-fno-partial-inlining', '-fno-strict-overflow', '-fno-fast-math',
            '-fno-reciprocal-math', '-fno-ira-share-save-slots', '-fno-auto-inc-dec', '-fno-tracer', '-fno-ira-loop-pressure', '-fno-function-sections', '-fno-function-cse', '-fno-ira-share-spill-slots']


    if gcc_version == '4.7.2':
        fno_init.remove('-fno-lto-report')
        fno_init.remove('-fno-ltrans')
        fno_init.remove('-fno-wpa')
        Ofast_defaults.append('-fno-inline-atomics')
        Ofast_defaults.append('-fno-optimize-strlen')
        Ofast_defaults.append('-fno-shrink-wrap')
        Ofast_defaults.append('-fno-tree-tail-merge')

    opt_level_defaults={'-O0':O0_defaults, '-O1':O1_defaults, '-O2':O2_defaults,
                        '-Os':Os_defaults, '-O3':O3_defaults, '-Ofast':Ofast_defaults}


# SUPPORT FOR ACF OPTS

# def read_acf_lines(acf_filename):

#     acf_opts = {}
#     with open(acf_filename, 'r') as acf_file:
#         for line in acf_file:
#             split_line = line.rstrip().split(',')
#             func, file, opt, value = split_line[0:4]
#             if len(file) > 0 : func = os.path.join(file, func)

#             if opt == 'optimize':
#                 if value.isdigit() or value == 's' or value == 'fast':
#                     flag = '-O'+value
#                 elif value[0] == 'O':
#                     flag = '-'+value
#                 else:
#                     flag = '-f'+value
#             elif opt == 'param' and \
#                     len(split_line) == 5 and \
#                     split_line[4][0] == '#' and \
#                     split_line[4][1:].isdigit():
#                 # Only '--param X=#n' is supported
#                 flag = '--param '+value+'='+split_line[4][1:]
#             else:
#                 # Flag not recognized
#                 continue

#             if func not in acf_opts:
#                 acf_opts[func] = flag
#             else:
#                 acf_opts[func] += ' '+flag

#     return [k+','+v for k,v in acf_opts.items()]

# END SUPPORT FOR ACF OPTS

def toggle_option(option):
    if option.startswith('-fno-'):
        return '-f'+option[5:]
    elif option.startswith('-f'):
        return '-fno-'+option[2:]
    else:
        return None

def get_base_option(option):
    if option.startswith('-O'):
        return '-O'
    if option.startswith('-fno-'):
        option = '-f'+option[5:]
    eqidx = option.find('=')
    if eqidx != -1:
        option = option[:eqidx+1]
    return option

def get_opt_level(rev_option_list, default_level):

    for option in rev_option_list:
        if get_base_option(option) == '-O':
            if option == '-O':
                return '-O1'
            else:
                return option

    return default_level

def normalize_option_str(option_str, option_dict, default_opt_level = '-O0'):

    if len(option_str) == 0:
        return ''

    flags_str = option_str.replace('--param ', '--p') \
        .replace('--atos-optfile ', '--atos-optfile=')

    rev_flag_list = flags_str.split(' ')
    rev_flag_list.reverse()
    opt_level = get_opt_level(rev_flag_list, default_opt_level)
    rev_flag_list.extend(opt_level_defaults[opt_level])
    rev_flag_list.extend(fno_init)

    option_dict['-O'] = opt_level
    for option in rev_flag_list:
        if option == '': continue
        base_opt = get_base_option(option)
        if base_opt not in option_dict:
            option_dict[base_opt] = option

    return flags_str

#SUPPORT FOR ACF OPTS

# def parse_name_opt_lines(lines, global_str, local_flags):

#     for line in lines:
#         line = line.rstrip()
#         name, flags = line.split(',')
#         assert(name not in local_flags)
#         local_flags[name] = {}
#         normalize_option_str(global_str+' '+flags, local_flags[name])

# END SUPPORT FOR ACF OPTS

# Returns a dictionnary of dictionaries of options.
# Key '*' contains a dictionary of option on the command line
# Other keys are for file or function level options

# Each second level dictionary contains base options as keys and
# actual option as value. For example
# '-O': -O2
# '-funroll-all-loops': '-fno-unroll-all-loops'
# '-fira-algorithm=': '-fira-algorithm=priority'
# '--pmin-spec-prob=': '--pmin-spec-prob=10'

def canonicalize_option_str(cmdline_str):

# SUPPORT FOR ACF OPTS
#    obj_file_flag = '--atos-optfile'
#    acf_file_flag = '-fplugin-arg-acf_plugin-csv_file'
# END SUPPORT FOR ACF OPTS

    # Analyse command line options, create a dictionary of {base_opt:opt}
    global_flags = {}
    global_str = normalize_option_str(cmdline_str, global_flags, cmdline_str.split()[0])

    all_flags = {}

# SUPPORT FOR ACF OPTS

#     if obj_file_flag in global_flags:
#         obj_fileopt = global_flags[obj_file_flag]
#         obj_filename = obj_fileopt[len(obj_file_flag+'='):]

#         del global_flags[obj_file_flag]
#         global_str = global_str.replace(obj_fileopt, '')

#         with open(obj_filename, 'r') as opt_file:
#             obj_lines = opt_file.readlines()

#         parse_name_opt_lines(obj_lines, global_str, all_flags)

#     if acf_file_flag in global_flags:
#         acf_fileopt = global_flags[acf_file_flag]
#         acf_filename = acf_fileopt[len(acf_file_flag+'='):]

#         del global_flags[acf_file_flag]
#         global_str = global_str.replace(acf_fileopt, '')

#         if acf_filename[0] != '/':
#             acf_filename = '/work1/knochelh/HEVC/script/' + acf_filename # TBD: Use basepath ????

#         acf_lines = read_acf_lines(acf_filename)
#         parse_name_opt_lines(acf_lines, global_str, all_flags)

# END SUPPORT FOR ACF OPTS

    if '*' not in all_flags:
        all_flags['*'] = global_flags

    return all_flags

def output_flags_ranking(opts, atos_config, base_level, do_fdo, do_lto):

    BASEvariant='OPT'
    if do_fdo: BASEvariant+='-fprofile-use'+base_level
    BASEvariant+=base_level
    if do_lto: BASEvariant+='-flto'

    all_results = atos_lib.get_results(
        atos_config, atos_lib.default_obj(refid=BASEvariant))

    # First, look for the REF in the list of results
    REFres = all_results[0]
    if REFres.variant != 'REF':
        print 'ERROR: REF variant not found'
        exit (1)
    all_results.pop(0)

    # Then, look for the BASE variant
    BASEres = all_results[0]
    if BASEres.variant != BASEvariant:
        print 'ERROR: BASE variant not found'
        exit (1)
    all_results.pop(0)
    
    flags_weight = {}
    based_options = set(canonicalize_option_str(base_level)['*'].values())
    if do_lto: based_options.add('-flto')

    for result in all_results:
        option_str = result.dict()['conf']

        # Normalize the option set :
        # -> Replace -O options with default flags
        # -> Scan the option from right to left and ignore options and params that have alreay been seen

        parsed_options = canonicalize_option_str(option_str)
        diff_flags = set(parsed_options['*'].values()).difference(based_options)

        if len(diff_flags) != 1:
            print 'ERROR with', diff_flags
            exit (1)

        one_flag = diff_flags.pop()

        if opts.tradeoffs:
            weight = (opts.tradeoffs * result.speedup) + result.sizered
        else:
            weight = result.speedup

        if one_flag.startswith('-fno-'):
            one_flag = toggle_option(one_flag)
            weight = -weight

        flags_weight[one_flag] = weight

    rank_file = open(atos_config+'.rank', 'w')
    for rank, opt in enumerate(sorted(flags_weight.items(), key=lambda x: x[1], reverse=True )):
        rank_file.write('#%-3d %-35s % 6.2f\n' % (rank, opt[0], opt[1]*100))
    rank_file.close()

def do_flag_ranking(opts, base_level, do_fdo, do_lto):

    fdo_opt = '-f' if do_fdo else ''
    lto_opt = '-l' if do_lto else ''
    atos_config_dir = '%s%s%s%s' % (opts.config_path, base_level, fdo_opt, lto_opt)

    sh_name = './_temp.sh'
    sh_file = open(sh_name, 'w')

    sh_file.write("#!/bin/bash\n\n")
    sh_file.write("rm -rf %s\n\n" % atos_config_dir)
    sh_file.write("atos-init.sh %s \n\n" % atos_config_dir)    

    # Generate the BASE variant
    sh_file.write("atos opt -C %s -a \"%s\" %s %s -r\n\n" % (atos_config_dir, base_level, fdo_opt, lto_opt))

    base_flags = []
    base_flags.extend(opt_level_defaults[base_level])
    base_flags.extend(fno_init)

    # Only consider the first occurence of an option
    option_set = set()
    for option in base_flags:
        base_opt = get_base_option(option)
        if base_opt not in option_set:
            option_set.add(base_opt)
            sh_file.write("atos opt -C %s -a \"%s %s\" %s %s -r\n" %
                          (atos_config_dir, base_level, toggle_option(option), fdo_opt, lto_opt))

    sh_file.close()

    subprocess.check_call(['chmod', 'u+x', sh_name])
    subprocess.check_call([sh_name])

    output_flags_ranking(opts, atos_config_dir, base_level, do_fdo, do_lto)

    os.remove(sh_name)
    shutil.rmtree(atos_config_dir)

if __name__ == "__main__":

    import optparse
    parser = optparse.OptionParser(
        description='Flag profitability from exploration results')
    parser.add_option(
        '-C', dest='config_path',
        action='store', type='string', default='atos-configurations-ranking',
        help='atos configuration working directory')
    parser.add_option(
        '-s', dest="tradeoffs",
        action='store', type=float, default=None,
        help="selected tradeoff given size/perf ratio")
    (opts, args) = parser.parse_args()

    gcc_version = get_gcc_version()
    if gcc_version:
        major, minor, plevel = gcc_version.split('.')
    if not (gcc_version and major.isdigit() and minor.isdigit() and plevel.isdigit()):
        print 'ERROR: Could not determine gcc version. Abort'
        exit (1)

    if not os.path.isfile('atos-init.sh'):
        print 'ERROR: Please provide an \"atos-init.sh <conf_dir>\" shell script ' \
            'that calls \"atos-init -C $1 ...\". Abort'
        exit (1)

    init_gcc_flags(gcc_version)


    do_flag_ranking(opts, '-O2', False, False)
    do_flag_ranking(opts, '-O2', True, False)
    do_flag_ranking(opts, '-O2', False, True)
    do_flag_ranking(opts, '-O2', True, True)

    do_flag_ranking(opts, '-O3', False, False)
    do_flag_ranking(opts, '-O3', True, False)
    do_flag_ranking(opts, '-O3', False, True)
    do_flag_ranking(opts, '-O3', True, True)

    do_flag_ranking(opts, '-Os', False, False)
    do_flag_ranking(opts, '-Os', True, False)
    do_flag_ranking(opts, '-Os', False, True)
    do_flag_ranking(opts, '-Os', True, True)
