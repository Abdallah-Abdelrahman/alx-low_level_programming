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

	if (!key || !key[0] || !ht || !ht->array)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);


	if (!ht->array[idx])
	{
		return (initialize_node(ht, (char *)key, (char *)value, idx));
	}

	if (!strcmp(key, ht->array[idx]->key))
	{
		/* update */
		free(ht->array[idx]->value);
		ht->array[idx]->value = strdup(value);
		return (1);
	}

	/* collision */
	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	if (!node->key)
		return (0);
	node->value = strdup(value);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
/**
 * initialize_node - create a node
 * @ht: hash
 * @key: key
 * @value: value
 * @idx: hash value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int initialize_node(hash_table_t *ht, char *key, char *value, uli idx)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
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

	return (1);
}
