# Insert in Sorted Linked List

This directory contains a solution for inserting a new node into a sorted singly linked list. The goal is to maintain the sorted order of the list after the insertion.

## Files

- `insert_in_sorted_linked_list.c`: Contains the implementation of the function to insert a new node into the sorted linked list.
- `insert_in_sorted_linked_list.h`: Header file containing the function prototype and the definition of the list node structure.
- `main.c`: Example usage of the insertion function.
- `README.md`: This file.

## Function Prototype

```c
listint_t *insert_node(listint_t **head, int number);
```

- `head`: Double pointer to the head of the linked list.
- `number`: The value to be inserted into the list.

## Usage

1. Compile the code:

```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o insert
```

2. Run the executable:

```sh
./insert
```

## Example

Given a sorted linked list: `1 -> 3 -> 4 -> 6` and a number `5`, the function will insert `5` into the correct position to maintain the sorted order: `1 -> 3 -> 4 -> 5 -> 6`.

## Author

Walter Carrion
