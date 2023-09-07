#include "main.h"

/**
 * malloc_checked - allocates memory using malloc.
 * @b: bytes to allocates
 *
 * Return: a pointer of void
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (!ptr)
		exit(98);
	return (ptr);
}
