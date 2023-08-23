#include <stdio.h>

/**
 * _strncat - concatenates 2 strings using n bytes,
 * from source string.
 * @dest: destination string
 * @src: source string
 * @n: number of bytes from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	char *ptr = dest;

	for (; *dest; dest++)
		;
	for (; i < n && *src; src++, dest++, i++)
		*dest = *src;
	*dest = '\0';

	return (ptr);
}
