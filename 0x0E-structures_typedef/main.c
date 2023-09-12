#include <stdio.h>
#include "dog.h"

/**
 * main - write your short description
 * Description: Long desc
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	struct dog my_dog;
	(void)ac;
	(void)av;


	my_dog.name = "Poppy";
	my_dog.age = 3.5;
	my_dog.owner = "Bob";
	print_dog(&my_dog);
	return (0);
}
