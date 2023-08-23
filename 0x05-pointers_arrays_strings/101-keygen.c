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
	char str[20];

	srand(time(NULL));

	while (num != 2772)
	{
		num = rand() / 10000;
	}

	sprintf(str, "%d", num);

	return (0);
}
