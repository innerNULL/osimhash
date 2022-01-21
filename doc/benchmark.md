# Benchmarks
## CPP Benchmarks
```
2022-01-21T04:08:31+00:00
Running ./benchmarks/cpp/benchmarking
Run on (16 X 2494.14 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x16)
  L1 Instruction 32 KiB (x16)
  L2 Unified 4096 KiB (x16)
  L3 Unified 36608 KiB (x1)
Load Average: 0.06, 0.61, 1.85
***WARNING*** Library was built as DEBUG. Timings may be affected.
-------------------------------------------------------------------------------------------------
Benchmark                                                       Time             CPU   Iterations
-------------------------------------------------------------------------------------------------
BENCHMARK_Simhasher_extract_text50_top5                     14694 ns        14693 ns        47916
BENCHMARK_Simhasher_extract_text50_top10                    14866 ns        14865 ns        46870
BENCHMARK_Simhasher_extract_text50_top15                    14958 ns        14958 ns        45994
BENCHMARK_Simhasher_extract_text50_top20                    16172 ns        16172 ns        40034
BENCHMARK_Simhasher_extract_text500_top5                   197810 ns       197804 ns         3581
BENCHMARK_Simhasher_make_text50_top5                        18264 ns        18263 ns        45898
BENCHMARK_Simhasher_make_text50_top10                       16199 ns        16199 ns        44940
BENCHMARK_Simhasher_make_text50_top15                       17407 ns        17407 ns        43535
BENCHMARK_Simhasher_make_text50_top20                       16075 ns        16075 ns        43374
BENCHMARK_Simhasher_binaryStringToUint64                    0.000 ns        0.000 ns   1000000000
BENCHMARK_Simhasher_toBinaryString                           30.8 ns         30.8 ns     22771322
BENCHMARK_Simhasher_make_from_predefined_keywords5            218 ns          218 ns      3213931
BENCHMARK_Simhasher_make_from_predefined_keywords10           335 ns          335 ns      2109902
BENCHMARK_Simhasher_make_from_predefined_keywords20           556 ns          556 ns      1248217
BENCHMARK_Simhasher_make_from_predefined_keywords50          1214 ns         1214 ns       576246
BENCHMARK_Simhasher_make_from_predefined_keywords100         2329 ns         2329 ns       300230
BENCHMARK_Simhasher_make_from_predefined_keywords200         4488 ns         4488 ns       155937
BENCHMARK_Simhasher_make_from_predefined_keywords500        11117 ns        11117 ns        62610
BENCHMARK_Simhasher_make_from_predefined_keywords1000       28212 ns        28212 ns        24631
BENCHMARK_Simhasher_binaryStringToUint64_isEqual            0.000 ns        0.000 ns   1000000000
BENCHMARK_Simhasher_binaryStringToUint64_isEqual_10k        0.000 ns        0.000 ns   1000000000
BENCHMARK_Simhasher_binaryStringToUint64_isEqual_1000k      0.000 ns        0.000 ns   1000000000
BENCHMARK_osimhash_keywords2simhash_5                         217 ns          217 ns      3228335
BENCHMARK_osimhash_keywords2simhash_10                        328 ns          328 ns      2134004
BENCHMARK_osimhash_keywords2simhash_50                       1214 ns         1214 ns       576176
BENCHMARK_osimhash_keywords2simhash_200                      4486 ns         4486 ns       155978
BENCHMARK_osimhash_simhash2bin_str                           56.4 ns         56.4 ns     12396402
BENCHMARK_osimhash_is_equal_int                             0.000 ns        0.000 ns   1000000000
BENCHMARK_osimhash_is_equal_str                              36.1 ns         36.1 ns     19377813
BENCHMARK_osimhash_pairs_equal_int100                       28692 ns        28691 ns        24285
BENCHMARK_osimhash_pairs_equal_int200                       71223 ns        71220 ns         9793
BENCHMARK_osimhash_pairs_equal_int500                      459702 ns       459688 ns         1521
BENCHMARK_osimhash_pairs_equal_int1000                    1584211 ns      1584165 ns          442
BENCHMARK_osimhash_pairs_equal_str1000                    1345383 ns      1345356 ns          521
```

## Python Benchmarks
```
2022-01-22T02:57:12+00:00
Running ../benchmarks/python/benchmarking.py
Run on (16 X 2494.14 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x16)
  L1 Instruction 32 KiB (x16)
  L2 Unified 4096 KiB (x16)
  L3 Unified 36608 KiB (x1)
Load Average: 0.00, 0.00, 0.00
------------------------------------------------------------------------------------
Benchmark                                          Time             CPU   Iterations
------------------------------------------------------------------------------------
BENCHMARK_pyosimhash_keywords2simhash_5         1071 ns         1071 ns       649288
BENCHMARK_pyosimhash_keywords2simhash_10        1430 ns         1430 ns       486513
BENCHMARK_pyosimhash_keywords2simhash_50        4245 ns         4245 ns       164854
BENCHMARK_pyosimhash_keywords2simhash_100       7672 ns         7672 ns        90709
BENCHMARK_pyosimhash_keywords2simhash_200      14481 ns        14480 ns        48301
BENCHMARK_pyosimhash_simhash2bin_str             565 ns          565 ns      1244463
BENCHMARK_pyosimhash_is_equal_int                511 ns          511 ns      1398104
BENCHMARK_pyosimhash_is_equal_str                866 ns          866 ns       802645
BENCHMARK_pyosimhash_pairs_equal_int100        87708 ns        87705 ns         7991
BENCHMARK_pyosimhash_pairs_equal_int200       318597 ns       318583 ns         2193
BENCHMARK_pyosimhash_pairs_equal_int500      2264195 ns      2264095 ns          308
BENCHMARK_pyosimhash_pairs_equal_int1000    11759447 ns     11758794 ns           59
BENCHMARK_pyosimhash_pairs_equal_str1000    11347786 ns     11347563 ns           62
```
