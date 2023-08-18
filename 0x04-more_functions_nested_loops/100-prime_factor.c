#include <unistd.h>
#include "main.h"

/**
 * main - find the largest prime factor
 *
 * Return: 0 as exit status
 */
int main(void)
{

	long i = 2, number = 612852475143;

	while (number != 1)
	{
		if (number % i != 0)
			i++;
		else
		{
			number /= i;
		}
	}
	print_chars(i);

	putchar('\n');

	return (0);
}

/**
 * print_chars - print interger based on precision
 * @n: number to print to print it precisions.
 */
void print_chars(unsigned int n)
{
	if (n < 10)
	{
		putchar(n % 10 + '0');
	}

	else if ((n / 10) < 10)
	{
		putchar((n / 10) + '0');
		putchar((n % 10) + '0');
	}
	else
	{
		print_chars(n / 10);
		putchar((n % 10) + '0');
	}
}
