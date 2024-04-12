#include "binary_trees.h"

/**
 * max - Computes the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of @a and @b
 */
static int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Computes the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The height of the tree, or 0 if @tree is NULL
 */
static int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (0);
	left_height = height(tree->left);
	right_height = height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
