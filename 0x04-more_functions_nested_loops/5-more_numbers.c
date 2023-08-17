#include <stdio.h>
#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 */
void more_numbers(void)
{
	int i = 0, j = 0;

	for (; i < 10; i++)
	{
		for (; j < 15; j++)
		{
			if (j < 10)
				_putchar(j + '0');
			else
			{
				_putchar((j / 10) + '0');
				_putchar((j % 10) + '0');
			}
		}
		putchar('\n');

		/* book keeping */
		j = 0;
	}
}
