#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_all - prints anything(literally).
 * Description: Long desc
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
				if (str)
					printf("%s", str);
				if (!str)
					printf("%s", "(nil)");
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
 * print_char - print character
 * @c: character
 */
void print_char(char c)
{
	printf("%c", c);
}
/**
 * print_int - print integer
 * @n: integer
 */
void print_int(int n)
{
	printf("%i", n);
}
/**
 * print_float - print float
 * @n: float
 */
void print_float(float n)
{
	printf("%f", n);
}
/**
 * print_str - print string
 * @str: string pointer
 */
void print_str(char *str)
{
	printf("%s", str);
}
