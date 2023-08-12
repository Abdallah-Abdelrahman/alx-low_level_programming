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
	int n = 10, i = 0, j, k;

	while (i < 45)
	{
		for (j = i; j < n - 1; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				i++;
				putchar(j);
				putchar(k);
				if (i == 44)
					break;
				putchar(comma);
				putchar(space);
			}
		}
	}

	return (0);
}
