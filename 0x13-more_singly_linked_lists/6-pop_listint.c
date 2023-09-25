#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list.
 * Description: and returns the head node’s data (n).
 * @head: address of the head pointer
 *
 * Return: head's node data,
 * 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int n = 0;
	listint_t *tmp = 0;
	(void)tmp;

	if (!*head)
		return (n);

	tmp = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = 0;

	return (n);
}
