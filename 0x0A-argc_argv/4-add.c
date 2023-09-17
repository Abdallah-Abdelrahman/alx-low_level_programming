#include "main.h"

/**
 * main - adds positive numbers
 * @argc: number of args
 * @argv: array of pointers to string
 *
 * Return: `1` if argv[1] onward contains non-digits, `0` otherwise
 */
int main(int argc, char **argv)
{
	int i = 1, sum = 0, err;

	if (argc < 2)
	{
		printf("%d\n", sum);
		return (0);
	}
	while (argv[i])
	{
		err = has_ndigit(argv[i], 0);
		if (err)
			break;
		i++;
	}
	if (err)
	{
		printf("Error\n");
		return (1);
	}

	/* best-case scenario - all the arguments contian digits - */
	sum = add_recursive(argv, 1, argc - 1);

	printf("%d\n", sum);

	return (0);
}

/**
 * add_recursive - add numbers recursively
 * @ptr: array of pointers to string
 * @idx: pointer position (index) in ptr
 * @size: length of the array
 *
 * Return: the sum of arguments
 *
 */
int add_recursive(char **ptr, int idx, int size)
{
	int len = 0;

	for (; ptr[idx][len]; len++)
		;

	/* it's the last character in the string */
	if (size - 1 == 0)
		return (stoi(ptr[idx], len));

	return (stoi(ptr[idx], len) + add_recursive(ptr, idx + 1, size - 1));

}

/**
 * stoi - convert string to integer
 * @ptr: string pointer
 * @size: size of the string
 *
 * Return: integer representaion of the string
 */
int stoi(char *ptr, int size)
{
	int i = 0, num = 0, negative = 1;

	for (; ptr[i]; i++)
	{
		if (ptr[i] == '-')
		{
			negative *= -1;
			continue;
		}
		if (i != size - 1)
			num += (ptr[i] - 48) * _pow_recursion(10, size - (i + 1));
		else
			num += (ptr[i] - 48);

	}

	return (num * negative);
}

/**
 * _pow_recursion - calculate the power of x^y
 * @x: the base
 * @y: the power
 *
 * Return: x^y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}

/**
 * has_ndigit - check if string contains non-digit character
 * @ptr: string pointer
 * @idx: character position
 *
 * Return: 1 if it falls into the tested class, 0 otherwise
 */
int has_ndigit(char *ptr, int idx)
{

	if (ptr[idx])
	{
		if (ptr[idx] >= '0' && ptr[idx] <= '9')
			return (has_ndigit(ptr, idx + 1));
		else
			return (1);
	}

	return (0);
}
