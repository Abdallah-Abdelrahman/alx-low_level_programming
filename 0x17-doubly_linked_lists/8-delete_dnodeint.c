#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node.
 * Description: deletes at index index of a dlistint_t linked list.
 * @head: address of head pointer
 * @index: index of the node that should be deleted. Index starts at 0
 * Return: `1` if it succeeded, `-1` if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int len = dlistint_len(*head);
	dlistint_t *node_at_idx = 0;

	if (len > index)
		return (-1);
	node_at_idx = get_dnodeint_at_index(*head, index);
	if (!node_at_idx)
		return (-1);

	node_at_idx->prev->next = node_at_idx->next;
	node_at_idx->next->prev = node_at_idx->prev;
	free(node_at_idx);
	node_at_idx = 0;

	return (1);
}

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @h: pointer to head
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int len = 0;

	for (; h; h = h->next, len++)
		;

	return (len);
}

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
