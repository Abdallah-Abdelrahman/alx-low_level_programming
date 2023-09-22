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
	list_t *tmp = *head, *tail;

	if (!tmp)
	{
		return (add_node(head, str));
	}
	tail = malloc(sizeof(*tail));
	if (!tail)
		return (NULL);

	for (; tmp; tmp = tmp->next)
	{
		if (!(tmp->next))
		{
			tmp->next = tail;
			tail->str = strdup(str);
			tail->next = NULL;
		}
	}

	return (tail);
}

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: the head of the list
 * @str: string pointer as member of the node
 *
 * Return: address to the newly created node,
 * `NULL` on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->next = *head;
	*head = new;
	new->str = strdup(str);

	return (new);
}
