#include <unistd.h>

/**
  * main - Print string not listed in man (3) nor printf (3)
  * Return: 1 as exit status
  */
int main(void)
{
	char str[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19";

	write(1, str, 59);
	return (1);
}

