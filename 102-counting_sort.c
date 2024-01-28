#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
* counting_sort - Sorts an array of integers in ascending order using
*                 the Counting sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
int *count_array, *output_array;
int max_num = 0;
size_t i;
if (size < 2)
return;
/* Find the maximum number in the array */
for (i = 0; i < size; i++)
{
if (array[i] > max_num)
max_num = array[i];
}
/* Create the count_array and initialize it with zeros */
count_array = malloc((max_num + 1) * sizeof(int));
if (count_array == NULL)
return;
for (i = 0; i <= (size_t)max_num; i++)
count_array[i] = 0;
/* Count the occurrences of each number in the array */
for (i = 0; i < size; i++)
count_array[array[i]]++;
/* Print the count_array */
for (i = 0; i <= (size_t)max_num; i++)
{
if (i < (size_t)max_num)
printf("%d, ", count_array[i]);
else
printf("%d", count_array[i]);
}
printf("\n");
/* Update the count_array with cumulative sums */
for (i = 1; i <= (size_t)max_num; i++)
count_array[i] += count_array[i - 1];
/* Create the output_array and populate it with sorted values */
output_array = malloc(size * sizeof(int));
if (output_array == NULL)
{
free(count_array);
return;
}
for (i = size - 1; i < size; i--)
{
output_array[count_array[array[i]] - 1] = array[i];
count_array[array[i]]--;
}
/* Copy the sorted elements back to the original array */
for (i = 0; i < size; i++)
array[i] = output_array[i];
/* Print the sorted array */
print_array(array, size);
/* Free allocated memory */
free(count_array);
free(output_array);
}
