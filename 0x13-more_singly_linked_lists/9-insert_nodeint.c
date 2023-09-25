#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: address of head pointer
 * @idx: index of the list where new node should be added
 * @n: integer memeber in the node
 *
 * Return: pointer to the newly inserted node,
 * `NULL` on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int len = list_len(*head);

	if (idx > len)
		return (0);
	if (!*head)
		return (add_nodeint_end(head, n));
	return (insert(head, idx, n));
}

/**
 * insert - add a node at given cursor
 * @head: head pointer
 * @idx: indext at which to add the new node
 * @n: integer member in the node
 *
 * Return: pointer to the newly inserted node,
 * `NULL` on failure
 */
listint_t *insert(listint_t **head, unsigned int idx, int n)
{
	listint_t *node = malloc(sizeof(*node));

	if (!node)
		return (0);
	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		node->n = n;
		return (node);
	}

	return (insert(&(*head)->next, idx - 1, n));
}

/**
 * list_len - calculate the length of list
 * @head: head pointer
 *
 * Return: the length of the list
 */
unsigned int list_len(listint_t *head)
{
	if (!head)
		return (0);
	return (1 + list_len(head->next));
}
