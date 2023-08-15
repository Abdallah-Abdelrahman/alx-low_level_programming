#include "main.h"
#include <stdlib.h>

/**
* print_last_digit - prints the last digit of a number
* @n: number to find the last digit of
* Return: the value of the last digit.
*/
int print_last_digit(int n)
{
	_putchar((n % 10) + '0');
	if (n < 0)
	{
		_putchar((abs(n) % 10) + '0');
		return (abs(n) % 10);
	}
	return ((n % 10));
}
