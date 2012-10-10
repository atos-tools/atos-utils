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

import sys, os, itertools, math, re
import random

import logger
import utils
import arguments
import atos_lib
from logger import debug, warning, error, info


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


# ####################################################################


def gen_rnd_uniform_deps(
    flags_file='', optim_levels='', base_flags='', **kwargs):
    """
    generate random meaningful combination of compiler flags using dependencies
    """
    if not flags_file: return
    base_flags = base_flags or ''
    flag_list = optim_flag_list(flags_file)
    optim_levels = optim_flag_list.optim_flag.optlevel(optim_levels.split(','))
    if not flag_list.flag_list: return
    while True:
        handled_flags = set()
        available_flags = flag_list.available_flags(base_flags)
        flags = ''
        if not base_flags: flags += optim_levels.rand()
        while True:
            for f in sorted(list(available_flags)):
                if random.randint(0, 1): continue
                flags += ' ' + f.rand()
            handled_flags |= available_flags
            available_flags = (
                flag_list.available_flags(base_flags + ' ' + flags)
                - handled_flags)
            if not available_flags: break
        yield flags


# ####################################################################


def run_exploration_loop(args=None, **kwargs):

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

    def get_frontier_variants(configuration_path, **kwargs):
        db = atos_lib.atos_db.db(configuration_path)
        results = atos_lib.atos_client_results(db).get_results(
            only_frontier=True, objects=True)
        return map(lambda x: x.variant, results)

    def get_run_results(configuration_path, cookie, **kwargs):
        db = atos_lib.atos_db.db(configuration_path)
        results = atos_lib.results_filter_cookie(
            db.get_results(), cookie)
        # filter out failures
        results = filter(
            lambda x: "FAILURE" not in x.values(), results)
        if not results: return None
        # transform into result objects
        results = map(
            atos_lib.atos_client_results.result, results)
        # get target list
        targets = list(
            set(map(lambda x: x.target, results)))
        # merge multiple runs
        results = map(
            atos_lib.atos_client_results.result.merge_multiple_runs,
            map(lambda x: filter(lambda y: y.target == x, results), targets))
        # merge multiple targets
        result = atos_lib.atos_client_results.result.merge_targets(
            'group', results)
        return result.size, result.time

    def step(flags, variant):
        debug('step: %s, %s' % (variant, flags))
        # add flags from base_variant_configuration
        flags = (base_flags and (base_flags + ' ') or '') + flags
        variant = base_variant or variant
        fdo = variant in ['fdo', 'fdo+lto']
        lto = variant in ['lto', 'fdo+lto']
        if variant == 'lipo': flags += ' -fripa'
        # compute atos-opt argument list and invoque it
        run_cookie = atos_lib.new_cookie()
        opt_args = arguments.argparse.Namespace()
        opt_args.__dict__.update(vars(args))
        opt_args.__dict__.update(kwargs)
        status = utils.invoque(
            "atos-opt", opt_args,
            options=flags, fdo=fdo, lto=lto, record=True,
            cookies=(gen_args.get('cookies', []) + [run_cookie]))
        # unpack and aggregate (merge) results
        if status: return None
        results = get_run_results(cookie=run_cookie, **gen_args)
        debug('step-> %d, %s' % (status, str(results)))
        return results

    gen_args = dict(vars(args or {}).items() + kwargs.items())
    generator = gen_args.get('generator', None)
    max_iter = gen_args.get('nbiters', None)
    optim_variants = gen_args.get('optim_variants', None)
    optim_variants = (optim_variants or 'base').split(',')
    base_variants = gen_args.get('base_variants', None) or [None]
    base_variants = sum(map(
            lambda x: (  # replace 'frontier' by correspondind ids
                (x != 'frontier') and [x] or get_frontier_variants(**gen_args)
                ), base_variants), [])
    seed_number = gen_args.get('seed', 0)

    for variant_id in base_variants:
        base_flags, base_variant = (
            variant_id and get_variant_config(variant_id, **gen_args)
            or (None, None))
        generator_ = generator(
            base_flags=base_flags, base_variant=base_variant, **gen_args)
        random.seed(seed_number)
        result = None
        for ic in itertools.count():
            if ic == max_iter:
                debug('max_iter reached - exploration stopped')
                break
            try:
                fv = generator_.send(result)
            except StopIteration:
                debug('stopiteration - exploration stopped')
                break
            if isinstance(fv, tuple):
                flags, variant = fv
                result = step(flags, variant)
            else:
                variants = base_variant and [base_variant] or optim_variants
                result = dict(map(lambda x: (x, step(fv, x)), variants))
