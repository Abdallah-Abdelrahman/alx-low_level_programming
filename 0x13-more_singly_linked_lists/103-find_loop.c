#include "lists.h"

/**
 * find_listint_loop - find the loop recursively
 * @head: head pointer
 *
 * Return: address of node where loop started,
 * `NULL` if there's no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (!head || !head->next)
		return (0);
	if (head == head->next)
		return (head);

	return (catch_loop(head->next->next, head->next));
}

/**
 * catch_loop - catch loop in a list using tan, tan tan technique.
 * @h: head pointer
 * @nnext: next to next pointer node
 *
 * Return: address of node where loop started,
 * `NULL` if there's no loop
 */
listint_t *catch_loop(listint_t *h, listint_t *nnext)
{
	if (!h || !nnext)
		return (0);
	if (h == nnext)
		return (h);
	return (catch_loop(h->next->next, nnext->next));
}
