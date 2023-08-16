#include <stdio.h>
#include "main.h"

/**
* main -prints the first 50 Fibonacci numbers
*
* Return: 0 as exit status
*/


int main(void)
{
	unsigned long int i = 0, n1 = 0, n2 = 1;
	unsigned long int next = n1 + n2;

	for (; i < 50; i++)
	{
		printf("%ld", next);

		if (i != 49)
		{
			printf(", ");
		}

		n1 = n2;
		n2 = next;
		next = n1 + n2;


	}


	printf("\n");
	return (0);
}
