/// file: osimhasher_benchmark.h
/// date: 2022-01-20


#ifndef __OSIMHASHER_HENCHMARK_H__


#include <benchmark/benchmark.h>
#include <simhash/Simhasher.hpp>
#include <osimhash/osimhash.h>

#include "./vals.h"
#include "./utils.h"

using namespace simhash_benchmark;


namespace osimhash_benchmark {


static void BENCHMARK_osimhash_keywords2simhash_5(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::keywords2simhash(keywords5);
  }
}


static void BENCHMARK_osimhash_keywords2simhash_10(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::keywords2simhash(keywords10);
  }
}


static void BENCHMARK_osimhash_keywords2simhash_50(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::keywords2simhash(keywords50);
  }
}


static void BENCHMARK_osimhash_keywords2simhash_200(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::keywords2simhash(keywords200);
  }
}


static void BENCHMARK_osimhash_simhash2bin_str(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::simhash2bin_str(12983719273971873);
  }
}


static void BENCHMARK_osimhash_is_equal_int(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::is_equal(1298371921873, 1298371927874);
  }
}


static void BENCHMARK_osimhash_is_equal_str(
    benchmark::State& state) {
  for (auto _ : state) {
    osimhash::is_equal(simhash_bin_str1, simhash_bin_str2);
  }
}


static void BENCHMARK_osimhash_pairs_equal_int100(
    benchmark::State& state) {
  std::vector<uint64_t> fake_simhash = fake_order_id(100);
  for (auto _ : state) {
    osimhash::pairs_equal(fake_simhash);
  }
}


static void BENCHMARK_osimhash_pairs_equal_int200(
    benchmark::State& state) {
  std::vector<uint64_t> fake_simhash = fake_order_id(200);
  for (auto _ : state) {
    osimhash::pairs_equal(fake_simhash);
  }
}


static void BENCHMARK_osimhash_pairs_equal_int500(
    benchmark::State& state) {
  std::vector<uint64_t> fake_simhash = fake_order_id(500);
  for (auto _ : state) {
    osimhash::pairs_equal(fake_simhash);
  }
}


static void BENCHMARK_osimhash_pairs_equal_int1000(
    benchmark::State& state) {
  std::vector<uint64_t> fake_simhash = fake_order_id(1000);
  for (auto _ : state) {
    osimhash::pairs_equal(fake_simhash);
  }
}


static void BENCHMARK_osimhash_pairs_equal_str1000(
    benchmark::State& state) {
  std::vector<std::string> fake_simhash(1000, simhash_bin_str1);
  for (auto _ : state) {
    osimhash::pairs_equal(fake_simhash);
  }
}


} // simhash_benchmark

#endif


