#include "sort.h"
/**
 * shell_sort - function of the prototype
 * @array: array to take in
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, f, k;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = (space * 3) + 1;

	while (space)
	{
		for (f = space; f < size; f++)
		{
			temp = array[f];
			for (k = f; k >= space && array[k - space] > temp; k -= space)
			{
				array[k] = array[k - space];
			}
			array[k] = temp;
		}
		print_array(array, size);
		space /= 3;
	}
}

