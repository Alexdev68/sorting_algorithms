#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - This function/whole program implements the bitonic sort
 * @array: This is a list of integers
 * @size: This is the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	bitosort(array, 0, size, 1);
}

/**
 * bitosort - This function/whole program implements the bitonic sort algorithm
 * @arr: This is a list of integers
 * @sml: This is the initial index
 * @bitsiz: This is the size of the array
 * @dest: This is the destination whether increasing or decreasing. 1 or 0
 */
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
		printf("Result [%d/16] (%s):\n", bitsiz
				, (dest == 1) ? "UP" : "DOWN");
		print_array(&arr[sml], bitsiz);
	}
}

/**
 * merge - This function/whole program implements the bitonic sort algorithm
 * @arr: This is a list of integers
 * @sml: This is the initial index
 * @bitsiz: This is the size of the array
 * @dest: This is the destination whether increasing or decreasing. 1 or 0
 */
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

/**
 * compswap - This function compares values of the arr then swaps them
 * @arr: This is a list of integers
 * @a: This is an index to be used with the arr for comparison and swapping
 * @b: This is an index to be used with the arr for comparison and swapping
 * @dest: This is the destination whether increasing or decreasing. 1 or 0
 */
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
