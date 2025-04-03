#include <stdlib.h>
#include "binary_trees.h"

/**
 * build_avl_tree - Helper function to build an AVL tree recursively
 * @array: Pointer to the first element of the array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, size_t start, size_t end)
{
    avl_t *root;
    size_t mid;

    /* Base case: if start exceeds end, return NULL */
    if (start > end)
        return (NULL);

    /* Calculate the middle index */
    mid = (start + end) / 2;

    /* Create the root node with the middle element */
    root = binary_tree_node(NULL, array[mid]);
    if (root == NULL)
        return (NULL);

    /* Recursively build left subtree with elements before the middle */
    root->left = build_avl_tree(array, start, mid - 1);
    if (root->left != NULL)
        root->left->parent = root;

    /* Recursively build right subtree with elements after the middle */
    root->right = build_avl_tree(array, mid + 1, end);
    if (root->right != NULL)
        root->right->parent = root;

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    /* Check for invalid inputs */
    if (array == NULL || size == 0)
        return (NULL);

    /* Call the helper function to build the AVL tree */
    return (build_avl_tree(array, 0, size - 1));
}