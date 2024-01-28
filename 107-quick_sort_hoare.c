#include "sort.h"
/**
* quick_sort_hoare - Sorts an array of integers in ascending order using
*                    the Quick sort algorithm with Hoare partition scheme.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
hoare_partition(array, size, 0, size - 1);
}
/**
* hoare_partition - Implements the Hoare partition scheme for Quick sort.
* @array: The array to be sorted.
* @size: The size of the array.
* @low: The low index of the partition.
* @high: The high index of the partition.
*/
void hoare_partition(int *array, size_t size, int low, int high)
{
int pivot, i, j;
if (low < high)
{
pivot = array[high];
i = low - 1;
j = high + 1;
while (1)
{
do
{
i++;
} while (array[i] < pivot);
do
{
j--;
} while (array[j] > pivot);
if (i < j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
else
{
break;
}
}
hoare_partition(array, size, low, j);
hoare_partition(array, size, j + 1, high);
}
}
/**
* swap - Swaps two elements in an array.
* @a: Pointer to the first element.
* @b: Pointer to the second element.
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
