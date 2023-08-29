#include "main.h"

/**
 * print_diagsums - prints the sum of the 2 diagonals,
 * of a square matrix of integers.
 * @a: pointer to square array
 * @size: size of array
 * arr[i][j] = Base Address + (i * y + j) * size
 */
void print_diagsums(int *a, int size)
{
	int i = 0, j = 0;
	unsigned int sum1 = 0, sum2 = 0;

	for (; i < size; i++)
		sum1 += *(a + (i * size) + i);
	for (; i > 0; i--, j++)
		sum2 += *(a + (size * (i - 1)) + j);
	printf("%d, %d\n", sum1, sum2);
}
