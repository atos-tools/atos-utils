#!/usr/bin/env python
#
#

import common
import os
import random
import itertools
import re

from atos import utils
from atos import atos_lib
from atos import process
from atos import generators
from atos import profile


TEST_CASE = "ATOS generators - function_by_function"

args = common.atos_setup_args(ATOS_DEBUG_FILE="debug.log")

sha1dir = os.path.join(common.SRCDIR, 'examples', 'sha1-c')

atos_lib.generate_script("profile.sh", ";" "true", {})

status = utils.invoque(
    "atos-init", args,
    run_script=os.path.join(sha1dir, "run.sh"),
    build_script="gcc -o sha1-c %s %s" % (
        os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")),
    prof_script = "./profile.sh",
    no_run=True)
assert status == 0


def query_configs(cfg, **kwargs):
    def match(x):
        return all(
            map(lambda (k, v):
                    re.match('^%s$' % v, getattr(x, k, None) or ''),
                    kwargs.items()))
    return filter(match, cfg)


def generated_configs(gen, max_iter=None, cfg_to_res=None):
    random.seed(0)
    configs = []
    for ic in itertools.count():
        if ic == max_iter: break
        try:
            cfg = gen.send(None)
            configs.append(cfg)
            if not cfg_to_res: continue
            target, time, size = cfg_to_res(cfg)
            variant = atos_lib.variant_id(cfg.flags) + '-' + cfg.variant
            entry = {'target': target, 'variant': variant, 'conf': cfg.flags,
                     'cookies': ','.join(list(set(cfg.cookies or [])))}
            entry.update({'time': time, 'size': size})
            db = atos_lib.atos_db.db('atos-configurations')
            atos_lib.atos_client_db(db).add_result(entry)
        except StopIteration: break
    return configs


# reference results
entry = {'target': 'sha1-c', 'variant': 'REF', 'conf': '',
         'time': 1000, 'size': 1000}
db = atos_lib.atos_db.db('atos-configurations')
atos_lib.atos_client_db(db).add_result(entry)

# oprofile results
with open("oprof.out", "w") as oprof:
    print >>oprof, "vma              samples   %       linenr_info                    image_name symbol_name"

    print >>oprof, "0000000000400b93 353965337 52.2748 (no localization information)  sha1-c  SHA1ProcessMessageBlock"
    print >>oprof, "0000000000400a86 260243456 38.4336 (no localization information)  sha1-c  SHA1Input"

    print >>oprof, "00000000004006e4 62914627  9.2914  (no localization information)  sha1-c  main"
    print >>oprof, "0000000000400f6c 732       0.0001  (no localization information)  sha1-c  SHA1PadMessage"
    print >>oprof, "0000000000401110 25        0.0000  (no localization information)  sha1-c  __libc_csu_init"
    print >>oprof, "00000000004009c8 25        0.0000  (no localization information)  sha1-c  SHA1Reset"
    print >>oprof, "0000000000400a3f 20        0.0000  (no localization information)  sha1-c  SHA1Result"

# testing function partitionning

cold_funcs, hot_funcs = profile.partition_symbols_loc(".", 0, "oprof.out")
assert len(cold_funcs) == 7 and not hot_funcs
cold_funcs, hot_funcs = profile.partition_symbols_loc(".", 100, "oprof.out")
assert len(hot_funcs) == 7 and not cold_funcs
# todo: no reliable debug infos, need to actually run the profile
# assert all(map(lambda (s, l): l is None, hot_funcs))

utils.invoque("atos-build", args, options="-O2 -g")
cold_funcs, hot_funcs = profile.partition_symbols_loc(".", 100, "oprof.out")
assert len(hot_funcs) == 7 and not cold_funcs
# todo: check that debugs infos are correctly set
# we must give right addresses for that in oprof.out

cold_funcs, hot_funcs = profile.partition_symbols_loc(".", 70, "oprof.out")
assert len(hot_funcs) == 2 and len(cold_funcs) == 5
hot_funcs_syms = map(lambda (s, l): s, hot_funcs)
assert 'SHA1ProcessMessageBlock' in hot_funcs_syms
assert 'SHA1Input' in hot_funcs_syms

utils.invoque("atos-build", args, options="-O2")
process.commands.mkdir("csv")
process.commands.touch("plugin.so")

#
#   gen_function_by_function
#     gen_function_by_function(
#        acf_plugin_path, hwi_size, prof_script, imgpath, csv_dir,
#        hot_th, cold_opts='-Os noinline cold', flags_file='', per_func_nbiters=0,
#        base_flags='', base_variant='', optim_variants='')
#

# testing cold runs (base_flags, base_variant, optim_variants)

gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="7",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os")
cfg = generated_configs(gen)
assert len(cfg) == 2  # default run + cold options
assert query_configs(cfg, flags='-O2', variant='base')
assert query_configs(
    cfg, flags='-O2 -fplugin=plugin.so .*', variant='base')

gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O3")
cfg = generated_configs(gen)
assert len(cfg) == 2  # default run + cold options
assert query_configs(cfg, flags='-O3', variant='base')
assert query_configs(cfg, flags='-O3 -fplugin=.*', variant='base')

gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O4", base_variant="fdo", optim_variants='base,lto')
cfg = generated_configs(gen)
assert len(cfg) == 2  # default run + cold options
assert query_configs(cfg, flags='-O4', variant='fdo')
assert query_configs(cfg, flags='-O4 -fplugin=.*', variant='fdo')

gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O5", optim_variants='base,lto')
cfg = generated_configs(gen)
assert len(cfg) == 2  # default run + cold options
assert query_configs(cfg, flags='-O5', variant='base')
assert query_configs(cfg, flags='-O5 -fplugin=.*', variant='base')

# testing hot_th and cold_opts

gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O2")
cfg = generated_configs(gen)
assert len(cfg) == 2  # default run + cold options
assert query_configs(cfg, flags='-O2', variant='base')
assert query_configs(cfg, flags='-O2 -fplugin=.*', variant='base')

cold_cfg = query_configs(cfg, flags='-O2 -fplugin=.*', variant='base')[0]
cold_csv = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", cold_cfg.flags)
assert os.path.isfile(cold_csv)
cold_csv_lines = open(cold_csv).readlines()
assert len(cold_csv_lines) == 5
cold_csv_flags = set(map(
            lambda x: ','.join(x.strip().split(',')[2:]), cold_csv_lines))
assert 'optimize,s' in cold_csv_flags

cold_csv_funcs = set(map(lambda x: x.strip().split(',')[0], cold_csv_lines))
assert cold_csv_funcs == set(
    ['SHA1Result', 'SHA1PadMessage', 'main', 'SHA1Reset', '__libc_csu_init'])


gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="99", cold_opts="-O0 -fnothing",
    base_flags="-O2")
cfg = generated_configs(gen)
cold_cfg = query_configs(cfg, flags='-O2 -fplugin=.*', variant='base')[0]
cold_csv = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", cold_cfg.flags)
assert os.path.isfile(cold_csv)
cold_csv_lines = open(cold_csv).readlines()
assert len(cold_csv_lines) == 8 # 4 cold funcs * 2 flags
cold_csv_flags = set(map(
            lambda x: ','.join(x.strip().split(',')[2:]), cold_csv_lines))
assert cold_csv_flags == set(['optimize,0', 'optimize,nothing'])
cold_csv_funcs = set(map(lambda x: x.strip().split(',')[0], cold_csv_lines))
assert cold_csv_funcs == set(
    ['SHA1Result', 'SHA1PadMessage', 'SHA1Reset', '__libc_csu_init'])


# testing flags_file exploration

with open('flags.txt', 'w') as flagsf:
    print >>flagsf, '-fflag1'
    print >>flagsf, '-fflag2 -fflag3'
    print >>flagsf, '-fflag4'

def cfg_result(cfg):
    csvfile = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", cfg.flags)
    if not os.path.isfile(csvfile): csvfile = None
    nb_flags1 = csvfile and len(common.grep(csvfile, "flag1")) or 0
    nb_flags2 = csvfile and len(common.grep(csvfile, "flag2")) or 0
    nb_flags3 = csvfile and len(common.grep(csvfile, "flag3")) or 0
    time = 1000 - (100 * nb_flags2) - (200 * nb_flags1) - (10 * nb_flags3)
    size = 1000 - (100 * nb_flags1) - (200 * nb_flags2) - (10 * nb_flags3)
    return 'sha1-c', time, size

process.commands.mkdir("csv2")
gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv2", hot_th="70", cold_opts="-Os",
    base_flags="-O2", flags_file="flags.txt")
cfg = generated_configs(gen, cfg_to_res=cfg_result)
cfg = filter(lambda x: not x.profile, cfg)
# cold + (2 funcs * (3 flags) + 3 tradeoffs
assert len(cfg) == 10

# best-perf tradeoff composition (flags1, flags1)
size_cfg = cfg[-3]
size_csv = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", size_cfg.flags)
assert len(common.grep(size_csv, "flag1")) == 2
assert len(common.grep(size_csv, "flag2")) == 0

# best-size tradeoff composition (flags2, flags2)
perf_cfg = cfg[-1]
perf_csv = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", perf_cfg.flags)
assert len(common.grep(perf_csv, "flag2")) == 2
assert len(common.grep(perf_csv, "flag1")) == 0

# todo: check function names, csv format, cold funcs and cold opts...


# testing staged exploration

with open('atos-configurations/flags.inline.cfg', 'w') as flagsf:
    print >>flagsf, '-fflag1|-fflag2'

with open('atos-configurations/flags.loop.cfg', 'w') as flagsf:
    print >>flagsf, '-fflag3|-fflag3'

with open('atos-configurations/flags.optim.cfg', 'w') as flagsf:
    print >>flagsf, '#'

gen = generators.gen_function_by_function(
    acf_plugin_path="plugin.so", hwi_size="8",
    prof_script="./profile.sh", imgpath=".",
    csv_dir="csv", hot_th="70", cold_opts="-Os",
    base_flags="-O2", per_func_nbiters=100, optim_levels="-O2")
cfg = generated_configs(gen, cfg_to_res=cfg_result)
cfg = filter(lambda x: not x.profile, cfg)
# cold + 3 final tradeoffs
# + (2 funcs * (1 base + inline * 100 + loop * 100 * 2 tradeoffs + optim * 1 * 2 tradeoffs)
assert len(cfg) == 610

# best-perf tradeoff composition (flags1, flags1)
size_cfg = cfg[-3]
size_csv = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", size_cfg.flags)
assert len(common.grep(size_csv, "flag1")) == 2
assert len(common.grep(size_csv, "flag3")) == 2
assert len(common.grep(size_csv, "flag2")) == 0

# best-size tradeoff composition (flags2, flags2)
perf_cfg = cfg[-1]
perf_csv = re.sub(".*csv_file=([A-Za-z0-9/\-\.]*).*", "\\1", perf_cfg.flags)
assert len(common.grep(perf_csv, "flag2")) == 2
assert len(common.grep(size_csv, "flag3")) == 2
assert len(common.grep(perf_csv, "flag1")) == 0
