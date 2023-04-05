#include "search.h"

/**
 * linear_skip - Function that searches for value in a sorted skip list of int
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search
 * Return: Pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *tmp;

	if (list == NULL)
		return (NULL);

	if (list->n == value)
		return (list);

	current = list;
	while (current->express != NULL && current->n < value)
	{
		tmp = current;
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
	}
	return (linear_search(current, tmp, value));
}

/**
 * linear_search - Function that linear search the value
 * @current: Pointer to the value that move
 * @tmp: Pointer to tmp value search
 * @value: Value to find
 * Return: NULL or pointer to the node find
 */
skiplist_t *linear_search(skiplist_t *current, skiplist_t *tmp, int value)
{
	if (current->n < value)
	{
		tmp = current;
		while (current->next != NULL && current->n < value)
			current = current->next;

		printf("Value found between indexes [%lu] and [%lu]\n",
			   tmp->index, current->index);
	}
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
			   tmp->index, current->index);

	while (tmp->next != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);

		if (tmp->n == value)
			return (tmp);

		else if (tmp->n > value)
			return (NULL);

		tmp = tmp->next;

		if (tmp->n < value && tmp->next == NULL)
		{
			printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
			return (NULL);
		}
	}
	return (NULL);
}
