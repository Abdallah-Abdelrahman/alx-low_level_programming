#include "main.h"

/**
 * _pow_recursion - calculate the power of x^y
 * @x: the base
 * @y: the power
 *
 * Return: x^y
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
