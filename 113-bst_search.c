#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: Pointer to the node containing a value equals to value,
 *         or NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		else if (tree->n < value)
			tree = tree->right;
		else
			tree = tree->left;
	}

	return (NULL);
}
