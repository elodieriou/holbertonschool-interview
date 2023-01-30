#include "lists.h"

/**
 * check_cycle - Check if a linked list has a cycle in it
 * @list: beginning of the linked list
 * Return: 0 if there is no cycle, 1 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	slow = fast = list;
	while (slow != NULL && slow->next != NULL &&
	fast != NULL && fast->next != NULL){

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}
	return (0);
}
