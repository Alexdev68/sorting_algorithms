#include "sort.h"

/**
 * partition - Scans a partition of an array of integers for values less than
 * pivot value, and swaps them with first value in partition, then swaps pivot
 * value with first value in partition.
 * @array: Array of integers to be sorted
 * @low: Index in array that begins partition
 * @high: Index in array that ends partition
 * @size: Amount of elements in array
 * Return: ew index at which to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int k, l, pivot, temp;

	pivot = array[high];
	k = low;
	for (l = low; l < high; l++)
	{
		if (array[l] < pivot)
		{
			temp = array[k];
			array[k] = array[l];
			array[l] = temp;
			if (array[k] != array[l])
				print_array(array, size);
			k++;
		}
	}
	temp = array[k];
	array[k] = array[high];
	array[high] = temp;
	if (array[k] != array[high])
		print_array(array, size);
	return (k);
}

/**
 * quicksort - Recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort.
 * @array: Array of integers to be sorted
 * @low: Index in array that begins partition
 * @high: Index in array that ends partition
 * @size: Amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int x;

	if (low < high)
	{
		x = partition(array, low, high, size);
		quicksort(array, low, x - 1, size);
		quicksort(array, x + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using a quick
 * sort algorithm, with Lomuto partition scheme.
 * @array: Array of integers to be sorted
 * @size: Amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
