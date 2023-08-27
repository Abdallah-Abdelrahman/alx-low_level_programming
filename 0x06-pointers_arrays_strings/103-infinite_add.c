#include "main.h"

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
	int carry = 0, len_n1 = 0, len_n2 = 0, len = 0, sum = 0;

	for (; n1[len_n1]; len_n1++)
		;
	for (; n2[len_n2]; len_n2++)
		;

	if (len_n1 + 2 > size_r || len_n2 + 2 > size_r)
		return (0);

	for (; len < size_r; len_n1--, len_n2--, len++)
	{
		int valid_n1 = len_n1 - 1 >= 0 ? n1[len_n1 - 1] : '0';
		int valid_n2 = len_n2 - 1 >= 0 ? n2[len_n2 - 1] : '0';

		if (len_n1 <= 0 && len_n2 <= 0 && carry <= 0)
			break;
		sum = (valid_n1 - '0') + (valid_n2 - '0') + carry;
		r[len] = (sum % 10) + '0';
		carry = sum / 10;
	}
	/* sum of 2 str is greater than buffer */
	if (len >= size_r)
		return (0);
	rev_string(r, len);
	return (r);
}

/**
 * rev_string - reverse a string
 * @str: string pointer
 * @size: size of str
 */
void rev_string(char *str, int size)
{
	int i = 0;

	while (size > i)
	{
		char tmp = *(str + i);
		*(str + i) = *(str + (size - 1));
		*(str + (size - 1)) = tmp;

		i++;
		size--;
	}
}
