#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers.
 * Description: using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located,
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, start, end, mid;

	if (!array || size == 0)
		return (-1);
	if (array[0] == value)
		return (i);

	start = 0;
	end = size - 1;
	for (i = 1; i < size && array[i] <= value; i *= 2)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			i / 2, MIN(i, size - 1));
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (array[mid] < value)
		{
			start = mid + 1;
			PRINT(array, start, end);
		}
		else if (array[mid] > value)
		{
			end = mid - 1;
			PRINT(array, start, end);
		}
		else
			return (mid);
	}

	return (-1);
}
