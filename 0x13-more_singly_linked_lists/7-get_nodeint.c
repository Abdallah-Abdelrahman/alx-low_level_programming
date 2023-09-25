#include "lists.h"

/**
 * get_nodeint - returns the nth node of a listint_t linked list.
 * @head: head pointer
 * @index: index of targeted node started at `0`
 *
 * Return: returns the nth node,
 * `NULL` if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	if (!head)
		return (0);
	if (index == 0)
		return (head);

	return (get_nodeint_at_index(head->next, index - 1));
}

