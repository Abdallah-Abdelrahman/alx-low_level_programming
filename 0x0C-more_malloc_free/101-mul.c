#include "main.h"
#include <stdlib.h>

/**
 * mul - multiplies two positive numbers.
 * @ac: number of arguments
 * @av: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	int i = 0, ac1 = 0, ac2 = 0, zero = 48, old_s = 1, new_s = 2,
	idx, j, product, carry;
	char *ptr = 0, *acc = 0;

	if (ac != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (; av[1][ac1] || av[2][ac2]; )
	{
		if (av[1][ac1])
		{
			if (!_isdigit(av[1][ac1]))
			{
				printf("Error\n");
				exit(98);
			}
			ac1++;
		}
		if (av[2][ac2])
		{
			if (!_isdigit(av[2][ac2]))
			{
				printf("Error\n");
				exit(98);
			}
			ac2++;
		}
	}

	/* multiplicaiton happens here */
	for (i = 0; av[1][ac1 - 1]; i++, ac1--, carry = 0)
	{
		if (i > 0)
		{
			ptr = malloc(i);
			if (!ptr)
				return (1);
			for (idx = 0; idx < i; idx++)
				ptr[idx] = zero;
			old_s += idx;
			new_s = old_s + 1;
		}

		for (j = ac2 - 1; av[2][j]; idx++, j--)
		{
			product = ((av[1][ac1 - 1] - zero) *
					(av[2][j] - zero)) + carry;
			ptr = _realloc(ptr, old_s++, new_s++);
			if (!ptr)
				return (1);
			ptr[idx] = (product % 10) + zero;
			carry = product / 10;
		}
		ptr[idx] = 0;

		if (carry)
		{
			ptr = _realloc(ptr, old_s, new_s);
			if (!ptr)
				return (1);
			ptr[idx] = carry + zero;
			ptr[idx + 1] = 0;
		}
		rev_string(ptr, carry ? idx + 1 : idx);
		if (i > 0)
			acc = infinite_add(acc, ptr);
		else
			acc = ptr;
		old_s = 1, new_s = 2, ptr = NULL;
	}

	printf("%s\n", acc);
	if (acc)
		free(acc);

	return (0);
}

/**
 * infinite_add - adds 2 numbers
 * @acc: number to accumulate
 * @num: number to add to @acc
 * @acc_s: @acc size
 * @num_s: @num size
 *
 * Return: pointer to the result
 */
char *infinite_add(char *acc, char *num)
{
	int carry = 0, idx = 0, sum = 0, zero = 48,
	acc_len = 0, num_len = 0, largest;
	char *new_acc = 0, *tmp = 0;

	for (; acc[acc_len] || num[num_len];)
	{
		if (acc[acc_len])
			acc_len++;
		if (num[num_len])
			num_len++;
	}
	largest = acc_len > num_len ? acc_len : num_len;

	new_acc = malloc(largest + 1);

	for (; idx < largest; acc_len--, num_len--, idx++)
	{
		char acc_digit = acc_len - 1 >= 0 ? acc[acc_len - 1] : zero;
		char num_digit = num_len - 1 >= 0 ? num[num_len - 1] : zero;

		if (acc_len - 1 < 0 && num_len - 1 < 0)
			break;
		sum = (acc_digit - zero) + (num_digit - zero) + carry;
		new_acc[idx] = (sum % 10) + zero;
		carry = sum / 10;
	}
	new_acc[idx] = 0;
	if (carry)
	{
		acc[idx] = carry + zero;
		acc[idx + 1] = 0;
		tmp = _realloc(acc, largest + 1, largest + 2);
		if (!tmp)
		{
			free(new_acc);
			return (0);
		}
		tmp[idx + 1] = 0;
		new_acc = tmp;
	}

	rev_string(new_acc, carry ? idx + 1 : idx);
	free(acc);
	free(num);
	return (new_acc);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for `ptr`
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the newly allocated memory,
 * or `NULL`
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (0);
	}
	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (malloc(new_size));

	return (adjust_book((char *)ptr, old_size, new_size));
}

/**
 * adjust_book - adjust the book-keeping
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for `ptr`
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer
 */
void *adjust_book(char *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min = old_size;
	char *new_ptr;

	if (new_size < old_size)
	{
		min = new_size;
	}
	new_ptr = malloc(new_size);

	if (!new_ptr)
		return (0);

	for (i = 0; i < min; i++)
		new_ptr[i] = ptr[i];

	free(ptr);

	return (new_ptr);
}


/**
 * rev_string - reverse a string
 * @str: string pointer
 * @len: length of str
 *
 */
void rev_string(char *str, int len)
{
	int i = 0;

	while (len > i)
	{
		char tmp = str[i];

		str[i] = str[len - 1];
		str[len - 1] = tmp;

		i++;
		len--;
	}
}

/**
 * _isdigit - check if a parameter is number
 * @n: number to check
 *
 * Return: 1 on success, 0 on failure
 */
int _isdigit(char n)
{
	return (n >= '0' && n <= '9');
}
