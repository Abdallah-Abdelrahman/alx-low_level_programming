#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
* main -prints the first 98 Fibonacci numbers
*
* Return: 0 as exit status
*/
int main(void)
{
	unsigned long i = 0, n1 = 0, n2 = 1, next = n1 + n2;


	while (i < 98)
	{
		if (i != 0)
		{
			_putchar(',');
			_putchar(' ');
		}
		print_chars(next);
		n1 = n2;
		n2 = next;
		next = n1 + n2;
		i++;
	}

	_putchar('\n');

	return (0);
}

/**
 * print_chars - prints long integer number recursively
 * @n: number
 */
void print_chars(unsigned long int n)
{
	if (n > 9)
	{
		print_chars(n / 10);
		_putchar((n % 10) + '0');
	}
	else
		_putchar(n + '0');
}
