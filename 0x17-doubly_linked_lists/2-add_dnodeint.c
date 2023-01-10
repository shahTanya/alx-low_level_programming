#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_dnodeint -  adds a new node at the beginning of a dlistint_t list.
 * @head: a double pointer representing the address of the head of the list
 * @n: integer to initialize the new node with
 *
 * Return: a pointer to the new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;		/*new node is now pointing to what head is pointing to*/
	new->prev = NULL;

	if (*head)
	{
		(*head)->prev = new;
	}
	*head = new;			/*new node is now the head node*/

	return (*head);
}
