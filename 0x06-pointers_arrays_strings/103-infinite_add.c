#include "main.h"
#include <stdlib.h>

/**
 * infinite_add - adds 2 numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store the result
 * @size_r: buffer size
 *
 * Return: pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, carry = 0, len_n1 = 0, len_n2 = 0;

	for (; n1[len_n1]; len_n1++)
		;
	for (; n2[len_n2]; len_n2++)
		;
	if (len_n1 >= size_r || len_n2 >= size_r)
		return (0);

	for (; len_n1 - 1 > 0 || len_n2 - 1 > 0; len_n1--, len_n2--, i++)
	{
		r[i] = (n1[len_n1 - 1] + n2[len_n2 - 1] + carry) - 48 > 9
			? (((len_n1 - 1 > 0 ? n1[len_n1 - 1] : 48) +
						(len_n2 - 1 > 0 ?
						 n2[len_n2 - 1] : 48)
						+ carry) - 48) % 10
			: (n1[len_n1 - 1] + n2[len_n2 - 1] + carry) - 48;
		carry = (((len_n1 - 1 > 0 ? n1[len_n1 - 1] : 48)) +
				((len_n2 - 1 > 0 ?
				  n2[len_n2 - 1] : 48)) - 48) / 10;

	}

	if (i >= size_r)
		return (0);
	return (r);
}
