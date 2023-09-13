#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @array: array of int
 * @size: size of @array
 * @cmp: pointer to a func
 *
 * Return: 1 if there's a match,
 * -1 otherwise
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int idx, res = -1;

	if (size <= 0)
		return (-1);
	for (idx = 0; idx < size; idx++)
	{
		if (array && cmp)
			res = cmp(array[idx]);
		if (res)
			break;
	}

	return (res);
}
