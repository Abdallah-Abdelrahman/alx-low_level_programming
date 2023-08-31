#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: integer number
 *
 * Return: if doesn't have natural square root, returns -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n <= 1)
		return (n);
	return (diffing(n, 0, n));
}

/**
 * diffing - get the square root by diffing last from first
 * @n: integer number
 * @f: first
 * @l: last
 * 
 * Return: square root
 */
int diffing(int n, int f, int l)
{
	int m, sqrt_m;

	if (f > l)
		return (l);

	m = f + (l - f) / 2;
	sqrt_m = m * m;
	if (sqrt_m == n)
		return (sqrt_m);
	if (sqrt_m < n)
		return (diffing(n, m + 1, n));
	else
		return (diffing(n, f, m - 1));
}
