#include "list.h"

/**
 * add_node_end - Function that add a new node to the end of a
 * double circular linked list
 * @list: Double pointer to the head of list
 * @str: String to copy into the new node
 * Return: Address of the new node inserted in the list
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last_node;

	if (list == NULL && str == NULL)
		return (NULL);

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

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
	}

	else
	{
		last_node = (*list)->prev;
		new_node->next = *list;
		(*list)->prev = new_node;
		new_node->prev = last_node;
		last_node->next = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Function that add a new node to the beginning of a
 * double circular linked list
 * @list: Double pointer to the head of list
 * @str: String to copy into the new node
 * Return: Address of the new node inserted in the list
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *last_node;

	if (list == NULL && str == NULL)
		return (NULL);

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

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
	}

	else
	{
		last_node = (*list)->prev;
		new_node->next = *list;
		new_node->prev = last_node;
		last_node->next = (*list)->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}
