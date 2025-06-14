#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array
 * @array: The original array
 * @temp: Temporary array for merging
 * @left: Start index of left subarray
 * @mid: End index of left subarray
 * @right: End index of right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	/* Print the merging process */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	/* Copy elements to temp array */
	for (i = left; i <= right; i++)
		temp[i] = array[i];

	i = left;    /* Initial index of left subarray */
	j = mid + 1; /* Initial index of right subarray */
	k = left;    /* Initial index of merged subarray */

	/* Merge the temp arrays back into array[left..right] */
	while (i <= mid && j <= right)
	{
		if (temp[i] <= temp[j])
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[j];
			j++;
		}
		k++;
	}

	/* Copy remaining elements of left subarray */
	while (i <= mid)
	{
		array[k] = temp[i];
		i++;
		k++;
	}

	/* Copy remaining elements of right subarray */
	while (j <= right)
	{
		array[k] = temp[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts array using merge sort
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Start index
 * @right: End index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		/* Sort left half */
		merge_sort_recursive(array, temp, left, mid);
		/* Sort right half */
		merge_sort_recursive(array, temp, mid + 1, right);
		/* Merge the sorted halves */
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	/* Allocate temporary array (only one malloc call as required) */
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);

	/* Free the temporary array (only one free call as required) */
	free(temp);
}