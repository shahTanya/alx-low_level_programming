#include "main.h"

/**
 * mod - returns the remainger when a is divided by b.
 * @a: a long int.
 * @b: a long int.
 *
 * Return: the remainder of a divided by b.
 */
long int mod(long int a, long int b)
{
	if (b < 0)
	{
		return (a);
	}

	return (a % b);
}
