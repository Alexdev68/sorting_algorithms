#include "sort.h"
/**
*swap - The positions of two elements into an array
*@array: Array
*@item1: Array element
*@item2: Array element
*/
void swap(int *array, size_t item1, size_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: Array
 *@first: First array element
 *@last: Last array element
 *@size: Size array
 *Return: Return the position of the last element sorted
 */
int lomuto_partition(int *array, size_t first, size_t last, size_t size)
{
	int pvot = array[last];
	size_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pvot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - quicksort algorithm implementation
 *@array: Array
 *@first: First array element
 *@last: Last array element
 *@size: Array size
 */
void qs(int *array, size_t first, size_t last, int size)
{
	size_t psition = 0;


	if (first < last)
	{
		psition = lomuto_partition(array, first, last, size);

		qs(array, first, psition - 1, size);
		qs(array, psition + 1, last, size);
	}
}
/**
 *quick_sort - Prepare terrain to quicksort algorithm
 *@array: Array
 *@size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
