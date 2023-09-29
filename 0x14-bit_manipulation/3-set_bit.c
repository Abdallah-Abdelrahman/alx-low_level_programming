#include "main.h"

/**
 * set_bit - write your short description
 * @n: pointer to unsigned long
 * @index: index to set the bit
 *
 * Return: 1 on success,
 * -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n = *n | 1 << index;
	return (1);
}
