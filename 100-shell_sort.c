#include "sort.h"

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
 * shell_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array

 */
void shell_sort(int *array, size_t size)
{
	size_t gape, k, l;

	if (array == NULL || size < 2)
		return;

	for (gape = 1; gape < (size / 3);)
		gape = gape * 3 + 1;

	for (; gape >= 1; gape /= 3)
	{
		for (k = gape; k < size; k++)
		{
			l = k;
			while (l >= gape && array[l - gape] > array[l])
			{
				swap_ints(array + l, array + (l - gape));
				l -= gape;
			}
		}
		print_array(array, size);
	}
}
