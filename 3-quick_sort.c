#include "sort.h"

/**
 * swap - swaps two intgers
 * @a: first integer
 * @b: second integer
 *
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
 * lomuto_partition - sorts an array of integers using Lomuto partition scheme
 * @array: array of integers
 * @left: first index of the subset
 * @right: last index of the subset
 * @size: Size of the array
 * Return: An integer
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int *piv, abv, bel;

	piv = array + right;
	for (abv = bel = left; bel < right; bel++)
	{
		if (array[bel] < *piv)
		{
			if (abv < bel)
			{
				swap(array + bel, array + abv);
				print_array(array, size);
			}
			abv++;
		}
	}

	if (array[abv] > *piv)
	{
		swap(array + abv, piv);
		print_array(array, size);
	}

	return (abv);
}

/**
 * sort - Recursive function for the quicksort algorithm
 * @array: array of integers
 * @left: first index of the subset
 * @right: last index of the subset
 * @size: Size of the array
 */
void sort(int *array, int left, int right, size_t size)
{
	int i;

	if (right - left > 0)
	{
		i = lomuto_partition(array, left, right, size);
		sort(array, left, i - 1, size);
		sort(array, i + 1, right, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}
