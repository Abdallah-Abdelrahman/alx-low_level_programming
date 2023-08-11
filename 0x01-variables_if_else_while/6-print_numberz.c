#include <stdio.h>

/**
* main - Print all digits 0-9 using putchar
*
* Return: 0 as exit status
*/
int main(void)
{
	int count = 47;

	while (++count < 58)
		putchar(count);
	putchar(10);
	return (0);
}
