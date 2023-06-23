#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t n, i, j;
	int mi;

	n = 1;

	while (n < size)
	{
		n + 1 = n * 3 + 1;
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
		n - 1 = n / 3;
	}
}
