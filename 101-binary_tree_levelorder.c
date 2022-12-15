#include "binary_trees.h"
/**
 * binary_tree_levelorder - function that goes through a binary tree
 * using level-order traversal.
 * @tree: root node.
 * @func: function pointer to print the node value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_h = 0, level;

	if (!tree || !func)
		return;

	tree_h = tree_height(tree);
	for (level = 0; level <= tree_h; level++)
		print_level(tree, level, func);

}
/**
 * tree_height - function that measures the height of a sub-tree.
 * @tree: root node.
 * Return: the height of the tree or -1 if there is no tree.
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (-1);

	if (tree->left)
		left_height = tree_height(tree->left) + 1;
	if (tree->right)
		right_height = tree_height(tree->right) + 1;

	if (left_height >= right_height)
		return (left_height);
	return (right_height);
}
/**
 * print_level - function to print the nodes at the level.
 * @tree: root node.
 * @level: level of the node.
 * @func: function pointer to print the node value.
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (!level)
		func(tree->n);

	print_level(tree->left, level - 1, func);
	print_level(tree->right, level - 1, func);

}
