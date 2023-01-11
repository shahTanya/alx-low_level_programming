#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
size_t dlistint_len2(const dlistint_t *h);
void pop_dlistint2(dlistint_t **head);



/**
 * delete_dnodeint_at_index - deletes
 * the node at index index of a dlistint_t linked list.
 * @head: holds the address of the pointer to the first node
 * @index: the index at which to delete the node/structure
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t  *temp, *temp2;
	unsigned int list_len;
	long int i;

	list_len = dlistint_len2(*head);
	if (index >= list_len || list_len == 0)
	{
		return (-1);
	}

	temp = *head;
	if (index > 0)
	{
		for (i = 0; i < (long int)index; i++)
		{
			/**
			 * By the end of this loop, temp2 will hold the address
			 * of the node before the index position, and temp will
			 * hold the address of the struct currently at the index position
			 */
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next;	/* struct at temp2 now points two structs ahead */
		if (temp->next)			/* temp not tail of list */
			temp->next->prev = temp2;
		free(temp);			/* frees the memory allocated to the deleted struct */
	}
	else if (index == 0)			/* if first node is to be deleted */
	{
		pop_dlistint2(head);
	}
	return (1);
}


/**
 * pop_dlistint2 - deletes the head node of a dlistint_t linked list.
 * @head: a pointer storing the address of the pointer to the list head
 */
void pop_dlistint2(dlistint_t **head)
{
	dlistint_t *head_cpy;

	if (dlistint_len2(*head) != 0)
	{
		head_cpy = *head; /* collect the address to free */

		/* change the head */
		*head = (*head)->next;
		if (*head)
		{
			(*head)->prev = NULL;
		}

		/* free previous head */
		free(head_cpy);
	}
}


/**
 * dlistint_len2 - determines number of elements of the structure dlistint_s
 * @h: the head of a structure of type 'struct dlistint_s'
 *
 * Return: the number of nodes in the list
 */
size_t dlistint_len2(const dlistint_t *h)
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
