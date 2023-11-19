#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of array
 * Return: The maximum integer in the array

 */
int get_max(int *array, int size)
{
	int maximum, h;

	for (maximum = array[0], h = 1; i < size; h++)
	{
		if (array[h] > maximum)
			maximum = array[h];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of array
 
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

