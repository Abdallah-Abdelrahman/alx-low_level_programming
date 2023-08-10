#include <unistd.h>

/**
  * main - Print string not listed in man (3) nor printf (3)
  * Return: 1 as exit status
  */
int main(void)
{

	write(1, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);

	return (1);
}
