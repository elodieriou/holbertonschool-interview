#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);
heap_t *find_last_node(heap_t *root);
int heap_size(heap_t *root);
void heapify(heap_t **root);

#endif /* BINARY_TREE_H */
