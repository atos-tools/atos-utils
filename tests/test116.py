#!/usr/bin/env python
#
#

import common
import os, sys, re, random, itertools, functools

from atoslib import utils
from atoslib import atos_lib
from atoslib import generators
from atoslib import process

TEST_CASE = "ATOS generators - staged"


args = common.atos_setup_args(ATOS_DEBUG_FILE="debug.log")


# ####################################################################
#
# creation of fake atos-config directory
#

atos_config = "atos-configurations"
process.commands.mkdir(atos_config)
db = atos_lib.atos_db.db(atos_config)
process.commands.touch("sha1-c")

atos_lib.generate_script(
    "profile.sh", ";" "true", {})
process.commands.mkdir("csv")
process.commands.touch("plugin.so")

with open('atos-configurations/flags.inline.cfg', 'w') as flagsf:
    print >>flagsf, '-fgood1|-fbad1'
    print >>flagsf, '-fgood2|-fgood2'
    print >>flagsf, '-fbad2|-fbad2'
    print >>flagsf, '-fnone1|-fnone1'

with open('atos-configurations/flags.loop.cfg', 'w') as flagsf:
    print >>flagsf, '-fgood3|-fbad3'
    print >>flagsf, '-fgood4|-fbad4'
    print >>flagsf, '-fnone2|-fnone2'

with open('atos-configurations/flags.optim.cfg', 'w') as flagsf:
    print >>flagsf, '-fgood5|-fbad5'
    print >>flagsf, '-fnone3|-fnone3'
    print >>flagsf, '-fcrash1|-fnone4'

#
# generation of profile files (fctmap.out, oprof.out)
#

def profile_gen():
    with open('fctmap.out', 'w') as flagsf:
        print >>flagsf, 'sha1.o SHA1Reset'
        print >>flagsf, 'sha1.o SHA1Result'
        print >>flagsf, 'sha1.o SHA1PadMessage'
        print >>flagsf, 'sha1.o SHA1Input'
        print >>flagsf, 'sha1.o SHA1ProcessMessageBlock'
        print >>flagsf, 'sha.o main'
        print >>flagsf, 'sha.o usage'
    with open('oprof.out', 'w') as flagsf:
        print >>flagsf, 'vma              samples   %       linenr_info                    image_name symbol_name'
        print >>flagsf, '0000000000400b93 353965337 52.2748 (no localization information)  sha1-c  SHA1ProcessMessageBlock'
        print >>flagsf, '0000000000400a86 260243456 38.4336 (no localization information)  sha1-c  SHA1Input'
        print >>flagsf, '00000000004006e4 62914627  9.2914  (no localization information)  sha1-c  main'
        print >>flagsf, '0000000000400f6c 732       0.0001  (no localization information)  sha1-c  SHA1PadMessage'
        print >>flagsf, '0000000000401110 25        0.0000  (no localization information)  sha1-c  __libc_csu_init'
        print >>flagsf, '00000000004009c8 25        0.0000  (no localization information)  sha1-c  SHA1Reset'
        print >>flagsf, '0000000000400a3f 20        0.0000  (no localization information)  sha1-c  SHA1Result'

#
# estimation of time/size results given a set of flags
#

def get_cfg_result(cfg):
    good_flags = [
        ["-fgood1"], ["-fgood2"], ["-fgood3"], ["-fgood4"], ["-fgood5"],
        ["-fgood-g1-1", "-fgood-g1-2"],
        ["-fgood-g2-1", "-fgood-g2-2", "-fgood-g2-3"],
        ]
    bad_flags = [
        ["-fbad1"], ["-fbad2"], ["-fbad3"], ["-fbad4"], ["-fbad5"],
        ["-fbad-g1-1", "-fbad-g1-2"],
        ["-fbad-g2-1", "-fbad-g2-2", "-fbad-g2-3"],
        ]
    crash_flags = [["-fcrash1"]]
    #
    flag_list = generators.optim_flag_list.parse_line(cfg.flags)
    nb_good = len(
        filter(lambda f: (len(set(f) - set(flag_list)) == 0), good_flags))
    nb_bad = len(
        filter(lambda f: (len(set(f) - set(flag_list)) == 0), bad_flags))
    nb_crash = len(
        filter(lambda f: (len(set(f) - set(flag_list)) == 0), crash_flags))
    if nb_crash: return None, None
    # file-by-file acf flag
    acf_file_flag = filter(
        functools.partial(re.search, '--atos-optfile'),
        flag_list)
    if acf_file_flag:
        fbf_file = acf_file_flag[0][14:].strip('= ')
        fbf_config = (
            generators.gen_file_by_file_cfg.read_config_csv(fbf_file))
        for (obj, flags) in fbf_config.items():
            flags = generators.optim_flag_list.parse_line(flags)
            acf_nb_good = len(
                filter(lambda f: (len(set(f) - set(flags)) == 0), good_flags))
            acf_nb_bad = len(
                filter(lambda f: (len(set(f) - set(flags)) == 0), bad_flags))
            nb_good += acf_nb_good * 0.2
            nb_bad += acf_nb_bad * 0.2
    # function-by-function acf flag
    acf_func_flag = filter(
        functools.partial(re.search, '-fplugin-arg-acf_plugin-csv_file'),
        flag_list)
    if acf_func_flag:
        fbf_file = re.search(
            '-fplugin-arg-acf_plugin-csv_file=([^ ]*)',
            acf_func_flag[0]).group(1)
        fbf_config = (
            generators.gen_function_by_function_cfg.read_config_csv(fbf_file))
        for (obj, flags) in fbf_config.items():
            flags = generators.optim_flag_list.parse_line(flags)
            acf_nb_good = len(
                filter(lambda f: (len(set(f) - set(flags)) == 0), good_flags))
            acf_nb_bad = len(
                filter(lambda f: (len(set(f) - set(flags)) == 0), bad_flags))
            nb_good += acf_nb_good * 0.2
            nb_bad += acf_nb_bad * 0.2
    score = 1000 - ((nb_good - nb_bad) * 100)
    return float(score), score

#
# exploration loop and database update
#

def db_add_result(cfg, variant_id=None):
    db = atos_lib.atos_db.db(atos_config)
    time, size = get_cfg_result(cfg)
    if None in [time, size]:
        return None
    new_entry = {
        'variant': variant_id or atos_lib.variant_id(options=cfg.flags),
        'target': 'target',
        'conf': cfg.flags or '', 'time': time, 'size': size,
        'cookies': ','.join(cfg.cookies or [])
        }
    db.add_results([new_entry])
    return new_entry

def generator_loop(generator):
    all_results = []
    for cfg in generator:
        if cfg.profile: profile_gen()
        new_res = db_add_result(cfg)
        if new_res: all_results.append(new_res)
    return all_results


# ####################################################################
#
#
#

ref_entry = db_add_result(
    generators.config())

new_entry = db_add_result(
    generators.config(
        flags="-fgood1 -fbad1 -fgood-g1-1 -fgood2 "
        "-fgood-g1-2 -fbad-g1-1 -fbad-g1-2 -fgood3 -fbad-g2-1"),
    variant_id="VAR-1")
# good: 4: fgood1 fgood2 fgood3 fgood-g1-1_fgood-g1-2
# bad : 2: -fbad1 fbad-g1-1_fbad-g1-2
# score = 4 - 2 = 2 -> 1000 - 2 * 100 -> 800
assert new_entry['size'] == 800
assert new_entry['time'] == 800.0


generator = generators.gen_flags_pruning(
    variant_id='VAR-1',
    tradeoff=5.0, threshold=0.0,
    configuration_path=atos_config)
generator_loop(generator)
assert generator.final_flags == [
    '-fgood1', '-fgood2']


generator = generators.gen_flags_pruning(
    variant_id='VAR-1',
    update_reference=True,
    tradeoff=5.0, threshold=0.0,
    configuration_path=atos_config)
generator_loop(generator)
assert generator.final_flags == [
    '-fgood1', '-fgood-g1-1', '-fgood2', '-fgood-g1-2', '-fgood3']


generator = generators.gen_flags_pruning(
    variant_id='VAR-1',
    one_by_one=True,
    tradeoff=5.0, threshold=0.0,
    configuration_path=atos_config)
generator_loop(generator)
assert generator.final_flags == [
    '-fgood1', '-fgood-g1-1', '-fgood2', '-fgood-g1-2', '-fgood3']


generator = generators.gen_flags_pruning(
    variant_id='VAR-1',
    tradeoff=5.0, threshold=0.0,
    selection_size=2,
    configuration_path=atos_config)
generator_loop(generator)
assert generator.final_flags == [
    '-fgood2', '-fgood3', '-fbad-g2-1']


generator = generators.gen_flags_pruning(
    variant_id='VAR-1',
    tradeoff=5.0, threshold=0.0,
    random_selection=1,
    configuration_path=atos_config)
generator_loop(generator)


generator = generators.gen_flags_pruning(
    variant_id='VAR-1',
    tradeoff=5.0, threshold=-10,
    configuration_path=atos_config)
generator_loop(generator)


#
# ACF FUNCTION
#

generator = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O2", per_func_nbiters=100, optim_levels="-O2",
    configuration_path=atos_config)
results = generator_loop(generator)


generator = generators.gen_flags_pruning(
    variant_id=results[-1]['variant'],
    update_reference=True,
    tradeoff=5.0, threshold=0.0,
    configuration_path=atos_config)
generator_loop(generator)


#
# ACF FILE
#

generator = generators.gen_file_by_file(
    imgpath=".", csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O2", per_file_nbiters=100, optim_levels="-O2",
    configuration_path=atos_config)
results = generator_loop(generator)


generator = generators.gen_flags_pruning(
    variant_id=results[-1]['variant'],
    update_reference=True,
    tradeoff=5.0, threshold=0.0,
    configuration_path=atos_config)
generator_loop(generator)
