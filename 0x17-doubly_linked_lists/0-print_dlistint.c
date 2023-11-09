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

	for (; h; h = h->next)
		printf("%d\n", h->n);
	printf("-> %d elemnents\n", len);

	return (len);
}
