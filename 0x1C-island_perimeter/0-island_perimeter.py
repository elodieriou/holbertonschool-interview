#!/usr/bin/python3
"""This module defines the function island_perimeter"""


def island_perimeter(grid):
    """This function returns the perimeter of the island"""
    perimeter = 0
    for row in range(0, len(grid)):
        for zone in range(0, len(grid[row])):
            if grid[row][zone] == 1:
                if row == 0 or grid[row - 1][zone] == 0:
                    perimeter += 1
                if zone == 0 or grid[row][zone - 1] == 0:
                    perimeter += 1
                if row == len(grid) - 1 or grid[row + 1][zone] == 0:
                    perimeter += 1
                if zone == len(grid[row]) - 1 or grid[row][zone + 1] == 0:
                    perimeter += 1
    return perimeter
