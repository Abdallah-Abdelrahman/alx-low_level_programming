#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table,
 * NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h_table = malloc(sizeof(hash_table_t));

	if (!h_table)
		return (NULL);

	h_table->size = size;

		h_table->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
		if (!h_table->array)
		{
			free(h_table);
			return (NULL);
		}

	return (h_table);
}
