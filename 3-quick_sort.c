#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    size_t i, j, pivot;
    int tmp;

    /* If array is NULL or size is less than 2, do nothing */
    if (array == NULL || size < 2)
        return;
    /* Loop through the array and compare each element to the next */
    for (i = 0; i < size - 1; i++)
    {
        pivot = i;
        /* If the element is greater than the next, swap them */
        for (j = i + 1; j < size; j++)
        {
            /* Print the array after each swap */
            if (array[j] < array[pivot])
            {
                tmp = array[pivot];
                array[pivot] = array[j];
                array[j] = tmp;
                print_array(array, size);
            }
        }
    }
}
