#include "search_algos.h"
#define PROBE(low, high, a)\
	(low + (((double)(high - low) / (a[high] - a[low])) * (value - a[low])))


/**
 * interpolation_search - searches for a value in a sorted array of integers.
 * Description: using the Interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located,
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	int lo, hi, pos;

	if (!array || size == 0)
		return (-1);

	lo = 0, hi = size - 1;

	while (lo <= hi && value >= array[lo] && value <= array[hi])
	{
		if (lo == hi)
		{
			printf("Value checked array[%d] = [%d]\n", lo, array[lo]);
			return (array[lo] == value ? lo : -1);
		}

		/* determine the probe position */
		pos = PROBE(lo, hi, array);

		if (array[pos] == value)
		{
			printf("Value checked array[%d] = [%d]\n", pos, array[pos]);
			return (pos);
		}
		if (array[pos] > value)
		{
			hi = pos - 1;
		}
		else
			lo = pos + 1;
	}

	printf("Value checked array[%d] is out of range\n", (int)POS(lo, hi, array));
	return (-1);
}
