#include <stdio.h>
#include  "main.h"

/**
* main - write your short description
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{
	int n1 = 0, n2 = 2, sum = n1 + n2;

	while (sum <= 4000000)
	{
		n1 = n2;
		n2 = sum;
		sum = n1 + n2;
	}

	printf("%d\n", sum);

	return (0);
}

/**
  * fibonacci - sums up the previous 2-even values in a sequence
  * @n: the number to start the seuquence from
  *
  * Return: the sum of the sequence.
  */
int fibonacci(int n)
{
	if (n <= 2)
		return (n);
	return (fibonacci(n - 2) + fibonacci(n - 4));
}
