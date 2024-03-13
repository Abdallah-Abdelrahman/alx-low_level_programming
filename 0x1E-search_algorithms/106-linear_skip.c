#include "search_algos.h"

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
	(void)value;
	if (!list)
		return (NULL);
	return (list);
}
