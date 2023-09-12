#include "dog.h"

/**
 * free_dog - write your short description
 * @d: struct pointer
 *
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
