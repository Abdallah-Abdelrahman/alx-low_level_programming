#include "main.h"
#include <stdio.h>

/**
* main - write your short description
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 3, sum = 0;

	while (i < 1024)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}

		i++;

	}
	print_precision(sum);
	_putchar('\n');

	return (0);
}
