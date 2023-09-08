#include "main.h"

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	/**
	 * size_t:
	 * According to the 1999 ISO C standard (C99),
	 * size_t is an unsigned integer type of at least 16 bit
	 */
	size_t int_max = 9223372036854775807;
	size_t len = nmemb * size;
	size_t i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (0);

	if (len > int_max)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);

	for (i = 0; i < len; i++)
		ptr[i] = 0;

	return (ptr);
}
