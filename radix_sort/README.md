# Radix Sort Project

This project is part of the Holberton School interview preparation curriculum. It implements the **LSD (Least Significant Digit) Radix Sort** algorithm in C to sort an array of integers in ascending order.

---

## Requirements

- OS: Ubuntu 14.04 LTS
- Compiler: gcc 4.8.4
- Compilation flags: `-Wall -Werror -Wextra -pedantic`
- Code must follow [Betty](https://github.com/holbertonschool/Betty) coding style
- No global variables allowed
- No more than 5 functions per file
- Standard C library functions like `printf`, `puts`, etc. are **not allowed** (except for provided `print_array`)
- Sorting should only occur when the array size is 2 or more

---

## Files

| Filename         | Description                                      |
|------------------|--------------------------------------------------|
| `0-radix_sort.c` | Main implementation of the LSD Radix Sort        |
| `sort.h`         | Header file with function prototypes             |
| `print_array.c`  | Provided helper function to print arrays         |

---

## Function Prototype

```c
void radix_sort(int *array, size_t size);
