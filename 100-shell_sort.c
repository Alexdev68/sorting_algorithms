#include "sort.h"

/**
 * shell_sort - This function implements the shell sort algorthim knuth's
 * sequence
 * @array: This is a list of integers
 * @size: This is the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, j;
	int mi;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (n = n * 3 + 1; n > 0; n /= 3)
	{
		for (i = n; i < size; i++)
		{
			mi = array[i];

			j = i;
			while (array[j - n] > mi && j >= n)
			{
				array[j] = array[j - n];

				j -= n;

			}
			array[j] = mi;
		}
		print_array(array, size);
	}
}
