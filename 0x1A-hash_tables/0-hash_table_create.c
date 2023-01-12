#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


/**
 * hash_table_create - creates a hash table.
 * @size: array size.
 *
 * Return: a pointer to the newly-created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	hash_node_t **table_arr;
	unsigned long int i;

	if (size == 0)
	{
		return (NULL);
	}

	table_arr = malloc(sizeof(hash_node_t *) * size);
	if (!table_arr)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		/* init array */
		table_arr[i] = NULL;
	}

	table = malloc(sizeof(hash_table_t));
	if (!table)
	{
		return (NULL);
	}
	table->size = size;
	table->array = table_arr;

	return (table);
}
