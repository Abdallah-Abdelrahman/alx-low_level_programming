#include "variadic_functions.h"

/**
 * print_all - prints anything(literally).
 * @format: string contains formating characters
 * Description: the function has 4 formaters
 * i => integer
 * f => float
 * c => character
 * s => string
 *
 * Return: 0 as exit status
 */
void print_all(const char * const format, ...)
{
	int i = 0, flag = 0;
	va_list ap;

	va_start(ap, format);

	while (format && format[i])
	{
		print_var(format[i], ap, &flag);
		i++;
	}

	printf("\n");
	va_end(ap);
}

/**
 * print_var - print variable according to specifier
 * @c: specifier
 * @ap: argument pointer
 * @flag: based on flag delimite printed arguments
 */
void print_var(char c, va_list ap, int *flag)
{
	char *str;

	if (*flag)
		printf(", ");
	switch (c)
	{
		case 'i':
			printf("%d", va_arg(ap, int));
			*flag = 1;
			break;
		case 'f':
			printf("%f", va_arg(ap, double));
			*flag = 1;
			break;
		case 's':
			str = va_arg(ap, char *);
			*flag = 1;
			if (!str)
			{
				printf("%s", "(nil)");
				break;
			}
			printf("%s", str);
			break;
		case 'c':
			printf("%c", va_arg(ap, int));
			*flag = 1;
			break;
		default:
			*flag = 0;
	}
}
