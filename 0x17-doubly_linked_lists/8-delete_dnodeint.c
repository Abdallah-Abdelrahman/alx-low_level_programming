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
	dlistint_t *tmp;

	if (!*head)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		if (!(*head)->prev && !(*head)->next)
			*head = 0;
		else if (!(*head)->prev)
		{
			/* head */
			*head = tmp->next;
			(*head)->prev = 0;
		}
		else if (!(*head)->next)
		{
			/* tail */
			*head = tmp->prev;
			(*head)->next = 0;
		}
		else
		{
			(*head)->prev->next = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			*head = tmp->next;
		}
		free(tmp);
		return (1);
	}
	if ((*head)->next)
		return (delete_dnodeint_at_index(&((*head)->next), index - 1));
	return (-1);
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
