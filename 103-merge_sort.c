#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * PrintArray - Prints array of integers for range of indicies
 * @array: Array of values to be printed
 * @start: Starting index value
 * @end: Ending index value
 */
void PrintArray(int *array, int start, int end)
{

	int i;

	for (i = start; array && i < end; i++)
	{
		if (i > start)
		{
			printf(", ");
		}
		printf("%d", array[i]);
	}

	printf("\n");
}


/**
 * CopyArray - Simple 1 for 1 copy of source[] to sotint[]
 * @source: Array of values to be sorted
 * @start: starting index value
 * @end: ending index value
 * @sotint: array to store sorted integers
 */
void CopyArray(int *source, int start, int end, int *sotint)
{
	int i;

	for (i = start; i < end; i++)
		sotint[i] = source[i];
}

/**
 * AscendMerge - Sorts subsections of source[] by ascending value
 * @source: Array of values to be sorted
 * @start: Left run starting index value
 * @mid: Right run starting index value
 * @end: Right run ending index value
 * @sotint: Array to store sorted integers
 */
void AscendMerge(int *source, int start, int mid, int end, int *sotint)
{
	int x, y, z;

	x = start, y = mid;

	printf("Merging...\n");
	printf("[left]: ");
	PrintArray(source, start, mid);
	printf("[right]: ");
	PrintArray(source, mid, end);
	/* While there are elements in the left or right  */
	for (z = start; z <= end; z++)
	{
		/* If left run head exists and is <= existing right run head */
		if (x < mid && (y >= end || source[x] <= source[y]))
		{
			sotint[z] = source[x];
			x++;
		}
		else
		{
			sotint[z] = source[y];
			y++;
		}
	}

	for (z = start; z <= end; z++)
	{
		source[z] = sotint[z];
	}
	printf("[Done]: ");
	PrintArray(sotint, start, end);
}

/**
 * AscendSplitMerge - recursive engine of merge_sort, splits working copy of
 * array into left and right runs, then merges with AscendMerge
 * @source: Array of integers to be sorted
 * @start: Starting index value
 * @end: Ending index value
 * @sotint: Array to store sorted integers
 */
void AscendSplitMerge(int *source, int start, int end, int *sotint)
{
	int mid;

	if (end - start < 2) /* if run size == 1 */
		return;     /* consider it sorted */
	/* split the run longer than 1 item into halves */
	mid = (end + start) / 2;

	AscendSplitMerge(sotint, start, mid, source);  /* sort left run */
	AscendSplitMerge(sotint, mid, end, source);  /* sort right run */
	/* merge the resulting runs from array[] into work_copy[] */
	AscendMerge(source, start, mid, end, sotint);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using a
 * top-down merge sort algorithm
 * @array: Array of integers to be sorted
 * @size: Amount of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *work_copy;

	if (!array || size < 2)
		return;

	work_copy = malloc(sizeof(int) * size);
	if (!work_copy)
		return;

	CopyArray(array, 0, size - 1, work_copy);
	AscendSplitMerge(work_copy, 0, size, array);

	free(work_copy);
}
