============
Example sha1
============

Executive Summary
-----------------
When first exploring a benchmark, as described in the tutorial, it may be interesting to
run explorations in several steps in order to get refined results at each stage.

Generally a good approach is to go through the following steps::

    atos-explore: basic exploration on the whole program,
    atos-explore-staged: advanced exploration on the whole program,
    atos-explore-acf --file-by-file: advanced file by file exploration on hot files,
    atos-explore-acf: advanced exploration function by function on hot functions.


The next section describes the steps and results obtained on the sha1 example benchmark
on x86_64 target host with QEMU used as performance evaluation tool.

The results obtained on this configuration compared to the standard build configuration
(-O2) are:

- Best performance tradeoffs, 30.56% speedup, 13.44% code size increase::

    speedup | sizered |             target |                       variant_id
    +30.56% | -13.44% | sha-shatest-shacmp | bbc60eb968fb803987f4df19304e6a1e

- Best size tradeoffs, 13.57% speedup, 3.58% size reduction::

    speedup | sizered |             target |                       variant_id
    +13.57% |  +3.58% | sha-shatest-shacmp | 7b9351c456fa303f8e3ef446e2028aff


Exploration of sha1
-------------------

Setup the path to the ATOS tools and to your gcc compiler. Below is the setup
used for this experiment::

    $sh eval PATH=$PREFIX/bin:$PATH
    $sh atos -v
    atos version 2.0-rc1
    $sh gcc --version
    gcc (GCC) 4.7.2
    $sh hostname -f && lsb_release -ri
    hostname
    Distributor ID: Ubuntu
    Release:        10.04

Then get into the sha1 example directory::

    $sh cd $ROOT/examples/sha1

First basic exploration::

    $sh atos-init -c -C atos-configurations-explore -b "make clean all" -r ./run-qemu.sh -p ./run-qemu-oprofile.sh
    $sh /usr/bin/time -p atos-explore -C atos-configurations-explore --cookie 903263d85115ea7b5725ee300d02933fca74ae2a --reuse --log-file atos-explore-debug.log 2>&1 | tee atos-explore.log
    Exploration time: 50s
    Actual number of runs: 18
    $sh atos-play -C atos-configurations-explore -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id 
    +29.22% | -21.84% | sha-shatest-shacmp | 2e8010f29e5527991decaf9be331f624 
    +29.22% | -21.92% | sha-shatest-shacmp | 3be49fef5ed8151e8c257c9c89c1bb51 
     -3.87% | +10.08% | sha-shatest-shacmp | 14cbd5a765a9234615406bb0dde7b370 

Quick staged exploration (M=1 base iterations)::

    $sh atos-init -c -C atos-configurations-stg-1 -b "make clean all" -r ./run-qemu.sh -p ./run-qemu-oprofile.sh
    $sh /usr/bin/time -p atos-explore-staged -C atos-configurations-stg-1 -M1 --cookie cc8cdfeaab431d534a118361f8b13e669c867076 --reuse --log-file atos-explore-stg-1-debug.log 2>&1 | tee atos-explore-stg-1.log
    Exploration time: 1min 30s
    Actual number of runs: 30
    $sh atos-play -C atos-configurations-stg-1 -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id 
    +29.22% | -21.84% | sha-shatest-shacmp | 2e8010f29e5527991decaf9be331f624 
    +29.22% | -21.92% | sha-shatest-shacmp | 3be49fef5ed8151e8c257c9c89c1bb51 
     -3.87% | +10.08% | sha-shatest-shacmp | 14cbd5a765a9234615406bb0dde7b370 

Full staged exploration (M=100 base iterations)::

    $sh /usr/bin/time -p atos-explore-staged -C atos-configurations-stg-1 -M100 --cookie cc8cdfeaab431d534a118361f8b13e669c867076 --reuse --log-file atos-explore-stg-100-debug.log 2>&1 | tee atos-explore-stg-100.log
    Exploration time 47min
    Actual number of runs: 986
    $sh atos-play -C atos-configurations-stg-1 -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id
    +30.35% | -15.52% | sha-shatest-shacmp | d0ec1a35d34eddf1c8fdd0daca415801
    +29.92% | -16.47% | sha-shatest-shacmp | 9f869a5a9ceeefa68a1c53cb44663a47
     -4.44% | +11.05% | sha-shatest-shacmp | 44928198f90a4e71b14474d6c84dba14


Quick file by file exploration (N=1 base iterations)::

    $sh atos-init -c -C atos-configurations-fbf-1 -b "make clean all" -r ./run-qemu.sh -p ./run-qemu-oprofile.sh
    $sh /usr/bin/time -p atos-explore-acf -C atos-configurations-fbf-1 -N1 --file-by-file --cookie ab5cfe9c64448f76fde868ba36496ab04488d0dd --reuse --log-file atos-explore-fbf-1-debug.log 2>&1 | tee atos-explore-fbf-1.log
    Exploration time: 4min 50s
    Actual number of runs: 82
    $sh atos-play -C atos-configurations-fbf-1 -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id 
    +29.22% | -16.61% | sha-shatest-shacmp | 4ae65216930d4c7fcf252d6881a09563 
    +29.22% | -16.61% | sha-shatest-shacmp | 8a316476aaa9fa9646f6abdaf06f7485 
     -5.40% | +10.99% | sha-shatest-shacmp | c94d0a618cf0d9d2fdfb4368a2802182 

Full file by file exploration (N=100 base iterations)::

    $sh /usr/bin/time -p atos-explore-acf -C atos-configurations-fbf-1 -N100 --file-by-file --cookie ab5cfe9c64448f76fde868ba36496ab04488d0dd --reuse --log-file atos-explore-fbf-100-debug.log 2>&1 | tee atos-explore-fbf-100.log
    Exploration time: 2h55min
    Actual number of runs: 3663
    $sh atos-play -C atos-configurations-fbf-1 -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id 
    +30.56% | -13.44% | sha-shatest-shacmp | bbc60eb968fb803987f4df19304e6a1e 
    +30.56% | -13.44% | sha-shatest-shacmp | b8552f039240d3c7116a5033f6e013fc 
    +30.37% | -12.53% | sha-shatest-shacmp | 9620d33a9b5ba94feb5d6a59b2814098 

Quick function by function exploration (N=1 base iterations)::

    $sh atos-init -c -C atos-configurations-acf-1 -b "make clean all" -r ./run-qemu.sh -p ./run-qemu-oprofile.sh
    $sh /usr/bin/time -p atos-explore-acf -C atos-configurations-acf-1 -N1 --cookie ba7ac465be9440a6e3b90f7b394eb702fc41756d --reuse --log-file atos-explore-acf-1-debug.log 2>&1 | tee atos-explore-acf-1.log
    Exploration time: 5min 20s
    Actual number of runs: 91
    $sh atos-play -C atos-configurations-acf-1 -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id 
    +26.47% | -19.53% | sha-shatest-shacmp | 48583a818ca8efef698e63fa633994f8 
    +26.47% | -19.53% | sha-shatest-shacmp | f557da50d74d63668fb9845020e19d23 
     -0.00% |  +2.56% | sha-shatest-shacmp | 6d9ab5b9da4ae4bb4c4bfb496f6a74d2 

Full function by function exploration (N=100 base iterations)::

    $sh /usr/bin/time -p atos-explore-acf -C atos-configurations-acf-1 -N100 --cookie ba7ac465be9440a6e3b90f7b394eb702fc41756d --reuse --log-file atos-explore-acf-100-debug.log 2>&1 | tee atos-explore-acf-100.log
    Exploration time: 4h 33min
    Actual number of runs: 5267
    $sh atos-play -C atos-configurations-acf-1 -T -s 5 -s 1 -s 0.2
    speedup | sizered |             target |                       variant_id
    +27.38% | -17.61% | sha-shatest-shacmp | b36d865e356efe4c17b3bc3c56c0c59f
    +13.57% |  +3.65% | sha-shatest-shacmp | 1e877ecd0668e619eee78fbc0c0e4e36
    +13.57% |  +3.58% | sha-shatest-shacmp | 7b9351c456fa303f8e3ef446e2028aff

