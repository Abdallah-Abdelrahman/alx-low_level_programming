#include "main.h"

/**
 * is_prime_number - check for a prime number
 * @n: integer number
 *
 * Return: 1 if't a prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	if (n > 9 && n % 5 == 0)
		return (0);
	if (sum_digits(n) % 3 == 0)
		return (0);
	return (1);

}

/**
 * sum_digits - sum the digits of integer
 * @n: integer number
 *
 * Return: the sum of digits of a given number
 */
int sum_digits(int n)
{
	if (n < 10)
		return (n);
	return ((n % 10) + sum_digits(n / 10));
}
