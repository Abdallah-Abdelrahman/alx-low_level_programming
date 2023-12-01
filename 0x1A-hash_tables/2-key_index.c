#include "hash_tables.h"

/**
 * key_index - gives you the index of a key.
 * @key: the key
 * @size: the array size of hash_tables
 *
 * Return: index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
