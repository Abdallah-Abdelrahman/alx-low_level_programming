#include "lists.h"
#include <stddef.h>

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
			i = _strlen(h->str);
			printf("[%lu] %s\n", i, h->str);
		}
	}

	return (len);
}

/**
 * _strlen - get the length of string
 * @str: string pointer
 *
 * Return: the lenght of @str
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	if (!str)
		return (len);

	for (; str[len]; len++)
		;
	return (len);
}
