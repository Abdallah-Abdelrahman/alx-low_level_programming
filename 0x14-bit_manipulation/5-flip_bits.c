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

	return (count_set(n ^ m));
}

/**
 * count_set - count the 1's
 * @n: number
 *
 * Return: count of sets
 */
unsigned int count_set(unsigned long int n)
{
	if (!n)
		return (0);
	return ((n & 1) + count_set(n >> 1));
}
