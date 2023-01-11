#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t dlistint_len2(const dlistint_t *h);


/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: the first node
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node of a dlistint_t linked list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int list_len, n;
	dlistint_t *nth_node, *temp;

	temp = head;
	list_len = dlistint_len2(head);
	if (index >= list_len)
	{
		return (NULL);
	}

	for (n = 0; n <= index; n++)
	{
		nth_node = temp;
		temp = temp->next;
	}

	return (nth_node);
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
