#include "binary_trees.h"
#include <limits.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes along the longest path (empty tree => 0)
 */
static size_t tree_height(const binary_tree_t *tree)
{
        size_t lh, rh;

        if (!tree)
        {
                return (0);
        }

        lh = tree_height(tree->left);
        rh = tree_height(tree->right);

        return (lh > rh ? lh + 1 : rh + 1);
}

/**
 * is_bst_util - checks the BST property within bounds
 * @tree: pointer to the root of the subtree
 * @min: lower allowable value
 * @max: upper allowable value
 *
 * Return: 1 if all node->n satisfy min ≤ n ≤ max, else 0
 */
static int is_bst_util(const binary_tree_t *tree, long min, long max)
{
        if (!tree)
        {
                return (1);
        }

        if (tree->n < min || tree->n > max)
        {
                return (0);
        }

        return (is_bst_util(tree->left,  min, (long)tree->n - 1) &&
                        is_bst_util(tree->right, (long)tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 *         (NULL tree is not considered AVL here)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
        int lh, rh;

        if (!tree)
        {
                return (0);
        }

        /* Must satisfy BST property */
        if (!is_bst_util(tree, LONG_MIN, LONG_MAX))
        {
                return (0);
        }

        /* Compute balance factor */
        lh = (int)tree_height(tree->left);
        rh = (int)tree_height(tree->right);
        if ((lh - rh) > 1 || (rh - lh) > 1)
        {
                return (0);
        }

        /* Recursively ensure each subtree is also AVL */
        if (tree->left)
        {
                if (!binary_tree_is_avl(tree->left))
                {
                        return (0);
                }
        }

        if (tree->right)
        {
                if (!binary_tree_is_avl(tree->right))
                {
                        return (0);
                }
        }

        return (1);
}
