# -*- coding: utf-8 -*-
# file: utils.py
# date: 2022-01-22


from typing import List, Tuple


def fake_keywords(
        num: int
) -> List[Tuple[str, int] ]:
    keywords: List[Tuple[str, int] ] = []
    score: float = 1.0 / num;
    for i in range(num):
        keyword: str = "fake_" + str(i)
        keywords.append((keyword, score))
    return keywords


def fake_order_id(n: int) -> List[int]:
    results: List[int] = []
    for i in range(n):
        results.append(i)
    return results
