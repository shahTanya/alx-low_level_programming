#include "main.h"



/**
 * _strncpy - copies src string to dest
 * @dest: pointer to string to be overwritten
 * @src: pointer to modifier string
 * @n: integer determining number of bytes (characters) to be copied
 *
 * Return: a pointer to the modified string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, h;

	if (n <= _strlen(src))
	{
		/*copy the required subset of src, and*/
		/*continue with the remaining dest characters*/
		for (h = 0; n > 0; h++)
		{
			*(dest + h) = *(src + h);
			n--;
		}
	}
	else
	{
		/*copy the characters of src, stopping at NULL*/
		for (i = 0; *(src + i); i++)
		{
			*(dest + i) = *(src + i);
		}
	}

	if (i < n)
	{
		/*src is exhausted; fill remaining required space*/
		/*with null characters*/
		for (; i < n; i++)
		{
			*(dest + i) = '\0';
		}
	}

	return (dest);
}
