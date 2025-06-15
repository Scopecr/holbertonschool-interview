#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: The original array
 * @left: Left subarray
 * @left_size: Size of left subarray
 * @right: Right subarray
 * @right_size: Size of right subarray
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	/* Merge the two arrays */
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size) /* Copy remaining elements from left array */
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size) /* Copy remaining elements from right array */
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort
 * @array: The array to be sorted
 * @temp: Temporary array for merging
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = temp;
	right = temp + mid;

	/* Copy left half */
	for (i = 0; i < mid; i++)
		left[i] = array[i];

	/* Copy right half */
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	/* Recursively sort left and right halves */
	merge_sort_recursive(left, temp + size, mid);
	merge_sort_recursive(right, temp + size, size - mid);

	/* Merge the sorted halves */
	merge(array, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size * 2);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, size);

	free(temp);
}
