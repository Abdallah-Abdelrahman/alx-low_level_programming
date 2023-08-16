#include <stdio.h>
#include "main.h"

/**
* main -prints the first 50 Fibonacci numbers
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 1;

	while (i < 50)
	{
		if (i <= 2)
		{
			print_precision(i + '0');
		}

		else

			print_precision(i * (i - 1) + '0');

		if (i != 49)
		{
			_putchar(',');
			_putchar(' ');
		}
	}

	_putchar('\n');

	return (0);
}
