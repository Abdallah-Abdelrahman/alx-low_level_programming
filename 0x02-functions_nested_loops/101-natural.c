#include "main.h"

/**
* main - write your short description
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{
	int i = 3, sum = 0, f1st, s2nd, t3rd, f4;

	while (i < 1024)
	{
		if (i / 3 == 0 || i / 5 == 0)
		{
			sum += i;
		}

		i++;

	}
	f1st = sum % 10;
	s2nd = (sum / 10 / 10) % 10;
	t3rd = (sum / 10 / 10 / 10) % 10;
	f4th = (sum / 10 / 10) / 10;

	print_precision(sum);
	_putchar('\n');

	return (0);
}
