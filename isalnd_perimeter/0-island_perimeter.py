#!/usr/bin/python3

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
								# start with 4 sides
								perimeter += 4
								# subtract for each adjacent land cell
								if r > 0 and grid[r-1][c] == 1:       # up
										perimeter -= 1
								if r < rows - 1 and grid[r+1][c] == 1:  # down
										perimeter -= 1
								if c > 0 and grid[r][c-1] == 1:       # left
										perimeter -= 1
								if c < cols - 1 and grid[r][c+1] == 1:  # right
										perimeter -= 1

		return perimeter
