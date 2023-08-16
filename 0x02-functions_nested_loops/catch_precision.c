#include "main.h"
/**
  * print_precision - print interger based on precision
  * @n: number to print to print it precisions.
  */
void print_precision(int n)
{
	if ((n / 10) < 10)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		print_precision(n / 10);
		_putchar((n % 10) + '0');
	}
}
