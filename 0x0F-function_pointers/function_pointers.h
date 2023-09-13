#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <unistd.h>

void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));
int _putchar(char);
void print_chars(int n);
void print_error(char *str);

#endif /* HEADER */
