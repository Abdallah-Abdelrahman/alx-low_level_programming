#include "main.h"
#include <string.h>

/**
 * rot13 - encodes a string using rot13.
 * @str: string pointer
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *str)
{
	char *alphabet = "ABCDEFGHIjKLMNOPQRSTUVWXYZ";
	char *encode = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	char *ptr = str;
	int i;

	strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");
	strcpy(encode, "nopqrstuvwxyzabcdefghijklm");

	for (; *str; str++)
	{
		for (i = 0; i < 51; i++)
		{
			if (*str == alphabet[i])
				*str = encode[i];
		}

	}

	return (ptr);
}
