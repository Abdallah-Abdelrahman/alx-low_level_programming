#include "dog.h"

/**
 * print_dog - write your short description
 * @d: struct pointer
 *
 */
void print_dog(struct dog *d)
{
	if (!d)
		return;
	printf("Name: %s\nAge: %f\n,Owner: %s\n",
			d->name ? d->name : "(nil)",
			d->age, d->owner ? d->owner : "(nil)");
}
