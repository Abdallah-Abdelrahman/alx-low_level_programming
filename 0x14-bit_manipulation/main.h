#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <unistd.h>

unsigned int binary_to_uint(const char *b);
int _is_digit(char n);
unsigned int convert(const char *b, int idx);
void print_binary(unsigned long int n);
int _putchar(char c);
void print_rev(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);

#endif /* HEADER */
