#!/usr/bin/python3
"""This module defines a script that reads stdin line by line
 and computes metrics"""
from sys import stdin

countStatus = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}

totalSize = 0
countLine = 0


def print_stats():
    """This function defines the stat's format"""
    print("File size: {}".format(totalSize))
    for code in sorted(countStatus.keys()):
        if countStatus[code] > 0:
            print("{}: {}".format(code, countStatus[code]))


if __name__ == "__main__":
    try:
        for line in stdin:
            countLine += 1

            try:
                parseLine = line.split()
                totalSize += int(parseLine[-1])

                status = int(parseLine[-2])
                if status in countStatus.keys():
                    countStatus[status] += 1

            except ValueError:
                pass

            if countLine % 10 == 0:
                print_stats()

    except KeyboardInterrupt:
        print_stats()
        raise

    print_stats()
