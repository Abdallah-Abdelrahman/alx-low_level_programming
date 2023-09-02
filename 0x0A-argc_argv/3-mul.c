#include "main.h"

/**
 * main - prints the multipliation of argv
 * @argc: number of args
 * @argv: array of pointers to string
 *
 * Return: 1 if doesn't recieve 2 argv, 0 otherwise
 */
int main(int argc, char **argv)
{
	int i = 1, num1 = 0, num2 = 0, argc1 = 0, argc2 = 0, product = 1;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	for (; argv[i][argc1] || argv[i + 1][argc2]; )
	{
		if (argv[i][argc1])
			argc1++;
		if (argv[i + 1][argc2])
			argc2++;
	}

	num1 = stoi(argv[1], argc1);
	num2 = stoi(argv[2], argc2);
	product = num1 * num2;
	printf("%d\n", product);
	return (0);
}
/**
 * stoi - convert string to integer
 * @ptr: string pointer
 * @size: size of the string
 *
 * Return: integer represenaion of the string
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
