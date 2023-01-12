#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * key_index - returns the index for the associated key.
 * @key: string representing data record key.
 * @size: number representing the size of the hash table containing the data.
 *
 * Return: the index corresponding to the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int code;

	code = hash_djb2(key);

	return (code % size);
}
