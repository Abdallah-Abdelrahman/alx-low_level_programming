#ifndef HEADER
#define HEADER
#include <stdarg.h>
#include <stdio.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void delimitate(int idx, char c);
void print_var(char c, va_list ap);

#endif /* HEADER */
