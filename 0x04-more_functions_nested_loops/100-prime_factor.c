#include "main.h"
#include <stdio.h>
#include <unistd.h>



/**
* main - write your short description
* Description: Long desc
*
* Return: 0 as exit status
*/
int main(void)
{

	long i, largest_factor, number = 612852475143;

	while (number % 2 == 0)
	{
		largest_factor = 2;
		number /= 2;
	}

	for (i = 3; i * i <= number; i += 2)
	{
		while (number % i == 0)
		{
			largest_factor = i;
			number /= i;
		}
	}

	if (number > 2)
	{
		largest_factor = number;
	}
	print_chars(largest_factor);
	_putchar('\n');

	return (0);
}

/**
  * print_chars - print interger based on precision
  * @n: number to print to print it precisions.
  */
void print_chars(unsigned int n)
{
	if (n < 10)
	{
		_putchar(n % 10 + '0');
	}

	else if ((n / 10) < 10)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		print_chars(n / 10);
		_putchar((n % 10) + '0');
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
