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
	unsigned int long int_max = 9223372036854775807;
	size_t len = nmemb * size;
	size_t i;
	void *ptr;
	char *cpy;

	if (nmemb == 0 || size == 0)
		return (0);

	if (len > int_max)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	cpy = (char *)ptr;

	for (i = 0; i < nmemb; i++)
		cpy[i] = 0;

	return (ptr);
}
