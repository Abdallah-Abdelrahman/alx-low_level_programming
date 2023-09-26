#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: head pointer
 *
 * Return: pointer to the 1st node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	unsigned int len = list_len(*head);

	if (!head)
		return (0);
	return (reverse(head, len, 0));
}

/**
 * reverse - reverse singly linked list
 * @head: address of the head pointer
 * @len: size of the list
 * @idx: current index of the node
 *
 * Return: pointer to the 1st node of the reversed list
 */
listint_t *reverse(listint_t **head, unsigned int len, unsigned int idx)
{
	int tmp;

	if (len == 1)
		return (*head);
	if (idx < len)
	{
		tmp = get_nodeint_at_index(*head, idx)->n;
		get_nodeint_at_index(*head, idx)->n
			= get_nodeint_at_index(*head, len - 1)->n;
		get_nodeint_at_index(*head, len - 1)->n = tmp;
	}

	return (reverse(head, len - 1, idx + 1));
}

/**
 * list_len - calculate the length of list
 * @head: head pointer
 *
 * Return: the length of the list
 */
unsigned int list_len(listint_t *head)
{
	if (!head)
		return (0);
	return (1 + list_len(head->next));
}

