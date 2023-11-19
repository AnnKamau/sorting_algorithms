#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of array
 * Return: The maximum integer in the array.

 */
int get_max(int *array, int size)
{
	int maximum, h;

	for (maximum = array[0], h = 1; h < size; h++)
	{
		if (array[h] > maximum)
			maximum = array[h];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array

 */
void counting_sort(int *array, size_t size)
{
	int *add, *sorted, maximum, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_max(array, size);
	add = malloc(sizeof(int) * (maximum + 1));
	if (add == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		add[i] = 0;
	for (i = 0; i < (int)size; i++)
		add[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		add[i] += add[i - 1];
	print_array(add, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[add[array[i]] - 1] = array[i];
		cadd[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(add);
}

