#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 */
void more_numbers(void)
{
	int i = 0, j = 0;

	for (; i < 10; i++)
	{
		for (; j < 15; j++)
		{
			if (j < 10)
				_putchar(j + '0');
			else 
			{
				_putchar((j / 10) + '0');
				_putchar((j % 10) + '0');
			}
		}
		_putchar('\n');

		/* book keeping */
		j = 0;
	}
}

/**
  * print_chars - print interger based on charaters
  * @n: number to print one character at a time.
  */
void print_chars(unsigned long int n)
{
	if (n < 10)
	{
		_putchar(n + '0');
	}

	else if ((n / 10) < 10)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		print_chars(n / 10);
		_putchar((n % 10) + '0');
	}
}
