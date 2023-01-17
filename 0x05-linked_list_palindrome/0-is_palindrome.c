#include "lists.h"

/**
 * is_palindrome - function that check if a linked list is a palindrome
 * @head: the beginning of the linked list
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *end = NULL, *newHead = NULL;
	int len = size_listint(&*head);

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return (1);

	slow = fast = *head;
	while (fast != NULL && fast->next != NULL)
	{
		end = slow;
		slow = slow->next;
		fast = fast->next->next;

		if (fast != NULL)
			newHead = slow->next;
		else
			newHead = slow;
	}
	end->next = NULL;

	if (len > 3)
		reverse_listint(&newHead);

	return (is_identical_listint(*head, &*newHead));
}

/**
 * size_listint - function that define the number of node in a linked list
 * @head: the beginning of the linked list
 * Return: the number of node
 */
int size_listint(listint_t **head)
{
	listint_t *tmp = *head;
	int len = 0;

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

/**
 * reverse_listint - function that reverse a linked list
 * @head: the beginning of the linked list
 * Return: Nothing
 */
void reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL, *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	*head = prev;
}

/**
 * is_identical_listint - function that check if two linked list are identical
 * @head1: the beginning of the first linked list
 * @head2: the beginning of the second linked list
 * Return: true if the lists are identical, false otherwise
 */
bool is_identical_listint(listint_t *head1, listint_t *head2)
{
	listint_t *tmp1 = head1, *tmp2 = head2;

	while (tmp1 != NULL && tmp2 != NULL)
	{
		if (tmp1->n == tmp2->n)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		else
			return (false);
	}
	return (true);
}
