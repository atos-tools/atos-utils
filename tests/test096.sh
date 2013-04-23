#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS web"

$SRCDIR/config/python_checks | grep requests | grep ok >/dev/null || skip "requests module not available"

test_cleanup() {
    [ "$server_pid" = "" ] || kill $server_pid
}

echo "spawn the server process"
python $ROOT/tests/server-test096.py > test096-server.log 2>&1 &
server_pid=$!
echo " pid=$server_pid"

# Wait for the server to find the right port number
do_loop=true
while [ $do_loop != false ]
do
  if [ -f server.conf ]
  then
    line=$(egrep "port=[0-9]+" server.conf 2>/dev/null || true)
    if [ "$line" != "" ]
    then
      port=$(echo $line | cut -d'=' -f2)
      echo " The server is listening on 127.0.0.1:$port"
      do_loop=false
    else
      sleep 1
    fi
  else
    sleep 1
  fi
done

# Doing the tests now
echo "================="
echo "Running the tests"
echo "================="

$ROOT/bin/atos web --server=127.0.0.1:$port project list > results
$ROOT/bin/atos web --server=127.0.0.1:$port project details 1 >> results

$ROOT/bin/atos web --server=127.0.0.1:$port experiment --project=1 list >> results
$ROOT/bin/atos web --server=127.0.0.1:$port experiment --project=1 details 1 >> results

$ROOT/bin/atos web --server=127.0.0.1:$port target --project=1 --experiment=1 list >> results
$ROOT/bin/atos web --server=127.0.0.1:$port target --project=1 --experiment=1 details 1 >> results

$ROOT/bin/atos web --server=127.0.0.1:$port run --project=1 --experiment=1 --target=1 list >> results
$ROOT/bin/atos web --server=127.0.0.1:$port run --project=1 --experiment=1 --target=1 details 1 >> results
$ROOT/bin/atos web --server=127.0.0.1:$port run --project=1 --experiment=1 --target=1 details 2 >> results


# Test the result
cat > expected_results << EOF
Projects on 127.0.0.1:$port
 1: Test project
Details of 'Test project'
 status: Active
 name: Test project
 created_at: 2011/10/23
 client: Someone
 experiments: 1
 owner: One engineer
 targets: 1
Experiment for project 1 on 127.0.0.1:$port
 1: first experiment
Details of 'first experiment'
 status: Starting
 runs: 2
 launched_at: 2012/12/29 13:02
 name: first experiment
 id: 1
Target for project 1 on 127.0.0.1:$port
 1: one target
Details of 'one target'
 id: 1
 name: one target
Run for experiment 1, target 1, on 127.0.0.1:$port
 1: d82cd2cbe396b918104639376d143f87
 2: 71a1e5f6d9f4518415485ee8d27a1a87
Details of 'd82cd2cbe396b918104639376d143f87'
 hash: d82cd2cbe396b918104639376d143f87
 sizered: 0.00
 speedup: 0.00
 version: 1.0-170-g3ff02e5c
 conf: 
 time: 11860.00
 id: 1
 uconf: 
 size: 240563
Details of '71a1e5f6d9f4518415485ee8d27a1a87'
 hash: 71a1e5f6d9f4518415485ee8d27a1a87
 sizered: 46.58
 speedup: -10.29
 version: 1.0-170-g3ff02e5c
 conf: -Os
 time: 13220.00
 id: 2
 uconf: 
 size: 128516
EOF

diff expected_results results
