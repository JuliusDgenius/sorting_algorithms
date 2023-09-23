#include "sort.h"

/**
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
