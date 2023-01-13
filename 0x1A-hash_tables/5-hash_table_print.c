#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


/**
 * hash_table_print - prints a hash_table_t hash table.
 * @ht: the hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, first = 1;
	hash_node_t *tmp;

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if ((ht->array)[i])
		{
			/* Pointer at index position is not NULL */
			tmp = (ht->array)[i];
			while (tmp)
			{
				/* Implement list printing */
				if (first)
				{
					printf("\'%s\': \'%s\'", tmp->key, tmp->value);
					first = 0;
				}
				else
				{
					printf(", \'%s\': \'%s\'", tmp->key, tmp->value);
				}

				tmp = tmp->next;
			}
		}
	}

	printf("}\n");
}
