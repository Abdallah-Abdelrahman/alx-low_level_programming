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
		if (i && is_format(format[i]))
			printf(", ");
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
 * is_format - check if character is formatting character
 * @c: character
 *
 * Return: 1 on success,
 * 0 on failure
 */
int is_format(char c)
{
	if (c == 'i' || c == 'f' || c == 's' || c == 'c')
		return (1);
	return (0);
}
