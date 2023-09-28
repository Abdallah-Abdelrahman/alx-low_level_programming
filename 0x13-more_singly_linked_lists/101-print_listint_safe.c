#include "lists.h"
#define BUFF 1024

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head pointer
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	int len = 0;
	listint_t **addr = 0;

	if (!head)
		return (0);

	if (!head->next)
	{
		printf("[%p] %i\n", (void *)&head->n, head->n);
		return (1);
	}

	addr = malloc(sizeof(addr) * BUFF);
	if (!addr)
		exit(98);

	for (; head; len++, head = head->next)
	{
		addr[len] = (listint_t *)head;
		if (is_circular(addr, len + 1))
		{
			free(addr);
			return (len);
		}
		printf("[%p] %i\n", (void *)&head->n, head->n);
	}

	free(addr);

	return (len);
}


/**
 * is_circular - check if a list is circular
 * @addr: array of pointers to struct
 * @len: length of addr
 *
 * Return: 1 if it's circular,
 * 0 otherwise
 */
int is_circular(listint_t **addr, int len)
{
	int i = 0, j;

	for (i = 0; i < len && addr[i]; i++)
		for (j = i + 1; j < len && addr[j]; j++)
			if (addr[i] == addr[j])
			{
				printf("-> [%p] %i\n",
				(void *)&addr[i]->n, addr[i]->n);
				return (1);
			}
	return (0);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size in bytes of the allocated space for `ptr`
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the newly allocated memory,
 * or `NULL`
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	size_t i, min = old_size;
	char *new_ptr;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (0);
	}
	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (malloc(sizeof(ptr) * new_size));
	if (new_size < old_size)
	{
		min = new_size;
	}
	new_ptr = malloc(sizeof(ptr) * new_size);

	if (!new_ptr)
		return (0);

	for (i = 0; i < min; i++)
		new_ptr[i] = ((char *)ptr)[i];

	free(ptr);

	return (new_ptr);
}
