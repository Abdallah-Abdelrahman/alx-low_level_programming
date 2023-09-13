#include "main.h"

/**
 * mul - multiplies two positive numbers.
 * @ac: number of arguments
 * @av: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	int i = 0, ac1 = 0, ac2 = 0, zero = 48, old_s = 0, new_s = 1,
	idx, j, k, product, carry;
	char *ptr = NULL, *acc = NULL;

	if (ac != 3)
	{
		printf("Error\n");
		exit(98);
	}

	/* TODO: check for any non-digit character */
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
			ptr = _malloc(sizeof(char) * i);
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


		if (i > 0)
		{

			rev_string(ptr, carry ? idx + 1 : idx);
			k = infinite_add(acc, ptr, k, carry ? idx + 1 : idx);
			/*rev_string(acc, k);*/
		}
		else
		{
			acc = _malloc(carry ? new_s : old_s);
			for (k = 0; ptr[k]; k++)
				acc[k] = ptr[k];
			acc[k] = 0;
			rev_string(acc, k);

		}
		old_s = 0, new_s = 1, ptr = NULL;
	}
	printf("%s\n", acc);


	/* clean-up ur shit */
	free(acc);

	return (0);
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
		return (_malloc(new_size));

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
	size_t i, min = old_size, max = new_size;
	char *new_ptr;

	if (new_size < old_size)
	{
		min = new_size;
		max = old_size;
	}
	new_ptr = malloc(max);

	if (!new_ptr)
		return (0);

	for (i = 0; i < min; i++)
		new_ptr[i] = ptr[i];

	free(ptr);

	return (new_ptr);
}

/**
 * _malloc - allocates memory using malloc.
 * @b: bytes to allocates
 *
 * Return: a pointer of void
 */
void *_malloc(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (!ptr)
		return (0);
	return (ptr);
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
int infinite_add(char *acc, char *num, int acc_s, int num_s)
{
	int carry = 0, idx = 0, sum = 0, zero = 48, largest = acc_s;

	printf("Before sum:\nacc = %s, num = %s\n", acc, num);

	if (num_s > acc_s)
	{
		largest = num_s;
		/*acc = _realloc(acc, acc_s, largest + 1); why it works w/out allocation ??? -_0 */
	}

	for (; idx < largest; acc_s--, num_s--, idx++)
	{
		char acc_digit = acc_s - 1 >= 0 ? acc[acc_s - 1] : zero;
		char num_digit = num_s - 1 >= 0 ? num[num_s - 1] : zero;

		if (acc_s - 1 < 0 && num_s - 1 < 0)
			break;
		sum = (acc_digit - zero) + (num_digit - zero) + carry;
		acc[largest - (idx + 1)] = (sum % 10) + zero;
		carry = sum / 10;
	}
	acc[idx] = 0;
	if (carry)
	{
		rev_string(acc, idx);
		/*acc = _realloc(acc, largest + 1, largest + 2);*/
		acc[idx] = carry + zero;
		acc[idx + 1] = 0;
		rev_string(acc, idx + 1);

	}


	return (carry ? idx + 1 : idx);
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
