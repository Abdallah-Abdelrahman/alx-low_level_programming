#include "lists.h"

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

	new->next = *head;
	new->str = strdup(str);
	*head = new;

	return (new);
}

