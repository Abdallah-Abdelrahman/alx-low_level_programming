#include "main.h"
/**
  * print_alphabet_x10 - Print alphabets in lowercase 10 times
  */
void print_alphabet_x10(void)
{
	int c = 'a', i = 0;

	for (; i < 10; i++)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}

	_putchar('\n');
	c = 'a';

	}
}
