#include "search_algos.h"
#define ADVANCE(tmp, list) {\
	if (tmp->n < value)\
	{\
		list = tmp;\
		while (tmp->next)\
			tmp = tmp->next;\
	} \
}

/**
 * linear_skip - performs search in a linked list with an express lane
 * Description: looking for a specific value in a singly linked list,
 * always leads to browse every element of the list.
 * A common way to optimize the time complexity of a search,
 * in a singly linked list is to modify the list itself,
 * by adding an “express lane” to browse it
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located.
 * If value is not present in list or if head is NULL,
 * your function must return NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;

	if (!list)
		return (NULL);

	tmp = list;

	/* determine block where value is present */
	while (tmp->express && tmp->n < value)
	{
		list = tmp;
		tmp = tmp->express;
		printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
	}
	/* advance tmp if it's beyond express lane */
	ADVANCE(tmp, list);

	printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, tmp->index);

	/* linear search */
	for (; list && list->index <= tmp->index; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
	}

	return (NULL);
}
