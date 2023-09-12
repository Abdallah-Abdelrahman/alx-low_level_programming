#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - write your short description
 * @name: name
 * @age: age
 * @owner: owner
 *
 * Return: pointer to struct of type dog_t,
 * Null on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int i = 0, j = 0;
	dog_t *dog = malloc(sizeof(*dog));

	if (!dog)
		return (0);

	dog->age = age;
	for (; name[i] || owner[j];)
	{
		if (name[i])
			i++;
		if (owner[j])
			j++;
	}
	dog->name = malloc(sizeof(char) * (i + 1));
	if (!dog->name)
		return (0);
	dog->owner = malloc(sizeof(char) * (j + 1));
	if (!dog->owner)
	{
		free(dog->name);
		return (0);
	}
	for (i = 0; name[i]; i++)
		dog->name[i] = name[i];
	dog->name[i] = 0;
	for (i = 0; owner[i]; i++)
		dog->owner[i] = owner[i];
	dog->owner[i] = 0;

	return (dog);
}
