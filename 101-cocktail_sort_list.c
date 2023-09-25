#include "sort.h"

/**
 * swap - swaps two nodes
 * @first_node: first node to swap
 * @second_node: second node to swap
 * @list: list to set null or not
 */
void swap(listint_t *first_node, listint_t *second_node, listint_t **list)
{
if (!(first_node->prev))
{
first_node->next = second_node->next;
if (second_node->next)
second_node->next->prev = first_node;
second_node->next = first_node;
second_node->prev = NULL;
first_node->prev = second_node;
*list = second_node;
}
else
{
second_node->prev->next = second_node->next;
if (second_node->next)
second_node->next->prev = second_node->prev;
first_node->prev->next = second_node;
second_node->prev = first_node->prev;
first_node->prev = second_node;
second_node->next = first_node;
}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using Cocktail Shaker sort algorithm
 * @list: Pointer to pointer to doubly linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tmp, *next_node;
int swapped;

if (list == NULL || !(*list) || (*list)->next == NULL)
return;

swapped = 1;

while (swapped)
{
swapped = 0;
tmp = *list;

while (tmp->next)
{
next_node = tmp->next;
if (tmp->n > next_node->n)
{
swap(tmp, next_node, list);
swapped = 1;
print_list((*list));
}
else
tmp = tmp->next;
}
if (!swapped)
break;
swapped = 0;

while (tmp->prev)
{
next_node = tmp->prev;
if (tmp->n < next_node->n)
{
swap(next_node, tmp, list);
swapped = 1;
print_list((*list));
}
else
tmp = tmp->prev;
}
}
}
