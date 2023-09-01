#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination
 * @src: source
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	char *ptr = dest;

	for (; i < n && *src; i++, src++, dest++)
		*dest = *src;
	for (; i < n; i++, dest++)
		*dest = '\0';

	return (ptr);
}
