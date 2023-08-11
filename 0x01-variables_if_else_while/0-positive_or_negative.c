#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
  * main - this where your app gets bootsrtaped
  *
  * Description: the function check whether a random,
  * number is either positve or negative
  * Return: return 0 as exit status
  */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n == 0)
		printf("%d is zero\n", n);
	else if (n > 0)
		printf("%d is positive\n", n);
	else
		printf("%d is negative\n", n);


	return (0);
}
