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
		switch (*(str - 1))
		{
			case ' ': case '.':
			case '(': case ')':
			case '{': case '}':
			case ',': case ';':
			case '?': case '!':
			case '\n': case '\t':
			case '"':
				if (*str >= 'a' && *str <= 'z')
					*str -= 32;
		}
		if (*(str - 1) == '\t')
			*(str - 1) = ' ';
		str++;
	}
	if (*ptr >= 'a' && *ptr <= 'z')
		*ptr -= 32;

	return (ptr);
}
