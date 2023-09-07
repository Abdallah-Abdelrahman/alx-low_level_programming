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
	size_t i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (0);

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);

	for (i = 0; i < nmemb; i++)
		ptr[i] = 0;

	return (ptr);
}
