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
	size_t m, R, L;

	if (!array)
		return (-1);

	/* `m` represents the block to jump */
	m = sqrt(size);

	/* find block where value is present */
	for (L = 0, R = m; size > L && array[L] < value; L = R, R += m)
		printf("Value checked array[%ld] = [%d]\n", L, array[L]);

	printf("Value found between indexes [%ld] and [%ld]\n",
			L ? L - m : L, L ? R - m : R);

	/* linear search */
	for (L = L ? L - m : L; MIN(size, R + 1) > L; L++)
	{
		printf("Value checked array[%ld] = [%d]\n", L, array[L]);
		if (array[L] == value)
			return (L);
	}
	return (-1);
}
