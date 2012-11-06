=================
ATOS Benchmarking
=================

The benchmarks results below summarize ATOS tools exploration results on a
variety of benchmarks and platforms.

There are generally three configurations shown depending on the expected
trade-off objectives:

- perf driven: results for the performance objective first
- perf-size driven: results for an equal performance/size objective
- size driven: results for a size objective first

In the results, performance and size are expressed as:

- speed-up: the increase in application speed compared to the standard build
  (positive percentage is better),
- size-reduction: the reduction in code size compared to the standard build
  (positive percentage is better).


ATOS Release 2.0
----------------

The tables below show some benchmarking results from the ATOS exploration performed on various configurations:

+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
| Benchmark id       | atos version    | configuration        | trade-off       | speed-up     |size-reduction|
+====================+=================+======================+=================+==============+==============+
| jpeg               | 2.0-rc1         | sh4 STLinux gcc-4.7.1| perf driven     |  +25.65%     |  -12.55%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | perf-size driven|  +25.35%     |  -12.55%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | size driven     |  +16.21%     |   -2.24%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
| zlib               | 2.0-rc1         | sh4 STLinux gcc-4.7.1| perf driven     |   +8.60%     |   +1.61%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | perf-size driven|   +5.53%     |   +9.11%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | size driven     |   -2.80%     |  +12.67%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+

+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
| Benchmark id       | atos version    | configuration        | trade-off       | speed-up     |size-reduction|
+====================+=================+======================+=================+==============+==============+
| sha1               | 2.0-rc1         | x86_64 QEMU gcc-4.7.2| perf driven     |  +30.39%     |  -15.52%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | perf-size driven|  +13.60%     |   +3.65%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | size driven     |   -4.42%     |  +11.05%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
| bzip2              | 2.0-rc1         | x86_64 QEMU gcc-4.7.2| perf driven     |   +1.73%     |  +18.65%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | perf-size driven|     idem     |     idem     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
|                    |                 |                      | size driven     |   -1.55%     |  +21.05%     |
+--------------------+-----------------+----------------------+-----------------+--------------+--------------+
