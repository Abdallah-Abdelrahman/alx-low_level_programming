#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_all - prints anything(literally).
 * @format: string contains formating characters
 * Description: the function has 3 formaters
 * i => integer
 * f => float
 * c => character
 * s => string
 *
 * Return: 0 as exit status
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str;
	va_list ap;

	va_start(ap, format);

	while (format[i])
	{
		delimitate(i, format[i]);
		switch (format[i])
		{
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				str = va_arg(ap, char *);
				if (!str)
				{
					printf("%s", "(nil)");
					break;
				}
				printf("%s", str);
				break;
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			default:
				break;
		}

		i++;
	}

	printf("\n");
	va_end(ap);
}

/**
 * delimitate - delimitate by comma followed by space
 * @idx: index
 * @c: character
 *
 */
void delimitate(int idx, char c)
{
	if (idx && (c == 'i' || c == 'f' || c == 's' || c == 'c'))
		printf(", ");
}
