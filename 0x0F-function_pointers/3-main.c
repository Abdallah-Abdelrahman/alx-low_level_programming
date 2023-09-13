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
	char *op = av[2];
	int n1 = atoi(av[1]);
	int n2 = atoi(av[3]);

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (op[1] || !get_op_func(op))
	{
		printf("Error\n");
		exit(99);

	}
	if (n2 == 0 && (op[0] == '/' || op[0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_op_func(op)(n1, n2));

	return (0);
}
