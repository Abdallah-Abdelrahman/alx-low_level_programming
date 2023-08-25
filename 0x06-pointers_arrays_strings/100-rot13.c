#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @str: string pointer
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *str)
{
	int i, j;
	char *alpha = "ABCDEFGHIjKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *encode = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
				str[i] = encode[j];
		}

	}

	return (str);
}
