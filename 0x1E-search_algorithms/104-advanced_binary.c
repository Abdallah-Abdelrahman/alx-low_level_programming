#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * Description: using the Binary search algorithm(left-most)
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is located.
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t start, end;

	if (!array || size == 0)
		return (-1);

	start = 0;
	end = size - 1;

	return (leftmost_binary(array, start, end, value));
}

/**
 * leftmost_binary - searches for a value in a sorted array of integers.
 * Description: using the Binary search algorithm(left-most)
 * @a: pointer to the first element in the array
 * @lo: index of smallest element in sub-array
 * @hi: index of biggest element in sub-array
 * @value: value to search for
 *
 * Return: index where value is located.
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int leftmost_binary(int *a, size_t lo, size_t hi, int value)
{
	size_t mid;

	if (lo > hi)
		return (-1);

	PRINT(a, lo, hi);

	mid = lo + (hi - lo) / 2;

	if (a[mid] == value)
		return (mid && a[mid - 1] == value
				? leftmost_binary(a, lo, mid, value)
				: (int)mid);
	if (a[mid] > value)
		return (leftmost_binary(a, lo, mid, value));
	return (leftmost_binary(a, mid + 1, hi, value));
}
