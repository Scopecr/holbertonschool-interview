/* 0-binary_tree_is_avl.c */
#include "binary_trees.h"
#include <limits.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height in nodes (empty tree => 0)
 */
static size_t tree_height(const binary_tree_t *tree)
{
		size_t lh, rh;

		if (!tree)
				return (0);
		lh = tree_height(tree->left);
		rh = tree_height(tree->right);
		return (lh > rh ? lh + 1 : rh + 1);
}

/**
 * is_bst_util - verifies the binary search property in a subtree
 * @tree: pointer to the root of the subtree
 * @min: lower bound (inclusive)
 * @max: upper bound (inclusive)
 *
 * Return: 1 if all nodes satisfy min ≤ n ≤ max, 0 otherwise
 */
static int is_bst_util(const binary_tree_t *tree, long min, long max)
{
		if (!tree)
				return (1);
		if (tree->n < min || tree->n > max)
				return (0);
		return (is_bst_util(tree->left,  min, (long)tree->n - 1) &&
						is_bst_util(tree->right, (long)tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 *         (empty tree is NOT considered AVL here)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
		int lh, rh;

		if (!tree)
				return (0);
		/* Must be a BST */
		if (!is_bst_util(tree, LONG_MIN, LONG_MAX))
				return (0);
		/* Check balance factor */
		lh = (int)tree_height(tree->left);
		rh = (int)tree_height(tree->right);
		if (lh - rh > 1 || rh - lh > 1)
				return (0);
		/* Recursively ensure subtrees are AVL too */
		if (tree->left && !binary_tree_is_avl(tree->left))
				return (0);
		if (tree->right && !binary_tree_is_avl(tree->right))
				return (0);
		return (1);
}
