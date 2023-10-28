#include "sort.h"
#include <stdio.h>
void swap(int *a, int *b);
void bitonicMerge(int *array, size_t size,
size_t start, size_t count, char dir);
void bitonicSort(int *array, size_t size,
size_t start, size_t count, char dir);

void bitonic_sort(int *array, size_t size);

/**
 * swap - exchange values of two variables.
 * @a: pointer to va1.
 * @b: pointer to var2.
 *Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonicMerge - recursive sorting of  a bitonic sequence
 * (asending:dir = 1) (desending: dir = 0)
 * @array: array of integers.
 * @size: length of array.
 * @start: starting index of the sequence in array to sort.
 * @count: number of elements to be sorted.
 * @dir: The direction to sort in.
 * Return void
 */
void bitonicMerge(int *array, size_t size, size_t start, size_t count,
		char dir)
{
	size_t i, freq = dir / 2;

	if (count > 1)
	{
		for (i = start; i < start + freq; i++)
		{
			if ((dir == UP && array[i] > array[i + freq]) ||
			    (dir == DOWN && array[i] < array[i + freq]))
				swap(array + i, array + i + freq);
		}
		bitonicMerge(array, size, start, freq, dir);
		bitonicMerge(array, size, start + freq, freq, dir);
	}
}

/**
 * bitonicSort - generate sequence
 * by sorting its two halves in opposite sorting orders
 * @array: array of integers
 * @size: length of array
 * @start: start index  bitonic sequence.
 * @count: The size of a block of the building bitonic sequence
 * @dir: direction to sort the bitonic sequence
 * Return:void
 */
void bitonicSort(int *array, size_t size, size_t start, size_t count, char dir)
{
	size_t cut = count / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", count, size, str);
		print_array(array + start, count);

		bitonicSort(array, size, start, cut, UP);
		bitonicSort(array, size, start + cut, cut, DOWN);
		bitonicMerge(array, size, start, count, dir);

		printf("Result [%lu/%lu] (%s):\n", count, size, str);
		print_array(array + start, count);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *using the Bitonic sort algorithm
 * @array: array of integers.
 * @size: length of array.
 * Return:void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	/*sort array of size in  ASCENDING order*/
	bitonicSort(array, size, 0, size, UP);
}
