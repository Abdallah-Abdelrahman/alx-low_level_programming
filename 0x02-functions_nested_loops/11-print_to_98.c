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

#include "main.h"
/**
  * print_precision - print interger based on precision
  * @n: number to print to print it precisions.
  */
void print_precision(int n)
{
	/* mulitple of 10 */
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
		print_precision(n / 10);
		_putchar((n % 10) + '0');
	}
}
