#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s, *s2, *s3, *s4, *s5, *s6;
    unsigned long int hash_table_array_size;

    hash_table_array_size = 1024;
    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));

    s = "hetairas";
    s2 = "mentioner";
    s3 = "heliotropes";
    s4 = "neurospora";
    s5 = "dram";
    s6 = "vivency";
    printf("%lu, %lu\n", key_index((unsigned char *)s, hash_table_array_size), key_index((unsigned char *)s2, hash_table_array_size));

    printf("%lu, %lu\n", key_index((unsigned char *)s3, hash_table_array_size), key_index((unsigned char *)s4, hash_table_array_size));

    printf("%lu, %lu\n", key_index((unsigned char *)s5, hash_table_array_size), key_index((unsigned char *)s6, hash_table_array_size));
    return (EXIT_SUCCESS);
}
