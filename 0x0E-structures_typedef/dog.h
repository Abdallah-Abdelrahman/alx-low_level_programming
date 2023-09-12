#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <stdio.h>
/**
 * struct dog - define type dog
 * @name: name of the dog
 * @age: the age
 * @owner: owned by whom
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif /* HEADER */

