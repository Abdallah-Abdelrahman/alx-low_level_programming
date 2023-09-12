#include "dog.h"

/**
 * init_dog - write your short description
 * @dog: struct
 * @name: member of dog
 * @age: member of dog
 * @owner: member of dog
 *
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;

}
