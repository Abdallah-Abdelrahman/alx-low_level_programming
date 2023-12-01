#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: hash table
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	uli idx, j;

	if (!ht || !ht->array)
		return;

	printf("{");
	for (idx = 0, j = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx])
		{
			if (j)
				printf(", ");
			printf("'%s': '%s'", ht->array[idx]->key, ht->array[idx]->value);
			j++;
		}
	}
	printf("}\n");
}
