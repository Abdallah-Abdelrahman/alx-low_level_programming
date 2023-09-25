#include "lists.h"

/**
 * sum_listint - calculate the sum of all data (n)
 * @head: head node pointer
 *
 * Return: the sum,
 * `0` if the list is empty
 */
int sum_listint(listint_t *head)
{
	if (!head)
		return (0);
	return (head->n + sum_listint(head->next));
}
