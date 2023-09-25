#include "lists.h"
#include <stdlib.h>

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
	unsigned int i = 0;
	listint_t *node = 0, *next = 0;

	if (!*head)
	{
		return (add_nodeint(head, n));
	}

	for (i = 0; *head; i++, *head = (*head)->next)
		if (i == idx - 1)
		{
			node = malloc(sizeof(*node));
			(*head)->next = node;
			node->n = n;
			next = get_nodeint_at_index((*head)->next, idx);
			if (!next)
				node->next = 0;
			else
				node->next = next;
			break;
		}
	return (node);
}

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: address of head pointer
 * @n: integer member in the node
 *
 * Return: pointer to the newly created node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node = malloc(sizeof(*node));

	if (!node)
		return (0);

	node->next = *head;
	node->n = n;
	*head = node;

	return (node);
}

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
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
