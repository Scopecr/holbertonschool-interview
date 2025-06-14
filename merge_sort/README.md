# Merge Sort Algorithm Implementation

This project implements the merge sort algorithm in C following specific requirements and coding standards.

## Project Overview

The merge sort algorithm is a divide-and-conquer sorting algorithm that divides the input array into two halves, recursively sorts both halves, and then merges the sorted halves. This implementation follows the top-down approach with specific requirements for array division and sorting order.

## Files Description

| File | Description |
|------|-------------|
| `sort.h` | Header file containing function prototypes and necessary includes |
| `0-merge_sort.c` | Main implementation of the merge sort algorithm |
| `0-O` | Big O notation file containing time complexity analysis |
| `print_array.c` | Utility function to print arrays (provided) |

## Algorithm Specifications

### Key Requirements
- **Top-down merge sort**: Uses recursive divide-and-conquer approach
- **Array division rule**: Left subarray size ≤ right subarray size
- **Sorting order**: Left subarray is sorted before the right subarray
- **Memory management**: Only one `malloc` and one `free` call allowed
- **Output format**: Displays the merging process with specific formatting

### Example Division
For array `{1, 2, 3, 4, 5}`:
- Left subarray: `{1, 2}` (size 2)
- Right subarray: `{3, 4, 5}` (size 3)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge_sort
```
## Usage
'''
#include "sort.h"

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
```

## Output Example

When running the provided main function, the output will display the initial array, the merging process, and the final sorted array:

```19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
...
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```