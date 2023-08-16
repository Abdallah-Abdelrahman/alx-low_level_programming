#include <stdlib.h>
#include "main.h"
/**
* print_to_98 - prints all natural numbers from n to 98.
* @n: real integer to print
*
*/
void print_to_98(int n)
{
	int end = 98;
	int abs_n = abs(n);

	while (n != end)
	{
		if (n < 0)
			_putchar('-');

		print_precision(abs_n);

		_putchar(',');
		_putchar(' ');

		/* book keeping o_0 */
		if (n < end)
			n++;
		else
			n--;

		abs_n = abs(n);

	}
	_putchar((end / 10) + '0');
	_putchar((end % 10) + '0');
	_putchar('\n');
}

/**
  * print_precision - print interger based on precision
  * @n: number to print.
  */
void print_precision(int n)
{
	int f, s, t;

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
