#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete_util - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_util(const binary_tree_t *tree,
		size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete_util(tree->left, 2 * index + 1, size) &&
			binary_tree_is_complete_util(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t index = 0;
	size_t size = binary_tree_size(tree);

	if (tree == NULL)
		return (0);

	return (binary_tree_is_complete_util(tree, index, size));
}
