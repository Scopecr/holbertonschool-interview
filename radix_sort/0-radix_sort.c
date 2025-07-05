#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Returns the maximum value in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum integer
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - A counting sort adapted for radix sort
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The digit to sort by (exponent: 1, 10, 100, etc.)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output;
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so it contains actual position */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size; i-- > 0;)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy to original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array using the LSD Radix Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}
