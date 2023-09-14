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
	int i = 0;
	va_list ap;

	va_start(ap, format);

	while (format[i])
	{
		delimitate(i, format[i]);
		print_var(format[i], ap);

		i++;
	}

	printf("\n");
	va_end(ap);
}

/**
 * print_var - print variable accorging to specifier
 * @c: specifier
 * @ap: argument pointer
 */
void print_var(char c, va_list ap)
{

	char *str;

	switch (c)
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
