# Doubly linked lists
Double linked list repo, each task or file encompasses certain functionality of the list.<br />
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
<summary><b>0-print_dlistint</b></summary>
`c` function that prints all the elements of a `dlistint_t` list.
</details>

---

<details>
<summary><b>1-dlistint_t_len</b></summary>
`c` function that returns the number of elements in a linked `dlistint_t` list.
</details>

---

<details>
<summary><b>2-add_dnoedint</b></summary>
`c` function that adds node at the beginning and return the new node.
</details>

---

<details>
<summary><b>3-add_dnoedint_end</b></summary>
`c` function that adds node at the end and return the new node.
</details>

---

<details>
<summary><b>4-free_dlistint</b></summary>
`c` function that frees a doubly linked list
</details>

---

<details>
<summary><b>5-get_dnodeint</b></summary>
`c` function that retrieves node at certain `index`.
</details>

---

<details>
<summary><b>6-sum_dlistint</b></summary>
`c` function that returns sum of all nodes in the list.
</details>

---

<details>
<summary><b>7-insert_dnodeint_at_index</b></summary>
`c` function that inserts a new node at a given position.
</details>

---

<details>
<summary><b>8-delete_dnodeint</b></summary>
`c` function that deletes the node at index index of a `dlistint_t` linked list.
</details>
