#include "sort.h"
void swap(int *a, int *b);
/**
* bubble_sort - sorts an array of integers
*in ascending order using the Bubble sort algorithm
* @array: pointer to int
* @size: size of array
* Return: (0 or exit error code)
*/
void bubble_sort(int *array, size_t size)
{
	size_t  i, j;
	int exist_swap = 0;

	if (!array || size <= 0)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		exist_swap = 0;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				exist_swap = 1;
			}
		}
		if (!exist_swap)
			break;
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
