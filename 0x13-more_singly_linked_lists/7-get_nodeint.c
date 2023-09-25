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
	unsigned int cursor = 0;

	if (!head)
		return (0);

	return (search_node(head->next, index, cursor));
}

/**
 * search_node - search node at particular index.
 * @head: head pointer
 * @idx: index fo targeted node
 * @cursor: index of node at any given moment
 *
 * Return: returns the nth node,
 * `NULL` if it does not exist
 */
listint_t *search_node(listint_t *head, unsigned int idx, unsigned int cursor)
{
	if (!head)
		return (0);
	if (cursor == idx)
		return (head);
	return (search_node(head->next, idx, cursor + 1));
}
