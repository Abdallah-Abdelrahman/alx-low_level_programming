#include "hash_tables.h"


/**
 * hash_table_delete - deletes a hash table.
 * @ht: hash table
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	ul i;

	if (ht && ht->array)
	{
		for (i = 0; i < ht->size; i++)
		{
			if (ht->array[i])
			{
				free_list(ht->array[i]);
				ht->array[i] = NULL;
			}
		}
		free(ht->array);
		free(ht);
	}
}

/**
 * free_list - free hash table indvidual node
 * @node: linked list
 */
void free_list(hash_node_t *node)
{
	if (node)
	{
		free_list(node->next);
		free(node->key);
		free(node->value);
		free(node);
	}
}
