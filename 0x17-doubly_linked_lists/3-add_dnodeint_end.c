#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_dnodeint_end -  adds a new node at the end of a dlistint_t list.
 * @head: a double pointer representing the address of the head of the list
 * @n: the integer to initialize the new node with
 *
 * Return: a pointer to the new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *temp = *head;
	/* temp is used so as not to change the address *head points to */

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;		/* new node is now pointing to NULL */

	if (dlistint_len(*head) == 0)
	{
		new->prev = NULL;
		*head = new;		/*new node now head node, if it's the first node of the list*/
	}
	else
	{
		for (; temp; temp = (temp)->next)
		{
			if ((temp)->next == NULL)	/*when we reach the previous tail of the list...*/
			{
				(temp)->next = new;	/* ...let it point to the new tail */
				new->prev = temp;
				break;
			}
		}
	}

	return (new);
}



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
