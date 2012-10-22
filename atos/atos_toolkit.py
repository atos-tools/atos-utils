#!/usr/bin/env python
#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License v2.0
# as published by the Free Software Foundation
#
# ATOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
#

import sys, os, itertools, re
from random import randint, sample, seed

import globals
import process
import atos_lib
import logger
import generators
from logger import debug, warning

# ####################################################################


class generator():

    optlist, optlevel, variants, baseopts = None, None, None, None
    atos_config, seed = None, None

    generators = []

    def __init__(self, func):
        self.func = func
        generator.generators += [self]

    def __call__(self, *args):
        return self.func(*args)

    def descr(self):
        option_name = '--' + self.func.func_name.replace('_', '-')
        option_narg = self.func.func_code.co_argcount
        option_help = self.func.func_doc.strip()
        option_args = option_narg and ','.join(
            self.func.func_code.co_varnames[:option_narg]).upper()
        return option_name, option_narg and 1 or 0, option_help, option_args


# ####################################################################

# Empirical iterative feedback-directed compilation plugins
#   http://ctuning.org/wiki/index.php/
#   CTools:CCC:Documentation:CCC_V2.5
#   #Empirical_iterative_feedback-directed_compilation_plugins


@generator
def gen_base():
    '''generate basic configurations'''
    for f in generator.optlevel.values():
        yield f


@generator
def gen_stdev(nbrun='10'):
    '''compute standard deviation of results'''
    debug('start stdev')
    flags, variant = '-O2', 'base'
    results = []
    for n in range(int(nbrun)):
        result = yield flags, variant
        results += [result[1]]
    debug('*** results: %s' % str(results))
    debug('*** average: %s' % str(atos_lib.average(results)))
    debug('*** stddev : %s' % str(atos_lib.standard_deviation(results)))
    debug('end stdev -> [%.1f%%]' % (atos_lib.variation_coefficient(
                results) * 100))


@generator
def gen_rnd_uniform():
    '''generate random combinations of compiler flags'''
    while True:
        flags = [generator.optlevel.rand()]
        flags += [f.rand() for f in generator.optlist.flag_list
                  if randint(0, 1)]
        yield ' '.join(flags)


@generator
def gen_rnd_fixed(seqlen='5'):
    '''generate random combinations of fixed length'''
    while True:
        flags = [generator.optlevel.rand()]
        flags += [f.rand() for f in sample(
                generator.optlist.flag_list, int(seqlen))]
        yield ' '.join(flags)


@generator
def gen_one_by_one(optlevel):
    '''try all flags one by one'''
    for flag in generator.optlist.flag_list:
        for flagval in flag.values():
            yield ' '.join([optlevel, flagval])


@generator
def gen_one_off_rnd(variantid, epsilon='0.001'):
    '''try removing flags from the configuration one by one'''
    baseflags = atos_get_result(variantid).conf.split()
    optlevel, flags = '', []
    # prepare flags list
    i, n = 0, len(baseflags)
    while i < n:
        flag = baseflags[i]
        if flag in ['--param', '-mllvm']:
            flag += ' ' + baseflags[i + 1]
            i += 1
        flags += [flag]
        i += 1
    # extract variant
    debug('gen_one_off [%s]' % variantid)
    fdo = (variantid.find('-fprofile-use') != -1)
    lto = (variantid.find('-flto') != -1)
    variant = (fdo and lto) and 'fdo+lto' or (
        fdo and 'fdo' or (lto and 'lto' or 'base'))
    # extract optlevel and remove useless options from flags
    if flags and flags[0].startswith('-O'): optlevel = flags.pop(0)
    if lto: flags.remove('-flto')
    # run initial sequence
    debug('*** running initial sequence for reference')
    orig_result = base_result = yield ' '.join([optlevel] + flags), variant
    debug('*** reference=%s' % (str(base_result)))
    # try to remove flags one by one
    curflags, removed = list(flags), []
    for flag in flags:
        debug('*** running without flag "%s"' % flag)
        testflags = list(curflags)
        testflags.remove(flag)
        result = yield ' '.join([optlevel] + testflags), variant
        debug('*** result=%s reference=%s orig-ref=%s' % (
                str(result), str(base_result), str(orig_result)))
        speedup = ((float(base_result[1]) / result[1]) - 1.0) * 100
        sizered = (1.0 - (float(result[0]) / float(base_result[0]))) * 100
        debug('*** speedup=%.2f%% sizered=%.2f%%' % (speedup, sizered))
        # compare to minimal allowed speedup (%)
        useless = not ((speedup < -float(epsilon)) or (sizered < 0))
        if useless:
            curflags.remove(flag)
            removed.append(flag)
            base_result = result
        debug('*** flag "%s" seems %s (speedup=%.2f%%, sizered=%.2f%%)' % (
                flag, useless and 'useless' or 'useful', speedup, sizered))
    debug('*** resulting list: [%s]' % ' '.join(curflags))
    debug('*** removed flags: [%s]' % ' '.join(removed))
    debug('gen_one_off [%s] -> useful=[%s] useless=[%s]' % (
            variantid, ' '.join(curflags), ' '.join(removed)))


@generator
def gen_simplf():
    '''get useful flag list from frontier points'''
    debug('gen_simplf')
    old_front_points = []
    while True:
        old_front_points_ids = [p.variant for p in old_front_points]
        cur_front_points = atos_get_result('frontier')
        new_front_points = [p for p in cur_front_points
                            if p.variant not in old_front_points_ids]
        debug('gen_simplf - new points: [%s]' % (
                ','.join([p.variant for p in new_front_points])))
        if new_front_points == []: break
        old_front_points.extend(cur_front_points)
        for p in new_front_points:
            debug('gen_simplf - point: [%s]' % (p.variant))
            generator = gen_one_off_rnd(p.variant)
            result = None
            while True:
                try: flags, variant = generator.send(result)
                except StopIteration: break
                result = yield flags, variant


# ####################################################################


def exploration_loop(generators, step=None, maxiter=None):
    for (gen_fct, gen_args) in generators:
        gen = gen_fct(*gen_args)
        result = None
        for ic in itertools.count():
            if ic == maxiter: break
            try:
                fv = gen.send(result)
            except StopIteration: break
            if isinstance(fv, tuple):
                flags, variant = fv
                result = step(flags, variant)
            else:
                flags = fv
                result = {}
                for variant in generator.variants:
                    result[variant] = step(flags, variant)


# ####################################################################


def atos_opt_get_result(variant, config, targets):
    db = atos_lib.atos_db.db(config)
    targets = (targets and targets.split(',')
               or list(set(db.get_results('$[*].target')))[-1:])
    client = atos_lib.atos_client_results(db, targets)
    if variant == 'frontier':
        return client.compute_frontier()
    return client.get_last_result(variant)


def atos_opt_get_variant_conf(variant, config, base_opts):
    db = atos_lib.atos_db.db(config)
    client = atos_lib.atos_client_db(db)
    results = client.query({'variant': variant})
    if not results: return None
    conf_opts = results[0].get('conf', ''), results[0].get('uconf', '')
    base_opts = base_opts or ['', '']
    conf_opts = map(lambda (x, y): '%s%s%s' % (x, x and ' ' or '', y),
                    zip(base_opts, conf_opts))
    return conf_opts


def atos_opt_get_frontier(config, targets, query=None):
    db = atos_lib.atos_db.db(config)
    client = atos_lib.atos_client_results(
        db, targets and atos_lib.strtolist(targets), query)
    results = client.get_results(only_frontier=True)
    return map(lambda x: x.get('variant', ''), results)


def atos_base_flags(flags, variant, baseopts):
    basemin_variant = (variant == 'basemin')
    variant = variant.replace('basemin', 'base')
    if not baseopts: return flags, variant
    variantd = {
        (0, 0, 0): variant,
        (0, 0, 1): 'lipo',
        (1, 0, 0): 'fdo',
        (0, 1, 0): 'lto',
        (1, 1, 0): 'fdo+lto'}
    base_flags, base_uflags = baseopts or ('', '')
    base_flags = base_flags + ' ' + flags
    fdo_set = base_uflags != ''
    lto_set = (base_flags.find('-flto') != -1)
    lipo_set = (base_flags.find('-fripa') != -1)
    # remove variant flags
    base_flags = base_flags.replace('-flto', '')
    base_flags = base_flags.replace('-fprofile-use', '')
    base_flags = base_flags.replace('-fripa', '')
    base_flags = re.sub('\ [\ ]*', ' ', base_flags)
    if basemin_variant:
        # keep only interesting flags (lto, fdo, ...) from
        # variant-flags given on command line
        return flags, variantd[(fdo_set, lto_set, lipo_set)]
    return base_flags, variantd[(fdo_set, lto_set, lipo_set)]


def atos_exp_base_flags(baseopts, nflags='', nvar='base'):
    new_opts = {
        'base': '',
        'fdo': '-fprofile-use',
        'lto': '-flto',
        'fdo+lto': '-fprofile-use -flto',
        'lipo': '-fprofile-use -fripa',
        }
    flags, variant = atos_base_flags(nflags, nvar, baseopts)
    return flags + ' ' + new_opts[variant]


def atos_opt_run(flags, variant, profdir, config, nbrun, baseopts, no_replay):
    variant_options_flags = {
        'base': ('', ''),
        'fdo': ('-f', ''),
        'lto': ('-l', ''),
        'fdo+lto': ('-f -l', ''),
        'lipo': ('-f', '-fripa')}
    flags, variant = atos_base_flags(flags, variant, baseopts)
    debug('RUN [%s] [%s]' % (variant, flags))
    profdir_option = profdir and ('-b %s' % profdir) or ''
    replay_option = no_replay and '-k' or ''
    nbrun_option = nbrun and ('-n %d' % nbrun) or ''
    variant_options, variant_flags = variant_options_flags[variant]
    status, output = process.system(
        '%s/atos-opt -C %s %s %s %s -r -a "%s %s" %s' % (
            globals.BINDIR, config, nbrun_option, replay_option,
            profdir_option, flags, variant_flags, variant_options),
        print_output=True, get_output=True)
    if not (status == 0 and output):
        debug('FAILURE [%s] [%s]' % (variant, flags))
        return None
    variant_id = None
    for line in output.split('\n'):
        res = re.match(
            '(Running|Skipping) variant (.*)\.\.\.', line)
        if res: variant_id = res.groups()[-1]
    assert variant_id
    result_point = atos_get_result(variant_id)
    result = result_point and (result_point.size, result_point.time) or None
    debug('RES ' + str(result))
    return result


def atos_get_result_wrapper(config, targets):
    return lambda v: atos_opt_get_result(v, config, targets)


def atos_run_wrapper(profdir, config, nbrun, baseopts, no_replay):
    return lambda f, v: atos_opt_run(
        f, v, profdir, config, nbrun, baseopts, no_replay)


# ####################################################################


if __name__ == '__main__':
    import optparse

    parser = optparse.OptionParser(
        description='Optimization space exploration loop',
        usage='%prog action [options] [variants]',
        version="%prog version " + globals.VERSION)

    # general options
    parser.add_option('-d', '--debug', dest='debug',
                      action='store_true', default=False,
                      help='print debug information (default: False)')
    parser.add_option('-q', '--quiet', dest='quiet',
                      action='store_true', default=False,
                      help='quiet mode (default: False)')
    parser.add_option('--dryrun', dest='dryrun',
                      action='store_true', default=False,
                      help='only print commands (default: False)')
    parser.add_option('--log', dest='logfile',
                      action='store', type='string', default=None,
                      help='log output to file (default: None)')
    parser.add_option('--max', dest='max',
                     action='store', type='int', default=None,
                     help='maximum number of iterations (default: None)')
    parser.add_option('--seed', dest='seed',
                     action='store', type='int', default=0,
                     help='set the seed for random generator (default: 0)')

    # atos loop option
    group = optparse.OptionGroup(
        parser, 'ATOS Options', 'Configuration of ATOS exploration loop')
    group.add_option('-B', '--profdir', dest='profdir',
                     action='store', type='string', default=None,
                     help='profile dir name (default: None)')
    group.add_option('-n', dest='nbrun',
                     action='store', type='int', default=None,
                     help='number of executions of run script (default: 1)')
    group.add_option('-k', dest='no_replay',
                     action='store_true', default=False,
                     help='do not replay existing configurations'
                     ' (default: False)')
    group.add_option('--targets', dest='targets',
                     action='store', type='string', default=None,
                     help='target list for results (default: None)')
    group.add_option('-C', dest='atos_configurations',
                     action='store', type='string',
                     default='./atos-configurations',
                     help='configuration path'
                     ' (default: ./atos-configurations)')
    parser.add_option_group(group)

    # generator options
    group = optparse.OptionGroup(
        parser, 'Generator Options', 'Options common to all generators')
    group.add_option('--flags', dest='flags',
                     action='store', type='string', default=None,
                     help='flags list file name (default: None)')
    group.add_option('--optlvl', dest='optlvl',
                     action='store', type='string', default='-Os,-O2,-O3',
                     help='optimization levels (default: -Os,-O2,-O3)')
    group.add_option('--variants', dest='variants',
                     action='store', type='string',
                     default='base,fdo,lto,fdo+lto',
                     help='list of variants (default: base,fdo,lto,fdo+lto)')
    group.add_option('--base-opts', dest='base_opts',
                     action='store', type='string', default=None,
                     help='options to be set for each build (default: None)')
    parser.add_option_group(group)

    # generators
    group = optparse.OptionGroup(
        parser, 'Generators', 'List of available generators')
    parser.set_defaults(generators=[])

    def optcallback(option, opt, value, parser, args):
        genargs = value and value.split(',') or []
        parser.values.generators += [(args, genargs)]

    for gen in generator.generators:
        name, nargs, help, meta = gen.descr()
        group.add_option(name, nargs=nargs, help=help,
                         type=(nargs and 'string' or None), metavar=meta,
                         action='callback',
                         callback=optcallback, callback_args=(gen,))
    parser.add_option_group(group)

    (opts, args) = parser.parse_args()

    logger.setup(vars(opts))
    process.setup(vars(opts))

    # generators setup
    generator.optlist = (
        opts.flags != None and generators.optim_flag_list(opts.flags))
    generator.optlevel = generators.optim_flag_list.optim_flag.optlevel(
        opts.optlvl.split(','))
    generator.variants = opts.variants.split(',')
    generator.atos_config = opts.atos_configurations
    generator.seed = opts.seed

    if opts.base_opts:
        opts.base_opts = opts.base_opts.split(',')
        if len(opts.base_opts) < 2: opts.base_opts += ['']
        generator.baseopts = atos_exp_base_flags(opts.base_opts)

    if opts.base_opts or args:
        generator.optlevel = generators.optim_flag_list.optim_flag.optlevel(
            [''])
        generator.variants = ['base']

    # exploration loop
    atos_get_result = atos_get_result_wrapper(
        opts.atos_configurations, opts.targets)

    seed(opts.seed)

    if args:
        for variant in args:
            if variant == 'frontier':
                args.extend(atos_opt_get_frontier(
                        opts.atos_configurations, opts.targets))
                continue
            base_opts = atos_opt_get_variant_conf(
                variant, opts.atos_configurations, opts.base_opts)
            if not base_opts:
                warning('variant not found: ' + variant)
                continue
            generator.baseopts = atos_exp_base_flags(base_opts)
            exploration_loop(opts.generators, maxiter=opts.max,
                             step=atos_run_wrapper(
                    opts.profdir, opts.atos_configurations, opts.nbrun,
                    base_opts, opts.no_replay))
    else:
        exploration_loop(opts.generators, maxiter=opts.max,
                         step=atos_run_wrapper(
                opts.profdir, opts.atos_configurations, opts.nbrun,
                opts.base_opts, opts.no_replay))
