#include "main.h"

/**
* print_times_table -prints the n times table, starting with 0.
* @n: integer to print
*
*/
void print_times_table(int n)
{

	if (n > 0 && n < 15)
	{
		print_table(n + 1);
	}

}

/**
  * print_table - print table according to n.
  * @n: interger > 0 && < 15
  */
void print_table(int n)
{
	int i = 0, j = 0;

	for (; i < n; i++)
	{
		for (; j < n; j++)
		{
			if (i * j < 9)
			{
				if (j != 0)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
				}
				_putchar((i * j) + '0');
			}

			if (i * j > 9 && i * j < 100)
			{
				_putchar(' ');
				_putchar((i * j / 10) + '0');
				_putchar((i * j % 10) + '0');

			}

			if (i * j > 99)
			{
				_putchar(' ');
				_putchar((((i * j) / 10) / 10) + '0');
				_putchar((((i * j) / 10) % 10) + '0');
				_putchar((i * j) + '0');
			}

			if (j < n)
				_putchar(',');


		}
		j = 0;

		_putchar('\n');
	}

}
