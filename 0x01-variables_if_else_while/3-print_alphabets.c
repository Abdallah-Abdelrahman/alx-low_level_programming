#include <stdio.h>

/**
  * main - print alphabets in lower & upper case
  *
  * Return: 0 as exit status
  */
int main(void)
{
	int lcount = 96, ucount = 64;

	while (++lcount < 123)
		putchar(lcount);
	while (++ucount < 91)
		putchar(ucount);
	putchar(10);

	return (0);
}
