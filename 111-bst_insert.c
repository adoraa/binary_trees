#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	bst_t *new_node, *current;
	current = *tree;

	while (current)
	{
		if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
			{
				new_node = binary_tree_node(current, value);
				if (new_node == NULL)
					return (NULL);
				current->left = new_node;
				return (new_node);
			}
		}
		else if (value > current->n)
		{
			if (current->right)
				current = current->right;
			else
			{
				new_node = binary_tree_node(current, value);
				if (new_node == NULL)
					return (NULL);
				current->right = new_node;
				return (new_node);
			}
		}
		else
			return (NULL);
	}

	return (NULL);
}
