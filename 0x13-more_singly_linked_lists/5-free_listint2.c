#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * Description: the function sets the `head` to `NULL`
 * @head: address of head node pointer
 *
 */
void free_listint2(listint_t **head)
{
	if (*head)
	{
		free_listint2(&(*head)->next);
		free(*head);
		*head = 0;
	}
}
