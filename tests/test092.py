#!/usr/bin/env python
#
#

import common
import os
import random
import itertools
import re
import tempfile

from atoslib import atos_lib, utils
from atoslib import generators


TEST_CASE = "ATOS generators - unit tests"


# common setup

args = common.atos_setup_args(ATOS_DEBUG_FILE="debug.log")
sha1dir = os.path.join(common.SRCDIR, 'examples', 'sha1-c')
status = utils.invoque(
    "atos-init", args, run_script=os.path.join(sha1dir, "run.sh"),
    build_script="gcc -o sha1-c %s %s" % (
        os.path.join(sha1dir, "sha.c"), os.path.join(sha1dir, "sha1.c")))
assert status == 0


#
# config_generator
#

generator = generators.config_generator()
try:
    generator.next()
    assert(False)
except generators.config_generator.UnimplementedException:
    pass
except:
    assert(False)


#
# gen_config
#

idx = 0
for cfg in generators.gen_config(variant='base'):
    idx += 1
assert(idx == 1)
assert(len(cfg.__dict__.items()) == 1)
assert(cfg.variant == 'base')


#
# gen_maxiters
#

idx = 0
generator = generators.gen_maxiters(generators.gen_config(), 0)
for cfg in generator():
    idx += 1
assert(idx == 0)
generator = generators.gen_maxiters(generators.gen_config())
for cfg in generator():
    idx += 1
assert(idx == 1)
generator = generators.gen_maxiters(generators.gen_config(), 1)
for cfg in generator():
    idx += 1
assert(idx == 2)


#
# gen_base
#

variant = 'base'
levels = '-O1,-O2,-O3'
expected_flgs = levels.split(',')
for cfg in generators.gen_base(generators.gen_config(variant=variant),
                    levels)():
    print str(cfg)
    assert(cfg.flags == expected_flgs.pop(0))
    assert(cfg.variant == variant)


#
# gen_variants
#

levels = '-O1,-O2,-O3'
variants = 'base,lto,fdo,fdo+lto'
expected_flgs = levels.split(',')
expected_vars = variants.split(',')
generator = generators.gen_variants(
    generators.gen_base(generators.gen_config(), levels), variants)
idx = 0
for cfg in generator():
    print str(cfg)
    assert(cfg.flags == expected_flgs[idx / len(expected_vars)])
    assert(cfg.variant == expected_vars[idx % len(expected_vars)])
    idx += 1


#
# gen_flags_file
#

flags = ['-O2', '-O2 -funroll-loops']
tmpf = tempfile.NamedTemporaryFile(delete=False)
tmpname = tmpf.name
try:
    tmpf.write("# Test flags\n")
    for flag in flags:
        tmpf.write(" %s # test flags\n" % flag)
    tmpf.close()
    generator = generators.gen_flags_file(
        generators.gen_config(variant='base'), tmpname)
    for cfg in generator():
        print str(cfg)
        assert(cfg.flags == flags.pop(0))
        assert(cfg.variant == 'base')
finally:
    os.unlink(tmpname)

# case of empty flag list
tmpf = tempfile.NamedTemporaryFile(delete=False)
tmpname = tmpf.name
try:
    tmpf.write("# Test flags\n")
    tmpf.close()
    generator = generators.gen_flags_file(
        generators.gen_config(flags='-O0', variant='base'), tmpname)
    nbcfg = 0
    for cfg in generator():
        nbcfg += 1
        print str(cfg)
        assert(cfg.flags == '-O0')
        assert(cfg.variant == 'base')
    assert nbcfg == 1
finally:
    os.unlink(tmpname)


#
# gen_rnd_uniform_deps
#

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
    tmpf.write("--param inline-call-cost=[4..32,2]\n")
    tmpf.write("-finline: --param inline-call-cost=\n")
    tmpf.write("-finline: -finline-small\n")
    tmpf.write("=> -O2\n")
    tmpf.write("-O2 => -finline\n")
    tmpf.close()
    generator = generators.gen_maxiters(
        generators.gen_rnd_uniform_deps(
            generators.gen_config(), tmpname, levels), 6)
    for cfg in generator():
        print str(cfg)
finally:
    os.unlink(tmpname)



#
# optim_flag_list
#

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
    fl = generators.optim_flag_list([tmpname])
    print fl.flag_list
    for flag in fl.flag_list:
        print flag.values()
    assert fl.find("-fno-inline-small")
    assert not fl.find("unknown")
finally:
    os.unlink(tmpname)


#
# gen_chained_exploration
#

# case of empty chain

for cfg in generators.gen_chained_exploration(
    generators_args=[], expl_cookie='expl_cookie',
    configuration_path='atos-configurations')():
    print str(cfg)
    assert 0
