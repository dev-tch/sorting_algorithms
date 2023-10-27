#include "sort.h"
void swap(int *a, int *b);
/**
*selection_sort - sort array with method sort selection
*@array: array of integers
*@size: dimension of array
*Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, index_min;
	/*check validity of inputs*/
	if (!array || size <= 0)
		return;
	for (i = 0 ; i < size - 1; i++)
	{
		index_min = i;
		/*second loop to determine index min*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_min])
				index_min = j;
		}
		/*swap min index element*/
		if (index_min != i)
		{
			swap(&array[i], &array[index_min]);
			print_array(array, size);
		}
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
