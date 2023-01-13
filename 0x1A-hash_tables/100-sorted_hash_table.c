#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


void sorted_insert(shash_table_t *sht, shash_node_t *node);
void retMalloc(shash_node_t ***retAdd);
shash_node_t **set_shash_list(
		shash_node_t **list, const char *key, const char *value);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
shash_table_t *shash_table_create(unsigned long int size);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);


/**
 * shash_table_create - creates a hash table.
 * @size: array size.
 *
 * Return: a pointer to the newly-created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	shash_node_t **table_arr;
	unsigned long int i;

	if (size == 0)
	{
		return (NULL);
	}

	table_arr = malloc(sizeof(shash_node_t *) * size);
	if (!table_arr)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		/* init array */
		table_arr[i] = NULL;
	}

	table = malloc(sizeof(shash_table_t));
	if (!table)
	{
		return (NULL);
	}
	/* Init the table */
	table->size = size;
	table->array = table_arr;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}



/**
 * shash_table_set - adds/modifies an element to/in the hash table.
 * @ht: the hash table as an array of pointers to shash_node_t structures.
 * @key: data key string.
 * @value: data to add.
 *
 * Return: 1 on success; 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, **ret;
	char *val, *key2;

	if (key == NULL || strcmp(key, "") == 0 || value == NULL || ht == NULL)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);

	if ((ht->array)[index] == NULL)
	{
		new_node = malloc(sizeof(shash_node_t));
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
		sorted_insert(ht, new_node); /* insert new node into sorted linked list */
	}
	else
	{
		/* Presence of a linked list */
		ret = set_shash_list(&((ht->array)[index]), key, value);
		if (ret[0] == NULL && ret[1] == NULL)
			return (0);
		if (ret[0])
			sorted_insert(ht, ret[0]); /* otherwise it is an update operation */
		free(ret);
	}

	return (1);
}



/**
 * set_shash_list - inserts a new node or updates an existing one.
 * @list: address of linked list of interest.
 * @key: a string.
 * @value: a string representing data to store.
 *
 * Note: if the first item of the returned array is
 * not NULL, then a new node was successfully created;
 * otherwise it is an update if the second item is not
 * also NULL. If both items are NULL, this indicates malloc failure.
 * Return: array of two pointers to shash_node_t types.
 */
shash_node_t **set_shash_list(
		shash_node_t **list, const char *key, const char *value)
{
	shash_node_t *tmp, *new_node, **ret;
	char *val, *key2;

	retMalloc(&ret); /* allocate and initialize array memory */
	tmp = *list;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			/* update existing value */
			val = strdup(value);
			if (!val)
			{
				return (ret);
			}
			free(tmp->value); /* free previous address */
			tmp->value = val; /* assign new address */
			ret[1] = *list; /* just to indicate update operation occured */
			return (ret); /* NULL as no new node is created to be returned */
		}
		tmp = tmp->next;
	}

	/* no existing node for key, insert new node at list start */
	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (ret);
	key2 = strdup((char *)key);
	if (!key2)
		return (ret);
	new_node->key = key2;
	val = strdup(value);
	if (!val)
		return (ret);
	new_node->value = val;
	new_node->next = *list;
	*list = new_node;
	ret[0] = new_node;

	return (ret);
}

/**
 * retMalloc - handles memory allocation to ret of set_shash_list().
 * @retAdd: address of the ret array.
 */
void retMalloc(shash_node_t ***retAdd)
{
	*retAdd = malloc(sizeof(shash_node_t *) * 2);
	if (!(*retAdd))
	{
		perror("retMalloc-malloc");
		exit(EXIT_FAILURE);
	}

	/* Initialize the array */
	(*retAdd)[0] = NULL;
	(*retAdd)[1] = NULL;
}


/**
 * sorted_insert - inserts a new node in a sorted doubly-linked list.
 * @sht: hash table with the head and tail of the sorted list.
 * @node: new shash_node_t node to insert.
 */
void sorted_insert(shash_table_t *sht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (sht->shead == NULL)
	{
		/* Empty sorted list; add node as first of list */
		node->sprev = NULL;
		node->snext = NULL;
		/* Update head and tail ptrs in hash table */
		sht->shead = node;
		sht->stail = node;
	}
	else
	{
		/* Search through list for where to insert node */
		tmp = sht->shead;
		while (tmp)
		{
			if (strcmp(tmp->key, node->key) > 0)
			{
				/* Insert before tmp */
				node->snext = tmp;
				node->sprev = tmp->sprev;
				tmp->sprev = node;
				if (node->sprev)
					(node->sprev)->snext = node;
				if (tmp == sht->shead)
				{/* Update head ptr in hash table */
					/* Previous head was replaced at top by node */
					sht->shead = node;
				}
				return;
			}
			tmp = tmp->snext;
		}
		/* Insert node at tail */
		(sht->stail)->snext = node;
		node->snext = NULL;
		node->sprev = sht->stail;
		sht->stail = node;  /* node is now new tail */
	}
}



/**
 * shash_table_get - return a key's value.
 * @ht: the hash table data structure.
 * @key: string to be used to retrieve the data value.
 *
 * Return: the string value, if key is found; else NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

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



/**
 * shash_table_print - prints a shash_table_t hash table.
 * @ht: the hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int first = 1;
	shash_node_t *tmp;

	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->shead;
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

		tmp = tmp->snext;
	}

	printf("}\n");
}


/**
 * shash_table_print_rev - prints a shash_table_t hash table.
 * @ht: the hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int first = 1;
	shash_node_t *tmp;

	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->stail;
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

		tmp = tmp->sprev;
	}

	printf("}\n");
}



/**
 * shash_table_delete - deletes a shash_table_t hash table.
 * @ht: the hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *tmp, *tmp2;

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
