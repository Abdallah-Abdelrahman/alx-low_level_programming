#include "main.h"

/**
 * get_bit - return bit at a given index
 * @n: number
 * @index: start form 0
 *
 * Return: bit at index,
 * -1 on error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n >> index) & 1);
}
