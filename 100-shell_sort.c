#include "sort.h"

/**
  * shell_sort - shell sorts an array ascendingly, using the Knuth sequence
  * @array: array to be sorted
  * @size: size of the array to be sorted
  *
  * Return: void
  */
void shell_sort(int *array, size_t size)
{
	int i, k, tmp, step;

	step = 1;

	while (step <= ((int) size - 1) / 9)
		step = 3 * step + 1;

	while (step >= 1)
	{
		for (i = step; i < (int) size; i++)
		{
			tmp = array[i];
			k = i - step;
			while (k >= 0 && tmp < array[k])
			{
				array[k + step] = array[k];
				k = k - step;
			}
			array[k + step] = tmp;
		}
		step /= 3;
		print_array(array, (int) size);
	}
}
