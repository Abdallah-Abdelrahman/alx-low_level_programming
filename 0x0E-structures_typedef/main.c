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
	
	dog_t *my_dog;

	(void)ac;
	(void)av;



	my_dog = new_dog("Poppy", 3.5, "Bob");
	printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
	return (0);
}
