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
 * counting_sort - sorts an array ascendingly using counting sort algorithm
 * @array: array of integers
 * @size: size of the array.
 *
 * Returns: void
 */
void counting_sort(int *array, size_t size)
{
	int i, maz, *loop, *result;

	if (size < 2 || array == NULL)
		return;
	maz = mazz(array, size);
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return;
	loop = malloc(sizeof(int) * (maz + 1));
	if (loop == NULL)
	{
		free(result);
		return;
	}
	for (i = 0; i < (maz + 1); i++)
		loop[i] = 0;
	for (i = 0; i < (int) size; i++)
		loop[array[i]] += 1;
	for (i = 0; i < (maz + 1); i++)
		loop[i] += loop[i - 1];

	print_array(loop, maz + 1);

	for (i = 0; i < (int) size; i++)
	{
		result[loop[array[i]] - 1] = array[i];
		loop[array[i]] -= 1;
	}
	for (i = 0; i < (int) size; i++)
		array[i] = result[i];

	free(loop), free(result);
}
