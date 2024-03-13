#include "search_algos.h"
#define JUMP(list, block) \
	for (; list->index < (block); list = list->next)

/**
 * jump_list - pointer to the head of the list to search in
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to the first node where value is located,
 * If value is not present in head or if head is NULL,
 * your function must return NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t m, R;
	listint_t *tmp;

	if (!list || size == 0)
		return (NULL);

	/* block to jump */
	m = sqrt(size);
	tmp = list;

	for (R = m; size >= R && tmp->n < value; R += m)
	{
		JUMP(tmp, R >= size ? size - 1 : R);
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			size >= R ? tmp->index - m : tmp->index - m + 1,
			MIN(tmp->index, size - 1));

	JUMP(list, size >= R ? tmp->index - m : tmp->index - m + 1);

	for (; list; list = list->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
	}

	return (NULL);
}
