#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
 $ @Description: https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/
 $ @Author: neozhao654@gmail.com
 $ @Date: 2022-07-12 09:13:29
 $ @LastEditors: neozhao654@gmail.com
 $ @LastEditTime: 2022-07-12 09:15:51
"""

import sys


def process_func(max_value, k):
    str_array = [str(i) for i in range(1, max_value + 1)]

    sorted_str_array = sorted(str_array, reverse=False)

    print(sorted_str_array[k - 1])

    # [print(i, v) for i, v in enumerate(sorted_str_array)]


if "__main__" == __name__:
    max_value = int(sys.argv[1])
    k = int(sys.argv[2])
    process_func(max_value, k)
