#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer
 *
 */
void print_number(int n)
{
	int n = 0;

	while (n < 10)
	{
		_putchar(n + '0');
		n++;
	}
	_putchar('\n');
}
