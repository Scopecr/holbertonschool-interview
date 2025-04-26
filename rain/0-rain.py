#!/usr/bin/python3
"""
0-rain module
Contains the rain function that calculates how much rainwater is retained.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls (list): A list of non-negative integers representing wall heights

    Returns:
        int: Total amount of rainwater retained

    """
    if not walls:
        return 0

    n = len(walls)
    total_water = 0

    # Precompute left and right maximum heights
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], walls[i])

    # Fill right_max array
    right_max[n-1] = walls[n-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])

    # Calculate water trapped at each position
    for i in range(n):
        total_water += max(0, min(left_max[i], right_max[i]) - walls[i])

    return total_water
