#include "sandpiles.h"
#include <stdio.h>

/**
 * is_stable - Check if sandpile is stable
 * @grid: 3x3 grid to check
 * Return: 1 if stable, 0 if unstable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - Perform one round of toppling on unstable cells
 * @grid: 3x3 grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	/* First compute how grains will be distributed */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				/* Remove 4 grains from current cell */
				tmp[i][j] += grid[i][j] - 4;

				/* Add 1 grain to each adjacent cell */
				if (i > 0)
					tmp[i - 1][j] += 1;
				if (i < 2)
					tmp[i + 1][j] += 1;
				if (j > 0)
					tmp[i][j - 1] += 1;
				if (j < 2)
					tmp[i][j + 1] += 1;
			}
			else
				tmp[i][j] += grid[i][j];
		}
	}

	/* Copy back the result */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = tmp[i][j];
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* Keep toppling until stable */
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
