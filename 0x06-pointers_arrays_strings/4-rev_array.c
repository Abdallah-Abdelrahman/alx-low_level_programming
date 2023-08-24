#include "main.h"

/**
 * reverse_array - write your short description
 * @a: pointer to array
 * @n: number of element of array
 *
 */
void reverse_array(int *a, int n)
{
	int i = 0;

	while (i < n)
	{
		int tmp = a[i];

		a[i] = a[n - 1];
		a[n - 1] = tmp;
		n--;
		i++;
	}
}
