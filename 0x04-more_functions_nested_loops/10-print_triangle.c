#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line.
 * @size: the size of the triangle
 *
 */
void print_triangle(int size)
{
	int i = 0, j, k;

	if (size <= 0)
		_putchar('\n');

	else
	{
		for (; i < size; i++)
		{
			j = size - i - 1;

			for (; j > 0; j--)
			{
				_putchar(' ');
			}

			k = 0;

			for (; k <= i; k++)
			{
				_putchar('#');
			}

			_putchar('\n');
		}

	}
}
