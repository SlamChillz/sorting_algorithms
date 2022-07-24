#include "sort.h"

/**
 * mazz - retrieves the maximum integer in an array
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: maximum integer in the array
 */
int mazz(int *array, int size)
{
	int i, maz;

	maz = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > maz)
			maz = array[i];
	}

	return (maz);
}

/**
  * radix - sorts an array ascendingly using the counting sort
  * @array: array of integers
  * @buff: A buffer to store the sorted array
  * @dig: significant digit to sort on
  * @size: size of the array
  *
  * Return: void
  */
void radix(int *array, int *buff, int dig, size_t size)
{
	int i, loop[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < (int) size; i++)
		loop[(array[i] / dig) % 10] += 1;

	for (i = 0; i < 10; i++)
		loop[i] += loop[i - 1];

	for (i = (int) size - 1; i >= 0; i--)
	{
		buff[loop[(array[i] / dig) % 10] - 1] = array[i];
		loop[(array[i] / dig) % 10] -= 1;
	}

	for (i = 0; i < (int) size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - sort an array ascendingly using LSD radix sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Returns: void
 */
void radix_sort(int *array, size_t size)
{
	int maz, dig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);

	if (buff == NULL)
		return;

	maz = mazz(array, size);
	for (dig = 1; maz / dig > 0; dig *= 10)
	{
		radix(array, buff, dig, size);
		print_array(array, size);
	}

	free(buff);
}
