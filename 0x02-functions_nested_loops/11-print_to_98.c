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
