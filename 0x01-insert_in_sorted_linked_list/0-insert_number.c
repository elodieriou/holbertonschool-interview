#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: integer to be included in new node
 * Return: the address of the new node or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	while (current->next && current->next->n < number)
		current = current->next;

	if (current == *head || current == NULL || current->next->n > number) {
		new->next = current;
		*head = new;
	}
	else {
		new->next = current->next;
		current->next = new;
	}

	return (new);

}
