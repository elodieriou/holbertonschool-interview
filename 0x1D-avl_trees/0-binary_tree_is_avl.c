#include "binary_trees.h"

/**
 * max - function that computes the max between two integers.
 * @a: first integer.
 * @b: second_integer.
 * Return: a or b.
 */
int max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/**
 * height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: The height.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (max(height(tree->left), height(tree->right)) + 1);
}

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: 0, 1 or 2
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (height(tree) - 1);
}

/**
 * binary_avl_traverse - function that traverse down the tree
 * @node: a pointer to the node of the root to check
 * @min: the min value of a node
 * @max: the max value of a node
 * -1 and +1 in the last return is for checkin no duplicate value
 * Return: 1 if the binary tree is a AVL, 0 otherwise
 */
int binary_avl_traverse(const binary_tree_t *node, int min, int max)
{
	int left_height, right_height;

	if (node == NULL)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	left_height = binary_tree_height(node->left);
	right_height = binary_tree_height(node->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_avl_traverse(node->left, min, node->n - 1) &&
			binary_avl_traverse(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_avl - function that checks if a binary tree is a valid AVL
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or otherwise, 1 if tree is a valide AVL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_avl_traverse(tree, INT_MIN, INT_MAX));
}
