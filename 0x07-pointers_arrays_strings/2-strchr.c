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
	int i = 0;
	char *ptr = NULL;

	if (!c)
		return (ptr);

	for (; s[i]; i++)
		if (s[i] == c)
		{
			ptr = &s[i];
			break;
		}
	return (ptr);
}
