#!/usr/bin/python3
"""
Calculates the perimeter of an island in a 2D grid.

This module provides a single function, island_perimeter, which takes a
rectangular grid of 0s (water) and 1s (land) and returns the total
perimeter of the one island (no lakes).
"""

def island_perimeter(grid):

    """
    :param grid: list[list[int]] where 1=land, 0=water
    :return: int perimeter of the single island
    """
    if not grid or not grid[0]:
        return 0

    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                perimeter += 4
                # subtract shared edges
                if r > 0 and grid[r-1][c] == 1:
                    perimeter -= 1
                if r < rows - 1 and grid[r+1][c] == 1:
                    perimeter -= 1
                if c > 0 and grid[r][c-1] == 1:
                    perimeter -= 1
                if c < cols - 1 and grid[r][c+1] == 1:
                    perimeter -= 1

    return perimeter
