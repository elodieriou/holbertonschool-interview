#!/usr/bin/python3
"""This module defines the isWinner function"""


def is_prime(n):
    """Define if a number is prime or not"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def get_largest_prime(n):
    """Define the largest prime number that's less than or equal
     to a given number"""
    for i in range(n, 1, -1):
        if is_prime(i):
            return i
    return None


def isWinner(x, nums):
    """Define who is winner"""
    Maria_wins = 0
    Ben_wins = 0
    for i in range(x):
        n = nums[i]
        largest_prime = get_largest_prime(n)
        if largest_prime is None:
            Ben_wins += 1
        elif largest_prime % 2 == 0:
            Maria_wins += 1
        else:
            Ben_wins += 1

    if Maria_wins > Ben_wins:
        return 'Maria'
    elif Ben_wins > Maria_wins:
        return 'Ben'
    else:
        return None
