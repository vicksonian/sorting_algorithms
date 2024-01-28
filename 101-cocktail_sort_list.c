#include "sort.h"
/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
*                      order using the Cocktail Shaker sort algorithm
*
* @list: Pointer to the head of the doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
do {
swapped = 0;
/* Forward pass */
for (current = *list; current->next != NULL; current = current->next)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
}
if (swapped == 0)
break;
swapped = 0;
/* Backward pass */
for (; current->prev != NULL; current = current->prev)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
}
} while (swapped);
}
/**
* swap_nodes - Swaps two nodes in a doubly linked list
*
* @list: Pointer to the head of the doubly linked list
* @a: First node to swap
* @b: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
if (a->prev != NULL)
a->prev->next = b;
else
*list = b;
if (b->next != NULL)
b->next->prev = a;
a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}
