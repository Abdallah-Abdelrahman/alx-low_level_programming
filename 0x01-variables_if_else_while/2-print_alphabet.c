#include <stdio.h>

/**
  * main - print alphabet in lowercase
  *
  * Return: 1 as exit status
  */
int main(void)
{
	int count = 96;

	while (++count < 123)
		putchar(count);
	putchar(10);

	return (0);
}
