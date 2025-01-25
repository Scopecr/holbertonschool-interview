#!/usr/bin/python3
"""Minimum operations
Copy All and Paste
write a method that calculates the fewest
number of operations needed to result in
exactly n H characters in the file.
"""


def minOperations(n):
    """ Minimum operations
    Returns an integer
    if n is impossible to achieve, return 0
    """
    if n <= 1:
        return 0
    for i in range(2, n + 1):
        if n % i == 0:
            return minOperations(n // i) + i
    return 0
