#include <stdio.h>
#include <stdlib.h>

/**
* main -prints the first 98 Fibonacci numbers
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 0, n1 = 0, n2 = 1, next = n1 + n2;

	while (i < 98)
	{
		printf("%d", abs(next));

		if (i != 97)
			printf(", ");

		n1 = n2;
		n2 = next;
		next = n1 + n2;
		i++;
	}

	printf("\n");

	return (0);
}
