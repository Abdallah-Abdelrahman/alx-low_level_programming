#include "lists.h"

/**
 * print_listint - prints all elements of list
 * @h: head of the list
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t len = 0;

	if (!h)
		return (len);

	for (len = 0; h; len++, h = h->next)
	{
		printf("%i\n", h->n);
	}

	return (len);
}
