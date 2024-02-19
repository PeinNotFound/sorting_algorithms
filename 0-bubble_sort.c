#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: an Array of integers
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp;
	bool swapped;

	for (i = 0; i < size; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}