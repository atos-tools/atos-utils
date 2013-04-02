#!/usr/bin/env python
#
#

import common
import os
import random
import itertools
import re
import tempfile

from atoslib import generators


TEST_CASE = "ATOS generators - unit tests"


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
