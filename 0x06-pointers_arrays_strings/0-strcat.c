#include "main.h"

/**
 * _strcat - concatenates 2 strings
 * @dest: destination string
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;

	for (; *dest; dest++, len++)
		;
	for (; *src; src++, len++)
		dest[len] = *src;

	dest[len] = '\0';

	return (dest);
}
