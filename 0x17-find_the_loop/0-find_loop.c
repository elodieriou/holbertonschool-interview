#include <stdio.h>
#include "lists.h"


/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: the head of the linked list
 * Return: the address of the node where the loop starts
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (head == NULL || head->next == NULL)
		return (NULL);

	while (slow && fast)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow && fast)
			{
				if (slow == fast)
					return (slow);

				slow = slow->next;
				fast = fast->next;

			}
		}
	}
	return (NULL);
}
