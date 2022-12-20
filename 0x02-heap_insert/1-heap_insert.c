#include "binary_trees.h"

/**
 * swap_node - function that swap the node between parent and child
 * @parent: the parent node
 * @new: the new node to swap
 * Return: Nothing
 */
void swap_node(int  *parent, int  *new)
{
	int tmp;

	tmp = *new;
	*new = *parent;
	*parent = tmp;
}

/**
 * binary_tree_size - function that counts the number of nodes
 * @tree: a pointer to the beginning of the tree
 * Return: 0 if tree is NULL, the number of node otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + 1 +
			binary_tree_size(tree->right));
}

/**
 * find_children - function that finds children
 * @tree: a pointer to the beginning of the tree
 * @index: the node to check
 * @size: the number of node in the tree
 * Return: left if child on left
 *         right if child on right
 *         NULL if children on left and right
 */
heap_t *find_children(heap_t *tree, size_t index, size_t size)
{
	heap_t *left_child, *right_child;

	if (index == size)
		return (tree);

	if (index > size)
		return (NULL);

	left_child = find_children(tree->left, 2 * index + 1, size);
	right_child = find_children(tree->right, 2 * index + 2, size);

	return (left_child ? left_child : (right_child ? right_child : NULL));
}

/**
 * find_parent_location - function that finds where to insert the new node
 * @tree: a pointer to the beginning of the tree
 * @new: the new node to insert
 * Return: the position of the parent
 */
heap_t *find_parent_location(heap_t *tree, heap_t *new)
{
	heap_t *parent;
	size_t size;

	size = binary_tree_size(tree);
	parent = find_children(tree, 0, (size - 1) / 2);

	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	return (parent);
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 * @root: Pointer to the beginning of the tree
 * @value: Integer stored in the node
 * Return: pointer to the inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent_location, *current;

	if (root == NULL)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new;
		return (new);
	}

	parent_location = find_parent_location(*root, new);
	new->parent = parent_location;
	current = new;

	while (current->parent && current->n > current->parent->n)
	{
		swap_node(&current->parent->n, &current->n);
		current = current->parent;
	}

	return (current);
}
