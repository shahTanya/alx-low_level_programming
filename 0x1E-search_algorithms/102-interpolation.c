#include "search_algos.h"


/**
 * interpolation_search - searches for a value in a sorted
 * array of integers using the Interpolation search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in the array.
 * @value: the key to search for.
 *
 * Assumptions:
 * 1.) @array will be sorted in ascending order.
 *
 * Return: the first index where value is
 * located, or -1 if not present or @array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low_idx = 0, high_idx = (int)size - 1;
	size_t probe_idx;

	while (
			(array[high_idx] != array[low_idx]) &&
			(value >= array[low_idx]) &&
			(value <= array[high_idx]))
	{
		probe_idx = low_idx + (
				((double)(high_idx - low_idx) /
				 (array[high_idx] - array[low_idx])) *
				(value - array[low_idx]));

		printf("Value checked array[%d] = [%d]\n", (int)probe_idx, array[probe_idx]);
		if (array[probe_idx] < value)
		{
			low_idx = probe_idx + 1;
		}
		else if (value < array[probe_idx])
		{
			high_idx = probe_idx - 1;
		}
		else
		{
			return ((int)probe_idx);
		}
	}

	if (value == array[low_idx])
	{
		printf("Value checked array[%d] = [%d]\n", (int)probe_idx, array[probe_idx]);
		return (low_idx);
	}

	printf("Value checked array[%d] is out of range\n", (int)probe_idx);

	return (-1);
}
