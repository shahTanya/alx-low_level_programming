#include "search_algos.h"

void print_array(int *array, int l_idx, int r_idx);


/**
 * binary_search - searches for a value in a
 * sorted array of integers using the Binary search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in the array.
 * @value: the key to search for.
 *
 * Assumptions:
 * 1.) @array will be sorted in ascending order.
 * 2.) @value will not more than once in @array.
 *
 * Algorithm:
 * 1.) Set left_idx to 0 and right_idx to n-1.
 * 2.) If left_idx > right_idx, the search is unsuccessful. Return -1.
 * 3.) Set m (the index of the middle element)
 * to the floor of half of (left_idx + right_idx).
 * 4.) If value at index m is < @value, set left_idx to m+1 and go to step 2.
 * 5.) If value at index m is > @value, set right_idx to m-1 and go to step 2.
 * 6.) Now, the value at index m is equal to @value. Search done; return m.
 *
 * Return: the index where value is located,
 * or -1 if not present or array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
	int m, left_idx = 0, right_idx = (int)size - 1;

	if (!array)
	{
		return (-1);
	}

	while (left_idx <= right_idx)
	{
		printf("Searching in array: ");
		print_array(array, left_idx, right_idx);
		m = (left_idx + right_idx) / 2; /* the middle index of [sub]array */
		if (array[m] < value)
		{
			left_idx = m + 1;
		}
		else if (array[m] > value)
		{
			right_idx = m - 1;
		}
		else
		{
			/* Match found */
			return (m);
		}
	}

	return (-1);
}


/**
 * print_array - prints the passed array.
 * @array: pointer to the first element of the array to print.
 * @l_idx: the index in @array to start printing from.
 * @r_idx: the index in @array to stop printing at.
 */
void print_array(int *array, int l_idx, int r_idx)
{

	int i;

	for (i = l_idx; i <= r_idx; i++)
	{
		if (i == l_idx)
		{
			printf("%d", array[i]);
			continue;
		}
		printf(", %d", array[i]);
	}
	printf("\n");
}
