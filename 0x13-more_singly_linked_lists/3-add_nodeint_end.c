#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: head of list
 * @n: integer value in the node
 *
 * Return: pointer to the appended node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *tail;

	if (!*head)
		return (add_nodeint(head, n));

	if ((*head)->next)
		return (add_nodeint_end(&(*head)->next, n));

	tail = malloc(sizeof(*tail));
	if (!tail)
		return (0);

	tail->n = n;
	tail->next = 0;
	(*head)->next = tail;

	return (tail);
}

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: address of head pointer
 * @n: integer member in the node
 *
 * Return: pointer to the newly created node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node = malloc(sizeof(*node));

	if (!node)
		return (0);

	node->next = *head;
	node->n = n;
	*head = node;

	return (node);
}

