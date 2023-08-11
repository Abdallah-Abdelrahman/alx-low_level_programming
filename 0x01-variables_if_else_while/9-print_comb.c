#include <stdio.h>

/**
* main - prints all possible combinations of single-digit numbers
*
* Return: 0 as exit status
*/
int main(void)
{
	int count = 47;
	int comma = 44;
	int space = 32;

	while (++count < 58)
	{
		putchar(count);
		if (count == 57)
			break;
		putchar(comma);
		putchar(space)
	}
	putchar(10);

	return (0);
}
