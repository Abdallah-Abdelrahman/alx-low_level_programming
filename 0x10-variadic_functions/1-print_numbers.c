#include "variadic_functions.h"

/**
 * print_numbers - prints numbers, followed by a new line.
 * @separator: separator
 * @n: numbr of integers
 *
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;


	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		if (i && separator)
			printf("%s", separator);
		printf("%d", va_arg(ap, typeof(n)));
	}
	printf("\n");
	va_end(ap);
}
