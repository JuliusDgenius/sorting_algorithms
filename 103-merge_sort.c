#include "sort.h"

/**
 * print_left_and_right - Prints left and right partition of the array
 * @array: The array
 * @size: Size of the second array
 * @lb: lower bound of array
 * @mid: midpoint of array
 * Return: void
 */
void print_left_and_right(int *array, int size, int lb, int mid)
{
int k;

printf("Merging...\n");
printf("[left]: ");
for (k = lb; k < mid; k++)
{
if (k != mid - 1)
printf("%d, ", array[k]);
else
printf("%d\n", array[k]);
}

printf("[right]: ");
k = mid;
while (k < size)
{
if (k < size - 1)
printf("%d, ", array[k]);
else
printf("%d\n", array[k]);
k++;
}
}

/**
 * merge - Divides an array two to apply to Merge sort algorithm.
 * @array: The array to sort
 * @size: Size of the array
 * @lb: lower bound of array
 * @mid: midpoint of the array
 * @cpy: copy of the array
 *
 * Return: void
 *
 */
void merge(int *array, int size, int lb, int mid, int *cpy)
{
int i, j, k;

/* Print left sub array */
print_left_and_right(array, size, lb, mid);

i = lb;
j = mid;

printf("[Done]: ");
for (k = lb; k < size; k++)
{
if (i < mid && (j >= size || array[i] <= array[j]))
{
cpy[k] = array[i];
i++;
}
else
{
cpy[k] = array[j];
j++;
}
if (k < size - 1)
printf("%d, ", cpy[k]);
k++;
}
}

/**
 * mergeSort - merges and sorts two subarrays of array
 * @array: An array
 * @size: The size of the array
 * @cpy: Pointer to hold array copy
 * @lb: lower bound of array
 *Return: void
 */
void mergeSort(int *cpy, int lb, size_t size, int *array)
{
int mid;

if (size - lb < 2) /* Check if array has more than 1 element */
return;
mid = (size + lb) / 2;

/* recursive calls to split and sort subarrays */
mergeSort(array, lb, mid, cpy);
mergeSort(array, mid, size, cpy);
/* Merge the subarrays */
merge(cpy, size, lb, mid, array);
}

/**
 * copy_array - Makes a copy of given array
 * @array: array given
 * @cpy: Array output copy
 * @size: Size of the array
 * Return: void
 */
void copy_array(int *array, int *cpy, int size)
{
int i;

for (i = 0; i < (int)size; i++)
cpy[i] = array[i];
}

/**
 * merge_sort - Makes subarrays, merge and them to sort
 * @array: Array to sort
 * @size: Size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
int *cpy;

cpy = malloc(sizeof(int) * size - 1);

if (cpy == NULL)
return;
copy_array(array, cpy, size);

mergeSort(cpy, 0, size, array);
free(cpy);
}
