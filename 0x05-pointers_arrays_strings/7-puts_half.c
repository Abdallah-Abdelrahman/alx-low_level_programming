#include "main.h"

/**
 * puts_half - prints half of the string
 * @str: stirng pointer
 *
 */
void puts_half(char *str)
{
	int len = 0, count = 0;

	for (; *str; str++, len++)
		;

	if (len % 2 == 0)
		count = len / 2;
	else
		count = (len - 1) / 2;

	for (; *(str - count); count--)
		_putchar(*(str - count));

	_putchar('\n');
}
