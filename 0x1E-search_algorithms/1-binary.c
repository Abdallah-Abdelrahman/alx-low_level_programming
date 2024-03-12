#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers.
 * Description: using the Binary search algorithm
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is located.
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid, start, end;

	if (!array || size == 0)
		return (-1);

	start = 0;
	end = size - 1;

	PRINT(array, start, end);
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
