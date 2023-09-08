#ifndef HEADER
#define HEADER
#include <stdlib.h>
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int white_space(char *ptr);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_malloc(unsigned int b);
void *adjust_book(char *ptr, unsigned old_size, unsigned new_size);


#endif
