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
	int long long sum = fibonacci(4000000);

	printf("%lld", sum);

	return (0);
}

/**
  * fibonacci - sums up the previous to numbers in a sequence
  * @n: the number to start the seuquence from
  *
  * Return: the sum of the sequence.
  */
long long int fibonacci(long long int n)
{
	if ((n % 2 == 0) && n < 4000000)
	{
		if (n > 2)
			return (fibonacci(n - 1) + fibonacci(n - 2));
		else
			return (n);
	}
}
