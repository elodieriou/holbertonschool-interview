#!/usr/bin/python3
"""rain module"""


def rain(walls):
    """Rain function calculate how many square of water will be retained
    after it rains.
    """

    if not walls:
        return 0

    count = 0
    length = len(walls)

    for i in range(1, length - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for k in range(i + 1, length):
            right = max(right, walls[k])

        count += min(left, right) - walls[i]

    return count
