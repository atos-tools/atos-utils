#!/usr/bin/env python
#
#

import common
import os
from atoslib import utils, atos_lib

TEST_CASE = "ATOS atos-run invocation"

args = common.atos_setup_args(ATOS_DEBUG_FILE="debug.log")

with open("./test.c", "w") as testf:
    print >>testf, '#include <stdlib.h>'
    print >>testf, '#include <stdio.h>'
    print >>testf, 'int main(void)'
    print >>testf, '{'
    print >>testf, '  char *remote = getenv("REMOTE_PROFILE_DIR");'
    print >>testf, '  char *local = getenv("LOCAL_PROFILE_DIR");'
    print >>testf, '  char *error = getenv("ERROR_CODE");'
    print >>testf, '  fprintf(stdout, "hello\\n");'
    print >>testf, '  if (remote) fprintf(stdout, "remote %s\\n", remote);'
    print >>testf, '  if (local) fprintf(stdout, "local %s\\n", local);'
    print >>testf, '  fprintf(stdout, "test %s\\n", (getenv("TIME") ?: "99"));'
    print >>testf, '  fprintf(stdout, "user %s\\n", (getenv("TIME") ?: "99"));'
    print >>testf, '  if (error) return atoi(error);'
    print >>testf, '  return 0;'
    print >>testf, '}'

atos_lib.generate_script("build.sh", ["gcc", "test.c"], {})
atos_lib.generate_script("run.sh", ["./a.out"], {})
atos_lib.generate_script("get_res.sh", ";"
        "echo ATOS: aaa: size: 2000;"
        "x=`cat - | grep test | awk '{ print ($2 + 1) * 1000 }'`;"
        "echo ATOS: aaa: time: $x", {})
atos_lib.generate_script("get_res_2.sh", ";"
        "echo ATOS: bin1: size: 1001;"
        "echo ATOS: bin1: time: 1000;"
        "echo ATOS: bin2: size: 2002;"
        "echo ATOS: bin2: time: 2000;"
        "echo ATOS: bin3: size: 3003;"
        "echo ATOS: bin3: time: 3000;", {})



status = utils.invoque(
    "atos-init", args, build_script="./build.sh", run_script="./run.sh")
assert status == 0
assert len(common.atos_results({"variant" : "REF"})) == 1

#
# -r, --record
# -a OPTIONS, --options OPTIONS
#

status = utils.invoque("atos-run", args, options="-O2", record=True)
assert status == 0
results = common.atos_results({"variant" : "OPT-O2"})
assert len(results) == 1 and results[0]["time"] == 99000

os.putenv("TIME", "90")
status = utils.invoque("atos-run", args, options="-O3", record=True)
assert status == 0
results = common.atos_results({"variant" : "OPT-O3"})
assert len(results) == 1 and results[0]["time"] == 90000

#
# -g GOPTS, --genprof GOPTS
#

status = utils.invoque("atos-run", args, options="-O2", gopts="-O1", record=True)
assert status == 0
results = common.atos_results({"variant" : "OPT-fprofile-generate-O1-O2"})
assert len(results) == 1

#
# -u UOPTS, --useprof UOPTS
#

status = utils.invoque("atos-run", args, options="-O2", uopts="-O1", record=True)
assert status == 0
results = common.atos_results({"variant" : "OPT-fprofile-use-O1-O2"})
assert len(results) == 1


#
# -w VARIANT, --variant VARIANT
#

os.putenv("TIME", "101")
status = utils.invoque("atos-run", args, variant="X1", record=True)
assert status == 0
results = common.atos_results({"variant" : "X1"})
assert len(results) == 1 and results[0]["time"] == (101 * 1000)
assert results[0]["target"] == "a.out"

#
# -n NBRUNS, --nbruns NBRUNS
#

os.putenv("TIME", "102")
status = utils.invoque("atos-run", args, variant="X2", record=True, nbruns=4)
assert status == 0
results = common.atos_results({"variant" : "X2"})
assert len(results) == 4 and results[0]["time"] == (102 * 1000)

status = utils.invoque("atos-run", args, variant="X3", record=True, nbruns=0)
assert status == 0
assert not common.atos_results({"variant" : "X3"})

#
# positional arguments: command
#

status = utils.invoque("atos-run", args, variant="X4", record=True, nbruns=1,
                       command=["env", "TIME=103", "./a.out"])
assert status == 0
results = common.atos_results({"variant" : "X4"})
assert len(results) == 1 and results[0]["time"] == (103 * 1000)

#
# -o OUTPUT_FILE, --output OUTPUT_FILE
#

os.putenv("TIME", "104")
status = utils.invoque("atos-run", args, variant="X5", record=True, output_file="x5.txt")
assert status == 0
assert not common.atos_results({"variant" : "X5"})
assert "ATOS: a.out: X5: time: 104000.0\n" in open("x5.txt").readlines()

#
# -s, --silent
#

status = utils.invoque("atos-run", args, variant="X6", record=True, silent=True)
assert status == 0
assert not common.atos_results({"variant" : "X6"})

#
# -i ID, --identifier ID
#

os.putenv("TIME", "106")
status = utils.invoque("atos-run", args, variant="X7", record=True, id="ZZZ")
assert status == 0
results = common.atos_results({"variant" : "X7"})
assert len(results) == 1 and results[0]["time"] == (106 * 1000)
assert results[0]["target"] == "ZZZ"

#
# -e EXE, --exe EXE
#

os.putenv("TIME", "107")
status = utils.invoque("atos-run", args, variant="X8", record=True, exe="./a.out")
assert status == 0
results = common.atos_results({"variant" : "X8"})
assert len(results) == 1 and results[0]["time"] == 107 * 1000
assert results[0]["size"] == common.atos_results({"variant" : "X7"})[0]["size"]

#
# -b REMOTE_PATH, --remote_path REMOTE_PATH
#

os.putenv("TIME", "108")
status = utils.invoque("atos-run", args, gopts="-O2", variant="X9",
                       record=True, remote_path="ZZZ")
assert status == 0
results = common.atos_results({"variant" : "X9"})
assert len(results) == 1 and results[0]["time"] == 108 * 1000
assert common.grep(common.atos_log_name(variant="X9"), "remote ZZZ")
local_line = common.grep(common.atos_log_name(variant="X9"), "local")
expected_prof = os.path.join(
    os.getcwd(), "atos-configurations", "profiles",
    str(atos_lib.hashid(atos_lib.pvariant_id("-O2"))))
assert local_line and local_line[0] == "local " + expected_prof

#
# -t RESULTS_SCRIPT, --results-script RESULTS_SCRIPT
#

os.putenv("TIME", "109")
status = utils.invoque("atos-run", args, variant="X10", record=True,
                       results_script="./get_res.sh")
assert status == 0
results = common.atos_results({"variant" : "X10"})
assert len(results) == 1 and results[0]["time"] == (110 * 1000)



status = utils.invoque("atos-run", args, options="-O4", record=True,
                       results_script="./get_res_2.sh")
assert status == 0
results = common.atos_results({"variant" : "OPT-O4", 'target': 'bin1'})
assert len(results) == 1 and results[0]["time"] == 1000 and results[0]["size"] == 1001
results = common.atos_results({"variant" : "OPT-O4", 'target': 'bin2'})
assert len(results) == 1 and results[0]["time"] == 2000 and results[0]["size"] == 2002
results = common.atos_results({"variant" : "OPT-O4", 'target': 'bin3'})
assert len(results) == 1 and results[0]["time"] == 3000 and results[0]["size"] == 3003


# run failure

os.putenv("TIME", "120")
os.putenv("ERROR_CODE", "1")
status = utils.invoque("atos-run", args, variant="X11", record=True)
assert status != 0
