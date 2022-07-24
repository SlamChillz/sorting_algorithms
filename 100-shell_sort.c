#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

/**
 * shell_sort - Sort an array ascendingly using shell sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t step, i, k;

	if (array == NULL || size < 2)
		return;

	for (step = 1; step < (size / 3);)
		step = step * 3 + 1;

	for (; step >= 1; step /= 3)
	{
		for (i = step; i < size; i++)
		{
			k = i;
			while (k >= step && array[k - step] > array[k])
			{
				swap(array + k, array + (k - step));
				k -= step;
			}
		}
		print_array(array, size);
	}
}
