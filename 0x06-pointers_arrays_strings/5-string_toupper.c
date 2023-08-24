#include "main.h"

/**
 * string_toupper - changes all lower-case to upper-case.
 * @str: pointer to a string
 *
 * Return: pointer to the modified string
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
	}
	return (ptr);
}
