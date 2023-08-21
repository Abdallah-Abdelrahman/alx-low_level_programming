#include "main.h"

/**
 * print_rev - prints a string, in reverse
 * @s: string pointer
 *
 */
void print_rev(char *s)
{
	char first = *s;

	while (*s)
		s++;
	while (first != *s)
		_putchar(*(--s));
	_putchar('\n');
}
