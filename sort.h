#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void quicksort(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

void PrintArray(int *array, int start,  int end);
void CopyArray(int *array, int end, int start, int *work_copy);
void AscendMerge(int *array, int iBeg, int iMid, int iEnd, int *work_copy);
void AscendSplitMerge(int *work_copy, int start, int end, int *array);

void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void Max_heapify(int *arr, size_t hsize, int idx, size_t siz);

void bitosort(int *arr, int sml, int bitsiz, int dest, int org_size);
void merge(int *arr, int sml, int bitsiz, int dest);
void compswap(int *arr, int a, int b, int dest);

#endif
