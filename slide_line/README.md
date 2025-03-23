# Slide Line

This project involves implementing a function to slide and merge an array of integers, mimicking the behavior of the 2048 game mechanics.

## Requirements

- Language: C
- Header File: `0-slide_line.h`

## Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

### Parameters:
- `line`: Pointer to an array of integers.
- `size`: Number of elements in the array.
- `direction`: Direction to slide and merge, either:
    - `SLIDE_LEFT` (defined as 0)
    - `SLIDE_RIGHT` (defined as 1)

### Return Value:
- `1` on success.
- `0` on failure.

## Usage

Include the `0-slide_line.h` header file in your program to use the `slide_line` function.

## Example

```c
#include "0-slide_line.c"
#include <stdio.h>

int main(void)
{
        int line[] = {2, 2, 0, 4};
        size_t size = 4;

        if (slide_line(line, size, SLIDE_LEFT))
        {
                for (size_t i = 0; i < size; i++)
                        printf("%d ", line[i]);
                printf("\n");
        }
        return 0;
}
```

## Author

- Holberton School
- Project for interview preparation