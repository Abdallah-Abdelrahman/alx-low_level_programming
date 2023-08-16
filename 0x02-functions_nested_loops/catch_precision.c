#include "main.h"
/**
  * print_precision - print interger based on precision
  * @n: number to print.
  */
void print_precision(int n)
{
	int f, s, t;

	if (n > 999)
	{
		f1st = n % 10;
		s2nd = (n / 10 / 10) % 10;
		t3rd = (n / 10 / 10 / 10) % 10;
		f4th = (n / 10 / 10) / 10;
	}

	if (n > 99)
	{
		f = n % 10;
		s = (n / 10) % 10;
		t = (n / 10) / 10;
		_putchar(t + '0');
		_putchar(s + '0');
		_putchar(f + '0');

	}

	if (n < 100 && n > 9)
	{

		f = n % 10;
		s = n / 10;
		_putchar(s + '0');
		_putchar(f + '0');

	}

	if (n < 10)
	{
		_putchar(n + '0');
	}
}
