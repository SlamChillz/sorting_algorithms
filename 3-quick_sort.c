#include "sort.h"

/**
  * lomuto - implements `Lomuto` partition scheme to divide and conquer
  * @array: array to partition
  * @low: start index
  * @high: end index
  * @size: length of array
  *
  * Return: pivot index, `pindex`
  */
int lomuto(int array[], int low, int high, size_t size)
{
	int pindex, focus;
	int pivot, socket;

	pindex = low;
	pivot = array[high];
	for (focus = low; focus < high; focus++)
	{
		if (array[focus] <= pivot)
		{
			if (pindex != focus)
			{
				socket = array[pindex];
				array[pindex] = array[focus];
				array[focus] = socket;
				print_array(array, size);
			}
			pindex++;
		}
	}
	if (pindex != high)
	{
		socket = array[pindex];
		array[pindex] = array[high];
		array[high] = socket;
		print_array(array, size);
	}
	return (pindex);
}

/**
  * quickSort - sorts array with quick sort algorithm recursively
  * @array: array to be sorted
  * @low: lowest index of the array partition to be sorted
  * @high: highest index of the array partition to be sorted
  * @size: length of array
  *
  * Returns: void
  */
void quickSort(int array[], int low, int high, size_t size)
{
	int pindex;

	if (high > low)
	{
		pindex = lomuto(array, low, high, size);
		quickSort(array, low, pindex - 1, size);
		quickSort(array, pindex + 1, high, size);
	}
}

/**
  * quick_sort - sorts array in ascending order using quick sort
  * @array: array to be sorted
  * @size: length of array
  *
  * Return: void
  */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = (int) size - 1;

	quickSort(array, low, high, size);
}
