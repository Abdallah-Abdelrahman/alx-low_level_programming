#ifndef HEADER
#define HEADER
#include <stdarg.h>
#include <stdio.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * format - format struct
 * @c: character format
 * @func: function to handle format
 */
typedef struct format
{
	char *fmt;
	void(*func)(void);
} fmt;
void print_char(char c);
void print_int(int n);
void print_str(char *str);
void print_float(float n);

#endif /* HEADER */
