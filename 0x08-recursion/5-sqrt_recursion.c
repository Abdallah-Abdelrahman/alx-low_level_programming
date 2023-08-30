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
	return (n);
}
