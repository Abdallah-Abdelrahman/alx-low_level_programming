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
	int carry = 0, len_n1 = 0, len_n2 = 0,
	    idx = 0, sum = 0, largest = 0, arr[2] = {0, 0},
	    *lens = len2str(n1, n2, arr);
	len_n1 = lens[0], len_n2 = lens[1], largest = len_n1;

	if (len_n2 > len_n1)
		largest = len_n2;
	if (largest + 1 > size_r)
		return (0);
	for (; idx < largest; len_n1--, len_n2--, idx++)
	{
		char valid_n1 = len_n1 - 1 >= 0 ? n1[len_n1 - 1] : '0';
		char valid_n2 = len_n2 - 1 >= 0 ? n2[len_n2 - 1] : '0';

		if (len_n1 - 1 < 0 && len_n2 - 1 < 0)
			break;
		sum = (valid_n1 - '0') + (valid_n2 - '0') + carry;
		r[idx] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry > 0 && largest + 2 > size_r)
		return (0);
	if (carry > 0)
		r[largest] = carry + '0';
	rev_string(r, carry > 0 ? idx + 1 : idx);
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

/**
 * len2str - calculate the lenght of 2 strings
 * @p1: 1st string
 * @p2: 2nd string
 * @arr: array of 2 elems represenet the initial
 * size of each
 *
 * Return: pointer to array of 2 integer
 */
int *len2str(char *p1, char *p2, int arr[])
{
	for (; p1[arr[0]] || p2[arr[1]]; )
	{
		if (p1[arr[0]])
			arr[0]++;
		if (p2[arr[1]])
			arr[1]++;
	}

	return (arr);
}
