#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *node;

	queue_t *queue = NULL;

	queue = queue_create();

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		*node = (binary_tree_t *)queue_front(queue);
		func(node->n);
		if (node->left != NULL)
			queue_push(queue, (void *)node->left);
		if (node->right != NULL)
			queue_push(queue, (void *)node->right);
		queue_pop(queue);
	} queue_delete(queue);
}
