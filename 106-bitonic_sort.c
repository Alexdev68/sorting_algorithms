#include "sort.h"
#include <stdio.h>

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	bitosort(array, 0, size, 1);
}

void bitosort(int *arr, int sml, int bitsiz, int dest)
{
	int cd;

	if (bitsiz > 1)
	{
		cd = bitsiz / 2;

		printf("Merging [%d/16] (%s):\n", bitsiz
                                , (dest == 1) ? "UP" : "DOWN");
                print_array(&arr[sml], bitsiz);
		bitosort(arr, sml, cd, 1);
		bitosort(arr, sml + cd, cd, 0);
		merge(arr, sml, bitsiz, dest);
		printf("Merging [%d/16] (%s):\n", bitsiz
                                , (dest == 1) ? "UP" : "DOWN");
                print_array(&arr[sml], bitsiz);
	}
}

void merge(int *arr, int sml, int bitsiz, int dest)
{
	int i, cd;

	if (bitsiz > 1)
	{
		cd = bitsiz / 2;
		for (i = sml; i < sml + cd; i++)
		{
			compswap(arr, i, i + cd, dest);
		}
		merge(arr, sml, cd, dest);
		merge(arr, sml + cd, cd, dest);
	}
}

void compswap(int *arr, int a, int b, int dest)
{
	int temp;

	if ((dest == 1 && arr[a] > arr[b]) || (dest == 0 && arr[a] < arr[b]))
	{
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}
