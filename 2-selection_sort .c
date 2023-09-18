#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp;

    if (!array || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        // Assume the current element is the minimum
        min_idx = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        // If the minimum element is not the current element, swap them
        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;

            // Print the array after each swap
            print_array(array, size);
        }
    }
}
