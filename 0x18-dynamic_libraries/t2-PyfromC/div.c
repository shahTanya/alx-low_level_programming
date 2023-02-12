#include "main.h"

/**
 * div - divides a by b.
 * @a: a long int.
 * @b: a long int.
 *
 * Return: the quotient of a / b.
 */
long int div(long int a, long int b)
{
	if (b < 0)
	{
		return (a);
	}

	return (a / b);
}
