#include "main.h"

/**
 * flip_bits - write your short description
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	if (n == m)
		return (count_set(n));
	n ^= m;

	return (count_set(n));
}

/**
 * count_set - count the 1's
 * @n: number
 *
 * Return: count of sets
 */
unsigned int count_set(unsigned int n)
{
	if (!n)
		return (0);
	return ((n & 1) + count_set(n >> 1));
}

/**
 * equalbit_handler - return the number of bits in a number
 * @n:number
 *
 * Return: the count of bits
 */
unsigned int equalbit_handler(unsigned long int n)
{
	if (!n)
		return (0);
	return (1 + equalbit_handler(n >> 1));
}
