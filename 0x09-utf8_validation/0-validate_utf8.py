#!/usr/bin/python3
"""UTF-8 Validation"""
from typing import List


def count_ones(n: int) -> int:
    """ Count the number of one at the beginning of binary number"""
    count = 0
    mask = 1 << 7
    while mask & n:
        count += 1
        mask = mask >> 1
    return count


def validUTF8(data: List[int]) -> bool:
    """ Check if a given data set represents a valid UTF-8 encoding"""
    number_bytes = 0
    mask1 = 1 << 7

    for i in data:

        if not number_bytes:
            number_bytes = count_ones(i)

            if not number_bytes:
                continue

            if number_bytes == 1 or number_bytes > 4:
                return False

        else:
            if not (i & mask1):
                return False

        number_bytes -= 1
    return number_bytes == 0
