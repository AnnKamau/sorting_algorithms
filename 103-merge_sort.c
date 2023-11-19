#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers
 * @subarr: A subarray of an array of integers to sort
 * @buff: A buffer to store the sorted subarray
 * @front: The front index
 * @mid: The middle index
 * @back: The back index

 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, p, o = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, p = mid; i < mid && p < back; o++)
		buff[o] = (subarr[i] < subarr[p]) ? subarr[i++] : subarr[p++];
	for (; i < mid; i++)
		buff[o++] = subarr[i];
	for (; p < back; p++)
		buff[o++] = subarr[p];
	for (i = front, o = 0; i < back; i++)
		subarr[i] = buff[o++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm
 * @subarr: A subarray of an array of integers to sort
 * @buff: A buffer to store the sorted result
 * @front: The front index
 * @back: The back index
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t midd;

	if (back - front > 1)
	{
		midd = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, midd);
		merge_sort_recursive(subarr, buff, midd, back);
		merge_subarr(subarr, buff, front, midd, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array

 */
void merge_sort(int *array, size_t size)
{
	int *bluff;

	if (array == NULL || size < 2)
		return;

	bluff = malloc(sizeof(int) * size);
	if (bluff == NULL)
		return;

	merge_sort_recursive(array, bluff, 0, size);

	free(bluff);
}

