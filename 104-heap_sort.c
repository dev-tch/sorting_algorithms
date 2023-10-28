#include "sort.h"
/**
* swap - exchange values of two vars
* @a: var1
* @b: var2
* Return: void
*/
void swap(int *a, int *b)
{
	int save;

	save = *a;
	*a = *b;
	*b = save;
}

/**
* sift_down- extends the heap property
* @array: array to be sorted
* @size_array: length of array
* @base: index  base row of the tree
* @root: index root row of tree
* Return: void
*/
void sift_down(int *array, size_t size_array, size_t base, int root)
{
	size_t lt, rt;
	int max;

	max = root;

	lt = 2 * root + 1;
	rt = 2 * root + 2;

	if (lt < base && array[lt] > array[max])
		max = lt;

	if (rt < base && array[rt] > array[max])
		max = rt;
	if (max != root)
	{
		swap(&array[root], &array[max]);
		/*printf("Swap: %d %d\n", array[root], array[max]);*/
		print_array(array, size_array);
		sift_down(array, size_array, base,  max);
	}
}
/**
* heap_sort- sort array with algo heap sort
* @array: array to be sorted
* @size: length of array
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	int i;
	/*creation heap*/
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, size, i);


	/*extract elmenents from heap*/
	for (i = size - 1; i > 0; i--)
	{
		/*move root to end */
		swap(&array[0], &array[i]);
		print_array(array, size);
		/*printf("Swap: %d %d\n", array[0], array[i]);*/
		sift_down(array, size, i, 0);
	}
}

