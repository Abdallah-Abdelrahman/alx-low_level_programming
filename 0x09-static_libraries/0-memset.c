#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * @s: string pointer
 * @b: character to fill the buffer with
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
		s[i] = b;
	return (s);
}
