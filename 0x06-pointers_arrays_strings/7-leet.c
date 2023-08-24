#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string pointer
 *
 * Return: pointer to the encoded string
 */
char *leet(char *str)
{
	char *ptr = str;
	char *letters = "AEOTL";
	int i, codes[] = {4, 2, 0, 7, 1};

	for (; *str; str++)
	{
		for (i = 0; i < 5; i++)
		{
			if (*str == letters[i] || *str == letters[i] + 32)
				*str = codes[i];
		}
	}

	return (ptr);
}
