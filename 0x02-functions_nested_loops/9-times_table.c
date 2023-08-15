#include "main.h"
/**
* times_table -prints the 9 times table, starting with 0.
*/
void times_table(void)
{
	int i = 0, j;

	for (; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i * j < 10)
			{
				(j > 0) && _putchar('\t');
				_putchar((i * j) + '0');
			}

			else if (i * j > 9)
			{
				_putchar((i * j / 10) + '0');
				_putchar((i * j % 10) + '0');
			}

			if (j < 9)
			{
				_putchar(',');
			}



		}

		j = 0;

		_putchar('\n');
	}

	_putchar('\n');
}
