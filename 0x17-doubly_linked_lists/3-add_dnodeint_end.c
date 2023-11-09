#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: address of head pointner
 * @n: integer
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tail;

	if (!*head || !(*head)->next)
	{
		tail = malloc(sizeof(dlistint_t));
		tail->next = 0;
		tail->n = n;
		tail->prev = *head;
		if ((*head)->prev)
			(*head)->next = tail;
		else
			*head = tail;
		return (tail);
	}

	return (add_dnodeint_end(&(*head)->next, n));
}
