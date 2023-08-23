#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

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

	while ((num / 10) > 10)
	{
		putchar((num % 10) + '0');
		num /= 10;
	}
	putchar((num % 10) + '0');
	putchar((num / 10) + '0');


	return (0);
}
