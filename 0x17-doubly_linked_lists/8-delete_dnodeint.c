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
	unsigned int len = 0;
	dlistint_t *tmp;

	if (!head)
		return (-1);
	len = dlistint_len(*head);
	if (!*head || len <= index)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		if (len == 1)
		{
			free(*head);
			*head = 0;
		}
		else if (!(*head)->prev)
		{
			/* head */
			*head = tmp->next;
			(*head)->prev = 0;
			free(tmp);
		}
		else if (!(*head)->next)
		{
			/* tail */
			*head = tmp->prev;
			(*head)->next = 0;
			free(tmp);
		}
		else
		{
			(*head)->prev->next = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			free(tmp);
		}
		return (1);
	}
	return (delete_dnodeint_at_index(&(*head)->next, index - 1));
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
