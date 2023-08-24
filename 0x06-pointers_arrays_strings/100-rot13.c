#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @str: string pointer
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *str)
{
	char *alpha = "ABCDEFGHIjKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *encode = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *ptr = str;
	int i, j;

	for (j = 0; *(str + j); j++)
	{
		for (i = 0; i < 52; i++)
		{
			if (str[j] == alpha[i])
				str[j] = encode[i];
		}

	}

	return (ptr);
}
