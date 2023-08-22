#include <stdlib.h>
#include <stdio.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 * @argc: number of arguments
 * @argv: string pointer
 *
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	int j, r, nloops;
	unsigned int seed;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <seed> <nloops>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	seed = atoi(argv[1]);
	nloops = atoi(argv[2]);

	srand(seed);
	for (j = 0; j < nloops; j++)
	{
		r =  rand();
		printf("%d\n", r);
	}

	return (0);
}
