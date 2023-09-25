#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorting function following the bubble sort algorithm
 * @array: Unsorted array
 * @size: Size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j, tmp;

for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
print_array(array, size);
}
}
}
}
