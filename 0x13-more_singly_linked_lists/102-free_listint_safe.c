#include "lists.h"
#define BUFF 1024

/**
 * free_listint_safe - write your short description
 * @h: address of head pointer
 *
 * Return: the size of free'd list
 */
size_t free_listint_safe(listint_t **h)
{
	int len = 0;
	listint_t *next = 0;
	listint_t **addr = 0;

	if (!h || !*h)
		return (0);

	if (!(*h)->next)
	{
		free(*h);
		*h = 0;
		return (1);
	}

	addr = malloc(sizeof(addr) * BUFF);
	if (!addr)
		exit(98);
	for (; h && *h; len++)
	{
		next = (*h)->next;
		addr[len] = *h;
		if (is_circular2(addr, len + 1))
		{
			*h = 0;
			free(addr);
			return (len);
		}
		free(*h);
		*h = 0;
		*h = next;
	}

	free(addr);
	return (len);
}

/**
 * is_circular2 - check if a list is circular
 * @addr: array of pointers to struct
 * @len: length of addr
 *
 * Return: 1 if it's circular,
 * 0 otherwise
 */
int is_circular2(listint_t **addr, int len)
{
	int i = 0, j;

	for (i = 0; i < len && addr[i]; i++)
		for (j = i + 1; j < len && addr[j]; j++)
			if (addr[i] == addr[j])
				return (1);
	return (0);
}

