#include "menger.h"

/**
 * is_empty - Determines if a position in the Menger sponge is empty
 * @row: Row index in the Menger sponge
 * @col: Column index in the Menger sponge
 *
 * Return: 1 if position should be empty, 0 otherwise
 */
static int is_empty(size_t row, size_t col)
{
	/* Check if the cell should be empty based on Menger sponge pattern */
	while (row > 0 && col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);

		row /= 3;
		col /= 3;
	}

	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 *
 * Return: void
 */
void menger(int level)
{
	size_t size, row, col;

	/* If level is lower than 0, do nothing */
	if (level < 0)
		return;

	/* Calculate size of the Menger sponge: 3^level */
	size = pow(3, level);

	/* Draw the Menger sponge */
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			/* Print # or space based on Menger sponge pattern */
			if (is_empty(row, col))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
