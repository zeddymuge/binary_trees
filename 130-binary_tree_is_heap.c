#include "binary_trees.h"
/**
 * get_nodes - calculates no of nodes
 * @root: pointer to root node
 * Return: no of nodes
 */
int get_nodes(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (get_nodes(root->left) +
			get_nodes(root->right) + 1);
}

/**
 * check_complete - checks if tree is complete
 * @root: pointer to root node
 * @index: index of node
 * @nodes: no of nodes
 * Return: 1 if complete, 0 otherwise
 */
int check_complete(const binary_tree_t *root, int index, int nodes)
{
	if (!root)
		return (1);
	if (index >= nodes)
		return (0);

	return (check_complete(root->left, 2 * index + 1, nodes) &&
			check_complete(root->right, 2 * index + 2, nodes));
}

/**
 * check_status - checks if child > parent node
 * @node: pointer to node
 * Return: 1 if Max heap, 0 otherwise
 */
int check_status(const binary_tree_t *node)
{
	if (!node)
		return (1);
	if (node->left)
	{
		if (node->left->n > node->n)
			return (0);
	}
	if (node->right)
	{
		if (node->right->n > node->n)
			return (0);
	}
	return (check_status(node->left) && check_status(node->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int complete, status, index = 0, nodes;

	if (!tree)
		return (0);

	nodes = get_nodes(tree);
	complete = check_complete(tree, index, nodes);
	status = check_status(tree);

	return (complete && status);
}
