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
