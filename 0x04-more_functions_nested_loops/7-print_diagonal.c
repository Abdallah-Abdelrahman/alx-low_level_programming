#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 * @n: the number of times '\' printed.
 *
 */
void print_diagonal(int n)
{
	int i = 0, j;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (; i < n; i++)
		{
			j = i;

			while (j != 0 && j <= i)
			{
				_putchar(' ');

				/* book keeping */
				j++;
			}

			_putchar('\');
			_putchar('\n');
		}
	}
}
