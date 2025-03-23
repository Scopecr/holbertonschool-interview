#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * Return: 1 upon success, 0 upon failure
 */
static int slide_left(int *line, size_t size)
{
	size_t i, pos = 0;
	int merged = 0;

	/* First pass: slide all numbers to the left (removing zeros) */
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[pos++] = line[i];
		}
	}

	/* Fill the rest with zeros */
	for (i = pos; i < size; i++)
	{
		line[i] = 0;
	}

	/* Second pass: merge identical numbers */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			merged = 1;
		}
	}

	/* If we did merge, we need to slide again */
	if (merged)
	{
		pos = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				line[pos++] = line[i];
			}
		}

		for (i = pos; i < size; i++)
		{
			line[i] = 0;
		}
	}

	return (1);
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * Return: 1 upon success, 0 upon failure
 */
static int slide_right(int *line, size_t size)
{
	int i, pos;
	int merged = 0;

	/* First pass: slide all numbers to the right (removing zeros) */
	pos = size - 1;
	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[pos--] = line[i];
		}
	}

	/* Fill the rest with zeros */
	for (i = pos; i >= 0; i--)
	{
		line[i] = 0;
	}

	/* Second pass: merge identical numbers */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			merged = 1;
		}
	}

	/* If we did merge, we need to slide again */
	if (merged)
	{
		pos = size - 1;
		for (i = size - 1; i >= 0; i--)
		{
			if (line[i] != 0)
			{
				line[pos--] = line[i];
			}
		}

		for (i = pos; i >= 0; i--)
		{
			line[i] = 0;
		}
	}

	return (1);
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
		else
		return (slide_right(line, size));
}