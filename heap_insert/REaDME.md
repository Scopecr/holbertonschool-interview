# Binary Trees

## Overview

This project involves creating and manipulating binary trees, specifically focusing on creating nodes and inserting values into a Max Binary Heap.

## Functions

### `binary_tree_node`

This function creates a binary tree node.

**Prototype:**
```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

**Parameters:**
- `parent`: A pointer to the parent node of the node to create.
- `value`: The value to put in the new node.

**Description:**
- When created, a node does not have any children.
- The function returns a pointer to the new node, or `NULL` on failure.

### `heap_insert`

This function inserts a value into a Max Binary Heap.

**Prototype:**
```c
heap_t *heap_insert(heap_t **root, int value);
```

**Parameters:**
- `root`: A double pointer to the root node of the Heap.
- `value`: The value to store in the node to be inserted.

**Description:**
- The function returns a pointer to the inserted node, or `NULL` on failure.
- If the address stored in `root` is `NULL`, the created node becomes the root node.
- The function respects Max Heap ordering.
- You are allowed to have up to 6 functions in your file.

## Compilation

Your file `0-binary_tree_node.c` will be compiled during the correction.

## Example

```c
binary_tree_t *root = NULL;
binary_tree_t *node;

node = binary_tree_node(root, 42);
```
