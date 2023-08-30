#include "main.h"

/**
 * factorial - returns the factorial of a given number.
 * @n: number to calculate its factorial
 *
 * Return: if n < 0 returns -1, otherwise factorial
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n <= 2)
		return (n);
	return (n * factorial(n - 1));
}
