#include "main.h"
#include <stdio.h>

/**
 * _strspn - searches s from the start for only the occurence of accept
 * @s: string to search in
 * @accept: set of characters only allowed to be found in initial segment of s
 *
 * Return:  the number of bytes in the initial segment of s which consist
 * only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int j, flag = 0;
	unsigned int i;

	/*traverse through each character of s*/
	for (i = 0; *(s + i); i++)
	{
		/*traverse through each character of accept...*/
		for (j = 0; j < _strlen(accept); j++)
		{
			/*...and indicate if it is equal to the current*/
			/*character of s*/
			if (*(s + i) == *(accept + j))
			{
				flag = 1;
			}
		}
		/*return current value of i if current*/
		/*character of s matches none of the characters of accept*/
		if (flag == 0)
		{
			return (i);
		}
		flag = 0;
	}
	return (i);
}
