#include "main.h"

/**
 * cap_string - cpitalizes a string
 * @str: string pointer
 *
 * Return: pointer to modified string
 */
char *cap_string(char *str)
{
	char *ptr = str;

	while (*str)
	{
		if ((*str - 1 == 32) && (*str >= 'a' && *str <= 'z'))
			*str -= 32;
		str++;
	}
	if (*ptr >= 'a' && *ptr <= 'z')
		*ptr -= 32;

	return (ptr);
}
