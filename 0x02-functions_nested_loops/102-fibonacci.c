#include <stdio.h>
#include "main.h"

/**
* main -prints the first 50 Fibonacci numbers
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 1;

	while (i < 50)
	{
		if (i <= 2)
		{
			printf("%d", i);
		}

		if (i > 2)
			printf("%d", (i - 1) * (i - 2));

		if (i != 49)
		{
			printf(", ");
		}

		i++;
	}

	printf("\n");

	return (0);
}
