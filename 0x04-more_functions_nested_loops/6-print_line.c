#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: number of '_' to print
 *
 */
void print_line(int n)
{
	if (n <= 0)
		_putchar('\n');

	else
	{
		while (n)
		{
			_putchar('_');

			/* book keeping */
			n--;
		}
		_putchar('\n');
	}
}
