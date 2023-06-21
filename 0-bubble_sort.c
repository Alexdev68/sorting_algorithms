#include "sort.h"

/**
 * bubble_sort - This function implements the bubble sort sorting algorithm
 * @array: This is an array of integers
 * @size: This is the number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}
