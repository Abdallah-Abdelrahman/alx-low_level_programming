#include "main.h"

/**
 * puts2 - prints every other character, starting with 1st
 * @str: string pointer
 *
 */
void puts2(char *str)
{
	int i = 0;

	while (*str)
	{
		if (*str == '.')
			i++;

		if (i < 3)
			_putchar(*str);
		str += 2;
	}
	_putchar('\n');
}
