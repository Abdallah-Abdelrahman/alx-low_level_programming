#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: head pointer
 *
 * Return: pointer to the 1st node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *new_head;

	if (!*head || !(*head)->next)
		return (*head);

	new_head = reverse((*head)->next);
	(*head)->next->next = *head;
	(*head)->next = 0;
	*head = new_head;

	return (new_head);
}

/**
 * reverse - reverse list recursively
 * @head: head pointer
 *
 * Return: pointer to the last node
 */
listint_t *reverse(listint_t *head)
{
	listint_t *new_head;

	if (!head || !head->next)
		return (head);

	new_head = reverse(head->next);
	head->next->next = head;
	head->next = 0;

	return (new_head);
}

