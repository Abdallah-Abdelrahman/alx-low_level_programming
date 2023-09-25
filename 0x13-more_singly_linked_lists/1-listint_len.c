#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: header
 *
 * Return: returns number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t len = 0;

	if (!h)
		return (len);

	for (len = 0; h; len++, h = h->next)
		;
	return (len);
}
