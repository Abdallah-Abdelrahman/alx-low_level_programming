#ifndef HEADER
#define HEADER

/*-----------HEADERS-------------*/
#include <stdio.h>
#include <math.h>

/*-----------MACROS-------------*/
#define PRINT(a, L, R) {\
	size_t l = L;\
	if (L <= R)\
	{\
		printf("Searching in array: ");\
		for (; l <= R; l++)\
			printf("%d%s", a[l], l < R ? ", " : "\n");\
	} \
}
#define MIN(x, y) (x < y ? x : y)
#define PROBE(low, high, a)\
	(low + (((double)(high - low) / (a[high] - a[low])) * (value - a[low])))

/*-----------PROTOS-------------*/
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);

/*-----------HELPERS-------------*/
int leftmost_binary(int *a, size_t lo, size_t hi, int value, size_t size);
#endif /* HEADER */
