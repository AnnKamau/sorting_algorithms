#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array
 * @a: The first integer
 * @b: The second integer

 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary
 * @array: An array of integers representing a binary tree
 * @size: The size of the array
 * @base: The index of the base row
 * @root: The root node
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of array

 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		max_heapify(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swap_ints(array, array + a);
		print_array(array, size);
		max_heapify(array, size, a, 0);
	}
}

