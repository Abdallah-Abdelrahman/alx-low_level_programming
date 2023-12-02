#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: hash table
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	ul idx, j;
	hash_node_t *tmp = 0;

	if (!ht || !ht->array)
		return;

	printf("{");
	for (idx = 0, j = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx])
		{
			tmp = ht->array[idx];
			while (tmp)
			{
				if (j)
					printf(", ");
				printf("'%s': '%s'", tmp->key, tmp->value);
				tmp = tmp->next;
				j++;
			}
		}
	}
	printf("}\n");
}
