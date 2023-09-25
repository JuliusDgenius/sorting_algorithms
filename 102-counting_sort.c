#include "sort.h"
#include <limits.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: Array of integers >= 0
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
int *count_array = malloc(sizeof(int) * (size + 1));
int *output_array = malloc(sizeof(int) * size);
size_t i;
int max = 0;

for (i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
/* Initialize count_array with zeros */
for (i = 0; (int)i <= max; i++)
count_array[i] = 0;
/* Count the occurrences of each number */
for (i = 0; i < size; i++)
++count_array[array[i]];
/* Calculate prefix sum */
for (i = 1; (int)i <= max; i++)
count_array[i] = count_array[i] + count_array[i - 1];
print_array(count_array, max + 1);
/* Buld the sorted output_array */
for (i = size - 1; (int)i >= 0; i--)
output_array[--count_array[array[i]]] = array[i];
/* Copy the sorted array back to the original array */
for (i = 0; i < size; i++)
{
array[i] = output_array[i];
}
free(count_array);
free(output_array);
}
