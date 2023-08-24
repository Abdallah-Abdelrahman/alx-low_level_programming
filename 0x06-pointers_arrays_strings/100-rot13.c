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
	int i;

	for (; *str; str++)
	{
		for (i = 0; i < 52; i++)
		{
			if (*str == alpha[i])
				*str = encode[i];
		}

	}

	return (ptr);
}