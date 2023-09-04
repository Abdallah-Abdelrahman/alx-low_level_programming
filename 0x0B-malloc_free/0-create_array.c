#include "main.h"

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @size: size of the array
 * @c: character
 *
 * Return: `NULL` if size is `0` or it fails, pointer otherwise
 */
char *create_array(unsigned int size, char c)
{
	int i = 0;
	char *ptr;

	if (size < 1)
		return (0);

	ptr = malloc(sizeof(char) * size);

	if (!ptr)
		return (0);
	for (; i < size; i++)
		ptr[i] = c;

	return (ptr);
}
