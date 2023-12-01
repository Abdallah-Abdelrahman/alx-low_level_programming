#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	uli idx;
	hash_node_t *node = 0;

	if (!key)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);

	if (!ht->array[idx])
	{
		/* set element */
		ht->array[idx] = malloc(sizeof(hash_node_t *));
		if (!ht->array[idx])
			return (0);
		ht->array[idx]->key = strdup(key);
		ht->array[idx]->value = strdup(value);
		ht->array[idx]->next = NULL;
		return (1);
	}

	if (!strcmp(key, ht->array[idx]->key))
	{
		/* update */
		ht->array[idx]->value = strdup(value);
		return (1);
	}

	/* collision */
	node = malloc(sizeof(hash_node_t *));
	if (!node)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
