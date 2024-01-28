#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
* merge - Merges two subarrays of array[].
* @array: The array to be sorted.
* @left: Index of the leftmost element of the subarray.
* @middle: Index of the middle element of the subarray.
* @right: Index of the rightmost element of the subarray.
*/
void merge(int *array, size_t left, size_t middle, size_t right)
{
size_t i, j, k;
size_t n1 = middle - left + 1;
size_t n2 = right - middle;
int *left_array, *right_array;
/* Create temporary arrays */
left_array = malloc(n1 * sizeof(int));
right_array = malloc(n2 * sizeof(int));
if (left_array == NULL || right_array == NULL)
{
free(left_array);
free(right_array);
return;
}
/* Copy data to temporary arrays left_array[] and right_array[] */
for (i = 0; i < n1; i++)
left_array[i] = array[left + i];
for (j = 0; j < n2; j++)
right_array[j] = array[middle + 1 + j];
i = 0;
j = 0;
k = left;
/* Merge the temporary arrays back into array[left...right] */
while (i < n1 && j < n2)
{
if (left_array[i] <= right_array[j])
{
array[k] = left_array[i];
i++;
}
else
{
array[k] = right_array[j];
j++;
}
k++;
}
/* Copy the remaining elements of left_array[], if there are any */
while (i < n1)
{
array[k] = left_array[i];
i++;
k++;
}
/* Copy the remaining elements of right_array[], if there are any */
while (j < n2)
{
array[k] = right_array[j];
j++;
k++;
}
/* Print the merging step */
printf("[Done]: ");
print_array(array + left, right - left + 1);
/* Free allocated memory */
free(left_array);
free(right_array);
}
/**
* merge_sort_recursive - Recursive function to perform merge sort.
* @array: The array to be sorted.
* @left: Index of the leftmost element of the subarray.
* @right: Index of the rightmost element of the subarray.
*/
void merge_sort_recursive(int *array, size_t left, size_t right)
{
if (left < right)
{
size_t middle = left + (right - left) / 2;
/* Recursively sort the first and second halves */
merge_sort_recursive(array, left, middle);
merge_sort_recursive(array, middle + 1, right);
/* Merge the sorted halves */
printf("Merging...\n[left]: ");
print_array(array + left, middle - left + 1);
printf("[right]: ");
print_array(array + middle + 1, right - middle);
merge(array, left, middle, right);
}
}
/**
* merge_sort - Sorts an array of integers in ascending order using
*              the Merge sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
merge_sort_recursive(array, 0, size - 1);
}
