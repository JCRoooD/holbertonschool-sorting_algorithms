#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: Array to be partitioned
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort_recursive - Recursively sorts an array using quicksort
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
