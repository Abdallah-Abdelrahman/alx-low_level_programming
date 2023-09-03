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
	int sum = 0;

	/* best-case scenario - all the arguments contian digits - */
	if (argc > 1)
		sum += add_recursive(argv, 1, argc - 1);
	printf("%d\n", sum);

	return (0);
}

/**
 * add_recursive - add numbers recursively
 * @ptr: array of pointers to string
 * @idx: pointer position (index) in ptr
 * @size: number of arguments
 *
 * Return: the sum of arguments
 */
int add_recursive(char **ptr, int idx, int size)
{
	int len = 0;

	printf("ptr = %s\n", ptr[idx]);

	/* TODO: handle the case where the string contains non-digits */
	for (; ptr[idx][len]; len++)
		;
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
 * _isdigit - check if character is a digit
 * @c: character
 *
 * Return: 1 if it's digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}
