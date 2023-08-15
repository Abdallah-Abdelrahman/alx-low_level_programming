#include "main.h"
/**
* times_table -prints the 9 times table, starting with 0.
*/
void times_table(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i * j < 10)
			{
				_putchar((i * j) + '0');
				_putchar((i * j) + '0');
			}

			else if (i * j > 10)
			{
				_putchar((i * j / 10) + '0');
				_putchar((i * j % 10) + '0');
			}

			if (j < 9)
			{
				_putchar(',');
				_putchar(' ');
			}


		}
		_putchar('\n');
	}

	_putchar('\n');
}
