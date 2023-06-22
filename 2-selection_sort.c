#include "sort.h"
#include <stdbool.h>

/**
 * selection_sort - This function implements the selection sort algorithm
 * @array: This is a list of unsorted integers
 * @size: This is the number of elements of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minim;

	for (i = 0; i < size - 1; i++)
	{
		minim = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minim])
			{
				minim = j;
			}
		}

		if (minim != i)
		{
			int t;
			t = array[i];
			array[i] = array[minim];
			array[minim] = t;
			print_array(array, size);
		}
	}
}
