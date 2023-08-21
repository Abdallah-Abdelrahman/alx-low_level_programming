#include "main.h"

/**
 * puts2 - prints every other character, starting with 1st
 * @str: string pointer
 *
 */
void puts2(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str += 1;
	}
	_putchar('\n');
}
