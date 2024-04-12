#include "binary_trees.h"

/**
 * binary_tree_levelorder_util - Utility function for level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * @level: Current level being processed
 *
 * Description: This function traverses the binary tree in level-order.
 */
void binary_tree_levelorder_util(const binary_tree_t *tree,
		void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_levelorder_util(tree->left, func, level - 1);
		binary_tree_levelorder_util(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree in level-order.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Calculate the height of the tree */
	int height = binary_tree_height(tree);

	/* Traverse the tree level by level */
	for (int level = 1; level <= height + 1; level++)
		binary_tree_levelorder_util(tree, func, level);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}
