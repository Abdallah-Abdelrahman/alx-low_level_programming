#include "main.h"

/**
 * swap_int - swap the values of two integers
 * @a: pointer to the 1st integer
 * @b: pointer to the 2nd integer
 *
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
