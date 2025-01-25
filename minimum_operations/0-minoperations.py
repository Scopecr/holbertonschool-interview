#!/usr/bin/python3
def minOperations(n):
    """Minimun operations
    Returns and integer
    id n is impossible to achieve return 0
    """
    if n <= 1:
        return 0
    for i in range(2, n +1):
        if n % i == 0:
            return minOperations(n // i) + i
    return 0