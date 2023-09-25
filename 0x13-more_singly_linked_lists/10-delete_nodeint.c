#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node.
 * Description: at index index of a listint_t linked list.
 * @head: address of head pointer
 * @index: at which to delete a node
 * Return: 1 on success,
 * -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp;

	if (!*head)
		return (-1);

	tmp = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		tmp = 0;
		return (1);
	}
	return (delete_nodeint_at_index(&(*head)->next, index - 1));
}
