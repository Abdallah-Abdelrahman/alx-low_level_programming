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
	dlistint_t *node;
	unsigned int len = dlistint_len(*h);

	if (idx > len)
		return (0);
	if (idx == len)
		return (add_dnodeint_end(h, n));
	if (idx == 0)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (0);
		node->n = n;
		node->next = *h;
		if (*h)
		{
			node->prev = (*h)->prev;
			(*h)->prev = node;
		}
		else
			node->prev = 0;
		*h = node;
		return (node);
	}
	return (insert_dnodeint_at_index(&(*h)->next, idx - 1, n));
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

