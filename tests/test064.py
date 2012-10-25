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
from atos import generators

TEST_CASE = "ATOS generators - staged"

args = common.atos_setup_args(ATOS_DEBUG_FILE="debug.log")

sha1dir = os.path.join(common.SRCDIR, 'examples', 'sha1-c')

status = utils.invoque(
    "atos-init", args, run_script=os.path.join(sha1dir, "run.sh"),
    build_script="gcc -o sha1-c %s %s" % (
        os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")),
    no_run=True)
assert status == 0


# reference results
entry = {'target': 'sha1-c', 'variant': 'REF', 'conf': '',
         'time': 10000, 'size': 10000}
db = atos_lib.atos_db.db('atos-configurations')
atos_lib.atos_client_db(db).add_result(entry)

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


def cfg_result(cfg):
    flags_time_size = {
        ('-O2', 'base'): (1000, 1000),
        ('-O2 -1111', 'base'): (900, 1000),
        ('-O2 -1111 -3333', 'base'): (800, 1000),
        ('-O2 -1111 -3333 -5555', 'base'): (700, 1000),
        ('-O2', 'fdo'): (950, 1050),
        ('-O2 -1111', 'fdo'): (850, 1050),
        # (*, *): (2000, 2000)
        }
    time, size = flags_time_size.get(
        (cfg.flags, cfg.variant), (2000, 2000))
    return 'sha1-c', time, size


#
#   gen_staged
#     gen_staged(optim_levels='', optim_variants='', nbiters='',
#        configuration_path='atos-configurations', seed='0')
#

gen = generators.gen_staged()
cfg = generated_configs(gen)
# no optim_levels: nothing to generate
assert len(cfg) == 0

gen = generators.gen_staged(optim_levels='-O2,-O3', optim_variants='base,fdo')
cfg = generated_configs(gen)
# (O2, base), (O3, base), (O2, fdo), (O3, fdo)
assert len(cfg) == 4
assert len(query_configs(cfg, flags='-O2', variant='base')) == 1
assert len(query_configs(cfg, flags='-O2', variant='fdo')) == 1
assert len(query_configs(cfg, flags='-O3', variant='base')) == 1
assert len(query_configs(cfg, flags='-O3', variant='fdo')) == 1

with open('atos-configurations/flags.inline.cfg', 'w') as flagsf:
    print >>flagsf, '-1111|-2222'
with open('atos-configurations/flags.loop.cfg', 'w') as flagsf:
    print >>flagsf, '-3333|-4444'
with open('atos-configurations/flags.optim.cfg', 'w') as flagsf:
    print >>flagsf, '-5555|-6666'

gen = generators.gen_staged(
    optim_levels='-O2,-O3', optim_variants='base', nbiters='50')
cfg = generated_configs(gen, cfg_to_res=cfg_result)
# 2 base configs (O2, O3)
# + (3 * flags_file) * (1 tradeoff variant) * 50
assert len(cfg) == 152
assert query_configs(cfg, flags='-O2')
assert query_configs(cfg, flags='-O3')
assert query_configs(cfg, flags='-O2 -1111')
assert query_configs(cfg, flags='-O2 -2222')
assert not query_configs(cfg, flags='-O2 -2222 .*')
assert query_configs(cfg, flags='-O2 -1111 -3333')
assert query_configs(cfg, flags='-O2 -1111 -4444')
assert not query_configs(cfg, flags='-O2 -1111 -4444 .*')
assert query_configs(cfg, flags='-O2 -1111 -3333 -5555')
assert query_configs(cfg, flags='-O2 -1111 -3333 -6666')

gen = generators.gen_staged(
    optim_levels='-O2,-O3', optim_variants='base,fdo', nbiters='50')
cfg = generated_configs(gen, cfg_to_res=cfg_result)
# (O2, O3) * 2 (base, fdo)
# + 50 * inline * 2 (base, fdo)
# + 50 * loop * 2 (base, fdo)
# + 50 * optim * 2 (base, fdo)
assert len(cfg) == 254
