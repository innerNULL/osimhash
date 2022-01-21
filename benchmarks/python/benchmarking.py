# -*- coding: utf-8 -*-
# file: benchmarking.py
# date: 2022-01-21


import os
import sys

CURR_DIR: str = os.path.abspath(
    os.path.dirname(__file__))
MOD_DIR: str = os.path.join(
    CURR_DIR, 
    "..", "..", "build", "bindings", "python")

sys.path.append(MOD_DIR)

import google_benchmark as benchmark
import pyosimhash
from google_benchmark._benchmark import State

from lib import utils
from lib import vals


@benchmark.register
def BENCHMARK_pyosimhash_keywords2simhash_5(
        state: State
) -> None:
    while state:
        pyosimhash.keywords2simhash(vals.keywords5)


@benchmark.register
def BENCHMARK_pyosimhash_keywords2simhash_10(
        state: State
) -> None:
    while state:
        pyosimhash.keywords2simhash(vals.keywords10)


@benchmark.register
def BENCHMARK_pyosimhash_keywords2simhash_50(
        state: State
) -> None:
    while state:
        pyosimhash.keywords2simhash(vals.keywords50)


@benchmark.register
def BENCHMARK_pyosimhash_keywords2simhash_100(
        state: State
) -> None:
    while state:
        pyosimhash.keywords2simhash(vals.keywords100)


@benchmark.register
def BENCHMARK_pyosimhash_keywords2simhash_200(
        state: State
) -> None:
    while state:
        pyosimhash.keywords2simhash(vals.keywords200)


@benchmark.register
def BENCHMARK_pyosimhash_simhash2bin_str(
        state: State
) -> None:
    while state:
        pyosimhash.simhash2bin_str(12983719273971873)


@benchmark.register
def BENCHMARK_pyosimhash_is_equal_int(
        state: State
) -> None:
    while state:
        pyosimhash.is_equal(1298371921873, 1298371927874)


@benchmark.register
def BENCHMARK_pyosimhash_is_equal_str(
        state: State
) -> None:
    while state:
        pyosimhash.is_equal(
            vals.simhash_bin_str1, vals.simhash_bin_str2)


@benchmark.register
def BENCHMARK_pyosimhash_pairs_equal_int100(
        state: State
) -> None:
    fake_simhash: List[int] = utils.fake_order_id(100)
    while state:
        pyosimhash.pairs_equal(fake_simhash);


@benchmark.register
def BENCHMARK_pyosimhash_pairs_equal_int200(
        state: State
) -> None:
    fake_simhash: List[int] = utils.fake_order_id(200)
    while state:
        pyosimhash.pairs_equal(fake_simhash);


@benchmark.register
def BENCHMARK_pyosimhash_pairs_equal_int500(
        state: State
) -> None:
    fake_simhash: List[int] = utils.fake_order_id(500)
    while state:
        pyosimhash.pairs_equal(fake_simhash);


@benchmark.register
def BENCHMARK_pyosimhash_pairs_equal_int1000(
        state: State
) -> None:
    fake_simhash: List[int] = utils.fake_order_id(1000)
    while state:
        pyosimhash.pairs_equal(fake_simhash);


@benchmark.register
def BENCHMARK_pyosimhash_pairs_equal_str1000(
        state: State
) -> None:
    fake_simhash: List[str] = [vals.simhash_bin_str1] * 1000
    while state:
        pyosimhash.pairs_equal(fake_simhash);


if __name__ == "__main__":
    benchmark.main()
