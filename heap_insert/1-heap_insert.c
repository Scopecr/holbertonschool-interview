#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * enqueue - Adds a node to the queue for level-order traversal.
 * @queue: Array of node pointers used for BFS traversal.
 * @node: Node to add to the queue.
 * @rear: Pointer to the rear index.
 */
void enqueue(heap_t **queue, heap_t *node, int *rear)
{
	queue[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - Removes a node from the queue.
 * @queue: Array of node pointers used for BFS traversal.
 * @front: Pointer to the front index.
 *
 * Return: The dequeued node.
 */
heap_t *dequeue(heap_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * heapify_up - Maintains the Max Heap property by swapping as needed.
 * @node: Pointer to the newly inserted node.
 *
 * Return: Pointer to the final position of the inserted node.
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		/* Swap values */
		int temp = node->n;

		node->n = node->parent->n;
		node->parent->n = temp;

		/* Move up the tree */
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node.
 * @value: Value to insert.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *temp;
	heap_t *queue[1024]; /* Simple queue for level-order traversal */
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	/* If heap is empty, create root */
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	/* Level-order traversal to find insertion point */
	enqueue(queue, *root, &rear);

	while (front < rear)
	{
		temp = dequeue(queue, &front);

		/* Insert in first available left or right child */
		if (!temp->left)
		{
			temp->left = binary_tree_node(temp, value);
			new_node = temp->left;
			break;
		}

		enqueue(queue, temp->left, &rear);

		if (!temp->right)
		{
			temp->right = binary_tree_node(temp, value);
			new_node = temp->right;
			break;
		}

		enqueue(queue, temp->right, &rear);
	}

	/* Restore the Max Heap property */
	return (heapify_up(new_node));
}
