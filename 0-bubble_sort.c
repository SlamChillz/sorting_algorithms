#include "sort.h"

/**
  * bubble_sort - sorts array in ascending order using bubble sort
  * @array: array to be sorted
  * @size: length of array
  *
  * Return: void
  */
void bubble_sort(int *array, size_t size)
{
	size_t in, out;
	int socket;
	bool bubbled;

	if (array == NULL || size < 2)
		return;

	for (out = 0; out < size - 1; out++)
	{
		bubbled = false;
		for (in = 0; in < size - out - 1; in++)
		{
			if (array[in] > array[in + 1])
			{
				socket = array[in];
				array[in] = array[in + 1];
				array[in + 1] = socket;
				print_array(array, size);
				bubbled = true;
			}
		}
		if (!bubbled)
			break;
	}
}
