#include <stdio.h>

/**
* main -prints the first 98 Fibonacci numbers
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{
	int n1 = 1, n2 = 2, next = n1 + n2;

	while (i <= 98)
	{
		printf("%d, %d, %d", n1, n2, next);

		n1 = n2;
		n2 = next;
		next = n1 + n2;
		i++;
	}

	printf("\n");

	return (0);
}
