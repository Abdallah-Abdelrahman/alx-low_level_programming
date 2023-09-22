#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: address of the head pointer
 * @str: string pointer as member of node
 *
 * Return: adddress of the new node,
 * NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *tmp = *head, *tail = malloc(sizeof(*tail));

	if (!tail)
		return (NULL);

	for (; tmp; tmp = tmp->next)
	{
		if (!tmp->next)
		{
			tmp->next = tail;
			tail->next = NULL;
		}
	}

	return (0);
}
