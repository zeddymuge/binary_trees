#include "binary_trees.h"

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: pointer to the root node of the tree to traverse
 * Return: 1 if tree is complete, or 0 if not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_q *queen;
	binary_tree_t *tmp = NULL;
	int node_sum = 0;

	if (!tree)
		return (0);
	node_sum = binary_tree_size(tree), queen = malloc(sizeof(queue_q));
	if (!queen)
		return (0);
	memset(queen, 0, sizeof(queue_q));
	queen->head = 1, queen->tail = 0;
	queue_store(queen, tree);
	while (((queen->tail + 1) % MAX_Q_SIZE != queen->head) && node_sum)
	{
		tmp = queue_remove(queen, tmp);
		if (tmp)
		{
			node_sum--;
			queue_store(queen, tmp->left);
			queue_store(queen, tmp->right);
		}
		else
			break;
	}
	free(queen);
	if (node_sum)
		return (0);
	return (1);
}

/**
 * queue_store - store data to queue
 * @queen: the queue
 * @node: tree node of the same depth (from root)
 * Return: 0 if success, 1 if failed
 */
int queue_store(queue_q *queen, const binary_tree_t *node)
{
	if ((queen->tail + 2) % MAX_Q_SIZE == queen->head) /* if queue is full */
		return (1);
	queen->tail = (queen->tail + 1) % MAX_Q_SIZE;
	queen->queue_arr[queen->tail] = (binary_tree_t *)node;
	return (0);
}

/**
 * queue_remove - extract node data from queue
 * @queen: the queue
 * @node: tree node of the same depth (from root)
 * Return: node pointer with acquired data if success, null if failed
 */
binary_tree_t *queue_remove(queue_q *queen, const binary_tree_t *node)
{
	if ((queen->tail + 1) % MAX_Q_SIZE == queen->head) /* if queue is empty */
		return (NULL);
	node = queen->queue_arr[queen->head];
	queen->head = (queen->head + 1) % MAX_Q_SIZE;
	return ((binary_tree_t *)node);
}

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: size of binary tree, or 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t i = 0, left_i, right_i;

	if (!tree)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_i = binary_tree_size(tree->left);
	right_i = binary_tree_size(tree->right);
	i = left_i + right_i;
	return (i + 1);
}
