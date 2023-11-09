#include "lists.h"

/**
 * sum_dlistint - returns the sum.
 * Description: sum of all the data (n) of a dlistint_t linked list.
 * @head: head pointer
 * Return: sums of all nodes or `0` if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	if (!head)
		return (0);
	return (1 + sum_dlistint(head->next));
}
