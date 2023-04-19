#!/usr/bin/python3
"""rain module"""


def rain(walls):
    """Rain function calculate how many square of water will be retained
    after it rains.
    """

    if not walls or walls is None:
        return 0

    area = 0
    length = len(walls)

    for i in range(length):
        if walls[i] == 0:
            continue
        count = 0

        for j in range(i + 1, length):
            if walls[j] != 0 or j == length - 1:
                break
            count += 1

        if i < length - 1:
            min_wall = min(walls[i], walls[i + count + 1])
            area += count * min_wall

    return area
