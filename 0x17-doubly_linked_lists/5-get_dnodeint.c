#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: head pointer
 * @index: index of the node, starting from 0
 * Return: node at @index, or NULL if not any
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (!head)
		return (0);
	if (index == 0)
		return (head);
	return (get_dnodeint_at_index(head->next, index - 1));
}
