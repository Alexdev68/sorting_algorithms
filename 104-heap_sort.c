#include "sort.h"

/**
 * heap_sort - This function implements the shift down heap sort algorithm
 * @array: This is a list of integers
 * @size: This is the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = size / 2 - 1; i >= 0; i--)
	{
		Max_heapify(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);

		Max_heapify(array, i, 0, size);
	}
}

/**
 * Max_heapify - This function creates a max heap
 * @arr: This is the list of integers
 * @hsize: This is the heap size
 * @idx: This is an index int the arr[]
 * @siz: This is full size of the array for the purpose of printing
 */
void Max_heapify(int *arr, size_t hsize, int idx, size_t siz)
{
	int max = idx;
	size_t L = 2 * idx + 1;
	size_t R = 2 * idx + 2;
	int tp;

	if (arr[L] > arr[max] && L < hsize)
	{
		max = L;
	}

	if (arr[R] > arr[max] && R < hsize)
	{
		max = R;
	}

	if (max != idx)
	{
		tp = arr[idx];
		arr[idx] = arr[max];
		arr[max] = tp;
		print_array(arr, siz);

		Max_heapify(arr, hsize, max, siz);
	}
}
