#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: address of head pointer
 * @idx: position to insert at
 * @n: integer data
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int len = dlistint_len(*h);
	(void)len;


	return (insert(h, idx, n));
}

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @h: pointer to head
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int len = 0;

	for (; h; h = h->next, len++)
		;

	return (len);
}

/**
 * insert - add a node at given position
 * @head: head pointer
 * @idx: indext at which to add the new node
 * @n: integer member in the node
 *
 * Return: pointer to the newly inserted node,
 * `NULL` on failure
 */
dlistint_t *insert(dlistint_t **head, unsigned int idx, int n)
{
	if (idx == 0)
	{
		return (add_dnodeint(head, n));
	}

	return (insert(&(*head)->next, idx - 1, n));
}
