#!/usr/bin/env python
#
#

import common

TEST_CASE = "ATOS process module"

from atos import process

args = process.cmdline2list("command '' a\\\ file")
cmd = process.list2cmdline(args)
assert cmd == "command '' a\\\ file"

status = process.system("false", print_output=False)
assert status == 1

status = process.system("true", check_status=True)
assert status == 0

status, output = process.system("echo 1", get_output=True)
assert status == 0 and output.strip() == '1'

status, output = process.system(u"echo 2", get_output=True)
assert status == 0 and output.strip() == '2'

status, output = process.system([u"echo", u"3"], get_output=True)
assert status == 0 and output.strip() == '3'

status, output = process.system(
    "ls unknownfile", get_output=True)
assert status > 0 and output == ''

status, output = process.system(
    "ls unknownfile", get_output=True, output_stderr=True)
assert status > 0 and output != ''

status, output = process.system(
    "echo 12", stdin_str='aaa' * 100000, get_output=True)
assert status == 0 and output == '12\n'

status, output = process.system(
    "cat -", stdin_str='z' * 100000, get_output=True)
assert status == 0 and output == 'z' * 100000

status = process.system(
    "echo 12", stdin_str='aaa' * 100000)
assert status == 0

process.setup({'dryrun': True})
status = process.system("false")
assert status == 0

