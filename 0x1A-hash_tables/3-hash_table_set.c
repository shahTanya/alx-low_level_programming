#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


/**
 * hash_table_set - adds/modifies an element to/in the hash table.
 * @ht: the hash table as an array of pointers to hash_node_t structures.
 * @key: data key string.
 * @value: data to add.
 *
 * Return: 1 on success; 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	int stat;
	char *val, *key2;

	if (key == NULL || strcmp(key, "") == 0 || value == NULL || ht == NULL)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);

	if ((ht->array)[index] == NULL)
	{
		new_node = malloc(sizeof(hash_node_t));
		if (!new_node)
			return (0);
		key2 = strdup((char *)key);
		new_node->key = key2;
		val = strdup(value);
		if (!val)
			return (0);
		new_node->value = val;
		/* insert new node into hash table */
		new_node->next = (ht->array)[index]; /* new_node pointing to current value */
		(ht->array)[index] = new_node; /* new_node now head of linked list */
	}
	else
	{
		/* Presence of a linked list */
		stat = set_hash_list(&((ht->array)[index]), key, value);
		if (stat == 0)
			return (0);
	}

	return (1);
}


#ifndef SET_HASH_LIST_C
#define SET_HASH_LIST_C

/**
 * set_hash_list - inserts a new node or updates an existing one.
 * @list: address of linked list of interest.
 * @key: a string.
 * @value: a string representing data to store.
 *
 * Return: 1 on successful insertion or update; 0 otherwise.
 */
int set_hash_list(
		hash_node_t **list, const char *key, const char *value)
{
	hash_node_t *tmp, *new_node;
	char *val, *key2;

	tmp = *list;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			/* update existing value */
			val = strdup(value);
			if (!val)
			{
				return (0);
			}
			free(tmp->value); /* free previous address */
			tmp->value = val; /* assign new address */
			return (1);
		}

		tmp = tmp->next;
	}

	/* no existing node for key, insert new node at list start */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	key2 = strdup((char *)key);
	if (!key2)
		return (0);
	new_node->key = key2;
	val = strdup(value);
	if (!val)
	{
		return (0);
	}
	new_node->value = val;
	new_node->next = *list;
	*list = new_node;

	return (1);
}
#endif /* SET_HASH_LIST_C */
