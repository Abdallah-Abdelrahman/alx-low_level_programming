#include "main.h"

/**
 * print_square - prints a square, followed by a new line.
 * @size: integer represents square size
 *
 */
void print_square(int size)
{
	int i = 0, j = 0;

	if (size <= 0)
		_putchar('\n');

	else
	{
		for (; i < size; i++)
		{
			for (; j < size; j++)
			{
				_putchar('#');
			}

			/* book keeping */
			j = 0;

			_putchar('\n');
		}

	}
}
