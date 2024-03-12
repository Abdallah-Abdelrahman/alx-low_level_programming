#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers.
 * Description: using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located,
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	int m, R, L;

	if (!array || size == 0)
		return (-1);

	/* `m` represents the block to jump */
	m = sqrt(size);

	/* find block where value is present */
	for (L = 0, R = m; array[R] < value && R < size; L = R, R += m)
	{
		printf("Value checked array[%d] = [%d]\n", L, array[L]);
		if (array[L] == value)
			return (L);
	}
	printf("Value checked array[%d] = [%d]\n", L, array[L]);
	printf("Value found between indexes [%d] and [%d]\n", L, R);

	/* linear search */
	for (; array[L] <= value && L < MIN(size, R + 1); L++)
	{
		printf("Value checked array[%d] = [%d]\n", L, array[L]);
		if (array[L] == value)
			return (L);
	}
	return (-1);
}
