#include "main.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: memory area to be filled
 * @src: src from which to copy bytes
 * @n: integer determining number of bytes (characters) to be copied
 *
 * Return: a pointer to the modified buffer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}

	return (dest);
}
