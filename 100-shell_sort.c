#include "sort.h"

/**
 * shell_sort - This function implements the shell sort algorthim knuth's
 * sequence
 * @array: This is a list of integers
 * @size: This is the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n, i, j;
	int mi;

	n = 1;

	while (n < size)
	{
		n = n * 3 + 1;
	}

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			mi = array[i];

			j = i;

			while (array[j - n] > mi && j >= n)
			{
				array[j] = array[j - n];

				j = j - n;

			}
			array[j] = mi;
		}
		n = n / 3;

		if (n <= 1)
			print_array(array, size);
	}
}
