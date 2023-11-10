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

	if (!head || !*head)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		if (!tmp->prev && !tmp->next)
		{
			/* Only one node */
			*head = 0;
		}
		else if (!tmp->prev)
		{
			/* head */
			*head = tmp->next;
			tmp->next = 0;
			(*head)->prev = 0;
		}
		else if (!tmp->next)
		{
			/* tail */
			*head = tmp->prev;
			(*head)->next = 0;
		}
		else
		{
			(*head)->prev->next = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			(*head) = (*head)->prev;
		}
		/*free(tmp);*/
		return (1);
	}
	if ((*head)->next)
		return (delete_dnodeint_at_index(&((*head)->next), index - 1));
	return (-1);
}

