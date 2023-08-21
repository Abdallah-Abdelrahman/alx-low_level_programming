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
		if (*str == '.')
			break;
		str += 2;
	}
	_putchar('\n');
}
