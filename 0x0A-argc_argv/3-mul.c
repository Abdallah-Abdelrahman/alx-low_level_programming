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
	int i = 1, multi = 1, negative = 1;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	while (argc--)
	{
		if (argv[i])
		{
			for (; *argv[i]; argv[i]++)
			{
				if (*argv[i] == '-')
				{
					negative *= -1;
					continue;
				}
				multi *= (*argv[i] - 48);
			}
		}
		i++;
	}
	printf("%d\n", multi * negative);
	return (0);
}
