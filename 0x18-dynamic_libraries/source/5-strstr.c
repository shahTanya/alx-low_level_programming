#include "main.h"

/**
 * _strstr - finds the first occurrence of the substring needle in
 * the string haystack
 * @haystack: string to search in
 * @needle: sub-string to match
 *
 * Return: a pointer to the beginning of the located substring, or NULL if
 * the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, first, count = 0;

	if (*needle == '\0')
		return (haystack);
	/*start traversing haystack*/
	for (i = 0; *(haystack + i); i++)
	{
		j = 0;
		/*once a match is found between the current haystack*/
		/*character and the first character of needle...*/
		if (*(haystack + i) == *(needle + 0))
		{
			first = i;
			count++;
			/*...continuously check for matches between*/
			/*corresponding characters of haystack and needle*/
			for (i++; *(haystack + i) && count; i++)
			{
				j++;
				if (count == (_strlen(needle)))
					return (haystack + first);

				if (*(haystack + i) == *(needle + j))
				{
					count++;
					if (count == (_strlen(needle)))
						return (haystack + first);
				}
				else
				{
					/*if any match fails, reset count,*/
					/*and thus cause the loop to exit*/
					count = 0;
				}
			}
		}
	}

	return (NULL);
}
