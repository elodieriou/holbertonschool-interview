#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


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
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *);
int binary_tree_is_avl(const binary_tree_t *tree);
int max(int a, int b);
int height(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_avl_traverse(const binary_tree_t *node, int min, int max);

#endif /* BINARY_TREES_H */
