#include "sort.h"
/**
 * selection_sort - function of the prototype
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int indx = 0, mins, temp;
	size_t f, k;

	if (array == NULL || size < 2)
		return;

	for (f = 0; f < size - 1; f++)
	{
		mins = array[f];
		for (k = f + 1; k < size; k++)
		{
			if (array[k] < mins)
			{
				mins = array[k];
				indx = k;
			}
		}
		if (mins != array[f])
		{
			temp = array[f];
			array[f] = array[indx];
			array[indx] = temp;
			print_array(array, size);
		}
	}
}

