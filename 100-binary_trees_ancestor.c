#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of 2 nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;

	if (node1 == NULL || node2 == NULL)
		return (NULL);
	while (node1 != node2)
	{
		if (node1 == NULL)
			node1 = second;
		else
			node1 = node1->parent;
		if (node2 == NULL)
			node2 = first;
		else
			node2 = node2->parent;
	}
	return ((binary_tree_t *)node1);
}
