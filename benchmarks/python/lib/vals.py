# -*- coding: utf-8 -*-
# file: vals.py
# date: 2022-01-22


from typing import List, Tuple
from . import utils


simhash_bin_str1: str = "100010110110";
simhash_bin_str2: str = "110001110011";


keywords5: List[Tuple[str, int] ] = utils.fake_keywords(5)
keywords10: List[Tuple[str, int] ] = utils.fake_keywords(10)
keywords50: List[Tuple[str, int] ] = utils.fake_keywords(50)
keywords100: List[Tuple[str, int] ] = utils.fake_keywords(100)
keywords200: List[Tuple[str, int] ] = utils.fake_keywords(200)
