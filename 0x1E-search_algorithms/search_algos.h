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

/*-----------STRUCTS-------------*/
/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/*-----------PROTOS-------------*/
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

/*-----------HELPERS-------------*/
int leftmost_binary(int *a, size_t lo, size_t hi, int value);
#endif /* HEADER */
