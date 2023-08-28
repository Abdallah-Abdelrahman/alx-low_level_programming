#include "main.h"

/**
 *  _strchr - locates a character in a string
 * @s: string pointer
 * @c: character to find
 *
 * Return: pointer to the first occurence of `c`
 */
char *_strchr(char *s, char c)
{
	if (!c)
		return (NULL);

	for (; *s; s++)
		if (*s == c)
		{
			return (s);
		}
	return (NULL);
}
