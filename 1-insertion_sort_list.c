@@ -8,16 +8,13 @@ void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	node = (*list)->next;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while (node->prev)
		while ((node->prev) && (node->prev->n > node->n))
		{
			if (node->prev->n <= node->n)
				break;
			node = swap_node(node, list);
			print_list(*list);
		}
@@ -32,18 +29,18 @@ void insertion_sort_list(listint_t **list)
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *noderent = node;
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	if (back->prev)
		back->prev->next = noderent;
	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = noderent;
	if (noderent->next)
		noderent->next->prev = back;
	back->next = noderent->next;
	noderent->prev = back->prev;
	noderent->next = back;
	back->prev = noderent;

	return (noderent);
		*list = current;
	return (current);
}
 55 changes: 55 additions & 0 deletions55  
100-shell_sort.c
@@ -0,0 +1,55 @@
#include "sort.h"

/**
*swap - The positions of two elements into an array
*@array: Array
*@item1: Array element
*@item2: Array element
*/
void swap(int *array, int item1, int item2)
{
    int temp;

    temp = array[item1];
    array[item1] = array[item2];
    array[item2] = temp;
}
/**
*swap - The positions of two elements into an array
*@array: Array
*@item1: Array element
*@item2: Array element
*/
int less(int item1, int item2)
{
    if (item1 < item2)
        return 1;
    return 0;
}
/**
 * shell_sort - Function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{

    size_t space = 0, i, j = 0;

    while (space < size / 3)
    {
        space = 3 * space + 1;
    }

    while (space >= 1)
    {
        for (i = space; i < size; i++)
        {
            for (j = i; j >= space && less(array[j], array[j-space]); j -= space)
                swap(array, j, j-gap);
        }
        print_array(array, size);
        space /= 3;
    }
}
