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
	int sum = 0, n1 = 0, n2 = 1, next = n1 + n2;

	while (next <= 4000000)
	{
		if (next % 2 == 0)
			sum += next;

		n1 = n2;
		n2 = next;
		next = n1 + n2;
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
