#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 *
 * Return: 0 always
 */

int main(void)
{

	int num = 0;

	srand(time(NULL));

	while (num != 2772)
	{
		num = rand() / 10000;
	}

	printf("%s", "2772");

	return (0);
}
