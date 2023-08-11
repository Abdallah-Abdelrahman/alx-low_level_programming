#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
  * main - where your app gets bootstraped
  *
  * Description: it prints the last digit stored in the random number
  * Return: 0 as exit status
  */
int main(void)
{
	int n, last_digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit = n % 10;

	if (last_digit == 0)
		printf("Last digit of %d is %d and is %d\n", n, last_digit, last_digit);
	else if (last_digit < 6)
		printf("Last digit of %d is %d and is less than 6 and not 0\n",
		n, last_digit);
	else
		printf("Last digit of %d is %d and is greater than 5\n", n, last_digit);

	return (0);
}
