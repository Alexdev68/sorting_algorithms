#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - This function implements the counting sorting algorithm
 * @array: This is an list of integers
 * @size : This is the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *sorted, *count, i, max_val;
	size_t j;

	sorted = malloc(sizeof(int) * size);

	max_val = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max_val)
		{
			max_val = array[j];
		}
	}

	count = malloc(sizeof(int) * (max_val + 1));

	for (i = 0; i <= max_val; i++)
	{
		count[i] = 0;
	}

	for (j = 0; j < size; ++j)
	{
		++count[array[j]];
	}

	for (i = 1; i <= max_val; ++i)
	{
		count[i] += count[i - 1];
	}
	print_array(count, max_val + 1);

	for (i = size - 1; i >= 0; --i)
	{
		sorted[count[array[i]]- 1] = array[i];
		--count[array[i]];
	}

	for (j = 0; j < size; ++j)
	{
		array[j] = sorted[j];
	}

	free(count);
	free(sorted);
}
