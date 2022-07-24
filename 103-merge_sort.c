#include "sort.h"

/**
  * merge - merge two sorted subarrays
  * @array: original array
  * @copy: copy of array
  * @left: start of the first array
  * @mid: end of the first array
  * @right: end of the second index
  *
  * Return: void
  */
void merge(int *array, int *copy, int left, int mid, int right)
{
	int i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + (mid), right - mid);

	while (k < right)
	{
		if ((i < mid) && ((j >= right) || (copy[i] <= copy[j])))
			array[k] = copy[i++];
		else
			array[k] = copy[j++];
		k++;
	}

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
  * mergeSort - implements `merge sort` recursively on an array
  * @array: array to be sorted
  * @copy: copy of array
  * @left: left index
  * @right: right index
  *
  * Return: void
  */
void mergeSort(int *array, int *copy, int left, int right)
{
	int mid, i;

	if ((right - left) > 1)
	{
		mid = (left + right) / 2;

		mergeSort(array, copy, left, mid);

		mergeSort(array, copy, mid, right);

		for (i = left; i <= right; i++)
			copy[i] = array[i];

		merge(array, copy, left, mid, right);
	}
}

/**
  * merge_sort - sorts an array using the `merge sort` algorithm
  * @array: pointer to the array to be sorted
  * @size: @size of the array
  *
  * Return: void
  */
void merge_sort(int *array, size_t size)
{
	int *copy, i;

	if (array == NULL)
		return;

	copy = malloc(sizeof(int) * size);

	if (copy != NULL)
	{
		for (i = 0; i < (int) size; i++)
			copy[i] = array[i];

		mergeSort(array, copy, 0, (int) size);

		free(copy);
	}
}
