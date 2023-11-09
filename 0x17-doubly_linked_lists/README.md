# Doubly linked lists
Double linked list repo, each task or file encompasses certain functionality of the list.
-- Doubly linked list structure
```
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;
```

<details>
<summary><b>0-print_dlistin</b></summary>
`c` function that prints all the elements of a `dlistint_t` list.
</details>
