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
import os

SORTED_FILE_PREFIX = "tmp_sorted_files"


def process_func(max_value, file_name):

    str_array = [str(i) for i in range(1, max_value + 1)]

    sorted_str_array = sorted(str_array, reverse=False)

    with open(file_name, "w", encoding="utf8") as fd_out:
        for v in sorted_str_array:
            fd_out.write(f"{v}\n")


def print_fn(sorted_file_path, k_values):
    print_cnt = 0
    k_value_set = set(k_values)

    with open(sorted_file_path, "r") as fd_in:
        for index, value in enumerate(fd_in):
            if (index + 1) in k_value_set:
                print(f"{index+1} -> {value}")
                print_cnt += 1
            if len(k_value_set) == print_cnt:
                break


if "__main__" == __name__:
    max_value = int(sys.argv[1])
    k_list = [int(k) for k in sys.argv[2:]]

    sorted_file_path = f"{SORTED_FILE_PREFIX}/{max_value}"

    if os.path.exists(sorted_file_path):
        print_fn(sorted_file_path, k_list)
    else:
        process_func(max_value, sorted_file_path)
        print_fn(sorted_file_path, k_list)
