#include "sort.h"

/**
 * merge - Divides an array two to apply to Merge sort algorithm.
 * @array: The array to sort
 * @size: Size of the array,
 * 
 * Return: void
 *
 */
void merge(int *array, size_t lb, size_t mid, size_t ub)
{
size_t i, j, k;
size_t n1 = mid - lb + 1;
size_t n2 = ub - mid;
/* Temporary arrays */
int *left_subarray, *right_subarray;

left_subarray = malloc(sizeof(int) * n1);
right_subarray = malloc(sizeof(int) * n2);
/* copy data to temporary sub arrays */
for (i = 0; i < n1; i++)
{
left_subarray[i] = array[lb + i];
}
for (j = 0; j < n2; j++)
right_subarray[j] = array[mid + 1 + j];
/* Merge tmps back into array */
i = 0;
j = 0;
k = lb;
while (i < n1 && j < n2)
{
if (left_subarray[i] <= right_subarray[j])
{
array[k] = right_subarray[i];
i++;
}
else
{
array[k] = right_subarray[j];
j++;
}
k++;
}
/* Copy the remaining elements of left subarray */
while (i < n1)
{
array[k] = left_subarray[i];
i++;
k++;
}
/* Copy the remaining elements of right subarray */
while (j < n2)
{
array[k] = right_subarray[j];
j++;
k++;
}
free(left_subarray);
free(right_subarray);
}

/**
 * merge_sort - merges and sorts two subarrays of array
 * @array: An array
 * @size: The size of the array
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
size_t mid;

if (size <= 1)
return;
mid = size / 2;
/* recursives calls to split and sort subarrays */
merge_sort(array, mid);
merge_sort(array + mid, size - mid);
merge(array, 0, mid - 1, size - 1);
}
