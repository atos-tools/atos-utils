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
from functools import partial
from random import randint, choice, sample, seed

import globals
import process
import atos_lib
import logger
from logger import debug, warning

# ####################################################################


class opt_flag():

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
            return '%s%d' % (flag, randint(min, max))
        elif self.choice:
            return choice(self.choice)
        else: assert 0

    def values(self):
        if self.range:
            def frange(min, max, step):
                val = float(min)
                while int(val) <= max:
                    yield int(val)
                    val = val + step
            nbvalues = 10
            flag, min, max = self.range
            return ['%s%d' % (flag, v) for v in frange(
                    min, max, float(max - min) / (nbvalues - 1))]
        elif self.choice:
            return list(self.choice)
        else: assert 0

    def isoptlevel(self):
        return self.optname() == '-O'

    @staticmethod
    def optlevel(opt):
        return opt_flag(fchoice=opt)

    def optname(self):
        return opt_flag.foptname(self.rand())

    @staticmethod
    def soptname(s):
        eqidx = s.find('=')
        if eqidx != -1:
            s = s[:eqidx + 1]
        return s

    @staticmethod
    def foptname(s):
        s = opt_flag.soptname(s)
        if s.startswith('-fno-'):
            s = s.replace('no-', '', 1)
        if s.startswith('-O'):
            s = '-O'
        return s


class opt_flag_list():

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
                    opt_flag.soptname(flag), []))
        # filter options already set ?
        return set(result)

    @staticmethod
    def parse_line(cmdline):
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
            flag_name = opt_flag.foptname(flag)
            explicitly_set = flag_isset.get(flag_name, False)
            if explicitly_set and not explicit: return
            flag_isset[flag_name] = explicit
            flag_value[flag_name] = flag
            flag_index[flag_name] = flag_idx
        flag_isset, flag_value, flag_index = {}, {}, {}
        # initial options
        flag_list, flag_idx = [''], 0
        # command line flags
        flag_list.extend(opt_flag_list.parse_line(cmdline))
        # expand aliases
        for flag in flag_list:
            handle_flag(flag, True)
            flag_aliases = list(self.aliases.get(flag, []))
            flag_idx += 1
            while flag_aliases:
                handle_flag(flag_aliases.pop(0), False)
                flag_idx += 1
        # return ordered and simplified flag list
        return sorted(flag_value.values(),
                      key=lambda x: flag_index[opt_flag.foptname(x)])

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
                flag_list += [opt_flag(frange=reobj.groups())]
                continue
            # choice flag
            choices = [w.strip() for w in line.split('|')]
            flag_list += [opt_flag(fchoice=choices)]
        # dependency dict
        dependencies = {}
        for flag in flag_list:
            for dep_parent in rev_dependencies.get(flag.optname(), ['']):
                dependencies.setdefault(dep_parent, []).append(flag)
        self.flag_list = flag_list
        self.dependencies = dependencies
        self.aliases = aliases


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
def gen_rnd_uniform_deps():
    '''generate random meaningful combination ''' \
        '''of compiler flags using dependencies'''
    if not generator.optlist.flag_list: return
    while True:
        handled_flags = set()
        available_flags = generator.optlist.available_flags(
            generator.baseopts or '')
        baseflags, flags = generator.baseopts or '', ''
        if not baseflags: flags += generator.optlevel.rand()
        while True:
            for f in sorted(list(available_flags)):
                if randint(0, 1): continue
                flags += ' ' + f.rand()
            handled_flags |= available_flags
            available_flags = (
                generator.optlist.available_flags(baseflags + ' ' + flags)
                - handled_flags)
            if not available_flags: break
        yield flags


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


@generator
def gen_acf(imgpath, oprof_script, acf_plugin,
            acf_hot_th='70', acf_cold_th='30',
            acf_cold_opts='-Os noinline cold', acf_flags_file=None):
    '''perform per function exploration'''

    def call_acf_oprofile(hot_th=acf_hot_th, cold_th=acf_cold_th,
                          cold_opts=None, hot_opts=None):
        imgopt = os.path.isdir(imgpath.split(':')[0]) and '-p' or '-e'
        cmd = [acf_oprofile, imgopt, imgpath, '-i', oprof_out,
               '--acf-hot-th', str(hot_th), '--acf-cold-th', str(cold_th)]
        if cold_opts: cmd += ['--acf-cold-opts', '"%s"' % cold_opts]
        if hot_opts: cmd += ['--acf-hot-opts', '"%s"' % hot_opts]
        status, output = process.system(
            ' '.join(cmd), get_output=True, check_status=True)
        return output

    def write_csv_file(options, funcname, *args):
        csv_name = 'acf-%s-%s-%s.csv' % (
            acf_hot_th, funcname, atos_lib.md5sum('\n'.join(args)))
        debug('*** CSV name created for %s: %s' % (funcname, csv_name))
        csv_path = os.path.join(csv_dir, csv_name)
        csv_file = open(csv_path, 'w')
        for a in args: csv_file.write(a)
        csv_file.close()
        return csv_path

    def filteropt(flag_str):
        flag_list = opt_flag_list.parse_line(flag_str)
        filter_in = ['^-f', '^-O', '^[^-]']
        flag_list = filter(
            lambda f: any(map(lambda i: re.match(i, f), filter_in)), flag_list)
        filter_out = ['^-fprofile', '^-flto', '^--param']
        flag_list = filter(
            lambda f: all(
                map(lambda i: not re.match(i, f), filter_out)), flag_list)
        return ' '.join(flag_list)

    debug('gen_acf')

    # TODO: remove this test
    # test disabled as acf should now work with all gcc versions
    if False and generator.baseopts and generator.atos_config:
        lto_set = (generator.baseopts.find('-flto') != -1)
        compiler_versions = atos_lib.json_config(generator.atos_config).query(
            atos_lib.strtoquery('$.compilers[*].version'))
        compiler_min_version = (
            compiler_versions and atos_lib.json_config.compiler_version_number(
                sorted(compiler_versions)[0]) or None)
        # no acf in lto mode if gcc version < 4.7
        if lto_set and compiler_min_version and compiler_min_version < 40700:
            warning('acf incompatible with lto for gcc < 4.7')
            return

    def_opts = ''
    acf_oprofile = os.path.join(globals.LIBDIR, 'atos-acf-oprofile.py')
    oprof_out = os.path.join('.', 'oprof.out')
    csv_dir = os.path.join('.', 'atos-configurations', 'acf_csv_dir')
    acf_cold_opts = filteropt(acf_cold_opts)

    debug('*** gen_acf params: imgpath: %s, oprofile script: %s, '
          'hot function threshold: %s, cold function treshold: %s, '
          'cold function options: %s' % (
            imgpath, oprof_script, acf_hot_th, acf_cold_th, acf_cold_opts))

    if not os.path.isdir(csv_dir):
        os.mkdir(csv_dir)

    # generate oprof.out in current dir
    process.system(oprof_script, check_status=True)

    if not os.path.exists(oprof_out):
        # Profile run failed: profile file not found
        debug('*** profile run failed: output file not found: %s' % oprof_out)
        return

    # build with default options
    yield def_opts, 'base'

    # Parse oprof.out for cold functions
    acf_csv_cold = call_acf_oprofile(hot_th=0, cold_opts=acf_cold_opts)
    debug('*** Cold functions:\n%s' % acf_csv_cold)
    csv_path = write_csv_file(def_opts, 'cold_run', acf_csv_cold)

    # Get HOST_WIDE_INT size obtained during atos-config
    hwi_size = atos_lib.json_config(generator.atos_config).query(
        atos_lib.strtoquery('$.compilers[*].host_wide_int'))
    acf_po = (' -fplugin=' + acf_plugin +
              ' -fplugin-arg-acf_plugin-host_wide_int=' + hwi_size[0] +
              ' -fplugin-arg-acf_plugin-verbose' +
              ' -fplugin-arg-acf_plugin-csv_file=')
    # Build-Run for reference results with cold functions
    result_ref = yield def_opts + acf_po + csv_path, 'base'

    final_hot_csv = ''
    previous_hot_csv = ''

    acf_opt_flag_list = (  # explore on given flags if any
        acf_flags_file and map(
            filteropt, map(lambda x: x.strip(),
                           open(acf_flags_file).readlines()))
        or [])

    hot_functions_processed = []
    first_iteration = True

    while True:
        # Avoid profile generation for first iteration,
        # already generated for cold functions
        if not first_iteration:
            # generate oprof.out in current dir
            process.system(oprof_script, check_status=True)
        first_iteration = False

        # Parse oprof.out for hot functions
        acf_csv_hot = call_acf_oprofile(cold_th=0, hot_opts='0XXX0')
        debug('*** Hot functions:\n%s' % acf_csv_hot)

        hot_functions = []
        # Filter hot functions names
        for csv_line in acf_csv_hot.split('\n'):
            if not csv_line: continue  # handle empty lines
            word = csv_line.split(',')
            hot_functions += [word[0]]
        debug('*** Hot functions names= %s' % hot_functions)

        # Discard already processed hot functions
        hot_functions_unprocessed = [
            f for f in hot_functions if not f in hot_functions_processed]
        debug('*** Hot functions not yet processed= %s' % (
                hot_functions_unprocessed))

        if not hot_functions_unprocessed:
            debug('*** All hot functions processed')
            break
        else:
            function = hot_functions_unprocessed[0]
            hot_functions_processed += [function]

        debug('*** Current function: %s' % function)

        best_function_csv = ''
        best_function_result = 0
        first_result = True
        for flg in acf_opt_flag_list:
            # Generate CSV file for the current hot function
            # plus the cold functions
            acf_csv_all_hot = call_acf_oprofile(cold_th=0, hot_opts=flg)
            debug('*** Current CSV for all hot functions:\n%s' % (
                    acf_csv_all_hot))

            acf_csv = ''
            # Filter current function only
            for csv_line in acf_csv_all_hot.split('\n'):
                if function in csv_line:
                    acf_csv += csv_line + '\n'
            debug('*** Current CSV for function %s:\n%s' % (function, acf_csv))
            csv_path = write_csv_file(
                flg, function, acf_csv, previous_hot_csv, acf_csv_cold)

            # Build-Run for results with current hot function
            current_cmd = flg + acf_po + csv_path
            result = yield current_cmd, 'base'
            if result == None:
                debug('*** Error during execution of command: %s' % (
                        current_cmd))
                continue

            debug('*** Best result=%s, new result=%s' % (
                    str(best_function_result), str(result)))
            if first_result or (result[1] < best_function_result[1]):
                # Keep these options for the current function
                best_function_csv = acf_csv
                best_function_result = result
                debug('*** Best CSV for function %s (perf= %s):\n%s' % (
                        function, str(best_function_result[1]),
                        best_function_csv))
            first_result = False

        # Record the best for this function
        previous_hot_csv += best_function_csv
        final_hot_csv += best_function_csv

    # Run the best csv for all hot functions together
    csv_path = write_csv_file(
        def_opts, 'best_hot_results', final_hot_csv, acf_csv_cold)

    # Build-Run for results with best hot functions options
    final_cmd = def_opts + acf_po + csv_path
    result = yield final_cmd, 'base'
    debug('*** Final result= %s' % str(result))

    debug('*** Final CSV:\n%s' % str(final_hot_csv))


@generator
def gen_staged(max_iter):
    '''perform staged exploration'''

    tradeoff_coeffs = [5, 1, 0.2]

    def get_tradeoffs(results):
        fselect = atos_lib.atos_client_results.select_tradeoff
        results = map(
            lambda x: fselect(results, perf_size_ratio=x), tradeoff_coeffs)
        # result objects can be none in case of failure
        return filter(lambda x: x is not None, results)

    def res_obj(result, flags, variant):
        return atos_lib.atos_client_results.result(
            {'size': result[0], 'time': result[1], 'target': '*',
             'flags': flags, 'variant': variant})

    def flags_files(dirname):
        def is_flags_file(f):
            return os.path.isfile(f) and re.match(
                '^flags.\w*.cfg$', os.path.basename(f))
        dirfiles = map(
            partial(os.path.join, dirname), os.listdir(dirname))
        return sorted(filter(is_flags_file, dirfiles))

    debug('gen_staged')

    flags_lists = flags_files(generator.atos_config)
    seed(generator.seed)

    results = []
    debug('** explore basic configurations')
    for optlevel in generator.optlevel.values():
        for variant in generator.variants:
            result = yield optlevel, variant
            if result: results.append(res_obj(result, optlevel, variant))

    for fl in flags_lists:
        debug('** explore on flag_list: ' + fl)
        tradeoffs = list(set(get_tradeoffs(results)))
        debug('** compute tradeoff list: ' + str(tradeoffs))
        for tradeoff in tradeoffs:
            debug('**** base tradeoff: ' + str(tradeoff))
            generator.optlist = opt_flag_list(fl)
            generator.baseopts = atos_exp_base_flags(
                '', tradeoff.flags, tradeoff.variant)
            gen = gen_rnd_uniform_deps()
            result = None
            for ic in itertools.count():
                if max_iter and ic >= int(max_iter): break
                try: flags = gen.send(result)
                except StopIteration: break
                flags = ' '.join([tradeoff.flags, flags])
                result = yield flags, tradeoff.variant
                if result: results.append(
                    res_obj(result, flags, tradeoff.variant))
    # return best tradeoffs
    raise StopIteration(dict(zip(tradeoff_coeffs, get_tradeoffs(results))))


@generator
def gen_file_by_file(cold_th, cold_opts, file_list,
                     flags_file=None, staged=None):
    '''perform per file exploration'''

    debug('gen_file_by_file')

    # get object/sample_count list
    obj_list = []
    for line in open(file_list):
        obj, count, part = line.split()
        obj_list.append((obj, int(count), float(part)))
    obj_list.sort(key=lambda x: x[1])

    # build cold/hot objects list
    cold_list, curr_part = [], 0.0
    for (obj, count, part) in obj_list:
        if curr_part + part > float(cold_th): break
        curr_part += part
        cold_list.append(obj)
    hot_list = filter(
        lambda y: y not in cold_list, map(lambda x: x[0], obj_list))
    debug('fbf cold object list: ' + str(cold_list))
    debug('fbf hot object list: ' + str(hot_list))

    csv_dir = os.path.join('.', 'atos-configurations', 'acf_csv_dir')
    if not os.path.isdir(csv_dir): os.mkdir(csv_dir)

    # default options for all hot files
    base_flags = atos_base_flags(
        '', 'base', (generator.baseopts or '', ''))[0].strip()

    def csv_part_opt(obj_flags):
        # build option file containing flags for each object
        sum_flags = atos_lib.md5sum(str(obj_flags.items()))
        csv_name = os.path.join(csv_dir, 'fbf-%s.csv' % (sum_flags))
        debug('fbf run [%s] -> %s' % (str(obj_flags), csv_name))
        with open(csv_name, 'w') as opt_file:
            for (obj, flags) in obj_flags.items():
                if flags: opt_file.write('%s,%s\n' % (obj, flags))
        return '--atos-optfile %s' % csv_name

    # reference run: simple partitioning with base flags
    debug('fbf reference run - hot/cold partition, cold options')
    cold_obj_flags = dict(map(lambda x: (x, cold_opts), cold_list))
    cold_obj_flags.update({'*': base_flags})
    obj_flags = dict(cold_obj_flags.items())
    ref_result = yield csv_part_opt(obj_flags), 'basemin'
    debug('fbf res [%s] -> %s' % (str(obj_flags), str(ref_result)))

    variant_modes = generator.baseopts and ['basemin'] or generator.variants

    # file-by-file staged exploration
    if staged and int(staged):
        for variant in variant_modes:
            debug('fbf staged exploration')
            hot_results = {}
            init_obj_flags = dict(cold_obj_flags)
            for hot_obj in hot_list:
                debug('fbf staged exploration: ' + hot_obj)
                generator.variants = ['base']  # do not loop on variants
                gen, result = gen_staged(int(staged)), None
                while True:
                    try:
                        flags, _ = gen.send(result)
                    except StopIteration:
                        tradeoffs_res = sys.exc_info()[1].args[0]
                        if not tradeoffs_res.keys(): break
                        for coeff in tradeoffs_res.keys():
                            hot_results.setdefault(
                                coeff, {})[hot_obj] = tradeoffs_res[coeff]
                        # explore other files with best_flags for current file
                        perf_coeff = sorted(tradeoffs_res.keys())[-1]
                        best_flags = tradeoffs_res[perf_coeff].flags
                        if base_flags: best_flags = '%s %s' % (
                            base_flags, best_flags)
                        init_obj_flags = dict(
                            init_obj_flags.items() + [(hot_obj, best_flags)])
                        break
                    if base_flags: flags = '%s %s' % (base_flags, flags)
                    obj_flags = dict(
                        init_obj_flags.items() + [(hot_obj, flags)])
                    result = yield csv_part_opt(obj_flags), variant
            debug('fbf staged exploration results: ' + str(hot_results))
            debug('compose best tradeoffs variants')
            for coeff in hot_results.keys():
                debug('compose best tradeoffs variants - coeff: ' + str(coeff))
                obj_flags = dict(init_obj_flags.items())
                for hot_obj in hot_results[coeff].keys():
                    flags = hot_results[coeff][hot_obj].flags
                    if base_flags: flags = '%s %s' % (base_flags, flags)
                    obj_flags[hot_obj] = flags
                yield csv_part_opt(obj_flags), variant

    # run exploration on hot files based on flag list
    if flags_file:
        debug('fbf file exploration')
        opt_flag_list = (flags_file and map(
                lambda x: x.strip(), open(flags_file).readlines()) or [])
        if base_flags: opt_flag_list = map(
            lambda x: '%s %s' % (base_flags, x), opt_flag_list)
        best_obj_flags = dict(cold_obj_flags)
        best_time = ref_result[1]
        for hot_obj in hot_list:
            best_flags = (base_flags, 'base')
            for hot_flags in opt_flag_list:
                obj_flags = dict(
                    best_obj_flags.items() + [(hot_obj, hot_flags)])
                for variant in variant_modes:
                    result = yield csv_part_opt(obj_flags), variant
                    if not result: continue
                    res_size, res_time = result
                    if res_time < best_time:
                        best_time, best_flags = res_time, (hot_flags, variant)
            best_obj_flags.update({hot_obj: best_flags})
        debug('fbf best config %s' % (str(best_obj_flags)))


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
    import __init__
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
        opts.flags != None and opt_flag_list(opts.flags))
    generator.optlevel = opt_flag.optlevel(opts.optlvl.split(','))
    generator.variants = opts.variants.split(',')
    generator.atos_config = opts.atos_configurations
    generator.seed = opts.seed

    if opts.base_opts:
        opts.base_opts = opts.base_opts.split(',')
        if len(opts.base_opts) < 2: opts.base_opts += ['']
        generator.baseopts = atos_exp_base_flags(opts.base_opts)

    if opts.base_opts or args:
        generator.optlevel = opt_flag.optlevel([''])
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
