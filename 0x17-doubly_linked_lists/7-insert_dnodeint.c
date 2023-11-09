#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: address of head pointer
 * @idx: position to insert at
 * @n: integer data
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node_at_idx = 0, *new_node = 0;
	unsigned int len = dlistint_len(*h);

	if (idx > len)
		return (0);

	node_at_idx = get_dnodeint_at_index(*h, idx);
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (0);
	new_node->n = n;
	new_node->next = node_at_idx;
	new_node->prev = node_at_idx->prev;
	node_at_idx->prev = new_node;

	return (new_node);
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
