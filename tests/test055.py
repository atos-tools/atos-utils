#!/usr/bin/env python
#
#

import common

TEST_CASE = "ATOS open locked dryrun"

from atos import process

with open("test", "w") as tmpfile:
    tmpfile.write("hello\n")

process.setup({'dryrun': True})
with process.open_locked('test') as inf:
    out = inf.readline()
    assert out == 'hello\n'

with process.open_locked('aa', 'w') as outf:
    outf.write(1)

