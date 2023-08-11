#include <stdio.h>

/**
* main - Print alphabets in reverse
*
* Return: 0 as exit status
*/
int main(void)
{
	int count = 123;

	while (--count > 96)
		putchar(count);
	putchar(10);
	return (0);
}
