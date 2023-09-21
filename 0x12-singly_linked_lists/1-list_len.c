#include "lists.h"

/**
 * list_len - write your short description
 * @h: head of singly linked list
 *
 * Return: the length of the list
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	if (!h)
		return (len);

	for (; h; h = h->next, len++)
		;

	return (len);
}
