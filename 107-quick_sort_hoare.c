#include "sort.h"
void swap(int *first, int *second);
void _hoareSort(int *array, size_t size, int left, int right);
/**
 * quick_sort_hoare - sorts an array of integers
 *in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: length of array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_hoareSort(array, size, 0, size - 1);
}

/**
 * _hoareSort - implement partition hoare
 * @array: array of integers
 * @size: length of array
 * @left: start index array partition
 * @right: end index array partition
 * Return: void
 */
void _hoareSort(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	if (right - left > 0)
	{
		pivot = array[right];
		for (above = left - 1, below = right + 1; above < below;)
		{
			do {
				above++;
			} while (array[above] < pivot);
			do {
				below--;
			} while (array[below] > pivot);

			if (above < below)
			{
				swap(array + above, array + below);
				print_array(array, size);
			}
		}
		_hoareSort(array, size, left, above - 1);
		_hoareSort(array, size, above, right);
	}
}

/**
 * swap - exchange values of two variables
 * @a: pointer to first varaible
 * @b: pointer to Second variable
 * Return: void
 */
void swap(int *a, int *b)
{
	int save;

	save = *a;
	*a = *b;
	*b = save;
}
