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
import types
import itertools
import operator

import process
import profile
import utils
import arguments
import atos_lib
import progress
import logger
from logger import debug, warning, error, info, message
import multiprocess


# ####################################################################


class optim_flag_list():

    class optim_flag():

        def __init__(self, frange=None, fchoice=None):
            assert bool(frange) ^ bool(fchoice)
            self.range, self.choice = None, None
            self.prob_select = self.prob_choice = 0.5
            if frange:
                flag, min, max, step = frange
                self.range = (flag, int(min), int(max), int(step or 1))
            if fchoice:
                self.choice = fchoice

        def __repr__(self):
            return self.optname()

        def __str__(self):
            return self.range and self.range[0] or self.choice[0]

        def rand(self):
            if self.range:
                flag, min, max, step = self.range
                val = min + random.randint(0, (max - min) / step) * step
                return '%s%d' % (flag, val)
            elif self.choice:  # pragma: branch_always
                if len(self.choice) == 2:
                    return self.choice[random.random() >= self.prob_choice]
                return random.choice(self.choice)
            else: assert 0  # pragma: unreachable

        def values(self, nbvalues=3):
            if self.range:
                def frange(min, max, step):
                    val = float(min)
                    while int(val) <= max:
                        yield int(val)
                        val = val + step
                flag, min, max, step = self.range
                return ['%s%d' % (flag, v) for v in frange(
                        min, max, float(max - min) / (nbvalues - 1))]
            elif self.choice:  # pragma: branch_always
                return list(self.choice)
            else: assert 0  # pragma: unreachable

        def optname(self):
            if self.range:
                flag, min, max, step = self.range
                flag_val = '%s%d' % (flag, min)
            elif self.choice:  # pragma: branch_always
                flag_val = self.choice[0]
            return optim_flag_list.optim_flag.foptname(flag_val)

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

    def __init__(self, filenames, weight_class=None):
        self.flag_list = []
        self.dependencies = {}
        self.aliases = {}
        self.weight_class = weight_class
        for filename in filenames:
            self.load_from_file(filename)

    def find(self, flagstr):
        for flag in self.flag_list:
            if (optim_flag_list.optim_flag.foptname(flagstr) ==
                flag.optname()): return flag
        return None

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
        cmd = [x.strip() for x in cmdline.strip().split(' ')]
        result, idx, cmdlen = [], 0, len(cmd)
        while idx < cmdlen:
            flag = cmd[idx]
            if flag in [
                '--param', '-mllvm', '--atos-optfile'] and idx + 1 < cmdlen:
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
        flag_list, rev_dependencies = [], {}
        flags_weights = {}
        # parse flags file
        for line in open(filename):
            line = line.split('#', 1)[0].strip()
            line = line.split('//', 1)[0].strip()
            if not line: continue
            # dependency
            reobj = re.match('^(.*)::(.*)', line)
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
                [self.aliases.setdefault(l, []).append(
                        r) for l in lalias for r in ralias]
                continue
            # range flag
            reobj = re.match('^(.*)\[(.*)\.\.([^,]*)(?:,(.*))?\]', line)
            if reobj:
                flag_list.extend(
                    [optim_flag_list.optim_flag(frange=reobj.groups())])
                continue
            # probability
            reobj = re.match('^(W.*)  *(\d*)%  *(\d*)%(.*)', line)
            if reobj:
                if reobj.group(1) != self.weight_class: continue
                prob_select = int(reobj.group(2)) / 100.0
                prob_choice = int(reobj.group(3)) / 100.0
                for flag in reobj.group(4).split(','):
                    flags_weights[flag.strip()] = (prob_select, prob_choice)
                continue
            # choice flag
            choices = [w.strip() for w in line.split('|')]
            flag_list += [optim_flag_list.optim_flag(fchoice=choices)]
        # dependency dict
        for flag in flag_list:
            for dep_parent in rev_dependencies.get(flag.optname(), ['']):
                self.dependencies.setdefault(dep_parent, []).append(flag)
            if flag.optname() in flags_weights:
                flag.prob_select, flag.prob_choice = \
                    flags_weights[flag.optname()]
        self.flag_list.extend(flag_list)

class config(atos_lib.default_obj):
    def extend_cookies(self, cookies):
        self.cookies = self.cookies or []
        self.cookies.extend(cookies or [])
        return self

# ####################################################################


class config_generator:
    """
    Abstract class for optimization configuraton generation.
    """
    class UnimplementedException(Exception):
        pass

    def estimate_exploration_size(self):
        raise self.UnimplementedException()

    def generate(self):
        raise self.UnimplementedException()

    def next(self):
        self.__generator__ = getattr(
            self, '__generator__', self.generate())
        return self.__generator__.next()

    def __iter__(self):
        return self.generate()

    def __call__(self, *args, **kwargs):
        return self.generate()

    def cookie(self, *args, **kwargs):
        configuration_path = getattr(self, 'configuration_path', None)
        kwargs.update({'configuration_path': configuration_path})
        return new_run_cookie(*args, **kwargs)

class gen_config(config_generator):
    """
    Generates a single configuration.
    """
    def __init__(self, configuration_path=None, **config_kwargs):
        self.configuration_path = configuration_path
        self.config_ = config(**config_kwargs)

    def estimate_exploration_size(self):
        return 1

    def generate(self):
        debug('gen_config: %s' % str(self.config_))
        yield self.config_

class gen_progress(config_generator):
    """
    Shows generator progress.
    """
    def __init__(self, parent=None, descr='config',
                 configuration_path=None, **ignored_kwargs):
        assert parent
        self.parent_ = parent
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        self.descr = descr
        self.update_lock = multiprocess.threading.Lock()

    def estimate_exploration_size(self):
        return self.parent_.estimate_exploration_size()

    def update(self):
        # update process status on new result notification
        with self.update_lock: self.progress_.update(
            maxval=self.parent_.estimate_exploration_size())

    def generate(self):
        progress_cookies = []
        maxiter = self.parent_.estimate_exploration_size()
        self.progress_ = progress.exploration_progress(
            descr=self.descr, maxval=maxiter, visible=maxiter,
            config_path=self.configuration_path)
        for ic in itertools.count(1):  # pragma: branch_always
            try:
                next_cfg = self.parent_.next()
                if multiprocess.enabled():
                    run_cookie = self.cookie(record=False)
                    progress_cookies.append(run_cookie)
                    next_cfg.extend_cookies([run_cookie])
                    # update will be called on atos_opt-thread end
                    next_cfg.opt_callbacks = (
                        next_cfg.opt_callbacks or []) + [self.update]
                else:
                    maxiter = self.parent_.estimate_exploration_size()
                    self.progress_.update(value=(ic - 1), maxval=maxiter)
                yield next_cfg
            except StopIteration:
                break
        multiprocess.wait_for_results(progress_cookies)
        self.progress_.end()

class gen_record_flags(config_generator):
    """
    Record yield flags for treadeoffs selection.
    """
    def __init__(self, parent=None, gen_cookie=None,
                 configuration_path=None, **ignored_kwargs):
        assert parent
        self.parent_ = parent
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        self.gen_cookie = self.cookie(gen_cookie)

    def estimate_exploration_size(self):  # pragma: uncovered
        return self.parent_.estimate_exploration_size()

    def generate(self):
        self.cookie_to_cfg = {}
        while True:
            try:
                cfg = self.parent_.next()
            except StopIteration:
                break
            run_cookie = self.cookie(self.gen_cookie, cfg.flags, record=False)
            self.cookie_to_cfg[run_cookie] = (cfg.flags, cfg.variant)
            yield cfg.extend_cookies([self.gen_cookie, run_cookie])

    def tradeoff_config(self, tradeoff):
        tradeoff_results = get_run_tradeoffs(
            [tradeoff], [self.gen_cookie], self.configuration_path)
        tradeoff_cookies = sum(map(
                lambda x: x.cookies.split(','), tradeoff_results), [])
        tradeoff_config = filter(
            bool, map(lambda x: self.cookie_to_cfg.get(x, ''),
                      tradeoff_cookies))
        return tradeoff_config[0] if tradeoff_config else (None, None)

class gen_maxiters(config_generator):
    """
    Limits the generator to a fixed number of iterations.
    """
    def __init__(self, parent=None, maxiters=None,
                 configuration_path=None, **ignored_kwargs):
        self.parent_ = parent or gen_config(configuration_path)
        assert(isinstance(self.parent_, config_generator) or isinstance(
                self.parent_, types.GeneratorType))
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        self.maxiters_ = maxiters

    def estimate_exploration_size(self):
        size = self.parent_.estimate_exploration_size()
        if self.maxiters_:
            size = min(size or self.maxiters_, self.maxiters_)
        return size

    def generate(self):
        debug('gen_maxiters: %s' % str(self.maxiters_))
        generator = self.parent_
        for ic in itertools.count():  # pragma: branch_always
            if self.maxiters_ != None and ic >= self.maxiters_:
                break
            try:
                yield generator.next()
            except StopIteration:
                break

class gen_base(config_generator):
    """
    Generates basic build configurations from the
    optim_levels given in the constructor.
    """
    def __init__(self, parent=None, optim_levels=None,
                 configuration_path=None, **ignored_kwargs):
        self.parent_ = parent or gen_config(configuration_path)
        assert(isinstance(self.parent_, config_generator) or isinstance(
                self.parent_, types.GeneratorType))
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        self.optim_levels_ = (
            optim_levels and optim_levels.split(',') or [])

    def estimate_exploration_size(self):
        size = self.parent_.estimate_exploration_size()
        nb_optim_levels = len(self.optim_levels_)
        if size: size *= nb_optim_levels
        return size

    def generate(self):
        debug('gen_base: %s' % str(self.optim_levels_))
        for cfg in self.parent_:
            if not self.optim_levels_:
                yield cfg
            else:
                for level in self.optim_levels_:
                    yield cfg.copy().update(flags=level)

class gen_variants(config_generator):
    """
    Generates build configurations from the
    optim_variants and given in the constructor.
    """
    def __init__(self, parent=None, optim_variants=None,
                 configuration_path=None, **ignored_kwargs):
        self.parent_ = parent or gen_config(configuration_path)
        assert(isinstance(self.parent_, config_generator) or isinstance(
                self.parent_, types.GeneratorType))
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        self.optim_variants_ = (
            optim_variants and optim_variants.split(',') or [])

    def estimate_exploration_size(self):
        size = self.parent_.estimate_exploration_size()
        nb_optim_variants = len(self.optim_variants_)
        if size: size *= nb_optim_variants
        return size

    def generate(self):
        debug('gen_variants: %s' % str(self.optim_variants_))
        for cfg in self.parent_:
            if not self.optim_variants_:
                yield cfg
            else:
                for variant in self.optim_variants_:
                    yield cfg.copy().update(variant=variant)

class gen_flags_file(config_generator):
    """
    Generate configurations based on flag lists from a file.
    Flags are appended to the child generator flags.
    """
    def __init__(self, parent=None, flags_file=None,
                 configuration_path=None, **ignored_kwargs):
        self.parent_ = parent or gen_config(configuration_path)
        assert(isinstance(self.parent_, config_generator) or isinstance(
                self.parent_, types.GeneratorType))
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        assert flags_file and os.path.isfile(flags_file)
        self.flags_file_ = flags_file
        self.flags_list_ = []
        with open(self.flags_file_) as f:
            for line in f:
                flags = line.split('#', 1)[0].strip()
                if flags: self.flags_list_.append(flags)

    def estimate_exploration_size(self):
        size = self.parent_.estimate_exploration_size()
        nb_flags = len(self.flags_list_)
        if size: size *= nb_flags
        return size

    def generate(self):
        debug('gen_flags_file')
        for cfg in self.parent_:
            if not self.flags_list_:
                yield cfg
            else:
                for flags in self.flags_list_:
                    if cfg.flags: flags = " ".join([cfg.flags, flags])
                    yield cfg.copy().update(flags=flags)

class gen_rnd_uniform_deps(config_generator):
    """
    Generate random meaningful combination of flags using dependencies.
    """
    def __init__(self, parent=None, flags_files=None, optim_levels=None,
                 configuration_path=None, weight_class=None,
                 **ignored_kwargs):
        self.parent_ = parent or gen_config(configuration_path)
        assert(isinstance(self.parent_, config_generator) or isinstance(
                self.parent_, types.GeneratorType))
        self.configuration_path = (
            configuration_path or parent and parent.configuration_path)
        assert flags_files
        self.flags_files_ = flags_files.split(',')
        assert all(map(os.path.isfile, self.flags_files_))
        self.optim_levels_ = optim_flag_list.optim_flag(
            fchoice=(optim_levels or '').split(','))
        self.flag_list_ = optim_flag_list(
            self.flags_files_, weight_class=weight_class)

    def estimate_exploration_size(self):
        if not self.flag_list_.flag_list:
            return self.parent_.estimate_exploration_size()
        return None

    def generate(self):
        debug('gen_rnd_uniform_deps [%s]' % str(self.flags_files_))

        for cfg in self.parent_:
            if not self.flag_list_.flag_list:
                # empty list case
                yield cfg
            else:
                # bug? loops only on the first parent-generated cfg
                base_flags = cfg.flags or ''
                while True:
                    handled_flags = set()
                    available_flags = self.flag_list_.available_flags(
                        base_flags)
                    flags = base_flags or self.optim_levels_.rand()
                    while True:
                        for f in sorted(list(available_flags), key=str):
                            if random.random() >= f.prob_select: continue
                            flags += ' ' + f.rand()
                        handled_flags |= available_flags
                        available_flags = (
                            self.flag_list_.available_flags(
                                base_flags + ' ' + flags)
                            - handled_flags)
                        if not available_flags: break
                    yield cfg.copy().update(flags=flags)

class gen_chained_exploration(config_generator):
    """
    Chain exploration taking selecting tradeoffs after each stage.
    """

    def __init__(
        self, generators_args=None, expl_cookie=None, stage_cookie=None,
        tradeoffs=None, nbiters=None, nbpoints=None, optim_variants=None,
        configuration_path=None, **kwargs):
        self.configuration_path = configuration_path
        self.expl_cookie = self.cookie(expl_cookie)
        self.tradeoffs = tradeoffs or [5, 1, 0.2]
        self.nbiters = int(nbiters) if nbiters != None else 100
        self.nbpoints = nbpoints and int(nbpoints) or 1
        # tradeoffs configs (flags, variants) for first exploration
        if stage_cookie:
            # does not work for function/file explorations
            selected_results = get_run_tradeoffs(
                self.tradeoffs, [stage_cookie], configuration_path,
                self.nbpoints)
            self.selected_configs = filter(
                bool, map(get_result_config, selected_results))
            self.initial_optim_variants = 'base'
            debug('gen_chained_exploration: tradeoffs for first stage: ' + str(
                    self.selected_configs))
        else:
            self.initial_optim_variants = optim_variants
            self.selected_configs = [(None, optim_variants)]
        # list of chained (generator, generator_arguments)
        if not generators_args:
            generators_args = []
            for i in itertools.count(1):  # pragma: branch_always
                generator_i = kwargs.get('generator%d' % i, None)
                if not generator_i: break
                gen_i_list = generator_i.split(',')
                gen_i, gen_i_args = eval(gen_i_list.pop(0)), {}
                for arg in gen_i_list:
                    key, value = arg.split(':', 1)
                    gen_i_args[key] = value
                generators_args += [(gen_i, gen_i_args)]
        generators_args_full = []
        for (generator, generator_args) in generators_args:
            gen_args = dict(kwargs)
            gen_args.update({'optim_variants': optim_variants})
            gen_args.update(generator_args or {})
            gen_args.update({'configuration_path': self.configuration_path})
            gen_args.update({'expl_cookie': self.expl_cookie})
            generators_args_full.append((generator, gen_args))
        self.generators_args = generators_args_full

    def estimate_exploration_size(self):
        if getattr(self, 'expl_size', None) is None:
            self.expl_size, self.prng_size = [], []
            optim_variants = self.initial_optim_variants
            for (nstage, (generator, generator_args)) \
                    in enumerate(self.generators_args):
                gen_base_ = gen_variants(
                    parent=gen_config(self.configuration_path),
                    optim_variants=optim_variants)
                generator_ = generator(
                    parent=gen_base_, **generator_args)
                generator_ = gen_maxiters(
                    parent=generator_, maxiters=self.nbiters)
                gen_size = generator_.estimate_exploration_size()
                pruning = generator_args.get('pruning', False)
                prn_size = (
                    gen_flags_pruning(
                        **generator_args).estimate_exploration_size()
                    if pruning else 0)
                is_aggreg_expl = 'aggregate' in generator_args
                nb_tradeoffs = 1 if is_aggreg_expl else (
                    len(self.selected_configs) if (nstage == 0) else (len(
                            self.tradeoffs) * self.nbpoints))
                self.expl_size.append([gen_size] * nb_tradeoffs)
                self.prng_size.append([prn_size] * nb_tradeoffs)
                optim_variants = 'base'  # tradeoff optim_variant
        return sum(sum(self.expl_size, [])) + sum(sum(self.prng_size, []))

    def update_progress_estimate(
        self, nstage, ntradeoff, size=None, pruning=False):
        if size and not pruning:
            self.expl_size[nstage][ntradeoff] = size
        elif size and pruning:
            self.prng_size[nstage][ntradeoff] = size
        elif not size and not pruning:
            self.expl_size[nstage] = self.expl_size[nstage][:ntradeoff]
        elif not size and pruning:
            self.prng_size[nstage] = self.prng_size[nstage][:ntradeoff]
        else: assert 0  # pragma: unreachable

    def generate(self):
        debug('gen_chained_exploration')
        self.estimate_exploration_size()
        stage_cookies, cookie_to_cfg = [], {}
        stage_progress = progress.exploration_progress(
            descr='stage', maxval=len(self.generators_args),
            config_path=self.configuration_path)
        for (nstage, (generator, generator_args)) \
                in enumerate(self.generators_args):
            debug('gen_chained_exploration: generator ' + str(
                    (generator, generator_args)))
            stage_cookies.append(self.cookie(
                    self.expl_cookie,
                    generator.__name__, generator_args, nstage,
                    descr="stage number %d" % (nstage)))
            self.update_progress_estimate(nstage, len(self.selected_configs))
            debug('gen_chained_exploration: args ' + str(generator_args))
            if not 'aggregate' in generator_args:
                for (ntradeoff, (flags, variant)) \
                        in enumerate(self.selected_configs):
                    debug('gen_chained_exploration: config ' + str(
                            (flags, variant)))
                    gen_base_ = gen_variants(parent=gen_config(
                            self.configuration_path, flags=flags),
                        optim_variants=variant)
                    generator_ = generator(
                        parent=gen_base_, **generator_args)
                    generator_ = gen_maxiters(
                        parent=generator_, maxiters=self.nbiters)
                    generator_ = gen_progress(
                        parent=generator_,
                        configuration_path=self.configuration_path)
                    for cfg in generator_:
                        self.update_progress_estimate(
                            nstage, ntradeoff,
                            size=generator_.estimate_exploration_size())
                        run_cookie = self.cookie(
                            stage_cookies[-1], cfg.flags, cfg.variant,
                            record=False)
                        cookie_to_cfg[run_cookie] = (cfg.flags, cfg.variant)
                        yield cfg.extend_cookies(
                            [self.expl_cookie, stage_cookies[-1], run_cookie])
            else:
                debug('gen_chained_exploration: configs ' + str(
                        (self.selected_configs)))
                generator_ = generator(
                    configs=self.selected_configs, **generator_args)
                generator_ = gen_maxiters(
                    parent=generator_, maxiters=self.nbiters)
                generator_ = gen_progress(
                    parent=generator_,
                    configuration_path=self.configuration_path)
                for cfg in generator_:
                    self.update_progress_estimate(
                        nstage, 0, size=generator_.estimate_exploration_size())
                    run_cookie = self.cookie(
                        stage_cookies[-1], cfg.flags, cfg.variant,
                        record=False)
                    cookie_to_cfg[run_cookie] = (cfg.flags, cfg.variant)
                    yield cfg.extend_cookies(
                        [self.expl_cookie, stage_cookies[-1], run_cookie])

            # select tradeoffs configs (flags, variants) for next exploration
            self.selected_configs, config_tradeoff = [], {}
            for tradeoff in self.tradeoffs:
                selected_results = get_run_tradeoffs(
                    [tradeoff], stage_cookies, self.configuration_path,
                    self.nbpoints)
                selected_cookies = sum(map(
                        lambda x: x.cookies.split(','), selected_results), [])
                selected_configs = filter(
                    bool, map(lambda x: cookie_to_cfg.get(x, None),
                              selected_cookies))
                map(lambda x: config_tradeoff.setdefault(x, tradeoff),
                    selected_configs)
                self.selected_configs = atos_lib.list_unique(
                    self.selected_configs + selected_configs)

            if generator_args.get('pruning', False):
                self.update_progress_estimate(
                    nstage, len(self.selected_configs), pruning=True)
                pruned_selected_config = []
                for (ntradeoff, (flags, variant)) \
                        in enumerate(self.selected_configs):
                    pruning_gen = gen_flags_pruning(
                        config_flags=flags,
                        config_variant=variant,
                        tradeoff=config_tradeoff.get((flags, variant)),
                        **generator_args)
                    generator_ = gen_progress(
                        parent=pruning_gen, descr='pruning',
                        configuration_path=self.configuration_path)
                    for cfg in generator_:
                        self.update_progress_estimate(
                            nstage, ntradeoff, pruning=True,
                            size=generator_.estimate_exploration_size())
                        yield cfg
                    pruned_flags = ' '.join(pruning_gen.final_flags)
                    pruned_selected_config.append((pruned_flags, variant))
                self.selected_configs = atos_lib.list_unique(
                    pruned_selected_config)

            stage_progress.update()
            debug('gen_chained_exploration: tradeoffs for next stages: ' + str(
                    self.selected_configs))
            stage_progress.update()

        stage_progress.end()
        # get best tradeoffs for the whole exploration
        tradeoffs = get_run_tradeoffs(
            self.tradeoffs, [self.expl_cookie], self.configuration_path)
        debug('gen_chained_exploration: final tradeoffs: %s' % (
                str(tradeoffs)))

class gen_file_by_file_cfg(config_generator):
    """
    Perform file-by-file exploration.
    """

    def __init__(
        self, imgpath, csv_dir,
        hot_th="70", cold_opts="-Os", base_flags=None,
        expl_cookie=None, tradeoffs=None, per_file_nbiters=None,
        flags_file=None, genetic=None, random=None,
        optim_variants=None, base_variant=None,
        configuration_path=None, **kwargs):
        assert imgpath
        assert csv_dir
        self.imgpath = imgpath
        self.csv_dir = os.path.abspath(csv_dir)
        self.configuration_path = configuration_path
        self.hot_th = hot_th
        self.cold_opts = cold_opts
        self.base_flags = base_flags or ''
        self.expl_cookie = self.cookie(expl_cookie)
        self.tradeoffs = tradeoffs or [5, 1, 0.2]
        self.per_file_nbiters = int(
            per_file_nbiters) if per_file_nbiters != None else 0
        self.flags_file = flags_file
        self.genetic = bool(genetic)
        self.random = bool(random)
        self.optim_variants = base_variant and [base_variant] or (
            optim_variants or 'base').split(',')
        self.base_variant = base_variant or 'base'
        self.kwargs = kwargs

    @staticmethod
    def read_config_csv(csv_file):
        return dict(
            map(lambda x: x.strip().split(',', 1),
                open(csv_file).readlines()))

    @staticmethod
    def create_config_csv(obj_flags, csv_dir):
        # build option file containing flags for each object file
        sum_flags = atos_lib.md5sum(str(sorted(obj_flags.items())))
        csv_name = os.path.join(csv_dir, 'fbf-%s.csv' % (sum_flags))
        with open(csv_name, 'w') as opt_file:
            for (obj, flags) in obj_flags.items():
                if flags: opt_file.write('%s,%s\n' % (obj, flags))
        return '--atos-optfile=%s' % csv_name

    def fbf_csv_opt(self, obj_flags, base_flags=''):
        csv_flags = gen_file_by_file_cfg.create_config_csv(
            obj_flags, self.csv_dir)
        debug('gen_file_by_file: run [%s] -> %s' % (str(obj_flags), csv_flags))
        return base_flags + ' ' + csv_flags

    def estimate_exploration_size(self):
        # profiling run + simple partitionning
        expl_size = 2
        if not (self.flags_file or self.per_file_nbiters):
            return expl_size
        if getattr(self, 'generator_size', None) is None:
            if self.flags_file:
                generator = gen_flags_file(
                    flags_file=self.flags_file,
                    configuration_path=self.configuration_path)
            else:
                generator = gen_staged(
                    nbiters=self.per_file_nbiters,
                    tradeoffs=self.tradeoffs,
                    configuration_path=self.configuration_path,
                    **self.kwargs)
            est_expl_size = generator.estimate_exploration_size()
            est_nb_objs = 5  # depends on threshold/...
            self.generator_size = [
                dict([(objnum, est_expl_size) for objnum in range(
                            est_nb_objs)])] * len(self.optim_variants)
        # for each variant in optim_variants
        for variant_expl in self.generator_size:
            # for each hot objects
            # - profiling run + exploration
            for hotobj_expl in variant_expl.values():
                expl_size += hotobj_expl + 1
            # + 1 (last profiling)
            expl_size += 1
            # for each tradeoff: resulting run
            expl_size += len(self.tradeoffs)
            # for each tradeoff: resulting run w/cold_opts
            if self.cold_opts: expl_size += len(self.tradeoffs)

        return expl_size

    def generate(self):
        # TODO: some code can now be factorized with gen_function_by_function
        debug('gen_file_by_file')

        # run profiling script
        debug('gen_file_by_file: profiling run')
        # TODO: probably wrong in reuse mode and not parallelisable
        fctmap_file = os.path.join(os.getcwd(), "fctmap.out")
        fctmap_flags = " --atos-fctmap=%s" % fctmap_file
        process.commands.unlink(fctmap_file)
        yield config(
            flags=self.base_flags + fctmap_flags,
            variant=self.base_variant, profile=True)
        fct_map = profile.read_function_to_file_map("fctmap.out")

        # partition function symbols, then object files
        cold_objs, hot_objs = profile.partition_object_files(
            imgpath=self.imgpath, hot_th=self.hot_th, fct_map=fct_map,
            oprof_output="oprof.out")
        debug('gen_file_by_file: hot objects: ' + str(hot_objs))
        debug('gen_file_by_file: cold objects: ' + str(cold_objs))

        # reference run: simple partitioning with base flags
        debug('gen_file_by_file: ref - hot/cold partition, cold options')
        cold_obj_flags = dict(map(lambda x: (x, self.cold_opts), cold_objs))
        cold_obj_flags.update({'*': self.base_flags})
        yield config(
            flags=self.fbf_csv_opt(cold_obj_flags), variant=self.base_variant)

        if not (self.flags_file or self.per_file_nbiters): return

        # file-by-file exploration

        variant_progress = progress.exploration_progress(
            descr='variant', maxval=len(self.optim_variants),
            visible=(len(self.optim_variants) > 1),
            config_path=self.configuration_path)
        # update estimated exploration size
        for variant_num in range(len(self.optim_variants)):
            for x in self.generator_size[variant_num].keys():
                if x >= len(hot_objs): del self.generator_size[variant_num][x]

        for (variant_num, variant) in enumerate(self.optim_variants):
            debug('gen_file_by_file: exploration - ' + variant)

            base_obj_flags = {}  # explore without cold flags
            hot_objs_processed = []
            obj_to_cookie, cookie_to_flags = {}, {}

            obj_progress = progress.exploration_progress(
                descr='file', maxval=len(self.generator_size[variant_num]),
                config_path=self.configuration_path)

            while True:  # loop on hot object files

                # parse oprof.out for new hot objects list
                debug('gen_file_by_file: profiling run')
                yield config(
                    flags=self.fbf_csv_opt(base_obj_flags),
                    variant=variant, profile=True)
                cold_objs, hot_objs = profile.partition_object_files(
                    imgpath=self.imgpath, hot_th=self.hot_th, fct_map=fct_map,
                    oprof_output="oprof.out")
                debug('gen_file_by_file: hot objs=' + str(hot_objs))

                # discard already processed hot functions and select next func
                hot_objs_unprocessed = [
                    f for f in hot_objs if not f in hot_objs_processed]
                debug('gen_file_by_file: hot_objs_unprocessed= ' + str(
                        hot_objs_unprocessed))
                if not hot_objs_unprocessed: break
                curr_hot_obj = hot_objs_unprocessed.pop()
                hot_objs_processed.append(curr_hot_obj)
                hot_obj_num = len(hot_objs_processed) - 1

                debug('gen_file_by_file: hot_obj: ' + str(curr_hot_obj))

                # keep track of current hot_obj results
                obj_cookie = self.cookie(
                    self.expl_cookie, curr_hot_obj, variant,
                    descr="object %s, variant %s" % (curr_hot_obj, variant))
                obj_to_cookie[curr_hot_obj] = obj_cookie

                # create the generator that will be used for curr_hot_obj expl
                if self.flags_file:  # if requested, explore on flags list
                    debug('gen_file_by_file: file: %s ' % (self.flags_file))
                    generator = gen_flags_file(
                        flags_file=self.flags_file,
                        configuration_path=self.configuration_path)
                elif self.genetic:
                    debug('gen_file_by_file: genetic_exploration')
                    generator = gen_genetic(
                        nbiters=self.per_file_nbiters, expl_cookie=obj_cookie,
                        configuration_path=self.configuration_path,
                        tradeoffs=self.tradeoffs, **self.kwargs)
                elif self.random:
                    debug('gen_file_by_file: random_exploration')
                    generator = gen_explore_random(
                        nbiters=self.per_file_nbiters, expl_cookie=obj_cookie,
                        configuration_path=self.configuration_path,
                        **self.kwargs)
                else:  # else, perform a classic staged exploration
                    debug('gen_file_by_file: staged_exploration')
                    generator = gen_staged(
                        nbiters=self.per_file_nbiters, expl_cookie=obj_cookie,
                        configuration_path=self.configuration_path,
                        tradeoffs=self.tradeoffs, **self.kwargs)

                # run exploration loop on newly selected hot_obj
                while True:
                    # update estimated exploration size
                    self.generator_size[variant_num][hot_obj_num] = (
                        generator.estimate_exploration_size())
                    try: cfg = generator.next()
                    except StopIteration: break
                    # compose csv
                    #   from cold flags and best flags from previous objs
                    curr_hot_flags = '%s %s' % (self.base_flags, cfg.flags)
                    run_obj_flags = dict(base_obj_flags.items() + [
                            (curr_hot_obj, curr_hot_flags)])
                    # keep track of hot_obj flags for current run
                    run_cookie = self.cookie(
                        obj_cookie, cfg.flags, record=False)
                    cookie_to_flags[run_cookie] = curr_hot_flags
                    yield cfg.update(
                        flags=self.fbf_csv_opt(run_obj_flags),
                        variant=variant).extend_cookies(
                        [self.expl_cookie, obj_cookie, run_cookie])

                # explore other objs with best perf flags for current obj
                perf_coeff = sorted(self.tradeoffs)[-1]
                perf_results = get_run_tradeoffs(
                    [perf_coeff], [obj_cookie], self.configuration_path)
                perf_cookies = sum(map(
                        lambda x: x.cookies.split(','), perf_results), [])
                perf_flags = filter(
                    bool, map(lambda x: cookie_to_flags.get(x, ''),
                              perf_cookies))
                if perf_flags: base_obj_flags.update(
                    {curr_hot_obj: perf_flags[0]})
                obj_progress.update()

            obj_progress.end()

            # update estimated exploration size
            for x in self.generator_size[variant_num].keys():
                if x > hot_obj_num: del self.generator_size[variant_num][x]

            # compose config from best tradeoffs
            debug('gen_file_by_file: compose best tradeoffs variants')
            for coeff in self.tradeoffs:
                debug('gen_file_by_file: coeff: ' + str(coeff))
                coeff_obj_flags = dict(base_obj_flags.items())
                for hot_obj in obj_to_cookie.keys():
                    coeff_results = get_run_tradeoffs(
                        [coeff], [obj_to_cookie[hot_obj]],
                        self.configuration_path)
                    coeff_cookies = sum(map(
                            lambda x: x.cookies.split(','), coeff_results), [])
                    coeff_flags = filter(bool, map(
                            lambda x: cookie_to_flags.get(x, None),
                            coeff_cookies))
                    if coeff_flags: coeff_obj_flags.update(
                        {hot_obj: coeff_flags[0]})
                yield config(flags=self.fbf_csv_opt(
                        coeff_obj_flags, self.base_flags), variant=variant)
                # also try with cold options if needed
                if not self.cold_opts: continue
                debug('gen_file_by_file: cold coeff: ' + str(coeff))
                coeff_obj_flags.update(cold_obj_flags)
                yield config(flags=self.fbf_csv_opt(
                        coeff_obj_flags, self.base_flags), variant=variant)

            variant_progress.update()
        variant_progress.end()

class gen_function_by_function_cfg(config_generator):
    """
    Perform function-by-function exploration.
    """

    def __init__(
        self, imgpath, csv_dir, acf_plugin_path=None,
        hot_th="70", cold_opts="-Os noinline cold", base_flags=None,
        expl_cookie=None, tradeoffs=None, per_func_nbiters=None,
        flags_file=None, genetic=None, random=None,
        optim_variants=None, base_variant=None,
        configuration_path=None, **kwargs):
        assert imgpath
        assert csv_dir
        self.imgpath = imgpath
        self.csv_dir = os.path.abspath(csv_dir)
        self.configuration_path = configuration_path
        assert acf_plugin_path and os.path.isfile(acf_plugin_path)
        self.acf_plugin_path = acf_plugin_path
        self.hot_th = hot_th
        self.cold_opts = cold_opts
        self.base_flags = base_flags or ''
        self.expl_cookie = self.cookie(expl_cookie)
        self.tradeoffs = tradeoffs or [5, 1, 0.2]
        self.per_func_nbiters = int(
            per_func_nbiters) if per_func_nbiters != None else 0
        self.flags_file = flags_file
        self.genetic = bool(genetic)
        self.random = bool(random)
        self.optim_variants = base_variant and [base_variant] or (
            optim_variants or 'base').split(',')
        self.base_variant = base_variant or 'base'
        self.kwargs = kwargs

    @staticmethod
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

    @staticmethod
    def attribute_to_compiler_opt(attr):
        if attr.startswith('optimize,'):
            attr = attr.split(',', 1)[1]
            if len(attr) == 1:  # -Ox options
                opt = '-O' + attr
            else:  # -fx options
                opt = '-f' + attr
        elif attr.startswith('param,'):  # pragma: branch_always
            attr = attr.split(',', 1)[1]
            opt = '--param ' + attr.replace(',#', '=')
        else: opt = ''  # pragma: uncovered
        return opt

    @staticmethod
    def filter_options(flag_str):
        flag_list = optim_flag_list.parse_line(flag_str)
        filter_in = ['^-f', '^-O', '^[^-]', '^--param']  # useless filtering?
        flag_list = filter(
            lambda f: any(map(lambda i: re.match(i, f), filter_in)), flag_list)
        filter_out = ['^-fprofile', '^-flto']
        flag_list = filter(
            lambda f: all(
                map(lambda i: not re.match(i, f), filter_out)), flag_list)
        return ' '.join(flag_list)

    @staticmethod
    def read_config_csv(csv_file):
        fbf_config = {}
        for line in open(csv_file).readlines():
            fct, loc, flag = line.split(',', 2)
            flag = gen_function_by_function_cfg.attribute_to_compiler_opt(
                flag.strip())
            old_flags = fbf_config.get((fct, loc), '')
            fbf_config[(fct, loc)] = ' '.join([old_flags, flag])
        return fbf_config

    @staticmethod
    def create_config_csv(obj_flags, csv_dir):
        # build option file containing flags for each function
        sum_flags = atos_lib.md5sum(str(sorted(obj_flags.items())))
        csv_name = os.path.join(csv_dir, 'acf-%s.csv' % (sum_flags))
        with open(csv_name, 'w') as opt_file:
            for ((fct, loc), flags) in obj_flags.items():
                flag_list = map(
                    gen_function_by_function_cfg.compiler_opt_to_attribute,
                    optim_flag_list.parse_line(flags))
                for flag in flag_list:
                    opt_file.write('%s,%s,%s\n' % (fct, loc or '', flag))
        return '-fplugin-arg-acf_plugin-csv_file=' + csv_name

    def acf_csv_opt(self, obj_flags):
        csv_flags = gen_function_by_function_cfg.create_config_csv(
            obj_flags, self.csv_dir)
        debug('gen_function_by_function: run [%s] -> %s' % (
                str(obj_flags), csv_flags))
        return (
            self.base_flags +
            ' -fplugin=' + self.acf_plugin_path +
            ' -fplugin-arg-acf_plugin-verbose' +
            ' ' + csv_flags)

    def estimate_exploration_size(self):
        # profiling run + simple partitionning
        expl_size = 2
        if not (self.flags_file or self.per_func_nbiters):
            return expl_size
        if getattr(self, 'generator_size', None) is None:
            if self.flags_file:
                generator = gen_flags_file(
                    flags_file=self.flags_file,
                    configuration_path=self.configuration_path)
            else:
                generator = gen_staged(
                    nbiters=self.per_func_nbiters,
                    tradeoffs=self.tradeoffs,
                    configuration_path=self.configuration_path,
                    **self.kwargs)
            est_expl_size = generator.estimate_exploration_size()
            est_nb_objs = 5  # depends on threshold/...
            self.generator_size = [
                dict([(objnum, est_expl_size) for objnum in range(
                            est_nb_objs)])] * len(self.optim_variants)
        # for each variant in optim_variants
        for variant_expl in self.generator_size:
            # for each hot func
            # - profiling run + exploration
            for hotobj_expl in variant_expl.values():
                expl_size += hotobj_expl + 1
            # + 1 (last profiling)
            expl_size += 1
            # for each tradeoff: resulting run
            expl_size += len(self.tradeoffs)
            # for each tradeoff: resulting run w/cold_opts
            if self.cold_opts: expl_size += len(self.tradeoffs)
        return expl_size

    def generate(self):
        # TODO: some code can now be factorized with gen_file_by_file
        debug('gen_function_by_function')

        # run profiling script
        debug('gen_function_by_function: profiling run')
        yield config(
            flags=self.base_flags, variant=self.base_variant, profile=True)

        # get cold functions list and initialize func_flags map
        cold_funcs, hot_funcs = profile.partition_symbols_loc(
            imgpath=self.imgpath, hot_th=self.hot_th, oprof_output="oprof.out")
        cold_func_flags = dict(
            map(lambda x: (x, gen_function_by_function_cfg.filter_options(
                        self.cold_opts)), cold_funcs))

        # build/run with default cold options
        debug('gen_function_by_function: cold functions')
        yield config(flags=self.acf_csv_opt(
                cold_func_flags), variant=self.base_variant)

        if not (self.flags_file or self.per_func_nbiters): return

        # function-by-function exploration

        variant_progress = progress.exploration_progress(
            descr='variant', maxval=len(self.optim_variants),
            visible=(len(self.optim_variants) > 1),
            config_path=self.configuration_path)
        # update estimated exploration size
        for variant_num in range(len(self.optim_variants)):
            for x in self.generator_size[variant_num].keys():
                if x >= len(hot_funcs): del self.generator_size[variant_num][x]

        for variant in self.optim_variants:
            debug('gen_function_by_function: exploration - ' + variant)

            base_func_flags = {}  # explore without cold flags
            hot_funcs_processed = []
            func_to_cookie, cookie_to_flags = {}, {}

            obj_progress = progress.exploration_progress(
                descr='func', maxval=len(self.generator_size[variant_num]),
                config_path=self.configuration_path)

            while True:  # loop on hot functions

                # parse oprof.out for new hot functions list
                debug('gen_function_by_function: profiling run')
                yield config(flags=self.acf_csv_opt(base_func_flags),
                             variant=variant, profile=True)
                cold_funcs, hot_funcs = profile.partition_symbols_loc(
                    imgpath=self.imgpath, hot_th=self.hot_th,
                    oprof_output="oprof.out")
                debug('gen_function_by_function: hot funcs=' + str(hot_funcs))

                # discard already processed hot functions and select next func
                hot_funcs_unprocessed = [
                    f for f in hot_funcs if not f in hot_funcs_processed]
                debug('gen_function_by_function: hot_funcs_unprocessed=' + str(
                        hot_funcs_unprocessed))
                if not hot_funcs_unprocessed: break
                curr_hot_func = hot_funcs_unprocessed.pop()
                hot_funcs_processed.append(curr_hot_func)
                hot_func_num = len(hot_funcs_processed) - 1

                debug('gen_function_by_function: hot_func: ' + str(
                        curr_hot_func))

                # keep track of current hot_func results
                func_cookie = self.cookie(
                    self.expl_cookie, curr_hot_func, variant,
                    descr="function %s, variant %s" % (curr_hot_func, variant))
                func_to_cookie[curr_hot_func] = func_cookie

                # create the generator that will be used for curr_hot_func expl
                if self.flags_file:  # if requested, explore on flag list
                    debug('gen_function_by_function: file: %s ' % (
                            self.flags_file))
                    generator = gen_flags_file(
                        flags_file=self.flags_file,
                        configuration_path=self.configuration_path)
                elif self.genetic:
                    debug('gen_function_by_function: genetic_exploration')
                    generator = gen_genetic(
                        nbiters=self.per_func_nbiters, expl_cookie=func_cookie,
                        configuration_path=self.configuration_path,
                        tradeoffs=self.tradeoffs, **self.kwargs)
                elif self.random:
                    debug('gen_function_by_function: random_exploration')
                    generator = gen_explore_random(
                        nbiters=self.per_func_nbiters, expl_cookie=func_cookie,
                        configuration_path=self.configuration_path,
                        **self.kwargs)
                else:  # else, perform a classic staged exploration
                    debug('gen_function_by_function: staged_exploration')
                    generator = gen_staged(
                        nbiters=self.per_func_nbiters, expl_cookie=func_cookie,
                        configuration_path=self.configuration_path,
                        tradeoffs=self.tradeoffs, **self.kwargs)
                # run exploration loop on newly selected hot_func
                while True:
                    # update estimated exploration size
                    self.generator_size[variant_num][hot_func_num] = (
                        generator.estimate_exploration_size())
                    try: cfg = generator.next()
                    except StopIteration: break
                    # compose csv
                    #   from cold flags and best flags for previous funcs
                    curr_hot_flags = (
                        gen_function_by_function_cfg.filter_options(cfg.flags))
                    run_func_flags = dict(base_func_flags.items() + [
                            (curr_hot_func, curr_hot_flags)])
                    # keep track of hot_func flags for current run
                    run_cookie = self.cookie(
                        func_cookie, cfg.flags, record=False)
                    cookie_to_flags[run_cookie] = curr_hot_flags
                    yield cfg.update(
                        flags=self.acf_csv_opt(run_func_flags),
                        variant=variant).extend_cookies(
                        [self.expl_cookie, func_cookie, run_cookie])

                # explore other funcs with best perf flags for current func
                perf_coeff = sorted(self.tradeoffs)[-1]
                perf_results = get_run_tradeoffs(
                    [perf_coeff], [func_cookie], self.configuration_path)
                perf_cookies = sum(map(
                        lambda x: x.cookies.split(','), perf_results), [])
                perf_flags = filter(
                    bool, map(lambda x: cookie_to_flags.get(x, ''),
                              perf_cookies))
                if perf_flags: base_func_flags.update(
                    {curr_hot_func: perf_flags[0]})
                obj_progress.update()

            obj_progress.end()

            # update estimated exploration size
            for x in self.generator_size[variant_num].keys():
                if x > hot_func_num: del self.generator_size[variant_num][x]

            # compose config from best tradeoffs
            debug('gen_function_by_function: compose best tradeoffs variants')
            for coeff in self.tradeoffs:
                debug('gen_function_by_function: coeff: ' + str(coeff))
                coeff_func_flags = dict(base_func_flags.items())
                for hot_func in func_to_cookie.keys():
                    coeff_results = get_run_tradeoffs(
                        [coeff], [func_to_cookie[hot_func]],
                        self.configuration_path)
                    coeff_cookies = sum(map(
                            lambda x: x.cookies.split(','), coeff_results), [])
                    coeff_flags = filter(bool, map(
                            lambda x: cookie_to_flags.get(x, None),
                            coeff_cookies))
                    if coeff_flags: coeff_func_flags.update(
                        {hot_func: coeff_flags[0]})
                yield config(flags=self.acf_csv_opt(
                        coeff_func_flags), variant=variant)
                # also try with cold options if needed
                if not self.cold_opts: continue
                debug('gen_function_by_function: cold coeff: ' + str(coeff))
                coeff_func_flags.update(cold_func_flags)
                yield config(flags=self.acf_csv_opt(
                        coeff_func_flags), variant=variant)

            variant_progress.update()
        variant_progress.end()

class gen_flag_values(config_generator):
    """
    Perform fine exploration based on base flags and variant.
    """
    # note: some cases are not well handled
    # "-Os -O0" will not systematically lead to "-Os" as a best config, for ex

    # TODO: code cleaning & factorization, exploration size estimation

    def __init__(
        self, variant_id=None, config_flags=None, config_variant=None,
        nbvalues=None, try_removing=None, tradeoffs=None, keys=None,
        expl_cookie=None, configuration_path=None, weight_class=None,
        **kwargs):
        self.configuration_path = configuration_path
        self.nbvalues = int(nbvalues or 10)
        self.try_removing = int(try_removing or 0)
        self.tradeoffs = tradeoffs or [5, 1, 0.2]
        self.keys = keys and keys.split(',')
        self.expl_cookie = self.cookie(expl_cookie)
        self.kwargs = kwargs
        base_flags, base_variant = variant_id and get_variant_config(
            variant_id, configuration_path) or (config_flags, config_variant)
        self.base_variant = base_variant
        self.flags_list = optim_flag_list.parse_line(base_flags)
        file_flags_lists = [
            'flags.inline.cfg', 'flags.loop.cfg', 'flags.optim.cfg']
        file_flags_lists = filter(os.path.isfile, map(
            functools.partial(os.path.join, self.configuration_path),
            file_flags_lists))
        self.all_flags_list = optim_flag_list(
            file_flags_lists, weight_class=weight_class)

    def generate(self):

        def flag_values(flag_str):
            opt_flag = self.all_flags_list.find(flag_str)

            if opt_flag:
                # flag described in flags cfg files
                #   try initial value
                yield config(flags=flag_str)
                #   try without option
                if self.try_removing:
                    yield config(flags='')
                # stop if only pruning
                if self.nbvalues <= 0:
                    return
                # else try all values if not only pruning flags
                for value in opt_flag.values(nbvalues=self.nbvalues):
                    if value != flag_str: yield config(flags=value)

            elif flag_str.startswith('--atos-optfile'):
                # file-by-file flag
                fbf_file = flag_str[14:].strip('= ')
                fbf_config_init = dict(
                    map(lambda x: x.strip().split(',', 1),
                        open(fbf_file).readlines()))
                fbf_config = dict(fbf_config_init)
                debug('gen_flag_values (fbf): fbf_config: [%s]' % str(
                        fbf_config))
                obj_files = self.keys or fbf_config_init.keys()
                obj_flags_coeffs = {}
                for obj in obj_files:
                    debug('gen_flag_values (fbf): obj: [%s]' % str(obj))
                    generator = gen_flag_values(
                        config_flags=fbf_config_init[obj],
                        configuration_path=self.configuration_path,
                        nbvalues=self.nbvalues, tradeoffs=self.tradeoffs,
                        try_removing=self.try_removing,
                        **self.kwargs)
                    generator = gen_record_flags(
                        parent=generator,
                        configuration_path=self.configuration_path,
                        gen_cookie=self.cookie(self.expl_cookie, obj))
                    while True:
                        try:
                            cfg = generator.next()
                        except StopIteration:
                            break
                        new_cfg = dict(
                            fbf_config.items() + [(obj, cfg.flags)])
                        new_flags = gen_file_by_file_cfg.create_config_csv(
                            obj_flags=new_cfg,
                            csv_dir=os.path.dirname(fbf_file))
                        yield config(
                            flags=new_flags, cookies=cfg.cookies)
                    # record best object flags for each tradeoff
                    for coeff in self.tradeoffs:
                        obj_flags_coeffs.setdefault(
                            obj, {})[coeff] = (
                            generator.tradeoff_config(coeff)[0]
                            or fbf_config_init[obj])
                    # explore other objs with best perf flags for current obj
                    perf_coeff = sorted(self.tradeoffs)[-1]
                    flags_for_obj = obj_flags_coeffs[obj][perf_coeff]
                    debug('gen_flag_values (fbf): flg: ' + str(flags_for_obj))
                    fbf_config.update({obj: flags_for_obj})
                # compose best csv for each tradeoffs
                for coeff in self.tradeoffs:
                    fbf_config = dict(fbf_config_init)
                    for obj in obj_files: fbf_config.update(
                        {obj: obj_flags_coeffs[obj][coeff]})
                    new_flags = gen_file_by_file_cfg.create_config_csv(
                        obj_flags=fbf_config,
                        csv_dir=os.path.dirname(fbf_file))
                    yield config(flags=new_flags)

            elif flag_str.startswith('-fplugin-arg-acf_plugin-csv_file='):
                # function-by-function flag
                fbf_file = flag_str.split('=', 1)[1]
                fbf_config_init = {}
                for line in open(fbf_file).readlines():
                    fct, loc, flag = line.split(',', 2)
                    fbf_config_init[(fct, loc)] = ' '.join([
                            fbf_config_init.get((fct, loc), ''),
                            gen_function_by_function_cfg.
                            attribute_to_compiler_opt(flag.strip())])
                fbf_config = dict(fbf_config_init)
                func_flags_coeffs = {}
                debug('gen_flag_values (fbf): fbf_config: [%s]' % str(
                        fbf_config))
                if self.keys:
                    funcs = []
                    for key in self.keys: funcs.extend(
                        filter(lambda (f, p): f == key,
                               fbf_config_init.keys()))
                else: funcs = fbf_config_init.keys()
                for func in funcs:
                    debug('gen_flag_values (fbf): func: [%s]' % str(func))
                    generator = gen_flag_values(
                        config_flags=fbf_config_init[func],
                        configuration_path=self.configuration_path,
                        nbvalues=self.nbvalues, tradeoffs=self.tradeoffs,
                        try_removing=self.try_removing,
                        **self.kwargs)
                    generator = gen_record_flags(
                        parent=generator,
                        configuration_path=self.configuration_path,
                        gen_cookie=self.cookie(self.expl_cookie, func))
                    while True:
                        try:
                            cfg = generator.next()
                        except StopIteration:
                            break
                        new_cfg = dict(
                            fbf_config.items() + [(func, cfg.flags)])
                        new_flags = gen_function_by_function_cfg.\
                            create_config_csv(
                            new_cfg, csv_dir=os.path.dirname(fbf_file))
                        yield config(
                            flags=new_flags, cookies=cfg.cookies)
                    # record best object flags for each tradeoff
                    for coeff in self.tradeoffs:
                        func_flags_coeffs.setdefault(
                            func, {})[coeff] = (
                            generator.tradeoff_config(coeff)[0]
                            or fbf_config_init[func])
                    # explore other funcs with best perf flags for current func
                    perf_coeff = sorted(self.tradeoffs)[-1]
                    flags_for_func = func_flags_coeffs[func][perf_coeff]
                    debug('gen_flag_values (fbf): flg: ' + str(flags_for_func))
                    fbf_config.update({func: flags_for_func})
                # compose best csv for each tradeoffs
                for coeff in self.tradeoffs:
                    fbf_config = dict(fbf_config_init)
                    for func in funcs: fbf_config.update(
                        {func: func_flags_coeffs[func][coeff]})
                    new_flags = gen_function_by_function_cfg.create_config_csv(
                        fbf_config, csv_dir=os.path.dirname(fbf_file))
                    yield config(flags=new_flags)

            else:
                # unknown flag (or optim level): keep unchanged
                #   try without option
                if self.try_removing: yield config(flags='')
                yield config(flags=flag_str)

        debug('gen_flag_values')

        debug('gen_flag_values: initial flags: ' + str(self.flags_list))
        selected_flag_lists, flags_not_processed = [[]], list(self.flags_list)

        cookie_to_flags = {}
        while flags_not_processed:
            flag = flags_not_processed.pop(0)
            flag_cookie = self.cookie(self.expl_cookie, flag)
            debug('gen_flag_values: processing flag ' + str(flag))

            for flags_processed in selected_flag_lists:
                for cfg_flag_value in flag_values(flag):
                    flag_value = cfg_flag_value.flags
                    debug('gen_flag_values: * flag_value for %s: [%s]' % (
                            flag, flag_value))
                    debug('gen_flag_values: * already processed flags: ' + str(
                            flags_processed))
                    debug('gen_flag_values: * unprocessed flags: ' + str(
                            flags_not_processed))
                    cfg_flags = ' '.join(
                        flags_processed + [flag_value] + flags_not_processed)
                    run_cookie = self.cookie(self.expl_cookie, cfg_flags)
                    cfg_flag_value.extend_cookies([run_cookie])
                    cookie_to_flags[run_cookie] = flags_processed + [
                        flag_value]
                    yield config(
                        flags=cfg_flags, variant=self.base_variant,
                        cookies=[self.expl_cookie, flag_cookie, run_cookie]
                        ).extend_cookies(cfg_flag_value.cookies)

            selected_results = get_run_tradeoffs(
                self.tradeoffs, [flag_cookie], self.configuration_path)
            selected_cookies = sum(map(
                    lambda x: x.cookies.split(','), selected_results), [])
            selected_flag_lists = filter(
                lambda x: x is not None,
                map(lambda x: cookie_to_flags.get(x, None), selected_cookies))

        # print fine exploration results
        tradeoffs = get_run_tradeoffs(
            self.tradeoffs, [self.expl_cookie], self.configuration_path)
        debug('gen_flag_values: final tradeoffs: %s' % (str(tradeoffs)))

class gen_flags_pruning(config_generator):
    """
    Prune useless and inefficient flags.
    """
    def __init__(
        self, variant_id=None, config_flags=None, config_variant=None,
        tradeoff=None, threshold=None,
        update_reference=None, one_by_one=None,
        random_selection=None, selection_size=None, nb_threshold_runs=None,
        keep_opt_level=None,
        expl_cookie=None, configuration_path=None, **kwargs):
        self.configuration_path = configuration_path
        #
        self.tradeoff = float(
            tradeoff) if tradeoff is not None else 5.0
        self.threshold = float(
            threshold) if threshold is not None else 0
        self.update_reference = bool(
            int(update_reference)) if update_reference is not None else False
        self.one_by_one = bool(
            int(one_by_one)) if one_by_one is not None else False
        self.random_selection = bool(
            int(random_selection)) if random_selection is not None else False
        self.selection_size = int(
            selection_size) if selection_size is not None else 1
        self.nb_threshold_runs = int(
            nb_threshold_runs) if nb_threshold_runs is not None else 5
        self.keep_opt_level = bool(
            int(keep_opt_level)) if keep_opt_level is not None else False
        #
        self.base_flags, self.base_variant = variant_id and get_variant_config(
            variant_id, configuration_path) or (config_flags, config_variant)
        self.flags_list = gen_flags_pruning.group_flags(
            optim_flag_list.parse_line(self.base_flags or ''))
        #
        self.expl_cookie = self.cookie(
            expl_cookie, descr="flags pruning")
        self.kwargs = kwargs
        # list of flags to be removed
        self.pruning_attempts = map(list, itertools.combinations(
                enumerate(self.flags_list), self.selection_size))
        if self.keep_opt_level:
            optim_level_flags = filter(
                lambda (pos, flag): flag.startswith('-O'),
                enumerate(self.flags_list))
            self.pruning_attempts = filter(
                lambda s: not set(s).intersection(set(optim_level_flags)),
                self.pruning_attempts)
        if self.random_selection: random.shuffle(self.pruning_attempts)
        self.nb_pruning_attempts = len(self.pruning_attempts)
        self.special_pruning_attempts = None

    def estimate_exploration_size(self):  # pragma: uncovered
        if self.base_flags is None:
            return 20
        expl_size = 1 + self.nb_pruning_attempts
        if self.one_by_one:
            expl_size += 1
        # special acf flags
        if self.special_pruning_attempts is None:
            self.special_pruning_attempts = 0
            # acf file-by-file flag
            acf_file_flag = filter(
                functools.partial(re.search, '--atos-optfile'),
                self.flags_list)
            if acf_file_flag:
                fbf_file = acf_file_flag[0][14:].strip('= ')
                fbf_config = gen_file_by_file_cfg.read_config_csv(fbf_file)
                gen_size = 1  # final flags
                for (obj, flags) in fbf_config.items():
                    gen_size += self.recursive_pruning(
                        flags=flags).estimate_exploration_size()
                self.special_pruning_attempts += gen_size
            # acf function-by-function flag
            acf_func_flag = filter(
                functools.partial(re.search, '-fplugin-arg-acf_plugin'),
                self.flags_list)
            if acf_func_flag:
                fbf_file = re.search(
                    '-fplugin-arg-acf_plugin-csv_file=([^ ]*)',
                    acf_func_flag[0]).group(1)
                fbf_config = (
                    gen_function_by_function_cfg.read_config_csv(fbf_file))
                gen_size = 1  # final flags
                for (obj, flags) in fbf_config.items():
                    gen_size += self.recursive_pruning(
                        flags=flags).estimate_exploration_size()
                self.special_pruning_attempts += gen_size
        expl_size += self.special_pruning_attempts
        #
        return expl_size

    @staticmethod
    def group_flags(flag_list):
        result = []
        index, listlen = 0, len(flag_list)
        while index < listlen:
            flag = flag_list[index]
            if flag.startswith('-fplugin'):
                sub_list = []
                while index < listlen and flag_list[
                    index].startswith('-fplugin'):
                    sub_list.append(flag_list[index])
                    index += 1
                flag = ' '.join(sub_list)
            result += [flag]
            index += 1
        return result

    def run_config(self, *flag_lists, **kwargs):
        run_flags = ' '.join(sum(flag_lists, []))
        run_cookie = self.cookie(self.expl_cookie, run_flags, record=False)
        run_config = config(
            flags=run_flags, variant=self.base_variant,
            cookies=[self.expl_cookie, run_cookie])
        run_config.extend_cookies(kwargs.get('cookies', []))
        return run_config, run_cookie

    def run_result(self, run_cookie):
        results = get_run_results(
            [run_cookie], configuration_path=self.configuration_path)
        if not results: return None, None  # pragma: uncovered
        assert len(results) == 1
        return results[0].time, results[0].size

    def ref_result(self):
        db = atos_lib.atos_db.db(self.configuration_path)
        ref_results = atos_lib.merge_results(
            atos_lib.results_filter(db.get_results(), {'variant': 'REF'}))
        assert ref_results and len(ref_results) == 1
        return ref_results[0].time, ref_results[0].size

    def run_tradeoff(self, run_time, run_size):
        if not (run_time and run_size):  # pragma: uncovered
            return None
        run_speedup = (float(self.db_ref_time) / float(run_time)) - 1.0
        run_sizered = 1.0 - (float(run_size) / float(self.db_ref_size))
        run_tradeoff = (self.tradeoff * run_speedup) + run_sizered
        return run_tradeoff

    def update_ref_tradeoff(self, run_time, run_size, run_tradeoff):
        if not self.update_reference:
            return
        if self.one_by_one:  # pragma: uncovered
            return
        if run_tradeoff <= self.ref_init_tradeoff:
            return
        self.ref_init_tradeoff = run_tradeoff
        run_time *= (1.0 + self.threshold)
        self.ref_tradeoff = self.run_tradeoff(run_time, run_size)
        debug('gen_flags_pruning:   new_ref_tradeoff: %.4f' % (
                self.ref_tradeoff))

    def recursive_pruning(self, flags):
        generator = gen_flags_pruning(
            config_flags=flags,
            configuration_path=self.configuration_path,
            tradeoff=self.tradeoff,
            threshold=self.threshold,
            update_reference=self.update_reference,
            one_by_one=self.one_by_one,
            random_selection=self.random_selection,
            selection_size=self.selection_size,
            **self.kwargs)
        return generator

    def generate(self):
        debug('gen_flags_pruning')
        debug('gen_flags_pruning: tradeoff=%.1f threshold=%.2f ' % (
                self.tradeoff, self.threshold))
        debug('gen_flags_pruning: initial flags: ' + str(self.flags_list))

        # reference result (REF) for speedup/sizered computation
        self.db_ref_time, self.db_ref_size = self.ref_result()
        debug('gen_flags_pruning: db_reference result: (%.1f, %d)' % (
                self.db_ref_time, self.db_ref_size))

        # threshold computation
        compute_threshold = (self.threshold < 0)
        nb_ref_runs = compute_threshold and self.nb_threshold_runs or 1
        run_times = []
        for i in range(nb_ref_runs):
            run_config, ref_cookie = self.run_config(self.flags_list)
            run_cookie = self.cookie(ref_cookie, i, record=False)
            yield run_config.extend_cookies([run_cookie])
            run_time, run_size = self.run_result(run_cookie)
            assert run_time and run_size
            run_times.append(run_time)
            debug('gen_flags_pruning: ref_result (%d/%d): (%.1f, %d)' % (
                    i + 1, nb_ref_runs, run_time, run_size))

        if compute_threshold:
            debug('gen_flags_pruning: ref_run_times: ' + str(run_times))
            self.threshold = atos_lib.variation_coefficient(run_times)
            debug('gen_flags_pruning: computed threshold=%.2f ' % (
                    self.threshold))
            message('explore-flags-pruning: '
                    'Using estimated threshold of %.2f%%' %
                    (self.threshold * 100.0))

        # reference results (no flag removed)
        ref_time, ref_size = self.run_result(ref_cookie)
        assert ref_time and ref_size
        self.ref_init_tradeoff = self.run_tradeoff(ref_time, ref_size)
        debug('gen_flags_pruning: ref_result: (%.1f, %d)' % (
                ref_time, ref_size))
        # [(number_of_flags, not_ajusted_tradeoff, run_cookie)]
        successful_runs = [
            (len(self.flags_list), self.ref_init_tradeoff, run_cookie)]

        # apply threshold to the reference time (with no flags removed)
        ref_time *= (1.0 + self.threshold)
        debug('gen_flags_pruning: updated ref_time: %.1f' % (ref_time))

        # compute reference tradeoff value
        self.ref_tradeoff = self.run_tradeoff(ref_time, ref_size)
        debug('gen_flags_pruning: ref_tradeoff: %.4f' % (self.ref_tradeoff))

        # flags successfuly removed
        flags_removed = []

        while self.pruning_attempts:
            selected_flags = self.pruning_attempts.pop(0)
            debug('gen_flags_pruning: processing flag ' + str(selected_flags))

            # run without flag
            run_flags = list(enumerate(self.flags_list))
            if not self.one_by_one:
                map(run_flags.remove, flags_removed)
            map(run_flags.remove, selected_flags)
            run_flags = map(operator.itemgetter(1), sorted(run_flags))
            run_config, run_cookie = self.run_config(run_flags)
            debug('gen_flags_pruning:   run_flags: ' + str(run_flags))
            #
            yield run_config

            # get results, handle failures
            run_time, run_size = self.run_result(run_cookie)
            run_tradeoff = self.run_tradeoff(run_time, run_size)

            # take keep/remove decision
            if run_tradeoff != None and run_tradeoff >= self.ref_tradeoff:
                debug('gen_flags_pruning:   -> remove flags ' + str(
                        selected_flags))
                flags_removed.extend(selected_flags)
                successful_runs.append(
                    (len(run_flags), run_tradeoff, run_cookie))
                # remove pruned flags from pruning_attempts
                removed_attempts = filter(
                    lambda s: set(s).intersection(set(selected_flags)),
                    self.pruning_attempts)
                map(self.pruning_attempts.remove, removed_attempts)
                self.nb_pruning_attempts -= len(removed_attempts)

                # eventually update reference tradeoff
                self.update_ref_tradeoff(run_time, run_size, run_tradeoff)
                #
                continue

            debug('gen_flags_pruning:   -> keep flags ' + str(selected_flags))

            # handle special flags (only if selection size == 1)
            selected_flag = (
                selected_flags[0][1] if self.selection_size == 1 else '')

            if re.search('--atos-optfile', selected_flag):
                debug('gen_flags_pruning: acf-file flag -> ' + selected_flag)
                # file-by-file flag
                fbf_file = selected_flag[14:].strip('= ')
                fbf_config = gen_file_by_file_cfg.read_config_csv(fbf_file)
                fbf_create = functools.partial(
                    gen_file_by_file_cfg.create_config_csv,
                    csv_dir=os.path.dirname(fbf_file))
                debug('gen_flags_pruning (fbf): initial fbf_config: [%s]' % (
                        str(fbf_config)))

                for obj in fbf_config.keys():
                    debug('gen_flags_pruning (fbf): obj: [%s]' % (obj))
                    generator = self.recursive_pruning(flags=fbf_config[obj])
                    for cfg in generator:
                        new_cfg = dict(
                            fbf_config.items() + [(obj, cfg.flags)])
                        new_flags = fbf_create(obj_flags=new_cfg)
                        run_config, run_cookie = self.run_config(
                            run_flags + [new_flags], cookies=cfg.cookies)
                        yield run_config
                    # explore other objs with best perf flags for current obj
                    flags_for_obj = ' '.join(generator.final_flags)
                    fbf_config.update({obj: flags_for_obj})
                    debug('gen_flags_pruning (fbf) obj [%s] -> %s' % (
                            obj, str(flags_for_obj)))

                # update fbf flag
                new_flags = fbf_create(obj_flags=fbf_config)
                self.flags_list[selected_flags[0][0]] = new_flags
                debug('gen_flags_pruning (fbf) new flag -> %s' % new_flags)
                # run and update tradeoffs
                run_config, run_cookie = self.run_config(
                    run_flags + [new_flags])
                yield run_config
                run_time, run_size = self.run_result(run_cookie)
                run_tradeoff = self.run_tradeoff(run_time, run_size)
                if run_tradeoff != None and (
                    run_tradeoff >= self.ref_tradeoff):  # pragma: uncovered
                    successful_runs.append(
                        (len(run_flags), run_tradeoff, run_cookie))
                    # eventually update reference tradeoff
                    self.update_ref_tradeoff(run_time, run_size, run_tradeoff)

            elif re.search('-fplugin-arg-acf_plugin', selected_flag):
                debug('gen_flags_pruning: acf-file flag -> ' + selected_flag)
                # function-by-function flag
                fbf_file = re.search(
                    '-fplugin-arg-acf_plugin-csv_file=([^ ]*)',
                    selected_flag).group(1)
                fbf_config = (
                    gen_function_by_function_cfg.read_config_csv(fbf_file))
                fbf_create = lambda obj_flags: re.sub(
                    '-fplugin-arg-acf_plugin-csv_file=[^ ]*',
                    gen_function_by_function_cfg.create_config_csv(
                        csv_dir=os.path.dirname(fbf_file),
                        obj_flags=obj_flags),
                    selected_flag)
                debug('gen_flags_pruning (fbf): initial fbf_config: [%s]' % (
                        str(fbf_config)))

                for func in fbf_config.keys():
                    debug('gen_flags_pruning (fbf): func: [%s]' % str(func))
                    generator = self.recursive_pruning(flags=fbf_config[func])
                    for cfg in generator:
                        new_cfg = dict(
                            fbf_config.items() + [(func, cfg.flags)])
                        new_flags = fbf_create(obj_flags=new_cfg)
                        run_config, run_cookie = self.run_config(
                            run_flags + [new_flags], cookies=cfg.cookies)
                        yield run_config
                    # explore other funcs with best perf flags for current func
                    flags_for_func = ' '.join(generator.final_flags)
                    fbf_config.update({func: flags_for_func})
                    debug('gen_flags_pruning (fbf) func [%s] -> %s' % (
                            func, str(flags_for_func)))

                # update fbf flag
                new_flags = fbf_create(obj_flags=fbf_config)
                self.flags_list[selected_flags[0][0]] = new_flags
                debug('gen_flags_pruning (fbf) new flag -> %s' % new_flags)
                # run and update tradeoffs
                run_config, run_cookie = self.run_config(
                    run_flags + [new_flags])
                yield run_config
                run_time, run_size = self.run_result(run_cookie)
                run_tradeoff = self.run_tradeoff(run_time, run_size)
                if run_tradeoff != None and (
                    run_tradeoff >= self.ref_tradeoff):  # pragma: uncovered
                    successful_runs.append(
                        (len(run_flags), run_tradeoff, run_cookie))
                    # eventually update reference tradeoff
                    self.update_ref_tradeoff(run_time, run_size, run_tradeoff)

        # final flags list
        final_flags = list(enumerate(self.flags_list))
        map(final_flags.remove, flags_removed)
        final_flags = map(operator.itemgetter(1), final_flags)
        debug('gen_flags_pruning: final flags: ' + str(final_flags))
        self.final_flags = final_flags

        # try without all removed flags
        if self.one_by_one:
            debug('gen_flags_pruning: run_final_flags: ' + str(final_flags))
            run_config, run_cookie = self.run_config(final_flags)
            yield run_config
            run_time, run_size = self.run_result(run_cookie)
            run_tradeoff = self.run_tradeoff(run_time, run_size)
            if (run_tradeoff != None and    # pragma: branch_always
                run_tradeoff >= self.ref_tradeoff):
                successful_runs.append(
                    (len(run_flags), self.ref_init_tradeoff, run_cookie))

        # print best variant
        if successful_runs:  # pragma: branch_always
            best_run_cookie = sorted(successful_runs)[0][-1]
            best_run_results = get_run_results(
                [best_run_cookie], configuration_path=self.configuration_path)
            assert len(best_run_results) == 1
            message('explore-flags-pruning: best variant: %s [%s]' % (
                    best_run_results[0].variant,
                    atos_lib.hashid(best_run_results[0].variant)))


class gen_genetic_deps(config_generator):
    """
    Generate genetic evolution of previous items, using dependencies.
    """

    def __init__(self, parent=None, flags_files=None, optim_levels=None,
                 mutate_prob=None, mutate_rate=None, mutate_remove=None,
                 evolve_rate=None, configuration_path=None, weight_class=None,
                 **ignored_kwargs):
        assert flags_files
        assert configuration_path
        self.flags_files_ = flags_files.split(',')
        self.configuration_path = configuration_path
        assert all(map(os.path.isfile, self.flags_files_))
        self.optim_levels_ = optim_flag_list.optim_flag(
            fchoice=(optim_levels or '').split(','))
        self.parent_ = parent or gen_config()
        assert(isinstance(self.parent_, config_generator) or isinstance(
                self.parent_, types.GeneratorType))
        self.flag_list_ = optim_flag_list(
            self.flags_files_, weight_class=weight_class)
        self.mutate_prob = float(
            mutate_prob) if (mutate_prob is not None) else 0.3
        self.mutate_rate = float(
            mutate_rate) if (mutate_rate is not None) else 0.3
        self.evolve_rate = float(
            evolve_rate) if (evolve_rate is not None) else 0.3
        self.mutate_remove = float(
            mutate_remove) if (mutate_remove is not None) else 0.1

    def estimate_exploration_size(self):
        if not self.flag_list_.flag_list:  # pragma: uncovered
            return 1
        return None

    def generate(self):
        debug('gen_genetic_deps [%s]' % str(self.flags_files_))

        base_cfg = self.parent_.next()
        # ensure that there is no other parent cfg
        try:
            self.parent_.next()
            assert 0  # pragma: unreachable
        except: pass

        # handle case of empty flag list
        if not self.flag_list_.flag_list:  # pragma: uncovered
            yield base_cfg
            return

        debug('gen_genetic_deps: base_cfg: %s' % str(base_cfg))
        config_set, nb_retry, max_retry = set(), 0, 100
        base_flags = base_cfg.flags or ''

        while True:
            debug('gen_genetic_deps: flags: [%s]' % str(base_flags))
            flags, new_flags = optim_flag_list.parse_line(base_flags), []
            mutate_flags = (random.random() < self.mutate_prob)
            debug('gen_genetic_deps: %s' % (
                    mutate_flags and 'MUTATE' or 'EVOLVE'))

            # already-set flags
            for flag in flags:
                opt_name = optim_flag_list.optim_flag.foptname(flag)
                obj_flag = self.flag_list_.find(flag)

                available_flags = self.flag_list_.available_flags(
                    ' '.join(new_flags))
                flag_is_available = (
                    (not obj_flag) or obj_flag in available_flags)
                if not flag_is_available:  # pragma: branch_uncovered
                    debug('gen_genetic_deps: unavailable flag: ' + flag)
                    continue

                evolve_flag = (random.random() < self.evolve_rate)
                mutate_flag = (random.random() < self.mutate_rate)
                remove_flag = (random.random() < self.mutate_remove)

                # MUTATION
                if mutate_flags:  # pragma: uncovered
                    if mutate_flag:
                        if remove_flag:
                            if opt_name != '-O':  # pragma: uncovered
                                # case of optimization level
                                debug('gen_genetic_deps: remove flag=%s'
                                      % (flag))
                                continue
                        else:
                            # mutate current flag
                            if opt_name == '-O':  # pragma: branch_uncovered
                                # case of optimization level
                                new_flag = self.optim_levels_.rand()
                                new_flags.append(new_flag)
                                debug('gen_genetic_deps: mutate flag=%s->%s' %
                                      (flag, new_flag))
                                continue
                            elif obj_flag:  # pragma: branch_always
                                new_flag = obj_flag.rand()
                                new_flags.append(new_flag)
                                debug('gen_genetic_deps: mutate flag=%s->%s' %
                                      (flag, new_flag))
                                continue
                            else:  # pragma: uncovered
                                # case of unknown flag: keep unchanged
                                pass

                # EVOLUTION
                else:  # pragma: uncovered
                    # evolve_flags: only modify existing flags
                    if evolve_flag and obj_flag:
                        if obj_flag.range:
                            flag_, min, max, step = obj_flag.range
                            range = (max - min) / step
                            # extract current value
                            curval = int(flag.replace(opt_name, ''))
                            newval = curval + random.randint(
                                -range / 8, range / 8) * step
                            if newval < min: newval = min
                            elif newval > max: newval = max
                            new_flag = opt_name + str(newval)
                        else:
                            new_flag = obj_flag.rand()
                        new_flags.append(new_flag)
                        debug('gen_genetic_deps: evolve flag=%s->%s' % (
                                flag, new_flag))
                        continue

                # keep flag unchanged
                debug('gen_genetic_deps: keep flag=%s' % (flag))
                new_flags.append(flag)

            # MUTATION
            # consider adding new flags
            if mutate_flags:  # pragma: uncovered
                handled_flags = set(
                    filter(bool, map(self.flag_list_.find, flags)))
                while True:
                    available_flags = self.flag_list_.available_flags(
                        ' '.join(new_flags)) - handled_flags
                    if not available_flags: break
                    for flag in sorted(list(available_flags), key=str):
                        mutate_flag = (random.random() < self.mutate_rate)
                        if mutate_flag:
                            new_flag = flag.rand()
                            new_flags.append(new_flag)
                            debug('gen_genetic_deps: add flag=%s' % (new_flag))
                    handled_flags |= available_flags

            flags = ' '.join(new_flags)
            if flags in config_set:
                debug('gen_genetic_deps: flags in config_set: [%s]' % (flags))
                nb_retry += 1
                if nb_retry >= max_retry:  # pragma: uncovered
                    debug('gen_genetic_deps: nb_retry=%d: give up' % nb_retry)
                    return
                continue

            config_set.add(flags)
            nb_retry = 0

            debug('gen_genetic_deps: yield [%s]' % flags)
            yield base_cfg.copy().update(flags=flags)

class gen_genetic_crossover(config_generator):
    """
    Generate genetic evolution of previous items, using dependencies.
    """

    def __init__(
        self, configs=None, configuration_path=None, **ignored_kwargs):
        self.configs = configs
        flags_files = [
            'flags.inline.cfg', 'flags.loop.cfg', 'flags.optim.cfg']
        flags_files = filter(os.path.isfile, map(
                functools.partial(os.path.join, configuration_path),
                flags_files))
        self.flag_list = optim_flag_list(flags_files)
        self.configuration_path = configuration_path

    def estimate_exploration_size(self):
        return None  # TODO

    def generate(self):
        debug('gen_crossover')
        assert len(self.configs) >= 2

        while True:
            # select a subset of config for crossover
            nb_configs = random.randint(2, len(self.configs))
            selected_configs = random.sample(self.configs, nb_configs)
            debug('gen_crossover: %d selected configs: %s' % (
                    nb_configs, selected_configs))

            config_flags, config_variants = map(list, zip(*selected_configs))
            random.shuffle(config_flags)
            variant = random.choice(config_variants)
            debug('gen_crossover: variant %s -> %s' % (
                    str(config_variants), variant))
            debug('gen_crossover: flags=' + str(config_flags))

            flags_val = {}
            for flag_lists in config_flags:
                flags = optim_flag_list.parse_line(flag_lists)
                for flag in flags:
                    flag_name = optim_flag_list.optim_flag.foptname(flag)
                    flags_val.setdefault(flag_name, []).append(flag)

            for (flag, values) in flags_val.items():
                missing = len(config_flags) - len(values)
                flags_val[flag].extend([''] * missing)
            debug('gen_crossover: flags_val=' + str(flags_val))

            new_flags = []

            # start with the optimization level
            new_flags.append(
                random.choice(flags_val.pop('-O', [''])))

            # loop on selected config flags
            while True:
                available_flags = self.flag_list.available_flags(
                    ' '.join(new_flags))
                available_flags_set = []

                for flag in flags_val.keys():
                    obj_flag = self.flag_list.find(flag)
                    flag_is_available = (
                        (not obj_flag) or obj_flag in available_flags)
                    if flag_is_available:  # pragma: branch_uncovered
                        available_flags_set.append(flag)

                if not available_flags_set: break

                for flag in available_flags_set:
                    new_flags.append(
                        random.choice(flags_val.pop(flag)))

            flags = ' '.join(new_flags)
            debug('gen_crossover: yield [%s] [%s]' % (flags, variant))
            yield config(flags=flags, variant=variant)


# ####################################################################


def gen_explore_inline(
    optim_levels=None, optim_variants=None, nbiters=None, flags_file=None,
    configuration_path=None, **kwargs):
    assert configuration_path
    flags_file = flags_file or os.path.join(
        configuration_path, "flags.inline.cfg")
    return gen_progress(
        gen_maxiters(
            gen_variants(
                gen_rnd_uniform_deps(
                    flags_files=flags_file, optim_levels=optim_levels,
                    configuration_path=configuration_path,
                    **kwargs),
                optim_variants=optim_variants),
            nbiters),
        descr='expl-inline')

def gen_explore_loop(
    optim_levels=None, optim_variants=None, nbiters=None, flags_file=None,
    configuration_path=None, **kwargs):
    assert configuration_path
    flags_file = flags_file or os.path.join(
        configuration_path, "flags.loop.cfg")
    return gen_progress(
        gen_maxiters(
            gen_variants(
                gen_rnd_uniform_deps(
                    flags_files=flags_file, optim_levels=optim_levels,
                    configuration_path=configuration_path,
                    **kwargs),
                optim_variants=optim_variants),
            nbiters),
        descr='expl-loop')

def gen_explore_optim(
    optim_levels=None, optim_variants=None, nbiters=None, flags_file=None,
    configuration_path=None, **kwargs):
    assert configuration_path
    flags_file = flags_file or os.path.join(
        configuration_path, "flags.optim.cfg")
    return gen_progress(
        gen_maxiters(
            gen_variants(
                gen_rnd_uniform_deps(
                    flags_files=flags_file, optim_levels=optim_levels,
                    configuration_path=configuration_path,
                    **kwargs),
                optim_variants=optim_variants),
            nbiters),
        descr='expl-optim')

def gen_explore_random(
    optim_levels=None, optim_variants=None, nbiters=None,
    configuration_path=None, **kwargs):
    assert configuration_path
    file_flags_lists = [
        'flags.inline.cfg', 'flags.loop.cfg', 'flags.optim.cfg']
    file_flags_lists = filter(os.path.isfile, map(
            functools.partial(os.path.join, configuration_path),
            file_flags_lists))
    file_flags_lists = ','.join(file_flags_lists)
    return gen_progress(
        gen_maxiters(
            gen_variants(
                gen_rnd_uniform_deps(
                    flags_files=file_flags_lists, optim_levels=optim_levels,
                    configuration_path=configuration_path,
                    **kwargs),
                optim_variants=optim_variants),
            nbiters),
        descr='expl-random')

def gen_explore(
    optim_levels=None, optim_variants=None,
    configuration_path=None, **kwargs):
    assert configuration_path
    return gen_progress(
        gen_variants(
            gen_base(optim_levels=optim_levels,
                     configuration_path=configuration_path),
            optim_variants=optim_variants),
        descr='expl-base')

def gen_staged(
    configuration_path=None, seed='0', **kwargs):
    """
    perform staged exploration
    """
    assert configuration_path

    debug('gen_staged')

    random.seed(int(seed))

    # list of generators used during staged exploration
    generators = [
        (gen_base, {}),
        (gen_explore_inline, {}),
        (gen_explore_loop, {}),
        (gen_explore_optim, {})]

    chained_generator = gen_progress(
        gen_chained_exploration(
            generators_args=generators,
            configuration_path=configuration_path,
            **kwargs),
        descr='expl-staged')

    return chained_generator

def gen_genetic(
    flags_files=None, generations='10', seed='0', nbpoints=None,
    configuration_path=None, **kwargs):
    """
    perform genetic exploration
    """
    assert configuration_path

    debug('gen_genetic')

    random.seed(int(seed))

    flags_files = flags_files or [
        'flags.inline.cfg', 'flags.loop.cfg', 'flags.optim.cfg']
    flags_files = filter(os.path.isfile, map(
            functools.partial(os.path.join, configuration_path),
            flags_files))
    flags_files = ','.join(flags_files)

    # list of generators used during genetic exploration
    generators = [
        (gen_base, {})] + int(generations) * [
        (gen_genetic_deps, {'flags_files': flags_files})]

    chained_generator = gen_progress(
        parent=gen_chained_exploration(
            generators_args=generators,
            nbpoints=nbpoints,
            configuration_path=configuration_path,
            **kwargs), descr='expl-genetic')

    return chained_generator

def gen_chained(configuration_path=None, **kwargs):
    assert configuration_path
    return gen_progress(
        gen_chained_exploration(configuration_path=configuration_path,
                                **kwargs),
        descr='expl-chained')

def gen_file_by_file(configuration_path=None, **kwargs):
    assert configuration_path
    return gen_progress(
        gen_file_by_file_cfg(configuration_path=configuration_path,
                             **kwargs),
        descr='expl-file')

def gen_function_by_function(configuration_path=None, **kwargs):
    assert configuration_path
    return gen_progress(
        gen_function_by_function_cfg(configuration_path=configuration_path,
                                     **kwargs),
        descr='expl-func')

def gen_pruning(configuration_path=None, **kwargs):
    assert configuration_path
    return gen_progress(
        gen_flags_pruning(
            configuration_path=configuration_path, **kwargs),
        descr='pruning')


# ####################################################################


def new_run_cookie(*args, **kwargs):
    def record(cookie):
        if not record_cookie: return cookie
        assert configuration_path
        argstr = args and str(args) or None
        db = atos_lib.atos_cookie_db_json.cookie_db(configuration_path)
        db.add_cookie(
            cookie, parent=parent_cookie,
            description=cookie_descr, userset=userset)
        return cookie
    record_cookie = kwargs.get('record', True)
    cookie_descr = kwargs.get('descr', None)
    userset = kwargs.get('userset', False)
    configuration_path = kwargs.get('configuration_path', True)
    parent_cookie = (len(args) >= 1 and args[0] or None)
    if not parent_cookie:
        # new exploration cookie
        return record(atos_lib.new_cookie())
    if len(args) <= 1:
        # cookie already existing
        expl_cookie, parent_cookie = parent_cookie, None
        return record(expl_cookie)
    # computed cookie
    new_cookie = atos_lib.compute_cookie(*args)
    return record(new_cookie)


def get_run_tradeoffs(
    tradeoffs, cookies=None, configuration_path=None, nb_points=1):
    assert configuration_path
    results = get_run_results(
        matches=cookies, configuration_path=configuration_path)
    results = map(
        lambda x: atos_lib.atos_client_results.select_tradeoffs(
            results, perf_size_ratio=x, nb_points=nb_points), tradeoffs)
    # flatten results list
    results = sum(filter(bool, results), [])
    # Returns unique list of results, also filter
    # None result objects returned in case of failure
    results = atos_lib.list_unique(results)
    return results


def get_run_results(matches, configuration_path, **kwargs):
    multiprocess.wait_for_results(matches)
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
    return get_result_config(atos_lib.atos_client_results.result(results[0]))

def get_result_config(result):
    conf = result.dict().get('conf', '')
    uconf = result.dict().get('uconf', None)
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

    def step(flags, variant, cfg):
        flags = cfg.flags or ''
        variant = cfg.variant or 'base'
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
        run_cookies = gen_args.cookies and list(gen_args.cookies) or []
        # no debug in mp mode as it will wait for current run
        debug_step = logger._debug and not multiprocess.enabled()
        if debug_step:
            run_cookie = atos_lib.new_cookie()
            run_cookies.append(run_cookie)
        if cfg.cookies: run_cookies.extend(cfg.cookies)
        run_cookies = atos_lib.list_unique(run_cookies)
        utils.invoque(
            "atos-opt", opt_args, options=flags, fdo=fdo, lto=lto,
            record=True, profile=cfg.profile, cookies=run_cookies,
            opt_callbacks=cfg.opt_callbacks)
        # print debug info
        if debug_step:
            results = get_run_results(matches=[run_cookie], **vars(gen_args))
            debug('step-> ' + str(results))

    gen_args = dict(vars(args or {}).items() + kwargs.items())
    gen_args = atos_lib.default_obj(**gen_args)
    # handle extra arguments
    for arg in gen_args.extra_args or []:
        key, value = arg.split('=', 1)
        gen_args.__dict__[key] = value
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

    # exploration cookie (used for keeping configs already ran)
    expl_cookie = new_run_cookie(
        atos_lib.unique_cookie(gen_args.cookies),
        descr="exploration root cookie",
        userset=(len(gen_args.cookies or []) == 1),
        configuration_path=gen_args.configuration_path)
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
        generator_ = gen_args.generator(**vars(gen_args))

        while True:
            try:
                cfg = generator_.next()
            except StopIteration:
                break
            assert cfg.variant is not None or base_variant
            step(flags=cfg.flags, variant=cfg.variant or base_variant, cfg=cfg)
    return 0
