#include "main.h"

/**
 * _puts - write your short description
 * @str: pointer to string
 *
 */
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
