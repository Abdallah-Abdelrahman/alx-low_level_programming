#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @str: string pointer
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *str)
{
	int j;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *encode = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *ptr = str;

	for (; *str; str++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*str == alpha[j])
			{
				*str = encode[j];
				break;
			}
		}
	}

	return (ptr);
}

