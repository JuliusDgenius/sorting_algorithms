#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: pointer to array to sort
 * @size: number of elements
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	short int swapped;
	int temp;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swapped = i;
				print_array(array, len);
			}
		}
		size = swapped;
	} while (size >= 1);
}
