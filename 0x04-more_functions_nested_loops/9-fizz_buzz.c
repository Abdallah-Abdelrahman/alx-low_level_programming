#include <stdio.h>

/**
* main - prints the numbers from 1 to 100
* Description: for multiples of three print Fizz instead of the number,
* and for the multiples of five print Buzz.
* For numbers which are multiples of both three and five print FizzBuzz.
*
* Return: 0 as exit status
*/
int main(void)
{
	int n = 1;

	while (n < 101)
	{
		if (n % 3 == 0 && n % 5 == 0)
			printf("FizzBuzz");

		else if (n % 3 == 0)
			printf("Fizz");

		else if (n % 5 == 0)
			printf("Buzz");

		else if (n % 3 != 0 || n % 5 != 0)
			printf("%d", n);

		if (n != 100)
			printf(" ");

		/* book keeping */
		n++;

	}
	printf("\n");

	return (0);
}
