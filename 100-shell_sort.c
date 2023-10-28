#include "sort.h"
/**
* shell_sort - sorts an array of integers in ascending
*order using the Shell sort algorithm
* @array: array of integers
* @size: dimension of array
* Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int newElem;

	/*check validity of data*/
	if (!array || size <= 1)
		return;

	/* calculate the Knuth sequence*/
	while (gap  <= size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			newElem = array[i];
			j = i;
			while (j >= gap && array[j - gap] > newElem)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = newElem;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
