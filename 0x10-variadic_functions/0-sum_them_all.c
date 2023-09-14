#include "variadic_functions.h"

/**
 * sum_them_all - sums up all the variable (optional) arguments
 * @n: number of arguments
 *
 * Return: the sum,
 * 0 if @n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
	int i, sum;
	va_list ap;

	if (n <= 0)
		return (0);

	va_start(ap, n);

	for (; i < n; i++)
		sum += va_arg(ap, typeof(n));
	va_end(ap);

	return (sum);
}
