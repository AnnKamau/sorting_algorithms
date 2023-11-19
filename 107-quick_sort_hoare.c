#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in array
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
 * hoare_partition - Order a subset of an array of integers
 * @array: The array of integers
 * @size: The size of array
 * @left: The starting index
 * @right: The ending index
 * Return: The final partition index

 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, upper, below;

	pivot = array[right];
	for (upper = left - 1, below = right + 1; upper < below;)
	{
		do {
			upper++;
		} while (array[upper] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (upper < below)
		{
			swap_ints(array + upper, array + below);
			print_array(array, size);
		}
	}

	return (upper);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index
 * @right: The ending index

 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int parts;

	if (right - left > 0)
	{
		parts = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, parts - 1);
		hoare_sort(array, size, parts, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of array
 
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

