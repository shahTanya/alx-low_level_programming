#include "search_algos.h"
#include <math.h>

int _min(int num1, int num2);
listint_t *node_at(listint_t *start, int distance);


/**
 * jump_list - searches for a value in a
 * sorted list of integers using the Jump search algorithm.
 * @list: a pointer to the head of the list to search in.
 * @size: the number of nodes in list.
 * @value: the value to search for.
 *
 * Return: a pointer to the first node where value is
 * located, or NULL of value not present or list head is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	int flag = 1, block = sqrt((int)size), prev_idx = 0, curr_idx = block;
	listint_t *pprev_node, *prev_node, *curr_node;

	(void)pprev_node;

	if (!list)
	{
		return (NULL);
	}

	prev_node = list;
	curr_node = node_at(list, curr_idx);

	/* Iterate until current idx value is >= search key */
	while (
			(node_at
			 (prev_node, (_min(curr_idx, size) - 1) - prev_node->index))->n < value)
	{
		if (curr_idx != (int)size && curr_node->n == value)
		{
			break;
		}
		if (curr_idx >= (int)size)
		{
			break;
		}
		pprev_node = prev_node;
		prev_idx = curr_idx;
		curr_idx = curr_idx + block;
		prev_node = curr_node;
		curr_node = node_at(curr_node, (curr_idx - curr_node->index));
		if (prev_idx < (int)size)
		{
			printf("Value checked at index [%d] = [%d]\n", prev_idx, prev_node->n);
		}
	}

	if (curr_idx < (int)size)
	{
		printf("Value checked at index [%d] = [%d]\n", curr_idx, curr_node->n);
	}
	if (curr_idx >= (int)size)
	{
		printf(
				"Value checked at index [%d] = [%d]\n",
				(int)size - 1, node_at(list, size - 1)->n);
	}

	/* Answer, or last, block linear search */
	while (prev_node->n < value)
	{
		if (flag)
		{
			flag = 0;
			if (curr_idx >= (int)size)
			{
				printf(
						"Value found between indexes [%d] and [%d]\n", prev_idx, (int)size - 1);
			}
			else
			{
				printf(
						"Value found between indexes [%d] and [%d]\n", prev_idx, curr_idx);
			}
		}

		if (prev_idx < (int)size)
		{
			printf("Value checked at index [%d] = [%d]\n", prev_idx, prev_node->n);
		}
		prev_idx++;
		prev_node = node_at(prev_node, 1);

		if (prev_idx >= _min(curr_idx, size))
		{
			return (NULL);
		}
	}

	if (prev_node->n == value)
	{
		if (prev_idx < (int)size)
		{
			printf("Value checked at index [%d] = [%d]\n", prev_idx, prev_node->n);
		}
		return (prev_node);
	}

	return (NULL);
}


/**
 * node_at - returns the node at the specified list index.
 * @start: the node to start search from.
 * @distance: number of nodes between @start and target node.
 *
 * Return: the target node.
 */
listint_t *node_at(listint_t *start, int distance)
{
	int i;
	listint_t *target;


	target = start;
	for (i = 0; i < distance; i++)
	{
		target = target->next;
	}

	return (target);
}



/**
 * _min - returns the minimum of two integers.
 * @num1: an integer.
 * @num2: an integer.
 *
 * Return: the least between @num1 and @num2.
 */
int _min(int num1, int num2)
{
	int min;

	min = num1 > num2 ? num2 : num1;

	return (min);
}
