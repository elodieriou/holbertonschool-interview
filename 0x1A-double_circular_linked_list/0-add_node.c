#include "list.h"

/**
 * add_node_end - Function that add a new node to the end of a
 * double circular and doubly linked list
 * @list: Double pointer to the head of list
 * @str: String to copy into the new node
 * Return: Address of the new node inserted in the list
 */
List *add_node_end(List **list, char *str)
{
	List *node, *last_node;

	if (list == NULL && str == NULL)
		return (NULL);

	node = create_new_node(str);

	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
	}

	else
	{
		last_node = (*list)->prev;
		node->next = *list;
		(*list)->prev = node;
		node->prev = last_node;
		last_node->next = node;
	}

	return (node);
}

/**
 * add_node_begin - Function that add a new node to the beginning of a
 * double circular and doubly linked list
 * @list: Double pointer to the head of list
 * @str: String to copy into the new node
 * Return: Address of the new node inserted in the list
 */
List *add_node_begin(List **list, char *str)
{
	List *node, *last;

	if (list == NULL && str == NULL)
		return (NULL);

	node = create_new_node(str);

	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
	}

	else
	{
		last = (*list)->prev;
		node->next = *list;
		node->prev = last;

		last->next = (*list)->prev = node;
		*list = node;
	}

	return (node);
}

/**
 * create_new_node - Function that create a new node
 * @str: String to copy into the new node
 * Return: Address of the new node created
 */

List *create_new_node(char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}
