#!/usr/bin/python3
"""This module defines a script that reads stdin line by line
 and computes metrics"""
from sys import stdin
import re

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

regex = r"^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - "
regex += r"\[[\d\-:.\s]+\] \"[\w\s\/.]+\" "
regex += r"\d{1,3} \d{1,3}$"


def print_stats(total_size):
    """This function defines the stat's format"""
    print("File size: {}".format(total_size))
    for code in countStatus:
        if countStatus[code] > 0:
            print("{}: {}".format(code, countStatus[code]))


if __name__ == "__main__":
    try:
        for line in stdin:
            if re.match(regex, line):
                parseLine = line.split()
                status = int(parseLine[7])
                size = int(parseLine[8])

                if status not in countStatus.keys():
                    continue

                countLine += 1
                totalSize += size
                countStatus[status] += 1

                if countLine % 10 == 0:
                    print_stats(totalSize)

    except ValueError:
        pass

    except KeyboardInterrupt:
        print_stats(totalSize)
        raise
