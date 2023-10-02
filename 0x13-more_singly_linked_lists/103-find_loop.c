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
	listint_t *turtle;
	listint_t *rabbit;

	if (!head || !head->next)
		return (0);
	if (head == head->next || head == head->next->next)
		return (head);
	rabbit = (catch_loop(head->next, head->next->next, 1));
	if (!rabbit)
		return (0);
	turtle = head;
	return (catch_loop(turtle->next, rabbit->next, 0));
}

/**
 * catch_loop - catch loop in a list using tan, tan tan technique.
 * @h: head pointer
 * @nnext: next to next pointer node
 * @flag: to determine to go, aligned or separate
 *
 * Return: address of node where loop started,
 * `NULL` if there's no loop
 */
listint_t *catch_loop(listint_t *h, listint_t *nnext, int flag)
{
	if (!h || !nnext)
		return (0);
	if (h == nnext)
		return (h);
	return (catch_loop(h->next,
				flag
				? nnext->next->next
				: nnext->next, flag));
}
