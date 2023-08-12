#include <stdio.h>

/**
* main -prints all possible different combinations of three digits.
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 0, start = 48, end = 58, comma = 44, space = 32, j, k, l;

	while (i < 120)
	{
		for (j = start; j < end - 1; j++)
		{
			for (l = j + 1; l < end - 1; l++)
			{
				for (k = l + 1; k < end; k++)
				{
					++i;
					putchar(j);
					putchar(l);
					putchar(k);
					if (i == 120)
						break;
					putchar(comma);
					putchar(space);
				}
			}
		}
	}
	putchar(10);
	return (0);
}
