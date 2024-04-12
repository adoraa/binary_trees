#include "binary_trees.h"

/**
 * bst_find_min - Finds the minimum value in a Binary Search Tree
 * @root: Pointer to the root node of the BST
 *
 * Return: Pointer to the node containing the minimum value
 */
static bst_t *bst_find_min(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing
 *         the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
