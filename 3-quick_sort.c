#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @a: the pointer to the first element
 * @b: the pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - the partitions an array using the Lomuto scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: an ending index of the partition
 * @size: the Number of elements in @array
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, int size)
{
	int *pivot, L, H;

	pivot = array + high;
	for (L = H = low; high > H; H++)
	{
		if (array[H] <= *pivot)
		{
			if (L != H)
			{
				swap(&array[H], &array[L]);
				print_array(array, size);
			}
			L++;
		}
	}

	if (array[L] > *pivot)
	{
		swap(&array[L], pivot);
		print_array(array, size);
	}

	return (L);
}

/**
 * quick_sort_recursive - Recursively sorts an array using
 * the Quick Sort algorithm
 *
 * @array: is the array to be sorted
 * @low: it's the starting index of the array
 * @high: an ending index of the array
 * @size: the number of elements in @array
 */
void quick_sort_recursive(int *array, int low, int high, int size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in
 * ascending order using the Quick Sort algorithm
 *
 * @array: is the array to be sorted
 * @size: the number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}