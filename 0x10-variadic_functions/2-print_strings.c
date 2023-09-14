#include "variadic_functions.h"

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: separator
 * @n: number of strings
 *
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *str;
	va_list ap;

	if (separator)
	{
		va_start(ap, n);
		for (i = 0; i < n; i++)
		{
			if (i)
				printf("%s", separator);
			str = va_arg(ap, char *);

			printf("%s", str ? str : "(nil)");
		}
		printf("\n");
		va_end(ap);
	}
}
