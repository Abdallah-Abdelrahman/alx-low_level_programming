#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints an integer
 * @n: integer
 *
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		print_chars(abs(n));
	}
	else
	{
		print_chars(n);
	}
}


/**
 * print_chars - print interger based on precision
 * @n: number to print to print it precisions.
 */
void print_chars(int n)
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
