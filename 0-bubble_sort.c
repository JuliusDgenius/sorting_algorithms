#include "sort.h"

/**
 * bubble_sort - sorting function following the bubble sort algorithm
 * @array: Unsorted array
 * @size: Size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;

for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
swap(&array[j], &array[j + 1]);
print_array(array, size);
}
}
}
}
