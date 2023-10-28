#include "sort.h"

int _max(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *sortedArray);
void radix_sort(int *array, size_t size);

/**
 * _max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *Return: maximum of array
 */
int _max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_count_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: length of array.
 * @exp: is 10^i where i is current digit number.
 * @sortedArray:  store the sorted array.
 *Return: void
 */
void radix_count_sort(int *array, size_t size, int exp, int *sortedArray)
{
	int countArray[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		countArray[(array[i] / exp) % 10] += 1;

	for (i = 0; i < 10; i++)
		countArray[i] += countArray[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		sortedArray[countArray[(array[i] / exp) % 10] - 1] = array[i];
		countArray[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sortedArray[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array
 *Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *sortedArray;

	if (array == NULL || size < 2)
		return;

	sortedArray = malloc(sizeof(int) * size);
	if (sortedArray == NULL)
		return;

	max = _max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_count_sort(array, size, exp, sortedArray);
		print_array(array, size);
	}

	free(sortedArray);
}
