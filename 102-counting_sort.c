#include "sort.h"
#include <string.h>
#include <stdio.h>
/**
* counting_sort - array to be sorted with algo countingSort
*@array: array of integers
*@size: dimension of aray
*Return: void
*/
void counting_sort(int *array, size_t size)
{
	int *countArray, *sorted_array, max_array, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	max_array = array[0];

	for (i = 1; i < (int)size; i++)
	{
		max_array = (array[i] > max_array) ? array[i] : max_array;
	}
	countArray = malloc(sizeof(int) * (max_array + 1));
	if (countArray == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max_array + 1); i++)
		countArray[i] = 0;
	for (i = 0; i < (int)size; i++)
		countArray[array[i]] += 1;
	for (i = 0; i < (max_array + 1); i++)
		countArray[i] += countArray[i - 1];
	print_array(countArray, max_array + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[countArray[array[i]] - 1] = array[i];
		countArray[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(countArray);
}
