#include "lists.h"

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
