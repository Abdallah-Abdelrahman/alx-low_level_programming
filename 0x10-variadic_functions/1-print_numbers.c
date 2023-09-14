#include "variadic_functions.h"
#include <stdarg.h>

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

	if (separator)
	{
		for (i = 0; i < n; i++)
		{
			if (i)
				printf("%s", separator);
			printf("%d", va_arg(ap, typeof(n)));
		}
		printf("\n");
	}
}
