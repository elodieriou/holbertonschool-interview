#include "binary_trees.h"

/**
 * heap_extract - Function that extracts the root of a Max Binary Heap
 * @root: Double Pointer to the root node of the heap
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	last_node = find_last_node(*root);

	if ((*root) == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	if (last_node->parent != NULL && last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	if (last_node->parent != NULL && last_node->parent->right == last_node)
		last_node->parent->right = NULL;

	(*root)->n = last_node->n;
	free(last_node);

	heapify(root);
	return (value);
}

/**
 * find_last_node - Function that finds the last level-order node of the heap
 * @root: Double pointer to the root of the heap
 * Return: The last node
 */
heap_t *find_last_node(heap_t *root)
{
	int lvl = 0, i;
	int size = heap_size(root);
	heap_t *node = NULL;
	heap_t	**queue = malloc(size * sizeof(heap_t *));

	if (root == NULL || size == 0 || queue == NULL)
		return (NULL);

	queue[lvl++] = root;

	i = 0;
	while (i < size)
	{
		node = queue[i++];
		if (node->left != NULL)
			queue[lvl++] = node->left;
		if (node->right != NULL)
			queue[lvl++] = node->right;
	}

	free(queue);
	return (node);
}

/**
 * heap_size - Function that computes the size of the heap
 * @root: Double pointer to the root of the heap
 * Return: The size
 */
int heap_size(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (heap_size(root->left) + 1 + heap_size(root->right));
}

/**
 * heapify - Function that creates a max heap
 * @root: Double pointer to the root of the heap
 * Return: Nothing
 */
void heapify(heap_t **root)
{
	int tmp;
	heap_t *largest = *root;
	heap_t *left = (*root)->left;
	heap_t *right = (*root)->right;

	if (left != NULL && left->n > largest->n)
		largest = left;
	if (right != NULL && right->n > largest->n)
		largest = right;

	if (largest != *root)
	{
		tmp = largest->n;
		largest->n = (*root)->n;
		(*root)->n = tmp;

		heapify(&largest);
	}
}
