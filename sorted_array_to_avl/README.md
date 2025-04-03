# Sorted Array to AVL

This project implements a function to build an AVL tree from a sorted array. The AVL tree is a self-balancing binary search tree, ensuring that the height difference between the left and right subtrees of any node is at most one.

## Files

- **0-sorted_array_to_avl.c**: Contains the implementation of the `sorted_array_to_avl` function and its helper function `build_avl_tree`.

## Function Descriptions

### `sorted_array_to_avl`

This function builds an AVL tree from a sorted array.

- **Prototype**:
  ```c
  avl_t *sorted_array_to_avl(int *array, size_t size);
  ```
- **Parameters**:
  - `array`: Pointer to the first element of the sorted array.
  - `size`: Number of elements in the array.
- **Return Value**:
  - Pointer to the root node of the created AVL tree, or `NULL` on failure.

### `build_avl_tree`

A helper function that recursively builds the AVL tree.

- **Parameters**:
  - `array`: Pointer to the first element of the array.
  - `start`: Start index of the current subarray.
  - `end`: End index of the current subarray.
- **Return Value**:
  - Pointer to the root node of the created AVL tree, or `NULL` on failure.

## Usage

To use this implementation, include the `binary_trees.h` header file and compile the code with the required dependencies.

## Example

Given a sorted array: