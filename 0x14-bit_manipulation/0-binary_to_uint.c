#include "main.h"

/**
 * binary_to_uint - write your short description
 * @b: string pointer to the binary
 *
 * Return: 0 as exit status
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;

	if (!b)
		return (0);
	for (; b[i]; i++)
	{
		if (!_is_digit(b[i]))
			return (0);
	}

	return (convert(b, i));
}

/**
 * convert - convert binary to unsigned int recursively
 * @b: string pointer to the binary
 * @len: length of the string
 *
 * Return: decimal for the biany
 */
unsigned int convert(const char *b, int len)
{
	if (!*b)
		return (0);
	if (*b == '0')
		return (convert(b + 1, len - 1));

	return ((1 << (len - 1)) + convert(b + 1, len - 1));
}


/**
 * _is_digit - check if ascii is digit.
 * @n: ascii to check
 *
 * Return: 1 if it's digit,
 * 0 otherwise.
 */
int _is_digit(char n)
{
	return (n >= '0' && n <= '9');
}

