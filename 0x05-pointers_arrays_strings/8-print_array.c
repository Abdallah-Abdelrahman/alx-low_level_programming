#include "main.h"

/**
 * print_array - prints n elements of an array of integers
 * @a: point to array of integer
 * @n: number of elements in the array
 *
 */
void print_array(int *a, int n)
{
	int i = 0;

	for (; i < n; i++)
	{
		printf("%d", *(a + i));
		if (i != 4)
			printf(", ");
	}
	printf("\n");
}
