#include "search_algos.h"
#include <math.h>

int _min(int num1, int num2);


/**
 * jump_search - searches for a value in a
 * sorted array of integers using the Jump search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in the array.
 * @value: the key to search for.
 *
 * Assumptions:
 * 1.) @array will be sorted in ascending order.
 *
 * Algorithm: this works by first checking all items in the array at
 * index positions km, where k is the set of natural numbers starting from
 * 0 and m is the choosen block size (optimally, the sqrt of @size),
 * until an item is found that is larger than the search key, @value.
 * To find the exact position of the search key in the array,
 * a linear search is performed on the
 * sublist between the previous km index, and the current one.
 *
 * Return: the first index where value is
 * located, or -1 if not present or @array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	int flag = 1, block = sqrt((int)size), prev_idx = 0, curr_idx = block;

	printf("Value checked array[%d] = [%d]\n", prev_idx, array[prev_idx]);
	/* Iterate until current idx value is >= search key */
	while ((array[_min(curr_idx, size) - 1]) < value)
	{
		if (curr_idx != (int)size && array[curr_idx] == value)
		{
			break;
		}
		prev_idx = curr_idx;
		curr_idx = curr_idx + block;
		if (prev_idx < (int)size)
		{
			printf("Value checked array[%d] = [%d]\n", prev_idx, array[prev_idx]);
		}

		if (prev_idx >= (int)size)
		{
			prev_idx -= block;
			curr_idx -= block;
			break;
		}
	}


	/* Answer, or last, block linear search */
	while (array[prev_idx] < value)
	{
		if (flag)
		{
			flag = 0;
			printf(
					"Value found between indexes [%d] and [%d]\n", prev_idx, curr_idx);
		}
		if (prev_idx < (int)size)
		{
			printf("Value checked array[%d] = [%d]\n", prev_idx, array[prev_idx]);
		}
		prev_idx++;

		if (prev_idx > _min(curr_idx, size))
		{
			return (-1);
		}
	}

	if (array[prev_idx] == value)
	{
		if (prev_idx < (int)size)
		{
			printf("Value checked array[%d] = [%d]\n", prev_idx, array[prev_idx]);
		}
		return (prev_idx);
	}

	return (-1);
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
