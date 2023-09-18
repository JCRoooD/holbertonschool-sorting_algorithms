#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	/* If array is NULL or size is less than 2, do nothing */
	if (array == NULL || size < 2)
		return;
	/* Loop through the array and compare each element to the next */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* If the element is greater than the next, swap them */
		for (j = i + 1; j < size; j++)
		{
			/* Print the array after each swap */
			if (array[j] < array[min])
				min = j;
		}
		if (min != i) /* If the minimum is not the current element, swap */
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
