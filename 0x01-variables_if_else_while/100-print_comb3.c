#include <stdio.h>

/**
* main - print all possible different combinations of 2 digits
*
* Return: 0 as exit status
*/
int main(void)
{
	int comma = 44;
	int space = 32;
	int end = 58, i = 0, j, k;

	while (i < 45)
	{
		for (j = 48; j < end - 1; j++)
		{
			for (k = j + 1; k < end; k++)
			{
				i++;
				putchar(j);
				putchar(k);
				if (i == 45)
					break;
				putchar(comma);
				putchar(space);
			}
		}
	}

	return (0);
}
