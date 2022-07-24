#include "sort.h"

/**
  * selection_sort - sorts list in ascending order using selection sort
  * @array: an array of integers to be sorted
  * @size: length of the array to be sorted
  *
  * Return: void
  */
void selection_sort(int *array, size_t size)
{
	int socket;
	size_t in, out, focus;

	for (out = 0; out < size - 1; out++)
	{
		focus = out;
		for (in = out + 1; in < size; in++)
		{
			if (array[in] < array[focus])
				focus = in;
		}
		if (focus != out)
		{
			socket = array[focus];
			array[focus] = array[out];
			array[out] = socket;
			print_array(array, size);
		}
	}
}
