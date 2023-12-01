#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: hash table
 * @key: the key
 * Return: value associated with the element, or NULL
 * if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);
	node = ht->array[key_index((unsigned char *)key, ht->size)];

	if (!node)
		return (NULL);

	while (strcmp(node->key, key))
		node = node->next;

	return (node->value);
}
