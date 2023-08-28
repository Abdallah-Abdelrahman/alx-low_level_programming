#include "main.h"
#include <string.h>

/**
 *  _strchr - locates a character in a string
 * @s: string pointer
 * @c: character to find
 *
 * Return: pointer to the first occurence of `c`
 */
char *_strchr(char *s, char c)
{
	return (strchr(s, c));
}
