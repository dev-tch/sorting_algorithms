#include "sort.h"
#include <stdio.h>
void merge(int *array, int *sortedArray, size_t start, size_t mid,
		size_t end);
void merge_sort_helper(int *subarr, int *buff, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge - Sort left and right array of integers.
 * @array: array to be sorted
 * @sortedArray: save sorted elments to this array.
 * @start: start index.
 * @mid: middle index.
 * @end: end index.
 * Return: void
 */
void merge(int *array, int *sortedArray, size_t start, size_t mid,
		size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		sortedArray[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		sortedArray[k++] = array[i];
	for (; j < end; j++)
		sortedArray[k++] = array[j];
	for (i = start, k = 0; i < end; i++)
		array[i] = sortedArray[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_helper - helper function to merge left and right arrays.
 * @array: array to be sorted.
 * @sortedArray: to save sorted array .
 * @start: start index.
 * @end: end index.
 * Return: void
 */
void merge_sort_helper(int *array, int *sortedArray, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_sort_helper(array, sortedArray, start, mid);
		merge_sort_helper(array, sortedArray, mid, end);
		merge(array, sortedArray, start, mid, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: dimension of array.
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *sortedArray;

	if (array == NULL || size < 2)
		return;

	sortedArray = malloc(sizeof(int) * size);
	if (sortedArray == NULL)
		return;

	merge_sort_helper(array, sortedArray, 0, size);

	free(sortedArray);
}

