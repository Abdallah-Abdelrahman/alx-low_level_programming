#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <stdio.h>
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int white_space(char *ptr);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_malloc(unsigned int b);
void *adjust_book(char *ptr, unsigned old_size, unsigned new_size);
int infinite_add(char *, char *, int, int);
void rev_string(char *str, int size);
int *len2str(char *p1, char *p2, int arr[]);
int _isdigit(char n);

#endif
