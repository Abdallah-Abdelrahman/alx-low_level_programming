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
	char *ptr = dest;

	for (; *dest; dest++)
		;
	for (; *src; src++, dest++)
		*dest = *src;

	*dest = '\0';

	return (ptr);
}
