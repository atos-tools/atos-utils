====================
Example hevc decoder
====================

Executive Summary
-----------------
When first exploring an application, as described in the tutorial, it
may be interesting to run explorations in several steps in order to
get refined results at each stage.

Generally a good approach is to go through the following steps::

    atos-explore: basic exploration on the whole program,
    atos-explore-staged: advanced exploration on the whole program,
    atos-explore-acf --file-by-file: advanced file by file exploration on hot files,
    atos-explore-acf: advanced exploration function by function on hot functions.

This is exactly the approach we followed to tune the HEVC software
decoder application on an ARM cortex-a9 ORLY board.

The best results obtained by ATOS on this application compared to the
standard build configuration (-O3) are as follows:

- Best performance tradeoffs, 9.57% speedup, 21.80% size reduction::

    speedup | sizered |     target |                       variant_id 
     +9.57% | +21.80% | ldecod.exe | d4973b721400429019147cbcfa19f983 

Note that this numbers were obtained on top of the already highly
optimized HEVC software version (extensive usage of ARM Neon
instruction build-ins), which proves that, even on hand-optimized code,
the ATOS tool can still find non-negligible room for improvements.

Note also that this best configuration was reached with file-by-file
exploration, on top of which an additional exploration pass on
parameters value was applied (experimental feature to be integrated in
the next realease atos-3.0).

For a more detailed description of this work and its results, please refer
to the two presentations below::

   http://codex.cro.st.com/plugins/docman/?group_id=1806&action=show&id=278703
   http://codex.cro.st.com/plugins/docman/?group_id=1806&action=show&id=282260

How-to reproduce
----------------

The step-by-step procedure to replay the best configuration is described here::

    http://codex.cro.st.com/plugins/docman/?group_id=2626&action=show&id=292041

The best configuration csv file, as well as the run script is available here::

    http://codex.cro.st.com/plugins/docman/?group_id=2626&action=show&id=292043


Remaining Work
--------------

As stated above, best results were obtained exploring on option
parameters value, on top of the best file-by-file configuration.  This
type of exploration could also be performed on top of the best
function-by-function configuration, but this has not be tested yet (an
additional on-going developement is needed in ATOS to implement this feature).


