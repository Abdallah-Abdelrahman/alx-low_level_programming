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
	return (diffing(n, 0));
}

/**
 * diffing - get the square root by diffing last from first
 * @n: integer number
 * @guess: guess number
 *
 * Return: square root
 */
int diffing(int n, int guess)
{
	int sqrt_guess = guess * guess;

	if (sqrt_guess == n)
		return (guess);
	if (sqrt_guess > n)
		return (-1);
	return (diffing(n, guess + 1));
}
