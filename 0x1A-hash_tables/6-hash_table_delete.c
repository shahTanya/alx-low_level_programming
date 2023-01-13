#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


/**
 * hash_table_delete - deletes a hash_table_t hash table.
 * @ht: the hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp, *tmp2;

	for (i = 0; i < ht->size; i++)
	{
		if ((ht->array)[i])
		{
			/* Pointer at index position is not NULL */
			tmp = (ht->array)[i];
			while (tmp)
			{
				tmp2 = tmp->next;
				free(tmp->key);
				free(tmp->value); /* free the duplicated string address */
				free(tmp); /* free the malloc'd node */
				tmp = tmp2;
			}
		}
	}

	free(ht->array);
	free(ht);
}
