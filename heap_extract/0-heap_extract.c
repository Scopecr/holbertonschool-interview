#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t heap_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_last_node - Gets the last level-order node in the heap
 * @root: Pointer to the root node
 * @size: Size of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	heap_t *node;
	int bit;

	if (!root || size == 0)
		return (NULL);

	if (size == 1)
		return (root);

	node = root;

	/* Find the position by following the binary representation */
	/* We need to find the highest bit position */
	size_t temp = size;
	int depth = 0;

	while (temp > 1)
	{
		temp >>= 1;
		depth++;
	}

	/* Follow the path from the second highest bit */
	for (int i = depth - 1; i >= 0; i--)
	{
		bit = (size >> i) & 1;
		if (bit == 0)
			node = node->left;
		else
			node = node->right;
	}

	return (node);
}

/**
 * heapify_down - Restores heap property by moving node down
 * @node: Pointer to the node to heapify
 */
void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	if (!node)
		return;

	while (1)
	{
		largest = node;

		/* Check left child */
		if (node->left && node->left->n > largest->n)
			largest = node->left;

			/* Check right child */
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		/* If node is already the largest, heap property is satisfied */
		if (largest == node)
			break;

		/* Swap values */
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		/* Move down to the swapped child */
		node = largest;
	}
}

/**
 * remove_last_node - Removes the last node and replaces root value
 * @root: Pointer to the root node
 * @last_node: Pointer to the last node to remove
 */
void remove_last_node(heap_t *root, heap_t *last_node)
{
	heap_t *parent;

	/* Replace root value with last node value */
	root->n = last_node->n;

	/* Remove the last node */
	parent = last_node->parent;
	if (parent)
	{
		if (parent->left == last_node)
			parent->left = NULL;
		else
			parent->right = NULL;
	}

	free(last_node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 if function fails
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int root_value;
	size_t size;

	if (!root || !*root)
		return (0);

	root_value = (*root)->n;
	size = heap_size(*root);

	/* If only one node, delete it and set root to NULL */
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	/* Find and remove the last node */
	last_node = get_last_node(*root, size);
	if (!last_node)
		return (0);

	remove_last_node(*root, last_node);

	/* Restore heap property */
	heapify_down(*root);

	return (root_value);
}
