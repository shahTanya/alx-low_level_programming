#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


/**
 * hash_table_get - return a key's value.
 * @ht: the hash table data structure.
 * @key: string to be used to retrieve the data value.
 *
 * Return: the string value, if key is found; else NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp;

	if (key == NULL || key[0] == 0 || ht == NULL)
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);

	if ((ht->array)[index] == NULL)
	{
		/* No entry at index yet */
		return (NULL);
	}
	else
	{
		/* Conduct list search */
		tmp = (ht->array)[index]; /* tmp now holding the address of list head */
		while (tmp)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				/* key found */
				return (tmp->value);
			}

			tmp = tmp->next;
		}
	}

	/* Key not found */
	return (NULL);
}
