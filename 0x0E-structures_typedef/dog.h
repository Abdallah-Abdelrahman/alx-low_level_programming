#ifndef HEADER
#define HEADER
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
void init_dog(struct dog *d, char *name, float age, char *owner);
#endif /* HEADER */

