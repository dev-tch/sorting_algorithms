#include "sort.h"

void quick_sort_recursive(int *array, int start, int end, size_t size);
int partition(int *array, int start, int end, size_t size);
void swap(int *a, int *b);

/**
* quick_sort - sort array using quick sort method
* @array: array of integers
* @size: dimension of array
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	/*check validity of inputs */
	if (!array || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
/**
* partition - rearange elments of array
* @array: array of intergers
* @start: start index
* @end: end index
* @size: dimension of array
* Return: pivot-index
*/
int partition(int *array, int start, int end, size_t size)
{
	int pivot_value, i, j;

	pivot_value = array[end];

	i = start - 1;
	for (j = start; j <= end ; j++)
	{
		/*elment  is small than pivot*/
		if (array[j] < pivot_value)
		{
			/*increment min index element*/
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[end])
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quick_sort_recursive - helper function used in quick_sort
* @array: array of integers
* @start: start index
* @end: end index
* @size: dimension of array
* Return: void
*/
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end, size);
		quick_sort_recursive(array, start, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, end, size);
	}
}

/**
* swap - permutate two values
* @a: pointer to int
* @b: pointer to int
* Return: void
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
