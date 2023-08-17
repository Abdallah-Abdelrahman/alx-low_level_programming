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
			/* print the sequence here */
			print_chars(j);
		}
		_putchar('\n');
	}
}

/**
  * print_chars - print interger based on charaters
  * @n: number to print one character at a time.
  */
void print_chars(unsigned long long int n)
{
	if (n < 10)
	{
		_putchar(n % 10 + '0');
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
