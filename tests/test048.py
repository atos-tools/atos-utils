#!/usr/bin/env python
#
#

import common

TEST_CASE = "ATOS process module"

from atos import process

status = process.system("false", print_output=False)
assert status == 1

status = process.system("true", check_status=True)
assert status == 0

status, output = process.system("echo 1", get_output=True)
assert status == 0 and output.strip() == '1'

status, output = process.system(
    "ls unknownfile", get_output=True)
assert status > 0 and output == ''

status, output = process.system(
    "ls unknownfile", get_output=True, output_stderr=True)
assert status > 0 and output != ''

process.setup({'dryrun': True})
status = process.system("false")
assert status == 0
