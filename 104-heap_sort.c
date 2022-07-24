#include "sort.h"

/**
 * heapy - heapify
 * @arr: array
 * @n: tree size
 * @i: child
 * @size: array size
 *
 * Return: void
 */
void heapy(int *arr, size_t n, size_t i, size_t size)
{
	size_t largest, left, right;
	int temp;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		print_array(arr, size);
		heapy(arr, n, largest, size);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	long i;
	int temp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapy(array, size, (size_t)i, size);

	for (i = (long)size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i != 0)
			print_array(array, size);

		heapy(array, (size_t)i, 0, size);
	}
}
