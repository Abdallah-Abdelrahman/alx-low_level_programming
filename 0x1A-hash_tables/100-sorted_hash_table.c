#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

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
	sh_table->shead = malloc(sizeof(shash_node_t));
	if (!sh_table->shead)
		return (NULL);
	sh_table->shead->sprev = NULL;
	sh_table->stail = malloc(sizeof(shash_node_t));
	if (!sh_table->stail)
		return (NULL);
	sh_table->stail->snext = NULL;

	sh_table->array = calloc(size, sizeof(shash_node_t *));
	if (!sh_table->array)
	{
		free(sh_table);
		return (NULL);
	}

	return (sh_table);
}

/**
 * shash_table_set - adds an element to the hash table.
 * @ht: hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	uli idx, is_head = 0;
	shash_node_t *node = 0, *tmp;

	if (!key || !key[0] || !ht || !ht->array)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);

	if (!ht->array[idx])
	{
		return (initialize_nodes(ht, (char *)key, (char *)value, idx));
	}

	if (!strcmp(key, ht->array[idx]->key))
	{
		free(ht->array[idx]->value);
		ht->array[idx]->value = strdup(value);
		return (1);
	}
	tmp = ht->array[idx];
	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	if (!node->key)
		return (0);
	node->value = strdup(value);
	if (!tmp->next)
	{
		is_head = 1;
		if (strcmp(tmp->key, node->key) > 0)
			node->snext = tmp, node->sprev = NULL, tmp->sprev = node, tmp = node;
		else
			tmp->snext = node, node->sprev = tmp, node->snext = NULL;
	}
	if (is_head)
		while (strcmp(node->key, tmp->key) > 0)
			tmp = tmp->next;
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
/**
 * initialize_nodes - create a node
 * @ht: hash
 * @key: key
 * @value: value
 * @idx: hash value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int initialize_nodes(shash_table_t *ht, char *key, char *value, uli idx)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
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
	node->snext = NULL;
	node->sprev = NULL;
	ht->array[idx] = node;

	return (1);
}
