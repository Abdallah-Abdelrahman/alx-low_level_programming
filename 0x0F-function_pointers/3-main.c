#include "3-calc.h"

/**
 * main - selects the correct function,
 * to perform the operation asked by the user.
 * @ac: arguments count
 * @av: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (av[2][1] || !get_op_func(av[2]))
	{
		printf("Error\n");
		exit(99);

	}
	if (atoi(av[3]) == 0 && (av[2][0] == '/' || av[2][0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_op_func(av[2])(atoi(av[1]), atoi(av[3])));

	return (0);
}

#if 0
/**
 * print_chars - prints long integer number recursively
 * @n: number
 */
void print_chars(int n)
{
	if (n > 9)
		print_chars(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_error - prints Error
 * @str: Error string
 */
void print_error(char *str)
{
	int i;

	for (; str[i]; i++)
		_putchar(str[i]);
}
#endif
