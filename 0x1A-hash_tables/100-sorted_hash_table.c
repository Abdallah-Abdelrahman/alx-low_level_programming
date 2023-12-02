#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table,
 * NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sh_table = malloc(sizeof(shash_table_t));

	if (!sh_table)
		return (NULL);

	sh_table->size = size;
	sh_table->shead = sh_table->stail = NULL;

	sh_table->array = calloc(size, sizeof(shash_node_t *));
	if (!sh_table->array)
	{
		free(sh_table);
		return (NULL);
	}

	return (sh_table);
}

/**
 * shash_table_set - adds an element to the sorted hash table.
 * @ht: sorted hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	ul idx;
	shash_node_t *node = NULL;

	if (!key || !key[0] || !ht || !ht->array)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);

	if (!ht->array[idx])
	{
		return (initialize_node_s(ht, (char *)key, (char *)value, idx));
	}

	if (!strcmp(key, ht->array[idx]->key))
	{
		/* update */
		free(ht->array[idx]->value);
		ht->array[idx]->value = strdup(value);
		return (1);
	}

	/* collision */
	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	if (!node->key)
		return (0);
	node->value = strdup(value);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	insertion_sort(ht, node);
	return (1);
}

/**
 * initialize_node_s - create a node and inserted at the right place
 * @ht: sorted hash table
 * @key: key
 * @value: value
 * @idx: hash value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int initialize_node_s(shash_table_t *ht, char *key, char *value, ul idx)
{
	shash_node_t *node = malloc(sizeof(shash_node_t)), *tmp = ht->shead;

	if (!node)
		return (0);
	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (0);
	}
	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (0);
	}
	node->next = NULL;
	ht->array[idx] = node;
	if (!tmp)
	{
		node->snext = node->sprev = NULL;
		ht->shead = ht->stail = node;
	}
	else
		insertion_sort(ht, node);

	return (1);
}
/**
 * insertion_sort - insert node (key/value) pair at the right place
 * @ht: sorted hash table
 * @node: node to insert
 *
 * Return: Nothing
 */
void insertion_sort(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp = ht->shead;

	for (; tmp->snext && strcmp(node->key, tmp->key) > 0; tmp = tmp->snext)
		/* loop until node < tmp, or there's only one node, or we reach the tail */
		;

	if (strcmp(node->key, tmp->key) < 0)
	{
		node->snext = tmp;
		node->sprev = tmp->sprev;
		if (tmp->sprev)
		{
			tmp->sprev->snext = node;
			tmp->sprev = node;
		}
		else
			tmp->sprev = node;
		tmp = node;
	}
	else
	{
		node->sprev = tmp;
		node->snext = tmp->snext;
		tmp->snext = node;
		ht->stail = node;
	}

	for (; tmp->sprev; tmp = tmp->sprev)
		;
	ht->shead = tmp;

	for (; tmp->snext; tmp = tmp->snext)
		;
	ht->stail = tmp;
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: hash table
 * @key: the key
 * Return: value associated with the element, or NULL
 * if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;

	if (!ht || !key)
		return (NULL);
	node = ht->array[key_index((unsigned char *)key, ht->size)];

	if (!node)
		return (NULL);

	for (; strcmp(node->key, key); node = node->next)
		;

	return (node->value);
}

/**
 * shash_table_print - prints a hash table.
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	int j = 0;
	shash_node_t *tmp;

	if (!ht || !ht->shead)
		return;

	tmp = ht->shead;

	printf("{");

	for (j = 0; tmp; j++, tmp = tmp->snext)
	{
		if (j)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table reversed.
 * @ht: sorted hash table
 *
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int j = 0;
	shash_node_t *tmp;

	if (!ht || !ht->stail)
		return;

	tmp = ht->stail;

	printf("{");
	for (j = 0; tmp; j++, tmp = tmp->sprev)
	{
		if (j)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table.
 * @ht: sorted hash table
 *
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht)
	{
		free_shash_table(ht->shead);
		if (ht->array)
			free(ht->array);
		free(ht);
	}
}

/**
 * free_shash_table - free sorted hash table node
 * @shead: head of sorted table
 *
 * Return: Nothing
 */
void free_shash_table(shash_node_t *shead)
{
	if (shead)
	{
		free_shash_table(shead->snext);
		free(shead->key);
		free(shead->value);
		free(shead);
	}
}
