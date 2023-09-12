#include "dog.h"

/**
 * init_dog - write your short description
 * @d: struct
 * @name: member of dog
 * @age: member of dog
 * @owner: member of dog
 *
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	int len1, len2;

	if (!d)
		return;
	for (len1 = 0, len2 = 0; name[len1] || owner[len2]; )
	{
		if (name[len1])
			len1++;
		if (owner[len2])
			len2++;
	}
	(*d).age = age;
	(*d).name = malloc(len1 + 1);
	if ((*d).name == NULL)
	{
		free(d);
		exit(98);
	}
	(*d).owner = malloc(len2 + 1);
	if ((*d).owner == NULL)
	{
		free((*d).name);
		free(d);
		exit(98);
	}

	for (len1 = 0; name[len1]; len1++)
	{
		(*d).name[len1] = name[len1];
	}

	(*d).name[len1] = 0;
	for (len2 = 0; owner[len2]; len2++)
	{
		(*d).owner[len2] = owner[len2];
	}
	(*d).owner[len2] = 0;
}
