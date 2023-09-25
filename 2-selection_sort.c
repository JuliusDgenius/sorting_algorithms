#include "sort.h"

/**
 * swap - swaps values in an array
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * selection_sort - function that sorts an array of integers
 * using selection sort
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, n, k;

	for (i = 0; i < size - 1; i++)
	{
		for (n = size - 1, k = i + 1; n > i; n--)
		{
			if (array[n] < array[k])
				k = n;
		}
		if (array[i] > array[k])
		{
			swap(&array[i], &array[k]);
			print_array(array, size);
		}
	}
}
