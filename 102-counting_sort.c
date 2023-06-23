#include "sort.h"
/**
 * counting_sort - function of the prototype
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t a;
	int m, n, numb, dups;
	int *count;

	if (array == NULL || size < 2)
		return;
	n = array[0];
	for (a = 1; a < size; a++)
	{
		if (array[a] > n)
			n = array[a];
	}
	count = malloc(sizeof(int) * (n + 1));
	if (count == NULL)
		return;
	for (m = 0; m < (n + 1); m++)
		count[m] = 0;
	for (a = 0; a < size; a++)
	{
		numb = array[a];
		count[numb] += 1;
	}
	for (m = 0; m < n; m++)
	{
		count[m + 1] += count[m];
	}
	print_array(count, n + 1);
	for (a = 0, m = 0; m < n; m++)
	{
		if ((m == 0) && count[m] != 0)
		{
			for ((dups = count[m]); dups > 0; dups--)
				array[a++] = m;
		}
		if (count[m + 1] > count[m])
		{
			for ((dups = count[m + 1] - count[m]); dups > 0; dups--)
				array[a++] = (m + 1);
		}
	}

	free(count);
}

