#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: address of head pointer
 * @idx: index of the list where new node should be added
 * @n: integer memeber in the node
 *
 * Return: pointer to the newly inserted node,
 * `NULL` on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node;

	if (idx > _list_len(*head))
		return (0);
	if (!*head)
	{
		return (add_nodeint_end(head, n));
	}

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		node->n = n;
		return (node);
	}

	return (insert_nodeint_at_index(&(*head)->next, idx - 1, n));
}

/**
 * _list_len - calculate the length of list
 * @head: head pointer
 *
 * Return: the length of the list
 */
unsigned int _list_len(listint_t *head)
{
	if (!head)
		return (0);
	return (0 + _list_len(head->next));
}
