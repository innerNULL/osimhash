/// file: benchmarking.cpp
/// date: 2022-01-17


#include <benchmark/benchmark.h>
#include "./lib/Simhasher_benchmark.h"
#include "./lib/osimhash_benchmark.h"

using namespace simhash_benchmark;
using namespace osimhash_benchmark;


BENCHMARK(BENCHMARK_Simhasher_extract_text50_top5);
BENCHMARK(BENCHMARK_Simhasher_extract_text50_top10);
BENCHMARK(BENCHMARK_Simhasher_extract_text50_top15);
BENCHMARK(BENCHMARK_Simhasher_extract_text50_top20);

BENCHMARK(BENCHMARK_Simhasher_extract_text500_top5);


BENCHMARK(BENCHMARK_Simhasher_make_text50_top5);
BENCHMARK(BENCHMARK_Simhasher_make_text50_top10);
BENCHMARK(BENCHMARK_Simhasher_make_text50_top15);
BENCHMARK(BENCHMARK_Simhasher_make_text50_top20);


BENCHMARK(BENCHMARK_Simhasher_binaryStringToUint64);
BENCHMARK(BENCHMARK_Simhasher_toBinaryString);


BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords5);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords10);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords20);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords50);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords100);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords200);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords500);
BENCHMARK(BENCHMARK_Simhasher_make_from_predefined_keywords1000);


BENCHMARK(BENCHMARK_Simhasher_binaryStringToUint64_isEqual);
BENCHMARK(BENCHMARK_Simhasher_binaryStringToUint64_isEqual_10k);
BENCHMARK(BENCHMARK_Simhasher_binaryStringToUint64_isEqual_1000k);


BENCHMARK(BENCHMARK_osimhash_keywords2simhash_5);
BENCHMARK(BENCHMARK_osimhash_keywords2simhash_10);
BENCHMARK(BENCHMARK_osimhash_keywords2simhash_50);
BENCHMARK(BENCHMARK_osimhash_keywords2simhash_200);


BENCHMARK(BENCHMARK_osimhash_simhash2bin_str);


BENCHMARK(BENCHMARK_osimhash_is_equal_int);
BENCHMARK(BENCHMARK_osimhash_is_equal_str);


BENCHMARK(BENCHMARK_osimhash_pairs_equal_int100);
BENCHMARK(BENCHMARK_osimhash_pairs_equal_int200);
BENCHMARK(BENCHMARK_osimhash_pairs_equal_int500);
BENCHMARK(BENCHMARK_osimhash_pairs_equal_int1000);
BENCHMARK(BENCHMARK_osimhash_pairs_equal_str1000);


BENCHMARK_MAIN();
