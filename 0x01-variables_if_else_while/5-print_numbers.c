#include <stdio.h>

/**
* main - print all digits base 0-9
*
* Return: 0 as exit status
*/
int main(void)
{
	int count = -1;

	while (++count < 10)
		printf("%d", count);
	printf("\n");

	return (0);
}
