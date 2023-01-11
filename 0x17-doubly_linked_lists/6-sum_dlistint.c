#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - returns sum of all the data (n) of a dlistint_t linked list
 * @head: pointer to the first node/struct
 *
 * Return: the sum of all the data (n) of a dlistint_t linked list.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;
	dlistint_t *temp;

	sum = 0;
	temp = head;
	for (; temp; temp = temp->next)
	{
		sum += temp->n;
	}

	return (sum);
}
