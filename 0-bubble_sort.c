#include "sort.h"
/**
 * bubble_sort - function of the prototype
 * @array: array to be sort
 * @size: the size
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, newsize1 = size;
	int temp, swp;

	if (array == NULL || size < 2)
		return;

	while (newsize1)
	{
		swp = 0;
		for (x = 0; x < newsize1 - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x + 1];
				array[x + 1] = array[x];
				array[x] = temp;
				print_array(array, size);
				swp = 1;
			}
		}
		newsize1--;
		if (!swp)
			break;
	}
}

