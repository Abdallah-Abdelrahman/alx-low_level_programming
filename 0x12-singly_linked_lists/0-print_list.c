#include "lists.h"

/**
 * print_list - write your short description
 * @h: pointer to singly linked list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t len = 0, i;
	char *nil = "[0] (nil)";

	for (; h; len++, h = h->next)
	{
		if (!h->str)
			printf("%s\n", nil);
		else
		{
			for (i = 0; h->str[i]; i++)
				;
			printf("[%lu] %s\n", i, h->str);
		}
	}

	return (len);
}
