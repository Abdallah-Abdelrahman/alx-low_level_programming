#include <stdio.h>

/**
* main - print all numbers of base 16 in lowercase
*
* Return: 0 as exit status
*/
int main(void)
{
	int count10 = 47;
	int countc = 96;

	while (++count10 < 58)
		putchar(count10);
	while (++countc < 103)
		putchar(countc);
	putchar(10);

	return (0);
}
