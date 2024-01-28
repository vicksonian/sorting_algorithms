#include <stddef.h>
void countingSort(int array[], size_t size, int exp) {
size_t i;
int output[size];
int count[10] = {0};
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size - 1; i < size; i--) {
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
}
int getMax(int array[], size_t size) {
int max = array[0];
size_t i;
for (i = 1; i < size; i++)
if (array[i] > max)
max = array[i];
return max;
}
void radix_sort(int array[], size_t size) {
int max = getMax(array, size);
size_t exp;
for (exp = 1; max / exp > 0; exp *= 10)
countingSort(array, size, exp);
}
