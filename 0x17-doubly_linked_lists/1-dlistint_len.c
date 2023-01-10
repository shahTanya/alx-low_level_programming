#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len - determines the number of elements of the structure dlistint_s
 * @h: the head of a structure of type 'struct dlistint_s'
 *
 * Return: the number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t n = 0;
	dlistint_t *temp;

	temp = (dlistint_t *)h;
	for (; temp; temp = temp->next)
	{
		n++;
	}

	return (n);
}
