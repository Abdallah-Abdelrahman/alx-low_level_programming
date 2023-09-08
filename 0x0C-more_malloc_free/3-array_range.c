#include "main.h"

/**
 * array_range - creates an array of integers.
 * @min: min number
 * @max: max number
 *
 * Return: pointer to the newly created array,
 * NULL if min > max, or `malloc` fails
 */
int *array_range(int min, int max)
{
	int *ptr;
	size_t i, size;

	if (min > max)
		return (0);
	size = max - min + 1;
	ptr = malloc(sizeof(*ptr) * size);
	if (!ptr)
		return (0);
	for (i = 0; i < size; i++)
		ptr[i] = min + i;

	return (ptr);
}
