#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the elements of an array
 * @array: The array to print
 * @low: Starting index
 * @high: Ending index
 */
void print_array(int *array, int low, int high)
{
    printf("Searching in array: ");
    for (int i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - Recursive function to find the first occurrence
 * @array: Sorted array
 * @low: Lower bound index
 * @high: Upper bound index
 * @value: Value to search for
 * Return: Index of the first occurrence or -1
 */
int recursive_binary(int *array, int low, int high, int value)
{
    if (low > high)
        return -1;

    print_array(array, low, high);

    int mid = low + (high - low) / 2;

    if (array[mid] == value)
    {
        int left = recursive_binary(array, low, mid - 1, value);
        return (left != -1) ? left : mid;
    }
    else if (array[mid] > value)
    {
        return recursive_binary(array, low, mid - 1, value);
    }
    else
    {
        return recursive_binary(array, mid + 1, high, value);
    }
}

/**
 * advanced_binary - Searches for a value in a sorted array using recursion
 * @array: Pointer to the first element
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index of first occurrence, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return -1;

    return recursive_binary(array, 0, size - 1, value);
}
