#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search in
 * @accept: set of characters/bytes to match
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	/*traverse through each character of s*/
	for (i = 0; *(s + i); i++)
	{
		/*traverse through each character of accept...*/
		for (j = 0; j < _strlen(accept); j++)
		{
			/*...and returns the address of the byte*/
			/*that matches any character of accept*/
			if (*(s + i) == *(accept + j))
			{
				return (s + i);
			}
		}
	}

	return (NULL);
}
