#include "function_pointers.h"

/**
 * main - prints opcodes
 * @ac: arguments count
 * @av: array of pointers to string
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	int num = atoi(av[1]);
	int (*func)(int, char **) = main;

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (num < 0)
	{
		printf("Error\n");
		exit(2);
	}
	return (0);
}
