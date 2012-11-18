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
import random
import functools
import tempfile

import process
import profile
import utils
import arguments
import atos_lib
from logger import debug, warning, error, info, message


# ####################################################################


class optim_flag_list():

    class optim_flag():

        def __init__(self, frange=None, fchoice=None):
            assert bool(frange) ^ bool(fchoice)
            self.range, self.choice = None, None
            if frange:
                flag, min, max = frange
                self.range = (flag, int(min), int(max))
            if fchoice:
                self.choice = fchoice

        def __repr__(self):
            return self.optname()

        def __str__(self):
            return self.range and self.range[0] or self.choice[0]

        def rand(self):
            if self.range:
                flag, min, max = self.range
                return '%s%d' % (flag, random.randint(min, max))
            elif self.choice:
                return random.choice(self.choice)
            else: assert 0

        def values(self):
            if self.range:
                def frange(min, max, step):
                    val = float(min)
                    while int(val) <= max:
                        yield int(val)
                        val = val + step
                nbvalues = 3
                flag, min, max = self.range
                return ['%s%d' % (flag, v) for v in frange(
                        min, max, float(max - min) / (nbvalues - 1))]
            elif self.choice:
                return list(self.choice)
            else: assert 0

        def isoptlevel(self):
            return self.optname() == '-O'

        def optname(self):
            return optim_flag_list.optim_flag.foptname(self.rand())

        @staticmethod
        def optlevel(opt):
            return optim_flag_list.optim_flag(fchoice=opt)

        @staticmethod
        def soptname(s):
            eqidx = s.find('=')
            if eqidx != -1:
                s = s[:eqidx + 1]
            return s

        @staticmethod
        def foptname(s):
            s = optim_flag_list.optim_flag.soptname(s)
            if s.startswith('-fno-'):
                s = s.replace('no-', '', 1)
            if s.startswith('-O'):
                s = '-O'
            return s

    def __init__(self, filename):
        self.load_from_file(filename)

    def available_flags(self, cmdline=''):
        result = []
        # options that have no dependencies
        result.extend(self.dependencies.get('', []))
        # options that are enabled by command line
        cmdflags = self.expand_command_line(cmdline)
        for flag in cmdflags:
            result.extend(self.dependencies.get(
                    optim_flag_list.optim_flag.soptname(flag), []))
        # filter options already set ?
        return set(result)

    @staticmethod
    def parse_line(cmdline):
        cmdline = cmdline or ''
        cmd = [x.strip() for x in cmdline.split(' ')]
        result, idx, cmdlen = [], 0, len(cmd)
        while idx < cmdlen:
            flag = cmd[idx]
            if flag in ['--param', '-mllvm'] and idx + 1 < cmdlen:
                flag += ' ' + cmd[idx + 1]
                idx += 1
            result += [flag]
            idx += 1
        return result

    def expand_command_line(self, cmdline):
        def handle_flag(flag, explicit):
            if not flag: return
            flag_name = optim_flag_list.optim_flag.foptname(flag)
            explicitly_set = flag_isset.get(flag_name, False)
            if explicitly_set and not explicit: return
            flag_isset[flag_name] = explicit
            flag_value[flag_name] = flag
            flag_index[flag_name] = flag_idx
        flag_isset, flag_value, flag_index = {}, {}, {}
        # initial options
        flag_list, flag_idx = [''], 0
        # command line flags
        flag_list.extend(optim_flag_list.parse_line(cmdline))
        # expand aliases
        for flag in flag_list:
            handle_flag(flag, True)
            flag_aliases = list(self.aliases.get(flag, []))
            flag_idx += 1
            while flag_aliases:
                handle_flag(flag_aliases.pop(0), False)
                flag_idx += 1
        # return ordered and simplified flag list
        return sorted(flag_value.values(), key=lambda x: flag_index[
                optim_flag_list.optim_flag.foptname(x)])

    def load_from_file(self, filename):
        flag_list, rev_dependencies, aliases = [], {}, {}
        # parse flags file
        for line in open(filename):
            line = line.split('#', 1)[0].strip()
            line = line.split('//', 1)[0].strip()
            if not line: continue
            # dependency
            reobj = re.match('^(.*):(.*)', line)
            if reobj:
                ldeps = [x.strip() for x in reobj.group(1).split(',')]
                rdeps = [x.strip() for x in reobj.group(2).split(',')]
                [rev_dependencies.setdefault(r, []).append(
                        l) for l in ldeps for r in rdeps]
                continue
            # alias
            reobj = re.match('^(.*)=>(.*)', line)
            if reobj:
                lalias = [x.strip() for x in reobj.group(1).split(',')]
                ralias = [x.strip() for x in reobj.group(2).split(',')]
                [aliases.setdefault(l, []).append(
                        r) for l in lalias for r in ralias]
                continue
            # range flag
            reobj = re.match('^(.*)\[(.*)\.\.(.*)\]', line)
            if reobj:
                flag_list.extend(
                    [optim_flag_list.optim_flag(frange=reobj.groups())])
                continue
            # choice flag
            choices = [w.strip() for w in line.split('|')]
            flag_list += [optim_flag_list.optim_flag(fchoice=choices)]
        # dependency dict
        dependencies = {}
        for flag in flag_list:
            for dep_parent in rev_dependencies.get(flag.optname(), ['']):
                dependencies.setdefault(dep_parent, []).append(flag)
        self.flag_list = flag_list
        self.dependencies = dependencies
        self.aliases = aliases

class config(atos_lib.default_obj):
    def extend_cookies(self, cookies):
        self.cookies = self.cookies or []
        self.cookies.extend(cookies)
        return self

# ####################################################################


class config_generator:
    """
    Abstract class for optimization configuraton generation.
    """
    class UnimplementedException(Exception):
        pass

    def generate(self):
        raise self.UnimplementedException()

    @staticmethod
    def test():
        generator = config_generator()
        try:
            generator.generate()
        except config_generator.UnimplementedException:
            return
        except:
            assert(False)
        assert(False)

class gen_config(config_generator):
    """
    Generates a single configuration.
    """
    def __init__(self, **config_kwargs):
        self.config_ = config(**config_kwargs)

    def generate(self):
        debug('gen_config: %s' % str(self.config_))
        yield self.config_

    @staticmethod
    def test():
        idx = 0
        for cfg in gen_config(variant='base').generate():
            idx += 1
        assert(idx == 1)
        assert(len(cfg.__dict__.items()) == 1)
        assert(cfg.variant == 'base')

class gen_maxiters(config_generator):
    """
    Limits the generator to a fixed number of iterations.
    """
    def __init__(self, parent=None, maxiters=None,
                 **ignored_kwargs):
        self.maxiters_ = maxiters
        self.parent_ = parent or gen_config()
        assert(isinstance(self.parent_, config_generator))

    def generate(self):
        debug('gen_maxiters: %s' % str(self.maxiters_))
        generator = self.parent_.generate()
        for ic in itertools.count():
            if self.maxiters_ != None and ic >= self.maxiters_:
                break
            try:
                yield generator.next()
            except StopIteration:
                break

    @staticmethod
    def test():
        idx = 0
        generator = gen_maxiters(gen_config(), 0)
        for cfg in generator.generate():
            idx += 1
        assert(idx == 0)
        generator = gen_maxiters(gen_config())
        for cfg in generator.generate():
            idx += 1
        assert(idx == 1)
        generator = gen_maxiters(gen_config(), 1)
        for cfg in generator.generate():
            idx += 1
        assert(idx == 2)

class gen_base(config_generator):
    """
    Generates basic build configurations from the
    optim_levels given in the constructor.
    """
    def __init__(self, parent=None, optim_levels=None,
                 **ignored_kwargs):
        self.optim_levels_ = (
            optim_levels and optim_levels.split(',') or [])
        self.parent_ = parent or gen_config()
        assert(isinstance(self.parent_, config_generator))

    def generate(self):
        debug('gen_base: %s' % str(self.optim_levels_))
        for cfg in self.parent_.generate():
            if not self.optim_levels_:
                yield cfg
            else:
                for level in self.optim_levels_:
                    yield cfg.copy().update(flags=level)

    @staticmethod
    def test():
        variant = 'base'
        levels = '-O1,-O2,-O3'
        expected_flgs = levels.split(',')
        for cfg in gen_base(gen_config(variant=variant),
                            levels).generate():
            print str(cfg)
            assert(cfg.flags == expected_flgs.pop(0))
            assert(cfg.variant == variant)

class gen_variants(config_generator):
    """
    Generates build configurations from the
    optim_variants and given in the constructor.
    """
    def __init__(self, parent=None, optim_variants=None,
                 **ignored_kwargs):
        self.optim_variants_ = (
            optim_variants and optim_variants.split(',') or [])
        self.parent_ = parent or gen_config()
        assert(isinstance(self.parent_, config_generator))

    def generate(self):
        debug('gen_variants: %s' % str(self.optim_variants_))
        for cfg in self.parent_.generate():
            if not self.optim_variants_:
                yield cfg
            else:
                for variant in self.optim_variants_:
                    yield cfg.copy().update(variant=variant)

    @staticmethod
    def test():
        levels = '-O1,-O2,-O3'
        variants = 'base,lto,fdo,fdo+lto'
        expected_flgs = levels.split(',')
        expected_vars = variants.split(',')
        generator = gen_variants(gen_base(gen_config(), levels), variants)
        idx = 0
        for cfg in generator.generate():
            print str(cfg)
            assert(cfg.flags == expected_flgs[idx / len(expected_vars)])
            assert(cfg.variant == expected_vars[idx % len(expected_vars)])
            idx += 1

class gen_flags_file(config_generator):
    """
    Generate configurations based on flag lists from a file.
    Flags are appended to the child generator flags.
    """
    def __init__(self, parent=None, flags_file=None,
                 **ignored_kwargs):
        assert flags_file and os.path.isfile(flags_file)
        self.flags_file_ = flags_file
        self.parent_ = parent or gen_config()
        assert(isinstance(self.parent_, config_generator))

    def generate(self):
        debug('gen_flags_file')
        flags_list = []
        with open(self.flags_file_) as f:
            for line in f:
                flags = line.split('#', 1)[0].strip()
                if flags: flags_list.append(flags)
        for cfg in self.parent_.generate():
            if not flags_list:
                yield cfg
            else:
                for flags in flags_list:
                    if cfg.flags: flags = " ".join([cfg.flags, flags])
                    yield cfg.copy().update(flags=flags)

    @staticmethod
    def test():
        flags = ['-O2', '-O2 -funroll-loops']
        tmpf = tempfile.NamedTemporaryFile(delete=False)
        tmpname = tmpf.name
        try:
            tmpf.write("# Test flags\n")
            for flag in flags:
                tmpf.write(" %s # test flags\n" % flag)
            tmpf.close()
            generator = gen_flags_file(gen_config(variant='base'),
                                       tmpname)
            for cfg in generator.generate():
                print str(cfg)
                assert(cfg.flags == flags.pop(0))
                assert(cfg.variant == 'base')
        finally:
            os.unlink(tmpname)

class gen_rnd_uniform_deps(config_generator):
    """
    Generate random meaningful combination of flags using dependencies.
    """
    def __init__(self, parent=None, flags_file=None, optim_levels=None,
                 **ignored_kwargs):
        assert flags_file and os.path.isfile(flags_file)
        self.flags_file_ = flags_file
        self.optim_levels_ = (optim_levels or '').split(',')
        self.optim_levels_ = optim_flag_list.optim_flag.optlevel(
            self.optim_levels_)
        self.parent_ = parent or gen_config()
        assert(isinstance(self.parent_, config_generator))

    def generate(self):
        debug('gen_rnd_uniform_deps [%s]' % str(self.flags_file_))
        flag_list = optim_flag_list(self.flags_file_)

        for cfg in self.parent_.generate():
            if not flag_list.flag_list:
                # empty list case
                yield cfg
            else:
                base_flags = cfg.flags or ''
                while True:
                    handled_flags = set()
                    available_flags = flag_list.available_flags(base_flags)
                    flags = base_flags or self.optim_levels_.rand()
                    while True:
                        for f in sorted(list(available_flags), key=str):
                            if random.randint(0, 1): continue
                            flags += ' ' + f.rand()
                        handled_flags |= available_flags
                        available_flags = (
                            flag_list.available_flags(base_flags + ' ' + flags)
                            - handled_flags)
                        if not available_flags: break
                    yield cfg.copy().update(flags=flags)

    @staticmethod
    def test():
        random.seed(0)
        # Expected results with seed(0)
        expected_flgs = [
            '-O2 --param inline-call-cost=18 -fno-inline-small',
            '-O2 --param inline-call-cost=20',
            '-O2 --param inline-call-cost=25',
            '-O2',
            '-O2 -fno-inline-small',
            '-O2 -finline-small']
        levels = '-O2'
        tmpf = tempfile.NamedTemporaryFile(delete=False)
        tmpname = tmpf.name
        try:
            tmpf.write("# Test dependency flags\n")
            tmpf.write("-finline-small|-fno-inline-small\n")
            tmpf.write("--param inline-call-cost=[4..32]\n")
            tmpf.write("-finline: --param inline-call-cost=\n")
            tmpf.write("-finline: -finline-small\n")
            tmpf.write("=> -O2\n")
            tmpf.write("-O2 => -finline\n")
            tmpf.close()
            generator = gen_maxiters(
                gen_rnd_uniform_deps(gen_config(),
                                     tmpname,
                                     levels),
                6)
            for cfg in generator.generate():
                print str(cfg)
                #assert(cfg.flags == expected_flgs.pop(0))
        finally:
            os.unlink(tmpname)

def gen_basic(optim_levels=None, optim_variants=None, expl_cookie=None,
    **kwargs):
    """
    Perform basic exploration on flags and variants.
    """
    debug('gen_basic')
    generator = gen_variants(
        gen_base(optim_levels=optim_levels),
        optim_variants=optim_variants)

    for cfg in generator.generate():
        yield cfg.extend_cookies([expl_cookie])

def gen_staged(
    optim_levels=None, optim_variants=None, nbiters=None, fine_expl=None,
    configuration_path='atos-configurations', seed='0', expl_cookie=None,
    **kwargs):
    """
    perform staged exploration
    """
    debug('gen_staged')

    flags_lists = [
        'flags.inline.cfg', 'flags.loop.cfg', 'flags.optim.cfg']
    flags_lists = map(
        functools.partial(os.path.join, configuration_path), flags_lists)
    flags_lists = filter(os.path.isfile, flags_lists)
    tradeoff_coeffs = [5, 1, 0.2]
    nbiters = int(nbiters) if nbiters != None else 100
    random.seed(int(seed))

    # list of generators used during staged exploration
    generators = [(gen_base,
                   {'optim_levels': optim_levels},
                   None)]
    for flags_file in flags_lists:
        generators += [(gen_rnd_uniform_deps,
                        {'optim_levels': optim_levels,
                         'flags_file': flags_file},
                        nbiters)]

    expl_cookie = expl_cookie or atos_lib.new_cookie()
    stage_cookies = []
    cookie_to_cfg = {}
    selected_configs = [(None, optim_variants)]

    for (stage_generator, args, maxiters) in generators:
        stage_cookies.append(atos_lib.compute_cookie(
                expl_cookie, stage_generator.__name__, args))

        # run exploration on previously selected configs
        for (flags, variants) in selected_configs:
            debug('gen_staged: generator %s' %
                  str((stage_generator.__name__, flags, variants)))

            generator = gen_variants(
                gen_maxiters(
                    stage_generator(
                        gen_config(flags=flags),
                        **args),
                    maxiters=maxiters),
                optim_variants=variants)
            for cfg in generator.generate():
                run_cookie = atos_lib.compute_cookie(
                    stage_cookies[-1], cfg.flags, cfg.variant)
                cookie_to_cfg[run_cookie] = (cfg.flags, cfg.variant)
                yield cfg.extend_cookies(
                    [expl_cookie, stage_cookies[-1], run_cookie])

        # select tradeoffs configs (flags, variants) for next exploration
        selected_results = get_run_tradeoffs(tradeoff_coeffs, stage_cookies,
                                             configuration_path)
        selected_cookies = sum(map(
                lambda x: x.cookies.split(','), selected_results), [])
        selected_configs = filter(
            bool, map(lambda x: cookie_to_cfg.get(x, None), selected_cookies))
        debug('gen_staged: tradeoffs for next stages: ' + str(
                selected_configs))

    # get best tradeoffs for the whole exploration
    tradeoffs = get_run_tradeoffs(
        tradeoff_coeffs, [expl_cookie], configuration_path)
    debug('gen_staged: final tradeoffs: %s' % (str(tradeoffs)))


def gen_function_by_function(
    acf_plugin_path,
    imgpath, csv_dir, hot_th, cold_opts='-Os noinline cold',
    flags_file=None, per_func_nbiters=None,
    base_flags=None, base_variant=None, optim_variants=None,
    configuration_path='atos-configurations', expl_cookie=None, **kwargs):
    """
    perform per function exploration
    """

    def compiler_opt_to_attribute(opt):
        if opt.startswith('-O'):    # -Ox options
            csv_opt = 'optimize,' + opt[2:]
        elif opt.startswith('-f'):  # -fx options
            csv_opt = 'optimize,' + opt[2:]
        elif opt.startswith('--param '):  # --params xx=y options
            csv_opt = 'param,' + opt[8:]
            csv_opt = csv_opt.replace(' ', '').replace('=', ',#')
        else:  # direct attributes
            csv_opt = opt + ','
        return csv_opt

    def filter_options(flag_str):
        flag_list = optim_flag_list.parse_line(flag_str)
        filter_in = ['^-f', '^-O', '^[^-]']
        flag_list = filter(
            lambda f: any(map(lambda i: re.match(i, f), filter_in)), flag_list)
        filter_out = ['^-fprofile', '^-flto']
        flag_list = filter(
            lambda f: all(
                map(lambda i: not re.match(i, f), filter_out)), flag_list)
        return ' '.join(flag_list)

    def acf_csv_opt(obj_flags, base_flags=''):
        # build option file containing flags for each function
        sum_flags = atos_lib.md5sum(str(obj_flags.items()))
        csv_name = os.path.join(csv_dir, 'acf-%s.csv' % (sum_flags))
        debug('gen_function_by_function: run [%s] -> %s' % (
                str(obj_flags), csv_name))
        with open(csv_name, 'w') as opt_file:
            for ((fct, loc), flags) in obj_flags.items():
                flag_list = map(compiler_opt_to_attribute, flags.split())
                for flag in flag_list:
                    opt_file.write('%s,%s,%s\n' % (fct, loc or '', flag))
        return (
            base_flags +
            ' -fplugin=' + acf_plugin_path +
            ' -fplugin-arg-acf_plugin-verbose' +
            ' -fplugin-arg-acf_plugin-csv_file=' + csv_name)

    debug('gen_function_by_function')
    assert acf_plugin_path and os.path.isfile(acf_plugin_path)

    tradeoff_coeffs = [5, 1, 0.2]
    per_func_nbiters = int(per_func_nbiters) if per_func_nbiters != None else 0
    optim_variants = base_variant and [base_variant] or (
        optim_variants or 'base').split(',')
    base_flags = base_flags or '-O2'
    base_variant = base_variant or 'base'

    # run profiling script
    debug('gen_function_by_function: profiling run')
    yield config(flags=base_flags, variant=base_variant, profile=True)

    # get cold functions list and initialize func_flags map
    cold_funcs, hot_funcs = profile.partition_symbols_loc(
        imgpath=imgpath, hot_th=hot_th, oprof_output="oprof.out")
    cold_func_flags = dict(
        map(lambda x: (x, filter_options(cold_opts)), cold_funcs))

    # build/run with default cold options
    debug('gen_function_by_function: cold functions')
    yield config(flags=acf_csv_opt(
            cold_func_flags, base_flags), variant=base_variant)

    if not (flags_file or per_func_nbiters): return

    expl_cookie = expl_cookie or atos_lib.new_cookie()

    # function-by-function exploration

    for variant in optim_variants:
        debug('gen_function_by_function: exploration - ' + variant)

        base_func_flags = dict(cold_func_flags)
        hot_funcs_processed = []
        func_to_cookie, cookie_to_flags = {}, {}

        while True:  # loop on hot functions

            # parse oprof.out for new hot functions list
            debug('gen_function_by_function: profiling run')
            yield config(
                flags=acf_csv_opt(base_func_flags, base_flags),
                variant=variant, profile=True)
            cold_funcs, hot_funcs = profile.partition_symbols_loc(
                imgpath=imgpath, hot_th=hot_th, oprof_output="oprof.out")
            debug('gen_function_by_function: hot funcs=' + str(hot_funcs))

            # discard already processed hot functions and select next hot_func
            hot_funcs_unprocessed = [
                f for f in hot_funcs if not f in hot_funcs_processed]
            debug('gen_function_by_function: hot_funcs_unprocessed= ' + str(
                    hot_funcs_unprocessed))
            if not hot_funcs_unprocessed: break
            curr_hot_func = hot_funcs_unprocessed.pop()
            hot_funcs_processed.append(curr_hot_func)
            debug('gen_function_by_function: hot_func: ' + str(curr_hot_func))

            # keep track of current hot_func results
            func_cookie = atos_lib.compute_cookie(
                expl_cookie, variant, curr_hot_func)
            func_to_cookie[curr_hot_func] = func_cookie

            # create the generator that will be used for curr_hot_func expl
            if flags_file:  # if requested, explore on flag list
                debug('gen_function_by_function: file: %s ' % (flags_file))
                generator = gen_flags_file(flags_file=flags_file).generate()
            else:  # else, perform a classic staged exploration
                debug('gen_function_by_function: staged_exploration')
                generator = gen_staged(
                    nbiters=per_func_nbiters, expl_cookie=func_cookie,
                    configuration_path=configuration_path, **kwargs)

            # run exploration loop on newly selected hot_func
            while True:
                try: cfg = generator.next()
                except StopIteration: break
                # compose csv from cold flags and best flags for previous funcs
                curr_hot_flags = filter_options(cfg.flags)
                run_func_flags = dict(base_func_flags.items() + [
                        (curr_hot_func, curr_hot_flags)])
                # keep track of hot_func flags for current run
                run_cookie = atos_lib.compute_cookie(func_cookie, cfg.flags)
                cookie_to_flags[run_cookie] = curr_hot_flags
                yield cfg.update(
                    flags=acf_csv_opt(run_func_flags, base_flags),
                    variant=variant).extend_cookies([func_cookie, run_cookie])

            # explore other funcs with best perf flags for current func
            perf_coeff = sorted(tradeoff_coeffs)[-1]
            perf_results = get_run_tradeoffs(
                [perf_coeff], [func_cookie], configuration_path)
            perf_cookies = sum(map(
                    lambda x: x.cookies.split(','), perf_results), [])
            perf_flags = filter(
                bool, map(lambda x: cookie_to_flags.get(x, ''), perf_cookies))
            if perf_flags: base_func_flags.update(
                {curr_hot_func: perf_flags[0]})

        # compose config from best tradeoffs
        debug('gen_function_by_function: compose best tradeoffs variants')
        for coeff in tradeoff_coeffs:
            debug('gen_function_by_function: coeff: ' + str(coeff))
            coeff_func_flags = dict(base_func_flags.items())
            for hot_func in func_to_cookie.keys():
                coeff_results = get_run_tradeoffs(
                    [coeff], [func_to_cookie[hot_func]], configuration_path)
                coeff_cookies = sum(map(
                        lambda x: x.cookies.split(','), coeff_results), [])
                coeff_flags = filter(bool, map(
                        lambda x: cookie_to_flags.get(x, None), coeff_cookies))
                if coeff_flags: coeff_func_flags.update(
                    {hot_func: coeff_flags[0]})
            yield config(flags=acf_csv_opt(
                    coeff_func_flags, base_flags), variant=variant)

def gen_file_by_file(
    imgpath, csv_dir, hot_th, cold_opts="-Os",
    flags_file=None, per_file_nbiters=None,
    base_flags=None, base_variant=None, optim_variants=None,
    configuration_path='atos-configurations', expl_cookie=None, **kwargs):
    """
    perform per file exploration
    """

    def fbf_csv_opt(obj_flags, base_flags=''):
        # build option file containing flags for each object file
        sum_flags = atos_lib.md5sum(str(obj_flags.items()))
        csv_name = os.path.join(csv_dir, 'fbf-%s.csv' % (sum_flags))
        debug('gen_file_by_file: run [%s] -> %s' % (str(obj_flags), csv_name))
        with open(csv_name, 'w') as opt_file:
            for (obj, flags) in obj_flags.items():
                if flags: opt_file.write('%s,%s\n' % (obj, flags))
        return base_flags + ' --atos-optfile %s' % os.path.abspath(csv_name)

    debug('gen_file_by_file')
    # TODO: some code can now be factorized with gen_function_by_function

    tradeoff_coeffs = [5, 1, 0.2]
    per_file_nbiters = int(per_file_nbiters) if per_file_nbiters != None else 0
    optim_variants = base_variant and [base_variant] or (
        optim_variants or 'base').split(',')
    base_flags = base_flags or '-O2'
    base_variant = base_variant or 'base'
    fctmap_file = os.path.join(os.getcwd(), "fctmap.out")
    process.commands.unlink(fctmap_file)
    fctmap_flags = " --atos-fctmap=%s" % fctmap_file

    # run profiling script
    debug('gen_file_by_file: profiling run')
    yield config(
        flags=base_flags + fctmap_flags, variant=base_variant, profile=True)
    fct_map = profile.read_function_to_file_map("fctmap.out")

    # partition function symbols, then object files
    cold_objs, hot_objs = profile.partition_object_files(
        imgpath=imgpath, hot_th=hot_th, fct_map=fct_map,
        oprof_output="oprof.out")
    debug('gen_file_by_file: hot objects: ' + str(hot_objs))
    debug('gen_file_by_file: cold objects: ' + str(cold_objs))

    # reference run: simple partitioning with base flags
    debug('gen_file_by_file: ref - hot/cold partition, cold options')
    cold_obj_flags = dict(map(lambda x: (x, cold_opts), cold_objs))
    cold_obj_flags.update({'*': base_flags})
    yield config(
        flags=fbf_csv_opt(cold_obj_flags), variant=base_variant)

    if not (flags_file or per_file_nbiters): return

    expl_cookie = expl_cookie or atos_lib.new_cookie()

    # file-by-file exploration

    for variant in optim_variants:
        debug('gen_file_by_file: exploration - ' + variant)

        base_obj_flags = dict(cold_obj_flags)
        hot_objs_processed = []
        obj_to_cookie, cookie_to_flags = {}, {}

        while True:  # loop on hot object files

            # parse oprof.out for new hot objects list
            debug('gen_file_by_file: profiling run')
            yield config(
                flags=fbf_csv_opt(base_obj_flags),
                variant=variant, profile=True)
            cold_objs, hot_objs = profile.partition_object_files(
                imgpath=imgpath, hot_th=hot_th, fct_map=fct_map,
                oprof_output="oprof.out")
            debug('gen_file_by_file: hot objs=' + str(hot_objs))

            # discard already processed hot functions and select next hot_func
            hot_objs_unprocessed = [
                f for f in hot_objs if not f in hot_objs_processed]
            debug('gen_file_by_file: hot_objs_unprocessed= ' + str(
                    hot_objs_unprocessed))
            if not hot_objs_unprocessed: break
            curr_hot_obj = hot_objs_unprocessed.pop()
            hot_objs_processed.append(curr_hot_obj)
            debug('gen_file_by_file: hot_obj: ' + str(curr_hot_obj))

            # keep track of current hot_obj results
            obj_cookie = atos_lib.compute_cookie(
                expl_cookie, variant, curr_hot_obj)
            obj_to_cookie[curr_hot_obj] = obj_cookie

            # create the generator that will be used for curr_hot_obj expl
            if flags_file:  # if requested, explore on flags list
                debug('gen_file_by_file: file: %s ' % (flags_file))
                generator = gen_flags_file(flags_file=flags_file).generate()
            else:  # else, perform a classic staged exploration
                debug('gen_file_by_file: staged_exploration')
                generator = gen_staged(
                    nbiters=per_file_nbiters, expl_cookie=obj_cookie,
                    configuration_path=configuration_path, **kwargs)

            # run exploration loop on newly selected hot_obj
            while True:
                try: cfg = generator.next()
                except StopIteration: break
                # compose csv from cold flags and best flags for previous objs
                curr_hot_flags = '%s %s' % (base_flags, cfg.flags)
                run_obj_flags = dict(base_obj_flags.items() + [
                        (curr_hot_obj, curr_hot_flags)])
                # keep track of hot_obj flags for current run
                run_cookie = atos_lib.compute_cookie(obj_cookie, cfg.flags)
                cookie_to_flags[run_cookie] = curr_hot_flags
                yield cfg.update(
                    flags=fbf_csv_opt(run_obj_flags),
                    variant=variant).extend_cookies([obj_cookie, run_cookie])

            # explore other objs with best perf flags for current obj
            perf_coeff = sorted(tradeoff_coeffs)[-1]
            perf_results = get_run_tradeoffs(
                [perf_coeff], [obj_cookie], configuration_path)
            perf_cookies = sum(map(
                    lambda x: x.cookies.split(','), perf_results), [])
            perf_flags = filter(
                bool, map(lambda x: cookie_to_flags.get(x, ''), perf_cookies))
            if perf_flags: base_obj_flags.update(
                {curr_hot_obj: perf_flags[0]})

        # compose config from best tradeoffs
        debug('gen_file_by_file: compose best tradeoffs variants')
        for coeff in tradeoff_coeffs:
            debug('gen_file_by_file: coeff: ' + str(coeff))
            coeff_obj_flags = dict(base_obj_flags.items())
            for hot_obj in obj_to_cookie.keys():
                coeff_results = get_run_tradeoffs(
                    [coeff], [obj_to_cookie[hot_obj]], configuration_path)
                coeff_cookies = sum(map(
                        lambda x: x.cookies.split(','), coeff_results), [])
                coeff_flags = filter(bool, map(
                        lambda x: cookie_to_flags.get(x, None), coeff_cookies))
                if coeff_flags: coeff_obj_flags.update(
                    {hot_obj: coeff_flags[0]})
            yield config(flags=fbf_csv_opt(
                    coeff_obj_flags, base_flags), variant=variant)


# ####################################################################


def get_run_tradeoffs(
    tradeoffs, cookies=None, configuration_path=None):
    results = get_run_results(
        matches=cookies, configuration_path=configuration_path)
    fselect = atos_lib.atos_client_results.select_tradeoff
    results = map(
        lambda x: fselect(results, perf_size_ratio=x), tradeoffs)
    # Returns unique list of results, also filter
    # None result objects returned in case of failure
    results = atos_lib.list_unique(filter(bool, results))
    return results


def get_run_results(matches, configuration_path, **kwargs):
    db = atos_lib.atos_db.db(configuration_path)
    ref_results = atos_lib.merge_results(
        atos_lib.results_filter(db.get_results(), {'variant': 'REF'}))
    assert ref_results and len(ref_results) == 1
    variant_results = atos_lib.merge_results(
        atos_lib.results_filter_cookies(db.get_results(), matches)) or []
    map(lambda x: x.compute_speedup(ref_results[0]), variant_results)
    return variant_results


def get_variant_config(variant_id, configuration_path, **kwargs):
    db = atos_lib.atos_db.db(configuration_path)
    # search variant_id in results database
    results = atos_lib.atos_client_db(db).query({'variant': variant_id})
    if not results:
        warning("variant not found: '%s'" % variant_id)
        return None
    conf, uconf = results[0].get('conf', ''), results[0].get('uconf', None)
    # deduce optim_variant from conf & uconf
    variantd = {
        (0, 0, 0): 'base',
        (0, 0, 1): 'lipo',
        (1, 0, 0): 'fdo',
        (0, 1, 0): 'lto',
        (1, 1, 0): 'fdo+lto'}
    fdo_set = (uconf is not None)
    lto_set = (conf.find('-flto') != -1)
    lipo_set = fdo_set and (conf.find('-fripa') != -1)
    optim_variant = variantd[(fdo_set, lto_set, lipo_set)]
    # also deduce optim_flags
    optim_flags = conf.replace('-flto', '')
    optim_flags = optim_flags.replace('-fprofile-use', '')
    optim_flags = optim_flags.replace('-fripa', '')
    optim_flags = re.sub('\ [\ ]*', ' ', optim_flags)
    return optim_flags, optim_variant


def run_exploration_loop(args=None, **kwargs):

    def get_frontier_variants(configuration_path, **kwargs):
        db = atos_lib.atos_db.db(configuration_path)
        results = atos_lib.atos_client_results(db).get_results(
            only_frontier=True, objects=True)
        return map(lambda x: x.variant, results)

    def step(flags, variant, cookies=None, profile=None):
        flags = flags or ''
        variant = variant or 'base'
        debug('step: %s, %s' % (variant, flags))
        # add flags from base_variant_configuration
        flags = (base_flags and (base_flags + ' ') or '') + flags
        variant = base_variant or variant
        fdo = variant in ['fdo', 'fdo+lto']
        lto = variant in ['lto', 'fdo+lto']
        if variant == 'lipo': flags += ' -fripa'
        # compute atos-opt argument list and invoque it
        opt_args = arguments.argparse.Namespace()
        opt_args.__dict__.update(vars(args or {}))
        opt_args.__dict__.update(kwargs)
        run_cookie = atos_lib.new_cookie()
        run_cookies = gen_args.cookies and list(gen_args.cookies) or []
        run_cookies.append(run_cookie)
        if cookies: run_cookies.extend(cookies)
        run_cookies = list(set(run_cookies))
        utils.invoque(
            "atos-opt", opt_args, options=flags, fdo=fdo, lto=lto,
            record=True, profile=profile, cookies=run_cookies)
        # print debug info
        results = get_run_results(matches=[run_cookie], **vars(gen_args))
        debug('step-> ' + str(results))

    gen_args = dict(vars(args or {}).items() + kwargs.items())
    gen_args = atos_lib.default_obj(**gen_args)
    # run on all available variants by default
    optim_variants = (
        gen_args.optim_variants and gen_args.optim_variants.split(',')
        or atos_lib.get_available_optim_variants(gen_args.configuration_path))
    gen_args.optim_variants = ','.join(optim_variants)
    base_variants = gen_args.base_variants or [None]
    base_variants = sum(map(
            lambda x: (  # replace 'frontier' by correspondind ids
                (x != 'frontier') and [x] or get_frontier_variants(
                    **vars(gen_args))), base_variants), [])
    assert gen_args.generator

    # previous results wont be found without old exploration cookie
    if gen_args.reuse and not gen_args.cookies:
        error(" --reuse option must be used with --cookie option")
        return 1

    # exploration cookie (used for keeping configs already ran)
    expl_cookie = atos_lib.unique_cookie(gen_args.cookies)
    gen_args.cookies = (gen_args.cookies or []) + [expl_cookie]

    message("Identifier of exploration: " + str(expl_cookie))

    for variant_id in base_variants:
        random.seed(gen_args.seed or 0)
        base_flags, base_variant = (
            variant_id and get_variant_config(variant_id, **vars(gen_args))
            or (None, None))
        gen_args.update(
            base_flags=base_flags, base_variant=base_variant,
            expl_cookie=expl_cookie)
        if isinstance(gen_args.generator, config_generator):
            generator_ = gen_args.generator.generate()
        else:
            generator_ = gen_args.generator(**vars(gen_args))
            if isinstance(generator_, config_generator):
                generator_ = generator_.generate()

        for ic in itertools.count():
            try:
                cfg = generator_.next()
            except StopIteration:
                debug('stopiteration - exploration stopped')
                break
            if cfg.variant is not None:
                step(
                    flags=cfg.flags, variant=cfg.variant,
                    cookies=cfg.cookies, profile=cfg.profile)
            else:
                variants = base_variant and [base_variant] or optim_variants
                for variant in variants:
                    step(flags=cfg.flags, variant=variant,
                         cookies=cfg.cookies, profile=cfg.profile)
    return 0

if __name__ == "__main__":
    config_generator.test()
    gen_config.test()
    gen_maxiters.test()
    gen_base.test()
    gen_variants.test()
    gen_flags_file.test()
    gen_rnd_uniform_deps.test()
