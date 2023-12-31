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
	int num;
	int i;
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
	for (i = 0; av[1][i]; i++)
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			printf("Error\n");
			exit(2);
		}
	num = atoi(av[1]);
	for (i = 0; i < num; i++)
	{
		if (i)
			printf(" ");
		printf("%02x", *(((unsigned char *)func) + i));
	}
	printf("\n");

	return (0);
}
