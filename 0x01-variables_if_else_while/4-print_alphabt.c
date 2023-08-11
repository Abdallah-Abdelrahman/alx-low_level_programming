#include <stdio.h>

/**
* main - print alphabets except q & e
*
* Return: 0 as exit status
*/
int main(void)
{
	int count = 96;

	while (++count < 123)
	{
		if (count == 101 || count == 113)
			continue;
		putchar(count);
	}
	putchar(10);

	return (0);
}
