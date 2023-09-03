#include "main.h"
/**
  * print_precision - print interger based on precision
  * @n: number to print to print it precisions.
  */
void long_precision(unsigned long long int n)
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
		long_precision(n / 10);
		_putchar((n % 10) + '0');
	}
}
