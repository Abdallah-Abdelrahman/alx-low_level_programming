#include "main.h"

/**
 * get_endianness - write your short description
 *
 * Return: 0 as exit status
 */
int get_endianness(void)
{
	unsigned int i = 1;
	unsigned char *ptr = (unsigned char *)&i;

	return ((int)*ptr);
}
