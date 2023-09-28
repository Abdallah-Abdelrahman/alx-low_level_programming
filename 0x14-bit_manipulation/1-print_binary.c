#include "main.h"

/**
 * print_binary - write your short description
 * @n: the number to print its binary
 *
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
		_putchar('0');
	if (n > 0)
	{
		print_rev(n);
	}
}

/**
 * print_rev - print binary recursively
 * @n: the number to print its binary
 */
void print_rev(unsigned long int n)
{
	if (n > 0)
	{
		print_rev(n >> 1);
		_putchar((n & 1) + '0');
	}
}
