#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t linked list
 * @head: pointer to the first node of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp2, *temp = head;

	for (; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp);
	}
}
