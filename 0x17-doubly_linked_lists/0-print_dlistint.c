#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: pointer to head
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int len = 0;

	for (; h; h = h->next, len++)
		printf("%d\n", h->n);

	return (len);
}
